#ifndef CINHERITANCE_H
#define CINHERITANCE_H

// The vtable (with type YOURCLASSNAME_vtable) has to be the first
// member of your class YOURCLASSNAME

#define CALL_METHOD(ptr, parent, method, ...) ((parent##_vtable*)(ptr))->method(ptr, __VA_ARGS__)


#endif
