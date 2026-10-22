typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q_1FAAD0 {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3c[0x20D - 0x3C];
    u8 b20D;
    u8 pad20e[0x428 - 0x20E];
    u32 w428;
    u32 w42C;
} Q_1FAAD0;

typedef struct P_1FAAD0 {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 s1C;
    u8 pad1e[0x21 - 0x1E];
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad70[0x1B2 - 0x70];
    s8 b1B2;
    u8 pad1b3[0x1C4 - 0x1B3];
    Q_1FAAD0 *q;
    u8 pad1c8[0x1E6 - 0x1C8];
    u8 b1E6;
    u8 b1E7;
    u8 pad1e8[0x33B - 0x1E8];
    u8 b33B;
    u8 b33C;
    u8 pad33d[0x40C - 0x33D];
    u8 b40C;
    u8 b40D;
} P_1FAAD0;

extern void func_00175700(P_1FAAD0 *);
extern s32 func_00185980(P_1FAAD0 *);
extern void func_001757E0(P_1FAAD0 *, s32, s32);
extern void func_001E3210(P_1FAAD0 *, s32);

void func_001FAAD0(P_1FAAD0 *p)
{
    Q_1FAAD0 *q;
    p->b40C = 2;
    p->b33C = 5;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->b1B2 != 0) {
        if (func_00185980(p) != 0) {
            u32 t = p->b6;
            p->b6 = t + 1;
            q = p->q;
            q->f38 = p->f38;
            if (q->w42C & 0x4000000) {
                q->f38 = 52.5f + p->f38;
            }
            if (q->w428 & 0x20000000) {
                q->f38 = 52.5f + p->f38;
            }
            q->b20D = 2;
            p->f5C /= 16.0f;
            func_001757E0(p, 0x16, 7);
            return;
        } else {
            p->s1C = 1;
            p->b6 = 5;
            p->b40D = 0;
            p->b40C = 0;
            p->b33B = 0;
            p->b33C = 0;
            *(u32 *)&p->f5C = 0x40855555;
            if (p->b1E6 != 0) p->f5C = -p->f5C;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f60 = 0x41700000;
            *(u32 *)&p->f6C = 0xBF892492;
            p->b1E7 = 1;
            func_001757E0(p, 0x14, 6);
        }
    } else {
        s16 v = p->s1C - 1;
        p->s1C = v;
        if (v == 0) {
            u32 t = p->b6;
            p->b6 = t + 1;
            p->b40D = 0;
            p->b40C = 0;
            p->b33B = 0;
            p->b33C = 0;
            func_001E3210(p, 0x2B);
            p->f5C /= 2.0f;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f60 = 0xC0092492;
            *(u32 *)&p->f6C = 0xBF4DB6DB;
            func_001757E0(p, 1, 9);
            p->b21 = 1;
        }
    }
}
