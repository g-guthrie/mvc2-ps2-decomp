typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* func_00163F40: jump-table dispatch (real size 0x2C; json listed 0x70 including func_00163F70) */
typedef struct { u8 *p; u16 o; } W1812A_B;
extern void (*jtbl_00445A20[])(void *, void *);
typedef struct { s16 v, p; } W1B5350_T;
extern W1B5350_T D_004B5770[];
extern W1B5350_T D_004B5772[];
typedef struct { u8 pad0[0x20]; u8 idx; u8 pad21[0x13]; f32 f34; f32 f38; u8 pad3c[0x104]; s16 h140; } W1B5350_O;
void func_001B5350(W1B5350_O *s, W1B5350_O *d) {
    f32 x;
    s16 h;
    d->f34 = s->f34;
    d->f38 = s->f38;
    d->f38 += (f32)D_004B5772[d->idx].v;
    x = (f32)D_004B5770[d->idx].v;
    h = s->h140;
    d->h140 = h;
    if (h == 0) x = -x;
    d->f34 += x;
}
