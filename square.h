#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

typedef struct square
{
	shape_vtable vt;
	float dim;
} square;

// worth it?  or just let the user do it manually?
SHAPE_PREFIX_PROTOTYPES(square_);


#endif
