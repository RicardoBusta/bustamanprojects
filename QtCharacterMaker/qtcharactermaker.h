#ifndef QTCHARACTERMAKER_H
#define QTCHARACTERMAKER_H

#include <QApplication>

class MainWindow;

class QtCharacterMaker : public QApplication
{
  Q_OBJECT
public:
  explicit QtCharacterMaker(int argc, char *argv[]);

private:
  MainWindow *w;
};

#endif // QTCHARACTERMAKER_H
