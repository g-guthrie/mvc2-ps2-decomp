#ifndef MVC2_SIDE_INHIBIT_CALLBACKS_H
#define MVC2_SIDE_INHIBIT_CALLBACKS_H
/* Dispatchers pass both the child and its byte-addressed owner. */
typedef void (*Mvc2SideInhibitCallback)(unsigned char *, unsigned char *);
#endif
