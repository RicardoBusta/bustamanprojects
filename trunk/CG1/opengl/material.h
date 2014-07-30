#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>

class Material
{
public:
  Material();

  enum MaterialColor{
    red,
    green,
    blue,
    white,
    black
  };

  void load(QString file_name);

  void apply();
private:
  bool invalid_;
};

#endif // MATERIAL_H
