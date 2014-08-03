#include "animation.h"

#include "opengl/object.h"

Animation::Animation()
{
}

void Animation::step()
{
  step_spec();
}

void Animation::transform()
{
  transform_spec();
}
