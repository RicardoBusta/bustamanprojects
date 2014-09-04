#include "scene_fur.h"

SceneFur::SceneFur(QObject *parent):
  Scene(parent)
{
}

SceneFur::~SceneFur()
{
}

void SceneFur::setup_spec()
{
  Model::load(":/model/fur.obj");
  Model::load(":/model/skydome.obj");

  Object *fur_eyes = Object::create("Fur Eyes","fur_eyes");
  fur_eyes->setAltTexture("fur_alt.png");
  objects_.push_back(fur_eyes);

  const int num_layers = 50;
  const int num_layers_0 = 1;
  const int num_layers_1 = 30;
  const float fur_size = 0.5;

  const float gravity = -0.0003;
  const float velocity = 0.001;

  for(int i=0;i<num_layers;i++){
    int level;
    if(i < num_layers_0){
      level = 0;
    }else if(i<num_layers_1){
      level = 1;
    }else{
      level = 2;
    }
    Object *fur_layer = Object::create(QString("Fur layer %1").arg(i),QString("fur_level_%1").arg(level));
    fur_layer->setScale(1.0 + (fur_size/float(num_layers))*i);
    int alpha = 255*(1.0 - (1.0/float(num_layers))*i);
    int tone = 255.0 - alpha/2;
    float displacement = velocity*i + (gravity*i*i)/2;
    fur_layer->setCustomColor(QColor(tone,tone,tone,alpha));
    fur_layer->setPosition(QVector3D(0,displacement,0));
    fur_layer->setAltTexture("fur_alt.png");
    objects_.push_back(fur_layer);
  }

  skybox_ = Object::create("Skydome","skydome");
}

void SceneFur::buildControlWidget()
{

}
