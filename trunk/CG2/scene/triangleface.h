#ifndef TRIANGLEFACE_H
#define TRIANGLEFACE_H

#include "structures.h"

class SceneObject;

class TriangleFace{
public:
  TriangleFace();
  TriangleFace(const Ric::Vector &v0_, const Ric::Vector &v1_, const Ric::Vector &v2_, const Ric::Material &material_, bool reflect);

  Ric::Material material() const;
  void setMaterial(const Ric::Material &material);

  Ric::Vector v0() const;
  void setV0(const Ric::Vector &v0);

  Ric::Vector v1() const;
  void setV1(const Ric::Vector &value);

  Ric::Vector v2() const;
  void setV2(const Ric::Vector &value);

  Ric::Vector fc() const;
  void setFc(const Ric::Vector &value);

  Ric::Vector n() const;
  void setN(const Ric::Vector &n);

  void scale(double s);
  void move(Ric::Vector m);

  bool reflect;
private:
  Ric::Material material_;
  Ric::Vector v0_;
  Ric::Vector v1_;
  Ric::Vector v2_;
  Ric::Vector fc_;
  Ric::Vector n_;
//  SceneObject *object_;
};


#endif // TRIANGLEFACE_H
