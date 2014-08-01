#include "scene.h"

#include <QtOpenGL>

#include "utils/options.h"
#include "opengl/textures.h"
#include "opengl/shaders.h"

Scene *Scene::instance_ = NULL;
QMap<QString,Scene*> Scene::scene_;
QString Scene::current_scene_ = "none";

Scene::Scene():
  zoom_(Options::instance()->initial_zoom()),
  rot_x_(Options::instance()->initial_rot_x()),
  rot_y_(Options::instance()->initial_rot_y()),
  rot_z_(Options::instance()->initial_rot_z()),
  initialized_(false)
{
}

void Scene::setZoom(int zoom)
{
  if(zoom < 1){
    zoom_ = 1;
  }else if(zoom > 10000){
    zoom_ = 10000;
  }else{
    zoom_ = zoom;
  }
}

void Scene::addZoom(int zoom)
{
  setZoom( zoom_ + zoom );
}

void Scene::rotate(int rot_x, int rot_y, int rot_z)
{
  rot_x_ += rot_x*10;
  rot_y_ += rot_y*10;
  rot_z_ += rot_z*10;
}

void Scene::initialize()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);

  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void Scene::setup()
{
  if(initialized_) return;

  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);

  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);


  setup_spec();
  initialized_ = true;
}

void Scene::resize(int w, int h)
{
  int size = qMax(w,h);
  glViewport((w-size)/2.0,(h-size)/2.0,size,size);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //  glOrtho(-1,1,-1,1,-50,50);
  glFrustum(-.1,.1,-.1,.1,0.1,1000);
  glTranslatef(0,0,-1);

  glMatrixMode(GL_MODELVIEW);
}

void Scene::setOptions()
{
  if(Options::instance()->options_changed()){
    const QColor &cc = Options::instance()->clear_color();
    glClearColor(cc.redF(),cc.greenF(),cc.blueF(),1.0f);

    if(Options::instance()->get_option("check_textures")){
      glEnable(GL_TEXTURE_2D);
    }else{
      glDisable(GL_TEXTURE_2D);
    }

    Options::instance()->options_applied();
  }


}

void Scene::preDraw()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();

  if(Options::instance()->get_option("check_wireframe")){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
  }else{
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
  }
}

void Scene::draw()
{
  Shaders::instance()->bind("phong");
  glPushMatrix();
  float zoom = float(zoom_)/10000.0;
  glScalef(zoom,zoom,zoom);
  glRotatef(float(rot_x_)/50,1,0,0);
  glRotatef(float(rot_y_)/50,0,1,0);
  glRotatef(rot_z_,0,0,1);

  for(int i=0;i<objects_.size(); i++){
    objects_[i].draw();
  }
  glPopMatrix();
  Shaders::instance()->release("phong");
}

void Scene::drawSky()
{
  if(Options::instance()->get_option("check_skydome")){
  glPushMatrix();
  //glLoadIdentity();
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  glDisable(GL_LIGHTING);

  glRotatef(float(rot_x_)/50,1,0,0);
  glRotatef(float(rot_y_)/50,0,1,0);
  glRotatef(rot_z_,0,0,1);

  skybox_.draw();

  glPopAttrib();

  glPopMatrix();
  }
}

void Scene::drawArtifacts()
{
  glPushMatrix();

  glPushAttrib(GL_ALL_ATTRIB_BITS);
  glDisable(GL_LIGHTING);

  float zoom = float(zoom_)/10000.0;

  glRotatef(float(rot_x_)/50,1,0,0);
  glRotatef(float(rot_y_)/50,0,1,0);
  glRotatef(rot_z_,0,0,1);

  glScalef(zoom,zoom,zoom);

  for(int i=0;i<objects_.size(); i++){
    objects_[i].drawArtifacts();
  }

  if(Options::instance()->get_option("check_axis")){
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINES);
    // Axis
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);

    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
  }

  glPopAttrib();
  glPopMatrix();
}

void Scene::postDraw()
{
}

void Scene::step()
{
  for(int i=0;i<objects_.size(); i++){
    objects_[i].step();
  }
}

void Scene::addScene(QString scene_name, Scene *scene)
{
  if(scene_.contains(scene_name)){
    qWarning () << "scene with repeated name.";
    return;
  }

  scene_.insert(scene_name,scene);
}

bool Scene::valid()
{
  if(scene_.contains(current_scene_) && scene_[current_scene_]!=NULL){
    return true;
  }
  return false;
}

Scene *Scene::current()
{
  if(valid()){
    return scene_[current_scene_];
  }
}

void Scene::setCurrent(QString scene_name)
{
  if(scene_.contains(scene_name)){
    current_scene_ = scene_name;
    scene_[current_scene_]->setup();
  }else{
    qWarning () << "Scene do not exist.";
  }
}

void Scene::setup_spec()
{
}