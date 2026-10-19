typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/w189_a.c sn */
extern s32 func_0040A2F8();
extern s32 func_0040A310();
extern s32 func_0040A338();
extern s32 func_0040A350();
/* Uncredited legacy body: helper object arguments are still omitted.
 * The typed, explicit-argument C candidate has not matched retail yet. */
s32 func_0040A378(s32 a, s32 b) {
    s32 r = 0;
    if (a != 0) {
        switch (b) {
        case 0xC8:
            r = func_0040A2F8();
            break;
        case 0xC9:
            r = func_0040A310();
            break;
        case 0xCA:
        case 0xCC:
            r = func_0040A338();
            break;
        case 0xCB:
        case 0xCD:
            r = func_0040A350();
            break;
        case 0x12B:
            r = 1;
            break;
        }
        return r;
    }
    return 0;
}


typedef struct V404 { s32 *vt; } V404;
typedef struct P404 {
    s8 b0; u8 pad1[2]; s8 b3; s32 w4; u8 pad8[4]; s32 arr1[32]; V404 *w8C; V404 *arr2[32];
} P404;
extern void func_00404BD0();
extern void func_00401428();
extern void func_00405100();
extern void func_00405278();
extern void func_0011D8F8();
extern void func_00405118();
void func_00404968(P404 *p) {
    s32 i;
    V404 *o;
    if (p == 0) return;
    func_00404BD0(p);
    for (i = 0; i < p->b3; i++) {
        if (p->arr1[i] != 0) {
            func_00401428(p->arr1[i]);
            p->arr1[i] = 0;
        }
    }
    func_00405100();
    for (i = 0; i < p->b3; i++) {
        o = p->arr2[i];
        if (o != 0) {
            ((void (*)(V404 *))((s32 *)o->vt)[3])(o);
            p->arr2[i] = 0;
        }
    }
    if (p->w8C != 0) {
        ((void (*)(V404 *))((s32 *)p->w8C->vt)[3])(p->w8C);
        p->w8C = 0;
    }
    if (p->w4 != 0) {
        func_00405278(p->w4);
        p->w4 = 0;
    }
    func_0011D8F8(p, 0, 0x1C0);
    p->b0 = 0;
    func_00405118();
}
