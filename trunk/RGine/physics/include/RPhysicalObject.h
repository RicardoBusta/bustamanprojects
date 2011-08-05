/**
 * @file
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGine.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 * 
 * File: RPhysicalObject.h
 * Created on: Aug 5, 2011
 */

/* TODO
#ifndef RPHYSICALOBJECT_H_
#define RPHYSICALOBJECT_H_

#include <cmath>
#include <irrlicht.h>
#include <btBulletDynamicsCommon.h>
#include "vlJoint.h"

#define MeshBuffer IMeshBuffer
#define Vector3D vector3df

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

enum RShape {
    RSHAPE_SPHERE, RSHAPE_BOX, RSHAPE_CAPSULE, RSHAPE_CYLINDER, RSHAPE_CONE, RSHAPE_CONVEXHULL, RSHAPE_TRIMESH
};

/**
 * This class will be used by the physics engine to represent an object with physical behavior.
 *
class RPhysicalObject {
    friend class vlEnvironment;
    friend class PhysicsSim;
    friend class Joint;

private:
    btRigidBody* rigidBody;
    btCollisionShape* shape;
    btDefaultMotionState* motionState;
    double mass;

    //ISceneNode* irrnode;

public:
    void initializeTerrain(btCollisionShape* shape, btDefaultMotionState* motionState);
    void initialize(btCollisionShape* shape);

    void Update();

public:

    btRigidBody* getRigidBody();
    //ISceneNode* getSceneNode();
    btVector3 getJointReferenceAxis();

    //public:

    RPhysicalObject(ISceneNode* irrnode, double mass);
    ~RPhysicalObject();

    MeshBuffer* getMeshBuffer();
    Vector3D getScale();
    Vector3D getPosition();
    Vector3D getRotation();
    matrix4 getAbsoluteTransformation();

    float getAngularVel();
    float getLinearVel();

    void setRestitution(float c);
    void setFriction(float c);

    void setLinearDamping(float damp);
    void setAngularDamping(float damp);

    bool isColliding(RPhysicalObject* obj);
};

#endif /* RPHYSICALOBJECT_H_ */
