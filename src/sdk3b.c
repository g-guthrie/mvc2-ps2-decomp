typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned char u8;
#include "HtciFileRequest.h"

typedef struct { s8 a; s8 kind; s8 pad[2]; s32 val; } Obj;
extern s32 func_00406B50(void);
extern void func_003FB128(void *p);
extern char D_004BC3D0[], D_004BC128[], D_004BB4A8[];
extern s32 func_004000B0(s32 v);
extern s32 func_001089F0(s32 a, s32 b, s32 *c);
extern void func_003F79A8(s8 *a, s16 *x, s16 *y, s16 *z);

s32 func_00400C70(s32 unused, s32 *out) { *out = func_00406B50(); return 1; }
s32 func_00400C28(s32 unused, s32 *out) { *out = (func_00406B50() + 2047) / 2048; return 1; }
s32 func_00402460(s8 *p) {
    if (!p) { func_003FB128(D_004BC3D0); return -1; }
    return p[1] == 5;
}
s32 func_00401F88(Obj *p) {
    if (!p) { func_003FB128(D_004BC128); return -1; }
    if (p->kind >= 2) return func_004000B0(p->val);
    return 0;
}
s32 func_003FD4B0(s32 *p, s32 *out) {
    if (!p) { func_003FB128(D_004BB4A8); *out = 0; return -3; }
    *out = p[6];
    return p[7];
}
s32 func_0040AFD8(HtciFileRequest *p) {
    if (func_001089F0(p->file_handle_18, 1, &p->result_14) < 0) return 0;
    return p->result_14 != 1;
}
void func_003F81F0(void *state, void *input) {
    u8 *s = state;
    s16 t[3];
    func_003F79A8((s8 *)input, &t[0], &t[1], &t[2]);
    *(u16 *)(s + 0x9C) = t[0];
    *(u16 *)(s + 0x9E) = t[1];
    *(u16 *)(s + 0xA0) = t[2];
}
