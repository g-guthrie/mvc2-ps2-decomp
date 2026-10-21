#ifndef MVC2_ACTOR_INHERITED_STATE_H
#define MVC2_ACTOR_INHERITED_STATE_H
/* Native copies preserve [0xec,0x1b0). Only FC/100 are named here;
 * the remaining existing state bytes are deliberately opaque. */
typedef struct {
    unsigned char prefix[16];
    float field_FC, field_100;
    unsigned char remainder[172];
} ActorState;
typedef char ActorStateSizeCheck[sizeof(ActorState) == 0xC4 ? 1 : -1];
#endif
