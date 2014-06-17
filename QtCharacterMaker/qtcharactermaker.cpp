#include "qtcharactermaker.h"

#include "view/mainwindow.h"

QtCharacterMaker::QtCharacterMaker(int argc, char *argv[]) :
  QApplication(argc, argv)
{
  w = new MainWindow();
  w->show();
}
