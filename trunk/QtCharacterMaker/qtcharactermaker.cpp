#include "qtcharactermaker.h"

#include "view/mainwindow.h"
#include "view/actions.h"

QtCharacterMaker::QtCharacterMaker(int argc, char *argv[]) :
  QApplication(argc, argv)
{
  actions_ = new Actions();

  main_window_ = new MainWindow();
  main_window_->show();
}

MainWindow *QtCharacterMaker::main_window()
{
  return main_window_;
}

Actions *QtCharacterMaker::actions()
{
  return actions_;
}
