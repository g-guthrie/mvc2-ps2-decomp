typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3r;

/* jtbl_004760F0 case 0 of func_003C7F50: inherit state from owner q. */
void residual_003C7F70(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    s32 *d, *s;

    p[4]++;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    i = 0x31;
    do {
        *d = *s;
        i--;
        s++;
        d++;
    } while (i > 0);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3r *)(p + 0x50) = *(V3r *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_001757E0(p, 0x14, 0x19);
}
