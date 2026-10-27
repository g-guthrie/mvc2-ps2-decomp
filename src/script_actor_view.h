#ifndef MVC2_SCRIPT_ACTOR_VIEW_H
#define MVC2_SCRIPT_ACTOR_VIEW_H

typedef struct SA37_R {
    unsigned char *buf;
    unsigned short pos;
    unsigned char pad6, b7;
} SA37_R;

typedef struct SA37_J0 {
    unsigned char pad0[0x451];
    unsigned char a, b, c, b454;
    unsigned char pad455[0x460 - 0x455];
    signed int scratch;
    unsigned char pad464[0x492 - 0x464];
    unsigned char chosen, pad493, active;
    unsigned char pad495[3];
    float limit;
    unsigned char pad49c[0x4c8 - 0x49c];
    union { signed int integer; float real; } w4c8;
} SA37_J0;

typedef char SA37_J0_size_check[(sizeof(SA37_J0) == 0x4cc) ? 1 : -1];

#endif
