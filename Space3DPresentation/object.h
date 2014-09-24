#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

class Object
{
public:
  Object();

  QString model_name;
  QString texture;

  void draw();
};

#endif // OBJECT_H
