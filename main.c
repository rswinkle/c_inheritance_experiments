#include <stdio.h>
#include <stdlib.h>

#include "square.h"
#include "circle.h"



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
