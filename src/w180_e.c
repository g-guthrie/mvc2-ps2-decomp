typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct F {
    u8 pad0[0xC];
    s16 flags;
    s16 file;
    u8 pad10[0xC];
    void *cookie;
    s32 (*rd)();
    s32 (*wr)();
    s32 (*sk)();
    s32 (*cl)();
    u8 pad30[0x24];
    s32 *reent;
} F;

extern s32 func_0011B838();
extern F *func_0011B670();
extern int func_0011EAA0(void *, const char *, int, int);
extern s32 func_0011BF48();
extern s32 func_0011F9C8();
extern s32 func_0011FA30();
extern s32 func_0011FAB0();
extern s32 func_0011FB18();

F *func_0011B8F0(void *ptr, const char *name, const char *mode) {
    F *fp;
    s32 f;
    s32 flags;
    s32 oflags;
    flags = func_0011B838(ptr, mode, &oflags);
    if (flags == 0) {
        return 0;
    }
    fp = func_0011B670(ptr);
    if (fp == 0) {
        return 0;
    }
    f = func_0011EAA0(fp->reent, name, oflags, 0x1B6);
    if (f < 0) {
        fp->flags = 0;
        return 0;
    }
    fp->file = f;
    fp->rd = func_0011F9C8;
    fp->wr = func_0011FA30;
    fp->sk = func_0011FAB0;
    fp->cl = func_0011FB18;
    fp->flags = flags;
    fp->cookie = fp;
    if (flags & 0x100) {
        func_0011BF48(fp, 0, 2);
    }
    return fp;
}

extern void func_003F85D0(s32 a, s32 b, s32 c);

void func_003F8670(s32 a, s32 b, s32 c, s32 d) { func_003F85D0(a, a + b * 2, d); }
