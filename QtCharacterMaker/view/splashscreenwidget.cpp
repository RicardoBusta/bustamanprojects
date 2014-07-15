#include "splashscreenwidget.h"

SplashScreenWidget::SplashScreenWidget(QWidget *parent) :
  QSplashScreen(parent)
{
  this->setPixmap(QPixmap(":/images/splash.png"));
}

SplashScreenWidget::~SplashScreenWidget()
{

}
