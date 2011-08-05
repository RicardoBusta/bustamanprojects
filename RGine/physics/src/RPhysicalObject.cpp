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
 * File: RPhysicalObject.cpp
 * Created on: Aug 5, 2011
 */

/* TODO
#include "RPhysicalObject.h"

RPhysicalObject::RPhysicalObject(ISceneNode* irrnode, double mass) {
    this->mass = mass;
    this->irrnode = irrnode;
}

void RPhysicalObject::initializeTerrain(btCollisionShape* shape, btDefaultMotionState* motionState) {
    this->shape = shape;
    this->motionState = motionState;

    btVector3 inertia = btVector3(0,0,0);
    this->shape->calculateLocalInertia(0.0, inertia);
    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(0.0, motionState, this->shape, inertia);
    this->rigidBody = new btRigidBody(rigidBodyCI);
}

void RPhysicalObject::initialize(btCollisionShape* shape) {
    vector3df pos, rotation;
    pos = irrnode->getPosition();
    rotation = irrnode->getRotation();
    btQuaternion rot;
    rot.setEuler(rotation.Y*PI/180.0, rotation.X*PI/180.0, rotation.Z*PI/180.0);

    this->shape = shape;

    btTransform trans;
    trans.setIdentity();

    trans.setRotation(rot);
    trans.setOrigin(btVector3(pos.X, pos.Y, pos.Z));

    this->motionState = new btDefaultMotionState(trans);
    btScalar m = this->mass;
    btVector3 inertia(0,0,0);
    this->shape->calculateLocalInertia(m, inertia);
    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(m, this->motionState, this->shape, inertia);
    this->rigidBody = new btRigidBody(rigidBodyCI);


    this->rigidBody->setCenterOfMassTransform(trans);

}

RPhysicalObject::~RPhysicalObject() {
    irrnode->remove();
    delete rigidBody->getMotionState();
    delete rigidBody;
    delete shape;
}

void RPhysicalObject::Update() {
    btVector3 pos = rigidBody->getCenterOfMassPosition();
    btQuaternion rot = rigidBody->getOrientation();
    btVector3 eulerRot;

    btScalar W = rot.getW();
    btScalar X = rot.getX();
    btScalar Y = rot.getY();
    btScalar Z = rot.getZ();
    float WSquared = W * W;
    float XSquared = X * X;
    float YSquared = Y * Y;
    float ZSquared = Z * Z;

    eulerRot.setX(atan2f(2.0f * (Y * Z + X * W), -XSquared - YSquared + ZSquared + WSquared));
    eulerRot.setY(asinf(-2.0f * (X * Z - Y * W)));
    eulerRot.setZ(atan2f(2.0f * (X * Y + Z * W), XSquared - YSquared - ZSquared + WSquared));
    //eulerRot *= RADTODEG;
    eulerRot.setX( eulerRot.x()*180.0/PI );
    eulerRot.setY( eulerRot.y()*180.0/PI );
    eulerRot.setZ( eulerRot.z()*180.0/PI );

    if(irrnode != NULL) {
        irrnode->setPosition(vector3df(pos.x(), pos.y(), pos.z()));
        irrnode->setRotation(vector3df(eulerRot.x(), eulerRot.y(), eulerRot.z()));
    }
}

btRigidBody* RPhysicalObject::getRigidBody() {
    return rigidBody;
}

ISceneNode* RPhysicalObject::getSceneNode() {
    return irrnode;
}

MeshBuffer* RPhysicalObject::getMeshBuffer() {
    return ((IAnimatedMeshSceneNode*)irrnode)->getMesh()->getMesh(0)->getMeshBuffer(0);
}

Vector3D RPhysicalObject::getScale() {
    return irrnode->getScale();
}

Vector3D RPhysicalObject::getPosition() {
    return irrnode->getPosition();
}

Vector3D RPhysicalObject::getRotation() {
    return irrnode->getRotation();
}

matrix4 RPhysicalObject::getAbsoluteTransformation() {
    return irrnode->getAbsoluteTransformation();
}

float RPhysicalObject::getAngularVel() {
    btVector3 vel =	rigidBody->getAngularVelocity();

    return vel.length();
}

float RPhysicalObject::getLinearVel() {
    btVector3 vel =	rigidBody->getLinearVelocity();

    return vel.length();
}

void RPhysicalObject::setRestitution(float c) {
    rigidBody->setRestitution(c);
}

void RPhysicalObject::setFriction(float c) {
    rigidBody->setFriction(c);
}

void RPhysicalObject::setAngularDamping(float damp) {
    btScalar lin = rigidBody->getLinearDamping();
    rigidBody->setDamping(lin, damp);
}

void RPhysicalObject::setLinearDamping(float damp) {
    btScalar ang = rigidBody->getAngularDamping();
    rigidBody->setDamping(damp, ang);
}

bool RPhysicalObject::isColliding(RPhysicalObject* obj) {
    return rigidBody->checkCollideWith(obj->getRigidBody());
}
*/
