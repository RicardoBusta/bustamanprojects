#ifndef RAY_H
#define RAY_H


#include "structures.h"

class Scene;
class TriangleFace;
class SceneObject;

enum RAY_TYPE{ RAY_NORMAL, RAY_FAST, RAY_SHADOW };

class Ray
{
public:
  Ray();
  Ray(Ric::Vector o, Ric::Vector d, double far_length, double near_length, Ric::Color c);

  const TriangleFace *cast(const Scene &s);
  const TriangleFace *cast(const SceneObject &o);
  void calc(const TriangleFace *f, const Scene &scene, const unsigned int &level, const bool &adv_light);

  // Getters and Setters
  bool hit() const;
  double t() const;
  Ric::Vector o() const;
  Ric::Color color() const;
  Ric::Vector n() const;
  Ric::Vector l() const;
  Ric::Vector r() const;
  Ric::Vector v() const;
  Ric::Vector p() const;

  void AddColor(const Ric::Color &color);

private:
  bool hit_; //< If the ray hit any object.
  double t_; //< The parameter that will tell how far the ray hit.
  double near_length_; //< Min value for t_ parameter.
  double far_length_; //< Max value for t_ parameter.
  Ric::Vector o_; //< The ray origin.
  Ric::Vector d_; //< The ray direction.
  Ric::Color default_color_; //< The color the ray will return if it don't hit any object.
  Ric::Color color_; //< The ray color.
  Ric::Vector n_; //< Normal.
  Ric::Vector l_;//< Light Direction.
  Ric::Vector r_;//< Light Reflection.
  Ric::Vector v_;//< Viewer Direction.
  Ric::Vector p_; //< Hit Point.
};



#endif // RAY_H
