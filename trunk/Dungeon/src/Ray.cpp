/*
 * Ray.cpp
 *
 *  Created on: 06/01/2011
 *      Author: ricardo
 */

#include "Ray.h"
#include <cmath>

Ray::Ray(Point3 rp, Point3 rv) {
	hit = false;
	p.x = rp.x;
	p.y = rp.y;
	p.z = rp.z;
	v.x = rv.x;
	v.y = rv.y;
	v.z = rv.z;
}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

bool Ray::intersect(Shape *s){
	s->hitTest(p,v,&distance,&hit);
}

Shape::Shape(){
}

Sphere::Sphere(Point3 p, float nr=1){
	c.x = p.x;
	c.y = p.y;
	c.z = p.z;
	r = nr;
}

bool Sphere::hitTest(Point3 p, Point3 v, float *l, bool *hit){
	Point3 d(v.x-p.x,v.y-p.y,v.z-p.z);
	float A = d.x*d.x + d.y*d.y + d.z*d.z;
	float B = 2*(d.x*(p.x-c.x)+d.y*(p.y-c.y)+d.z*(p.z-c.z));
	float C = c.x*c.x + c.y*c.y + c.z*c.z + p.x*p.x + p.y*p.y + p.z*p.z - 2*(p.x*c.x + p.y*c.y + p.z*c.z) - (r*r);
	float delta = (B*B) - (4*A*C);
	if(delta < 0)
		return false;
	*l = (B+sqrt(delta)) / (-2*A);
	*hit = true;
	return true;
}

/*bool Cube::hitTest(){
 *  float t1, t2;
28	  int coordN; // = 0 si X, = 1 si Y, = 2 si Z
29	  int coordF; // = 0 si X, = 1 si Y, = 2 si Z
30	  float tNear = -100000;
31	  float tFar = 100000;
32
33	  //Calcul pour les plans X
34	  if(ray.getDirection()[0] == 0){
35	    if(ray.getOrigin()[0] < Xmin ||
36	       ray.getOrigin()[0] > Xmax){
37	         return false;
38	       }
39	  } else {
40	    t1 = (Xmin - ray.getOrigin()[0]) / ray.getDirection()[0];
41	    t2 = (Xmax - ray.getOrigin()[0]) / ray.getDirection()[0];
42
43	    if(t1 > t2){
44	      float temp = t1;
45	      t1 = t2;
46	      t2 = temp;
47	    }
48	    if(t1 > tNear){
49	      coordN = 0;
50	      tNear = t1;
51	    }
52	    if(t2 < tFar){
53	      coordF = 0;
54	      tFar = t2;
55	    }
56	    if(tNear > tFar || tFar < epsilon){
57	      return false;
58	    }
59	  }
60
61	  //Pour Y
62	  if(ray.getDirection()[1] == 0){
63	    if(ray.getOrigin()[1] < Ymin ||
64	       ray.getOrigin()[1] > Ymax){
65	         return false;
66	       }
67	  } else {
68	    t1 = (Ymin - ray.getOrigin()[1]) / ray.getDirection()[1];
69	    t2 = (Ymax - ray.getOrigin()[1]) / ray.getDirection()[1];
70
71	    if(t1 > t2){
72	      float temp = t1;
73	      t1 = t2;
74	      t2 = temp;
75	    }
76	    if(t1 > tNear){
77	      coordN = 1;
78	      tNear = t1;
79	    }
80	    if(t2 < tFar){
81	      coordF = 1;
82	      tFar = t2;
83	    }
84	    if(tNear > tFar || tFar < epsilon){
85	      return false;
86	    }
87	  }
88
89	  //Pour Z
90	  if(ray.getDirection()[2] == 0){
91	    if(ray.getOrigin()[2] < Zmin ||
92	       ray.getOrigin()[2] > Zmax){
93	         return false;
94	       }
95	  } else {
96	    t1 = (Zmin - ray.getOrigin()[2]) / ray.getDirection()[2];
97	    t2 = (Zmax - ray.getOrigin()[2]) / ray.getDirection()[2];
98
99	    if(t1 > t2){
100	      float temp = t1;
101	      t1 = t2;
102	      t2 = temp;
103	    }
104	    if(t1 > tNear){
105	      coordN = 2;
106	      tNear = t1;
107	    }
108	    if(t2 < tFar){
109	      coordF = 2;
110	      tFar = t2;
111	    }
112	    if(tNear > tFar || tFar < epsilon){
113	      return false;
114	    }
115	  }
116
117	  //Il y a intersection
118	  if (tNear > epsilon){
119	    dist = tNear;
120	    if(coordN == 0){
121	      _normal = Vec3<double>(-1., 0, 0);
122	    } else if(coordN == 1){
123	      _normal = Vec3<double>(0, 1., 0);
124	    } else if(coordN == 2){
125	      _normal = Vec3<double>(0, 0, 1.);
126	    }
127	  } else {
128	    dist = tFar;
129	    if(coordF == 0){
130	        _normal = Vec3<double>(1., 0, 0);
131	    } else if(coordF == 1){
132	      _normal = Vec3<double>(0, -1., 0);
133	    } else if(coordF == 2){
134	      _normal = Vec3<double>(0, 0, -1.);
135	    }
136	  }
137	  return true;
 */
