#include "actions.h"

#include <QDebug>

Actions::Actions(QObject *parent) :
  QObject(parent)
{
}

void Actions::OpenImage()
{
  qDebug() << "Open Image" ;
}
