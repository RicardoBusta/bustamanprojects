#ifndef TRIANGLEFACE_H
#define TRIANGLEFACE_H

#include "structures.h"

class SceneObject;

class TriangleFace{
public:
  TriangleFace();
  TriangleFace(const Ric::Vector &v0_, const Ric::Vector &v1_, const Ric::Vector &v2_, const Ric::Material &material_);
  TriangleFace(const TriangleFace &f, const Ric::Matrix4x4 *transform);

  void setTexCoords(const Ric::Vector &vt0, const Ric::Vector &vt1, const Ric::Vector &vt2);
  void setNormals(const Ric::Vector &vn0, const Ric::Vector &vn1, const Ric::Vector &vn2);

  Ric::Vector vt0() const;
  Ric::Vector vt1() const;
  Ric::Vector vt2() const;

  Ric::Vector vn0() const;
  Ric::Vector vn1() const;
  Ric::Vector vn2() const;

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

private:
  Ric::Material material_;
  Ric::Vector v0_;
  Ric::Vector v1_;
  Ric::Vector v2_;
  Ric::Vector fc_;
  Ric::Vector n_;

  bool vertex_texture_coord;
  Ric::Vector vt0_;
  Ric::Vector vt1_;
  Ric::Vector vt2_;

  bool vertex_normal;
  Ric::Vector vn0_;
  Ric::Vector vn1_;
  Ric::Vector vn2_;
//  SceneObject *object_;
};


#endif // TRIANGLEFACE_H