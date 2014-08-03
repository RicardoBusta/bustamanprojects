#ifndef ANIMATIONSPIN_H
#define ANIMATIONSPIN_H

#include "opengl/animation.h"

class AnimationSpin : public Animation
{
public:
  enum SPIN_DIRECTION{SPIN_X, SPIN_Y,SPIN_Z};

  AnimationSpin(float value, SPIN_DIRECTION direction);

private:
  float spin_value_;
  float current_spin_;
  SPIN_DIRECTION spin_direction_;

  void step_spec();
  void transform_spec();
};

#endif // ANIMATIONSPIN_H
