#ifndef SPLASHSCREENWIDGET_H
#define SPLASHSCREENWIDGET_H

#include <QSplashScreen>

namespace Ui {
  class SplashScreenWidget;
}

class SplashScreenWidget : public QSplashScreen
{
  Q_OBJECT

public:
  explicit SplashScreenWidget(QWidget *parent = 0);
  ~SplashScreenWidget();

private:
};

#endif // SPLASHSCREENWIDGET_H
