#ifndef MVC2_SONY_DECI2_CALL_H
#define MVC2_SONY_DECI2_CALL_H

/* Typed boundary for the original SDK syscall architecture primitive.
 * A0: operation; A1: opaque parameter record; V0: signed result.
 * V1 is the architecture syscall selector, loaded by the SDK primitive.
 */
int func_00104210(int operation, void *parameters);

#endif
