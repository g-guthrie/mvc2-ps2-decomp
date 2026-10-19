/* ./try.sh src/grok_bg_00323250.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern s32 func_00174170(void);
extern void func_001E0760(u8 *, s32);
extern void func_001757E0(u8 *, int, int);

void residual_00323250(u8 *p)
{
    u8 *q;
    s32 r;

    p[0x13C] = 0;
    if (D_004D18A0 >= 2) {
        p[0x13C] = 1;
        q = *(u8 **)(p + 0x220);
        r = func_00174170() & 1;
        if (q[1] == 58)
            r = p[2];
        if (r == 0) {
            p[6] = 2;
            p[0x20D] = 0;
            func_001E0760(p, 0);
        } else {
            p[6] = 1;
            p[0x20D] = 2;
            *(f32 *)(p + 0x38) += 549.1428833007812f;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x6C) = (s32)0xBECDB6DB;
        }
        func_001757E0(p, 18, r);
    }
}
