#include "circle.h"

#define SHAPE_PI 3.1415927

float circle_area(void* shape)
{
	circle* s = shape;
	return SHAPE_PI * s->radius * s->radius;
}

float circle_perimeter(void* shape)
{
	circle* s = shape;
	return SHAPE_PI * 2 * s->radius;
}

void circle_print(void* shape, FILE* f)
{
	circle* s = shape;
	fprintf(f, "radius: %.3f\narea: %.3f\nperimeter: %.3f\n", s->radius, s->vt.area(shape), s->vt.perimeter(shape));
}
