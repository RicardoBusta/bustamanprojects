/*
 * RGL3DBMP.cpp
 *
 *  Created on: 17/01/2011
 *      Author: ricardo
 */

#include "RGL3DBMP.h"
#include <SDL/SDL_opengl.h>

RGL3DBMP::RGL3DBMP() {
	voxel = new RGLVoxel[16*16*16];
	x = y = z = 0;
}

RGL3DBMP::~RGL3DBMP() {
	//delete voxel;
}

void RGL3DBMP::optimize(){
	for(int i=0;i<16;i++){
			for(int j=0;j<16;j++){
					for(int k=0;k<16;k++){
						if(i+j+k>10){
							voxel[(i)+16*((j)+16*(k))].a = false;
						}
					}
			}
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			for(int k=0;k<16;k++){
				if(i+1 < 16 and voxel[(i+1)+16*((j)+16*(k))].a){
					voxel[(i)+16*((j)+16*(k))].right = false;
				}
				if(i-1 >= 0 and voxel[(i-1)+16*((j)+16*(k))].a){
					voxel[(i)+16*((j)+16*(k))].left = false;
				}
				if(j+1 < 16 and voxel[(i)+16*((j+1)+16*(k))].a){
					voxel[(i)+16*((j)+16*(k))].top = false;
				}
				if(j-1 >= 0 and voxel[(i)+16*((j-1)+16*(k))].a){
					voxel[(i)+16*((j)+16*(k))].bottom = false;
				}
				if(k+1 < 16 and voxel[(i)+16*((j)+16*(k+1))].a){
					voxel[(i)+16*((j)+16*(k))].near = false;
				}
				if(k-1 >= 0 and voxel[(i)+16*((j)+16*(k-1))].a){
					voxel[(i)+16*((j)+16*(k))].far = false;
				}
			}
		}
	}
}

void RGL3DBMP::draw(){
	glPushMatrix();
	glTranslatef(x,y,z);
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			for(int k=0;k<16;k++){
					voxel[i+16*(j+16*k)].draw(i,j,k);
			}
		}
	}
	glPopMatrix();
}
