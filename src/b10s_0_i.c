typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 p0[0xC]; s32 f0c; s32 f10; u8 p1[0x24]; s32 (*f38)(s32, s32); s32 f3c; } O;
s32 func_0040F750(O *o, s32 k) {
    if (k == 1) return o->f0c;
    if (k == 0) return o->f10;
    if (o->f38 != 0) {
        o->f38(o->f3c, -3);
    }
    return 0;
}
