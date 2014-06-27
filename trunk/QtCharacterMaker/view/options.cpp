#include "options.h"

static Options *options_instance_ = NULL;

const int kInitialCursorWidth = 32;
const int kInitialCursorHeight = 32;

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
  cursor_size_ = QSize(kInitialCursorWidth,kInitialCursorHeight);
  selection_ = QRect(0,0,kInitialCursorWidth,kInitialCursorHeight);
  current_edit_mode_ = EDIT_MODE_GRID;
  current_tool_ = TOOL_SELECTION;
}
