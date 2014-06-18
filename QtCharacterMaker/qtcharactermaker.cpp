#include "qtcharactermaker.h"

#include "view/mainwindow.h"

#include <QTranslator>

QtCharacterMaker::QtCharacterMaker(int argc, char *argv[]) :
  QApplication(argc, argv)
{
  QTranslator translator;
  translator.load("://tokens_ptbr");

  installTranslator(&translator);

  main_window_ = new MainWindow();
  main_window_->show();
}

MainWindow *QtCharacterMaker::main_window()
{
  return main_window_;
}
