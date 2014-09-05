#ifndef CGAPPLICATION_H
#define CGAPPLICATION_H

#include <QApplication>

#include "widgets/mainwindow.h"

class CGApplication : public QApplication
{
public:
  CGApplication(int argc, char *argv[]);
  ~CGApplication();

  MainWindow *getMainWindow();
private:
  MainWindow main_window_;
};

#endif // CGAPPLICATION_H
