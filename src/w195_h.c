typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct R { u8 pad[0x38]; s32 didinit; };
typedef struct F {
    u8 *p;
    s32 r;
    s32 w;
    u16 flags;
    s16 file;
    u8 *base;
    s32 size;
    s32 lbfsize;
    u8 pad[0x54 - 0x1C];
    struct R *data;
} F;

extern struct R *D_0043B6F8;
extern void func_0011B7A8(struct R *);
extern s32 func_00122560(F *);
extern s32 func_0011B480(F *);

s32 func_001223F0(s32 c, F *fp) {
    s32 n;
    u32 fl;
    do {
    if (fp->data == 0) {
        fp->data = D_0043B6F8;
    }
    if (fp->data->didinit == 0) {
        func_0011B7A8(fp->data);
    }
    } while (0);
    fp->w = fp->lbfsize;
    if ((fp->flags & 8) == 0 || fp->base == 0) {
        if (func_00122560(fp)) {
            return -1;
        }
    }
    n = fp->p - fp->base;
    c = c & 0xFF;
    if (n >= fp->size) {
        if (func_0011B480(fp)) {
            return -1;
        }
        n = 0;
    }
    fp->w--;
    *fp->p++ = c;
    if (++n == fp->size || ((fl = fp->flags) & 1) && c == 10) {
        if (func_0011B480(fp)) {
            return -1;
        }
    }
    return c;
}
