#include "animation_spin.h"

#include <QtOpenGL>
#include <QDebug>

AnimationSpin::AnimationSpin(float value, SPIN_DIRECTION direction):
  Animation(),
  spin_value_(value),
  spin_direction_(direction)
{
}

void AnimationSpin::step_spec()
{
  current_spin_ += spin_value_;
}

void AnimationSpin::transform_spec()
{
  switch(spin_direction_){
  case SPIN_X:
    glRotatef(current_spin_,1,0,0);
    break;
  case SPIN_Y:
    glRotatef(current_spin_,0,1,0);
    break;
  case SPIN_Z:
    glRotatef(current_spin_,0,0,1);
    break;
  default:
    break;
  }
}
