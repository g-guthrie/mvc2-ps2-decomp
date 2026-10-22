typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct VT {
    u8 pad0[0x14];
    void (*f14)(void *);
    void (*f18)(void *, s32, s32, s32 *);
    u8 pad1c[4];
    void (*f20)(void *, s32, s32 *);
} VT;
typedef struct Obj { VT *vt; } Obj;
typedef struct Q {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    u8 pad1[0x14 - 0xC];
    Obj *f14;
    u8 pad2[0x2 - 0x18 + 0x18];
} Q;

extern char D_004BC790[];

void func_00403020(u8 *p)
{
    extern s32 func_00400050(s32);
    extern s32 func_00400068(s32);
    extern s32 func_00400080(s32);
    extern void func_003FFF30(s32, s32);
    extern void func_003FFF40(s32, s32);
    extern void func_003FFF50(s32, s32);
    extern void func_003FFED0(s32, s32);
    extern void func_003FB128(char *);
    s32 buf[4];
    s32 s1 = *(s32 *)(p + 4);
    Obj *s0 = *(Obj **)(p + 0x14);
    s32 s3, s4, s5;
    s3 = func_00400050(s1);
    s5 = func_00400068(s1);
    s4 = func_00400080(s1);
    if (*(s32 *)(p + 8) == 0 && *(s8 *)(p + 0x6C) == 0) {
        func_003FFF30(*(s32 *)(p + 4), -1);
        return;
    }
    ((void (*)(Obj *, s32, s32, s32 *))((u32 *)s0->vt)[6])(s0, 1, *(s32 *)(p + 0x50), buf);
    if (buf[1] < *(s32 *)(p + 0x50)) func_003FB128(D_004BC790);
    ((void (*)(Obj *, s32, s32 *))((u32 *)s0->vt)[8])(s0, 0, buf);
    func_003FFF40(s1, 0);
    *(s32 *)(p + 0x90) = s4 - s3;
    func_003FFF30(s1, s4 - s3);
    func_003FFF50(s1, s5);
    func_003FFED0(s1, s3);
    if (*(s8 *)(p + 2) == 2) {
        ((void (*)(Obj *))((u32 *)s0->vt)[5])(s0);
        ((void (*)(Obj *, s32, s32, s32 *))((u32 *)s0->vt)[6])(s0, 1, s5, buf);
        ((void (*)(Obj *, s32, s32 *))((u32 *)s0->vt)[8])(s0, 0, buf);
    }
    *(s32 *)(p + 0x4C) += 1;
}
