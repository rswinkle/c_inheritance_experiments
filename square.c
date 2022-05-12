#include "square.h"

float square_area(void* shape)
{
	square* s = shape;
	return s->dim * s->dim;
}

float square_perimeter(void* shape)
{
	square* s = shape;
	return 4 * s->dim;
}

void square_print(void* shape, FILE* f)
{
	square* s = shape;
	fprintf(f, "side: %.3f\narea: %.3f\nperimeter: %.3f\n", s->dim, s->vt.area(shape), s->vt.perimeter(shape));
}
