typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long u64;

/* Metrowerks 3.0.3: ./try.sh src/pw39_d.c */
u8 *func_0041B2C0(u32 *p) {
    u32 w = p[0];
    u32 n = w & 0xFFFF;
    u8 *q = (u8 *)p + 0x10;
    switch (w & 0x70000000) {
    case 0x10000000: return q + n * 16;
    case 0x20000000: return (u8 *)(p[1] & 0x7FFFFFFF);
    case 0x30000000:
    case 0x40000000: return q;
    case 0: return 0;
    case 0x50000000: return (u8 *)(p[1] & 0x7FFFFFFF);
    case 0x60000000:
    case 0x70000000: return 0;
    }
    return 0;
}
