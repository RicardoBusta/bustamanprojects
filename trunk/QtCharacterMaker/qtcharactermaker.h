#ifndef QTCHARACTERMAKER_H
#define QTCHARACTERMAKER_H

#include <QApplication>

class MainWindow;
class SplashScreenWidget;

#define cmApp ((QtCharacterMaker*)qApp)

class QtCharacterMaker : public QApplication
{
  Q_OBJECT
public:
  explicit QtCharacterMaker(int argc, char *argv[]);

  MainWindow *main_window();

private:
  MainWindow *main_window_;
  SplashScreenWidget *splash_screen_widget_;
};

#endif // QTCHARACTERMAKER_H
