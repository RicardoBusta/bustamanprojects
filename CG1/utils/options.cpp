#include "options.h"

#ifndef NULL
#define NULL 0
#endif

Options *Options::instance_ = NULL;

Options::Options():
  options_changed_(true),
  // Scene
  initial_zoom_(1000),
  initial_rot_x_(0),
  initial_rot_y_(0),
  initial_rot_z_(0),
  // Artifacts
  normal_size_(0.2),
  show_normals_(false),
  // Render
  show_wireframe_(false),
  shaders_(true),
  animation_(true),
  show_textures_(true),
  show_skydome_(true),
  clear_color_(QColor(Qt::darkBlue))
{
}

Options *Options::instance()
{
  if(NULL == instance_)
    instance_ = new Options;

  return instance_;
}

bool Options::options_changed() const
{
  return options_changed_;
}

void Options::options_applied()
{
  options_changed_ = false;
}

int Options::initial_zoom() const
{
  return initial_zoom_;
}

int Options::initial_rot_x() const
{
  return initial_rot_x_;
}

int Options::initial_rot_y() const
{
  return initial_rot_y_;
}

int Options::initial_rot_z() const
{
  return initial_rot_z_;
}

float Options::normal_size() const
{
  return normal_size_;
}

bool Options::show_normals() const
{
  return show_normals_;
}

bool Options::show_wireframe() const
{
  return show_wireframe_;
}

bool Options::shaders() const
{
  return shaders_;
}

bool Options::animation() const
{
  return animation_;
}

bool Options::show_skydome() const
{
  return show_skydome_;
}

bool Options::show_textures() const
{
  return show_textures_;
}

QColor Options::clear_color() const
{
  return clear_color_;
}
