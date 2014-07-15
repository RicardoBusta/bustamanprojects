#include "qtcharactermaker.h"

#include "view/mainwindow.h"
#include "view/splashscreenwidget.h"

#include <QTranslator>
#include <QTimer>

const bool splash = false;

QtCharacterMaker::QtCharacterMaker(int argc, char *argv[]) :
  QApplication(argc, argv)
{
  QTranslator translator;
  translator.load("://tokens_ptbr");

  installTranslator(&translator);

  main_window_ = new MainWindow();
  splash_screen_widget_ = new SplashScreenWidget();

  if(splash){
    splash_screen_widget_->show();
    QTimer::singleShot(1000,main_window_,SLOT(show()));
    QTimer::singleShot(1500,splash_screen_widget_,SLOT(hide()));
  }else{
    main_window_->show();
  }
}

MainWindow *QtCharacterMaker::main_window()
{
  return main_window_;
}
