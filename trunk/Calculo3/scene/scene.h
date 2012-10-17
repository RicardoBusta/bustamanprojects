#ifndef SCENE_H
#define SCENE_H

class Camera;
class Matrix4f;
class Material;
class Curve;

class Scene
{
public:
    Scene();
    ~Scene();

    //Camera *camera;

    float rotx, roty;

    Matrix4f *transformation;
    Material *material;

    Curve *curve;

    void draw();
};

#endif // SCENE_H
