#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>

typedef struct shape_vtable {
	float (*area)(void*);
	float (*perimeter)(void*);
	void (*print)(void*, FILE* f);
} shape_vtable;

#define SHAPE_VTABLE__INIT(method1, method2, method3) { method1, method2, method3 }
#define SHAPE_VTABLE__INIT_PREFIX(prefix) SHAPE_VTABLE__INIT(prefix##area, prefix##perimeter, prefix##print)

#define SHAPE_PREFIX_PROTOTYPES(prefix) \
float prefix##area(void* shape); \
float prefix##perimeter(void* shape); \
void prefix##print(void* shape, FILE* f)


// This really isn't shape specific, should be in something like inheritance.h

#define CALL(ptr, parent, method, ...) ((parent##_vtable*)(ptr))->method(ptr, __VA_ARGS__)



#endif
