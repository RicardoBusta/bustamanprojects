#ifndef SPLASHSCREENWIDGET_H
#define SPLASHSCREENWIDGET_H

#include <QWidget>

namespace Ui {
  class SplashScreenWidget;
}

class SplashScreenWidget : public QWidget
{
  Q_OBJECT

public:
  explicit SplashScreenWidget(QWidget *parent = 0);
  ~SplashScreenWidget();

private:
  Ui::SplashScreenWidget *ui;
};

#endif // SPLASHSCREENWIDGET_H
