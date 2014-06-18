#include "options.h"

static Options *options_instance_ = NULL;

Options *Options::instance()
{
  if(NULL == options_instance_){
    options_instance_ = new Options();
  }

  return options_instance_;
}

Options::Options(QObject *parent) :
  QObject(parent)
{
  selection_width_ = 32;
  selection_height_ = 32;
}
