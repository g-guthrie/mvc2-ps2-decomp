typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;
extern u8 D_004B7130[];

typedef struct { u8 pad[9]; u8 b9; u8 bA; u8 bB; u8 bC; } Q;

void func_0021F9B0(u8 *p)
{
    Q *q;
    f32 f;
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0021F810(u8 *);
    extern void func_0021F740(u8 *);
    extern void func_0021F8E0(u8 *);

    q = (Q *)(p + 0x2B8);
    p[0x2C1] = *(s8 *)(p + 0x151);
    func_00175700(p);
    if (q->bB != 0) {
        s32 a2;
        s32 c;
        u32 t2;
        if (q->b9 != (a2 = *(s8 *)(p + 0x151))) {
            if (p[0x269] == 3) {
                p[0x1B5] = 0x57;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            } else {
                p[0x1B5] = D_004B7130[p[0x1B7] * 2 + a2];
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
        }
        if ((*(s8 *)(p + 0x1B2) & 0x81) == 0x80) {
            u32 t = q->bB;
            q->bB = t - 1;
        }
        c = q->bC;
        if (c < 2) {
            if (p[0x1B7] == 0) {
                switch (c) {
                case 0:
                    if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
                        *(u16 *)(p + 0x366) = 0;
                        t2 = q->bC;
                        q->bC = t2 + 1;
                        func_0021F810(p);
                    }
                    break;
                case 1:
                    if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x20) != 0) {
                        *(u16 *)(p + 0x366) = 0;
                        t2 = q->bC;
                        q->bC = t2 + 1;
                        func_0021F740(p);
                    }
                    break;
                }
            } else {
                switch (c) {
                case 0:
                    if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
                        *(u16 *)(p + 0x366) = 0;
                        t2 = q->bC;
                        q->bC = t2 + 1;
                        func_0021F810(p);
                    }
                    break;
                case 1:
                    if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
                        *(u16 *)(p + 0x366) = 0;
                        t2 = q->bC;
                        q->bC = t2 + 1;
                        func_0021F8E0(p);
                    }
                    break;
                }
            }
        }
    }
    f = *(f32 *)(p + 0x60);
    if (f < 0.0f) {
        f32 z = 0.0f;
        p[6]++;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x68) = z;
        func_001757E0(p, 1, 9);
    }
}
