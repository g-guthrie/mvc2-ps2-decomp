typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175C00(void *p, s32 a);
extern void func_00176160(void *p, s32 a, s32 b, s32 c);
typedef struct { u8 pad[0x2B8]; s8 b[4]; } S18;

void func_00318CF0(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        func_00175C00(p, 0);
        return;
    }
    {
        s8 *q = ((S18 *)p)->b;
        s8 v = q[0] - 1;
        q[0] = v;
        if (v < 0) {
            q[0] = q[1];
            q[2] = q[2] ^ 1;
            if ((q[2] & 1) == 0) {
                func_00175C00(p, 0);
            } else {
                func_00176160(p, 0, 4, 1);
            }
        }
    }
}

