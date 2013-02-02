#ifndef POINT3F_H
#define POINT3F_H

class Point3f
{
public:
    Point3f();

    float x();
    void setX(float x);
    float y();
    void setY(float y);
    float z();
    void setZ(float z);

private:
    float data_[3];
};

#endif // POINT3F_H
