#ifndef MVC2_STATE_CALLBACKS_H
#define MVC2_STATE_CALLBACKS_H
/* Callback contracts recovered from the exact one- and two-argument dispatchers. */
typedef unsigned char u8;
typedef void (*Mvc2StateCallback)(u8 *);
typedef void (*Mvc2OwnerStateCallback)(u8 *, void *);
#endif
