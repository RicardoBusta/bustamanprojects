/*
 * RGLVoxel.cpp
 *
 *  Created on: 17/01/2011
 *      Author: ricardo
 */

#include "RGLVoxel.h"

#include <SDL/SDL_opengl.h>

RGLVoxel::RGLVoxel() {
	r = g = b = 1;
	a = true;
	visible = true;
	top = bottom = left = right = near = far = true;
}

RGLVoxel::~RGLVoxel() {
	// TODO Auto-generated destructor stub
}

void RGLVoxel::draw(int x,int y, int z){
	//glColor3f(r,g,b);
	glEnable(GL_CULL_FACE);
	if(a and visible){
		glColor3f(x/16.0,y/16.0,z/16.0);
		//glColor3f(r,g,b);
		glPushMatrix();
		glScalef(20,20,20);
		glBegin(GL_QUADS);
			//top face
			if(top){
				glNormal3f(0,1,0);
				glVertex3f(x-0.5,y+0.5,z-0.5);
				glVertex3f(x-0.5,y+0.5,z+0.5);
				glVertex3f(x+0.5,y+0.5,z+0.5);
				glVertex3f(x+0.5,y+0.5,z-0.5);
			}

			//bottom face
			if(bottom){
				glNormal3f(0,-1,0);
				glVertex3f(x-0.5,y-0.5,z-0.5);
				glVertex3f(x+0.5,y-0.5,z-0.5);
				glVertex3f(x+0.5,y-0.5,z+0.5);
				glVertex3f(x-0.5,y-0.5,z+0.5);
			}

			//near face
			if(near){
				glNormal3f(0,0,1);
				glVertex3f(x-0.5,y-0.5,z+0.5);
				glVertex3f(x+0.5,y-0.5,z+0.5);
				glVertex3f(x+0.5,y+0.5,z+0.5);
				glVertex3f(x-0.5,y+0.5,z+0.5);
			}

			//far face
			if(far){
				glNormal3f(0,0,-1);
				glVertex3f(x-0.5,y-0.5,z-0.5);
				glVertex3f(x-0.5,y+0.5,z-0.5);
				glVertex3f(x+0.5,y+0.5,z-0.5);
				glVertex3f(x+0.5,y-0.5,z-0.5);
			}

			//left face
			if(left){
				glNormal3f(-1,0,0);
				glVertex3f(x-0.5,y-0.5,z-0.5);
				glVertex3f(x-0.5,y-0.5,z+0.5);
				glVertex3f(x-0.5,y+0.5,z+0.5);
				glVertex3f(x-0.5,y+0.5,z-0.5);
			}

			//right face
			if(right){
				glNormal3f(1,0,0);
				glVertex3f(x+0.5,y-0.5,z-0.5);
				glVertex3f(x+0.5,y+0.5,z-0.5);
				glVertex3f(x+0.5,y+0.5,z+0.5);
				glVertex3f(x+0.5,y-0.5,z+0.5);
			}
		glEnd();
		glPopMatrix();
	}
}
