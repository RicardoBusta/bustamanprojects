/*
 * RColor.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: ricardo
 */

#include "RColor.h"

RColor::RColor() {
	// TODO Auto-generated constructor stub

}

RColor::~RColor() {
	// TODO Auto-generated destructor stub
}

RColor::RColor(int r, int g, int b){
	r_ = r;
	g_ = g;
	b_ = b;
}

RColor::RColor(float r, float g, float b){
	r_ = (int)(r*255.0);
	g_ = (int)(g*255.0);
	b_ = (int)(b*255.0);
}

int RColor::r(){
	return r_;
}

int RColor::g(){
	return g_;
}

int RColor::b(){
	return b_;
}

void RColor::setR(int r){
	r_ = r;
}

void RColor::setG(int g){
	g_ = g;
}

void RColor::setB(int b){
	b_ = b;
}

void RColor::setR(float r)
{
}

void RColor::setG(float g)
{
}

void RColor::setB(float b)
{
}

float RColor::rF()
{
	return r_/255.0;
}


float RColor::gF()
{
	return g_/255.0;
}

float RColor::bF()
{
	return b_/255.0;
}

