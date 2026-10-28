typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
extern s32 func_003FE5B0(void);
extern void func_003FE510(void);
extern void func_0040D118(void);
extern void func_004050A0(void);

s32 func_003FDA00(void)
{
    if (func_003FE5B0() == 1) {
        func_0040D118();
        func_004050A0();
    } else {
        func_003FE510();
        func_0040D118();
        func_004050A0();
    }
    return 0;
}

extern void func_0011D8F8(u8 *, s32, s32);
extern void func_0040BF58(u8 *, u8 *);
extern s32 func_00107E90(u8 *, s32);
extern s32 func_00108298(s32, s32, s32);
extern s32 func_001084D0(s32, u8 *, s32);
extern void func_00108118(s32);

s32 func_0040C2C0(u8 *a, u8 *b)
{
    u8 buf[256];
    s32 fd;
    s32 size;
    s32 n;
    func_0011D8F8(buf, 0, 256);
    func_0040BF58(a, buf);
    fd = func_00107E90(buf, 1);
    if (fd < 0) {
        return 0;
    }
    size = func_00108298(fd, 0, 2);
    if (size < 0) {
        return 0;
    }
    if (func_00108298(fd, 0, 0) < 0) {
        return 0;
    }
    n = 0x1000;
    if (size < 0x1001) {
        n = size;
    }
    if (func_001084D0(fd, b, n) < 0) {
        func_00108118(fd);
        return 0;
    }
    func_00108118(fd);
    return 1;
}

typedef struct { void **obj; s32 arg; } Ent;
extern s32 D_004872EC;
extern Ent D_0062FA08[];
typedef struct { s32 w; u8 f4; u8 pad[11]; } Rec;
extern Rec D_0062FB48[];
extern u8 D_0062FD48[];
extern void func_0011D8F8(u8 *, s32, s32);

void func_00405EB8(void)
{
    s32 i;
    D_004872EC = D_004872EC - 1;
    if (D_004872EC == 0) {
        for (i = 0; i < 40; i++) {
            if (D_0062FA08[i].obj != 0) {
                ((void (*)(s32))((u32 *)D_0062FA08[i].obj)[5])(D_0062FA08[i].arg);
            }
            D_0062FA08[i].obj = 0;
            D_0062FA08[i].arg = 0;
        }
        for (i = 31; i >= 0; i--) {
            D_0062FB48[i].f4 = 0;
        }
        func_0011D8F8(D_0062FD48, 0, 9);
        D_0062FD48[0] = 0;
    }
}

#include "cri_sj_ring_buffer_types.h"
typedef SJ_OBJ Obj;
extern s32 func_004053E8(s8 *, s32, u8 *);
extern void func_004104E0(SJCK *, s32, SJCK *, SJCK *);

void func_00405848(u8 *a)
{
    SJCK buf;
    SJCK buf2;
    Obj *o;
    u8 *s0;
    s32 n;
    o = *(Obj **)(a + 0x1C);
    s0 = a + 0xA0;
    o->vtbl->GetChunk(o, 1, 0x1800, &buf);
    n = func_004053E8(buf.data, buf.len, s0);
    if (n == 0) {
        o->vtbl->UngetChunk(o, 1, &buf);
        return;
    }
    if (n != buf.len) {
        for (;;) {
            __asm__ volatile("nop");
        }
    }
    func_004104E0(&buf, n, &buf, &buf2);
    o->vtbl->PutChunk(o, 0, &buf);
    o->vtbl->UngetChunk(o, 1, &buf2);
    *(s32 *)(a + 8) += n;
    a[1] = 2;
}
