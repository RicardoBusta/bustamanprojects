#include "triangleface.h"

#include "scene/sceneobject.h"

TriangleFace::TriangleFace()
{
}

TriangleFace::TriangleFace(const Ric::Vector &v0, const Ric::Vector &v1, const Ric::Vector &v2, const Ric::Material &material)
  : material_(material),
    v0_(v0),
    v1_(v1),
    v2_(v2),
    fc_((v0+v1+v2)/3),
    n_(((v1-v0)^(v2-v0)).Normalized())
{
}
Ric::Material TriangleFace::material() const
{
  return material_;
}

void TriangleFace::scale(double s)
{
  v0_ = v0_ * s;
  v1_ = v1_ * s;
  v2_ = v2_ * s;
  fc_ = (v0_+v1_+v2_)/3;
  n_ = ((v1_-v0_)^(v2_-v0_)).Normalized();
}

void TriangleFace::move(Ric::Vector m)
{
  v0_ += m;
  v1_ += m;
  v2_ += m;
  fc_ += m;
  n_ += m;
}


void TriangleFace::setMaterial(const Ric::Material &material)
{
  material_ = material;
}
Ric::Vector TriangleFace::v0() const
{
  return v0_;
}

void TriangleFace::setV0(const Ric::Vector &v0)
{
  v0_ = v0;
}
Ric::Vector TriangleFace::v1() const
{
  return v1_;
}

void TriangleFace::setV1(const Ric::Vector &value)
{
  v1_ = value;
}
Ric::Vector TriangleFace::v2() const
{
  return v2_;
}

void TriangleFace::setV2(const Ric::Vector &value)
{
  v2_ = value;
}
Ric::Vector TriangleFace::fc() const
{
  return fc_;
}

void TriangleFace::setFc(const Ric::Vector &value)
{
  fc_ = value;
}
Ric::Vector TriangleFace::n() const
{
  return n_;
}

void TriangleFace::setN(const Ric::Vector &n)
{
  n_ = n;
}

//Ric::Material TriangleFace::material()
//{
//  return object_->material_;
//}
