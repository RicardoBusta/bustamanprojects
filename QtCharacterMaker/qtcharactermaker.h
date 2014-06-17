#ifndef QTCHARACTERMAKER_H
#define QTCHARACTERMAKER_H

#include <QApplication>

class MainWindow;
class Actions;

#define cmApp ((QtCharacterMaker*)qApp)

class QtCharacterMaker : public QApplication
{
  Q_OBJECT
public:
  explicit QtCharacterMaker(int argc, char *argv[]);

  MainWindow *main_window();
  Actions *actions();

private:
  MainWindow *main_window_;
  Actions *actions_;
};

#endif // QTCHARACTERMAKER_H
