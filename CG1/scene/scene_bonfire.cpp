#include "scene_bonfire.h"

#include <QLabel>
#include <QVBoxLayout>

SceneBonfire::SceneBonfire(QObject *parent):
  Scene(parent)
{
}

SceneBonfire::~SceneBonfire()
{
}

void SceneBonfire::buildControlWidget()
{
  if(control_widget_ == NULL) return;

  control_widget_->setLayout(new QVBoxLayout);
  control_widget_->layout()->addWidget(new QLabel("Bonfire"));
}
