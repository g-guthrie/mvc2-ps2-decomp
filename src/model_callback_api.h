#ifndef MVC2_MODEL_CALLBACK_API_H
#define MVC2_MODEL_CALLBACK_API_H

/* The model walker supplies two node-data regions and a 32-bit context. */
/* Preserve the walker's existing element and node layouts. */
typedef struct { int id; unsigned char pad[0x8C]; unsigned char data[0x24]; } EL_d;
typedef struct ND_d {
    unsigned char pad0[0xC];
    struct ND_d *next;
    struct ND_d *child;
    unsigned char pad1[0x180 - 0x14];
    int idx;
} ND_d;
typedef void (*Mvc2ModelCallback)(unsigned char *, unsigned char *, int);
void func_00170E60(EL_d *, ND_d *, EL_d *, ND_d *, Mvc2ModelCallback, int);

#endif
