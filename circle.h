#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

typedef struct circle
{
	shape_vtable vt;
	float radius;
} circle;


// worth it?  or just let the user do it manually?
SHAPE_PREFIX_PROTOTYPES(circle_);


#endif
