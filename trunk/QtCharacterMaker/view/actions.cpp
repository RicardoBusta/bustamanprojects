#include "actions.h"


static Actions *actions_instance_ = NULL;

Actions *Actions::instance()
{
  if(NULL == actions_instance_){
    actions_instance_ = new Actions();
  }

  return actions_instance_;
}

Actions::Actions(QObject *parent) :
  QObject(parent)
{
}
