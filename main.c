#include <stdio.h>
#include <stdlib.h>

typedef struct shape_vtable {
	float (*area)(void*);
	float (*perimeter)(void*);
	void (*print)(void*, FILE* f);
} shape_vtable;

#define SHAPE_VTABLE__INIT(method1, method2, method3) { method1, method2, method3 }
#define SHAPE_VTABLE__INIT_PREFIX(prefix) SHAPE_VTABLE__INIT(prefix##area, prefix##perimiter, prefix##print)

typedef struct square
{
	shape_vtable vt;
	float dim;
} square;

typedef struct circle
{
	shape_vtable vt;
	float radius;
} circle;


float square_area(void* shape)
{
	square* s = shape;
	return s->dim * s->dim;
}

float square_perimiter(void* shape)
{
	square* s = shape;
	return 4 * s->dim;
}

void square_print(void* shape, FILE* f)
{
	square* s = shape;
	fprintf(f, "side: %.3f\narea: %.3f\nperimiter: %.3f\n", s->dim, s->vt.area(shape), s->vt.perimeter(shape));
}

#define SHAPE_PI 3.1415927

float circle_area(void* shape)
{
	circle* s = shape;
	return SHAPE_PI * s->radius * s->radius;
}

float circle_perimiter(void* shape)
{
	circle* s = shape;
	return SHAPE_PI * 2 * s->radius;
}

void circle_print(void* shape, FILE* f)
{
	circle* s = shape;
	fprintf(f, "radius: %.3f\narea: %.3f\nperimiter: %.3f\n", s->radius, s->vt.area(shape), s->vt.perimeter(shape));
}

#define CALL(ptr, parent, method, ...) ((parent##_vtable*)(ptr))->method(ptr, __VA_ARGS__)


#define NUM_SHAPES 20

int main()
{
	shape_vtable square_vtable = SHAPE_VTABLE__INIT_PREFIX(square_);
	shape_vtable circle_vtable = SHAPE_VTABLE__INIT_PREFIX(circle_);

	//square squares[NUM_SHAPES];
	
	void** shapes = malloc(NUM_SHAPES*sizeof(void*));

	for (int i=0; i<NUM_SHAPES/2; i++) {
		square* s = malloc(sizeof(square));
		s->vt = square_vtable;
		s->dim = i+1;
		shapes[i] = s;
	}

	for (int i=0; i<NUM_SHAPES/2; i++) {
		circle* s = malloc(sizeof(circle));
		s->vt = circle_vtable;
		s->radius = i+1;
		shapes[i+10] = s;
	}


	for (int i=0; i<NUM_SHAPES; i++) {
		//printf("%f\n", squares[i].vt.area(&squares[i]));
		//printf("%f\n", square_vtable.area(shapes[i]));

		//((shape_vtable*)(shapes[i]))->print(shapes[i], stdout);
		printf("shape %d:\n", i);
		CALL(shapes[i], shape, print, stdout);
		puts("");;
	}









	return 0;
}
