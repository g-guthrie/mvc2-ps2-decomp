typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
extern int func_001757E0(u8 *, int, int);

void func_002E67D0(u8 *p, u8 *q)
{
    u8 *e;
    s32 i;
    f32 k;
    f32 dx, dz, r, c;
    u32 a, b;
    e = D_004F20B0;
    e += (1 >> (p[2] & 1)) * 0x5B8;
    for (i = 0; i < 3; i++, e += 0xB70) {
        if (e[0] == 0) {
            continue;
        }
        k = 2.1428570747375488f;
        a = *(volatile u8 *)(e + 0x14C);
        b = e[0x14D];
        c = k * (f32)(s32)(a + b);
        dx = *(f32 *)(p + 0x34) - *(f32 *)(e + 0x34);
        dz = *(f32 *)(p + 0x38) - (c + (*(f32 *)(e + 0x38) - k * (f32)b));
        r = dx * dx + dz * dz;
        if (r < c * c) {
            if (*(s8 *)(q + 5) == 0) {
                q[5] = 1;
                func_001757E0(p, 0x15, 5);
                break;
            }
        } else if (*(s8 *)(q + 5) != 0) {
            q[5] = 0;
            func_001757E0(p, 0x15, 9);
        }
    }
}
