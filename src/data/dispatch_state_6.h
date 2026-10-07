#ifndef MVC2_DISPATCH_STATE_6_H
#define MVC2_DISPATCH_STATE_6_H
/* The state view used by indirect68_family.c; the cursor is byte six. */
typedef unsigned char u8;
typedef struct DispatchState_6 { u8 pad00[6]; u8 index; } DispatchState_6;
typedef void (*DispatchState6Handler)(DispatchState_6 *);
#endif
