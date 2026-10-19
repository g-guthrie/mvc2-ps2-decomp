typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s8 func_00175670(u8 *);
extern void func_001754A0(u8 *, int, int);
extern void func_0019B740(u8 *);

void func_0019B640(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (q[5] != 0) {
        func_0019B740(p);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (p[5] == 0) {
        if (func_00175670(p) < 0) {
            p[5]++;
            func_001754A0(p, 0x1B, 6);
        }
        return;
    }
    if (func_00175670(p) < 0)
        func_0019B740(p);
}
