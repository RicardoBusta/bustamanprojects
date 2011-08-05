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
 * File: RGLShapes.h
 * Created on: Aug 5, 2011
 */

#ifndef RGLSHAPES_H_
#define RGLSHAPES_H_

#include "RColor.h"

#include <RTriMesh.h>

void rglDrawBox(float width, float height, float depht, RColor color);
void rglDrawCapsule(float radius, float height, unsigned int div, RColor color); //TODO
void rglDrawCone(float radius, float height, unsigned int div, RColor color);
void rglDrawConvexHull(); //TODO
void rglDrawCylinder(float radius, float height, unsigned int div, RColor color);
void rglDrawSphere(float radius, unsigned int div, RColor color);
void rglDrawTriMesh(RTriMesh mesh); //TODO

#endif /* RGLSHAPES_H_ */
