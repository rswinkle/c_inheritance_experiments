#ifndef CINHERITANCE_H
#define CINHERITANCE_H


#define CALL_METHOD(ptr, parent, method, ...) ((parent##_vtable*)(ptr))->method(ptr, __VA_ARGS__)


#endif
