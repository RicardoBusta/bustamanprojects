#include "splashscreenwidget.h"
#include "ui_splashscreenwidget.h"

SplashScreenWidget::SplashScreenWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SplashScreenWidget)
{
  ui->setupUi(this);
}

SplashScreenWidget::~SplashScreenWidget()
{
  delete ui;
}
