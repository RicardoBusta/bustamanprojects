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
  cursor_size_ = QSize(32,32);
  selection_size_ = cursor_size_;
  selection_ = QRect(0,0,0,0);
}
