typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    u8 pad[0x3C];
    void *data;
} SF;

extern s32 func_001209B8(SF *, void *, void *);
s32 func_00122398(void *reent, u8 *str, void *fmt, void *ap) {
    SF f;
    s32 ret;
    f.data = reent;
    f.flags = 0x208;
    f.base = f.p = str;
    f.size = f.w = 0x7FFFFFFF;
    ret = func_001209B8(&f, fmt, ap);
    *f.p = 0;
    return ret;
}
