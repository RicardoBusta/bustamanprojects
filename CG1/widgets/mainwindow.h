#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "utils/options.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

private slots:
  void toggleWireframe(bool v);
  void toggleShaderOff(bool v);
  void toggleNormals(bool v);
  void toggleAnimation(bool v);
};

#endif // MAINWINDOW_H
