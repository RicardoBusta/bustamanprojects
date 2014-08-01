#include "shaders.h"

#include "utils/options.h"

Shaders * Shaders::instance_ = NULL;

Shaders::Shaders()
{
}

Shaders *Shaders::instance()
{
  if(NULL == instance_){
    instance_ = new Shaders;
  }
  return instance_;
}

bool Shaders::bind(QString shader_name)
{
  if(!Options::instance()->get_option("check_shader")) return true;

  if(instance_->map.contains(shader_name)){
    if(NULL != instance_->map[shader_name]){
      return instance_->map[shader_name]->bind();
    }else{
      return false;
    }
  }else{
    bool ok = true;
    instance_->map.insert(shader_name,new QGLShaderProgram);
    qDebug() << "Opening shader file:" << ":/shaders/"+shader_name+".vsh";
    ok &= instance_->map[shader_name]->addShaderFromSourceFile(QGLShader::Vertex,":/shaders/"+shader_name+".vsh");
    qDebug() << "Opening shader file:" << ":/shaders/"+shader_name+".fsh";
    ok &= instance_->map[shader_name]->addShaderFromSourceFile(QGLShader::Fragment,":/shaders/"+shader_name+".fsh");
    if(!ok){
      delete instance_->map[shader_name];
      instance_->map.remove(shader_name);
      instance_->map.insert(shader_name,NULL);
    }else{
      instance_->map[shader_name]->bind();
    }
    return ok;
  }
}

bool Shaders::release(QString shader_name)
{
  if(!Options::instance()->get_option("check_shader")) return true;

  if( instance_->map.contains(shader_name) && (NULL != instance_->map[shader_name]) ){
    instance_->map[shader_name]->release();
    return true;
  }else{
    return false;
  }
}
