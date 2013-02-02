#include "point3f.h"

Point3f::Point3f()
{
}

float Point3f::x()
{
    return data_[0];
}

void Point3f::setX(float x)
{
    data_[0] = x;
}

float Point3f::y()
{
    return data_[1];
}

void Point3f::setY(float y)
{
    data_[1] = y;
}

float Point3f::z()
{
    return data_[2];
}

void Point3f::setZ(float z)
{
    data_[2] = z;
}
