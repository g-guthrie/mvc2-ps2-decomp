typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00175580(u8 *, int, int, int);

void func_001B7570(u8 *p, u8 *q)
{
    u8 t;
    if (q[0x15B] < 128)
        return;
    p[5]++;
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    p[0x21] = q[0x15B];
    t = (u8)(q[0x15B] - 128);
    if (t == 18) {
        p[0x24] = 7;
        *(s8 *)(p + 0x31) = (s8)((s8)q[0x31] + 8);
        *(s8 *)(p + 0x31) = (s8)(*(s8 *)(p + 0x31) & 0x7F);
    } else {
        p[0x24] = 0;
    }
    func_00175580(p, 0x1B, 1, t);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
}
