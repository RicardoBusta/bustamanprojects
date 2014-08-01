#include "options.h"

#include <QDebug>

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

bool Options::get_option(QString option)
{
  if(check_options_.contains(option)){
  return check_options_[option];
  }else{
    qWarning() << "Invalid Option:" << option;
    return false;
  }
}

void Options::set_option(QString option, bool v)
{
  options_changed_ = true;
  if(check_options_.contains(option)){
    check_options_[option] = v;
  }else{
    check_options_.insert(option,v);
  }
}

QColor Options::clear_color() const
{
  return clear_color_;
}
