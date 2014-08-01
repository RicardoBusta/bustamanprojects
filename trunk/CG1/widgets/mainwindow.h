#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "utils/options.h"

#define DECLARE_TOGGLE_CHECK(c_name)\
    void toggle_(c_name)(bool v)

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

  void connectCheckBox(QWidget *check_box,bool value);

private slots:
  void shaderToggle(bool v);

  void optionToggled(bool v);
};

#undef DECLARE_TOGGLE_CHECK

#endif // MAINWINDOW_H
