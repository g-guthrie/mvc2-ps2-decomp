typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[1];
    u8 b1;
} Q;

typedef struct P {
    u8 pad0[0x34];
    f32 f34;
    u8 pad38[0x1BA - 0x38];
    u8 b1BA;
    u8 pad1BB[0x1C2 - 0x1BB];
    u16 h1C2;
    u8 pad1C4[0x1CC - 0x1C4];
    struct P *p1CC;
    Q *p1D0;
    u8 pad1D4[0x1E6 - 0x1D4];
    u8 b1E6;
    u8 pad1E7[0x211 - 0x1E7];
    s8 b211;
    u8 pad212[0x220 - 0x212];
    struct P *p220;
    u8 pad224[0x228 - 0x224];
    s8 *p228;
} P;

void func_0018CEA0(P *p) {
    extern void func_0018D030();
    extern void func_0018D0C0();
    Q *q;
    s32 h;
    P *o;
    s32 t;
    s8 *c;
    s8 *n;
    f32 z;
    f32 v;
    q = p->p1D0;
    if (q != 0) {
        h = p->h1C2;
        if (h & 0x10) {
            func_0018D030();
            return;
        } else if (h & 0x1000) {
            func_0018D0C0();
        } else {
            t = p->b1BA;
            if (h & 0x20) {
                t = ((s8)p->b1E6 ^ 1) & 0xFF;
            }
            h = p->b211;
            if (h != 0 && (q->b1 & 0x80) == 0 && ((s8)h & (1 << (p->b1E6 & 1))) != 0
                && ((o = p->p1CC) != 0 || (o = p->p220) != 0 || 1)
                && (o->b211 & (1 << (o->b1E6 & 1))) == 0) {
                z = 0.0f;
                c = p->p228;
                v = *c;
                n = c + 1;
                if (v > z) {
                    p->p228 = n;
                    if (t == 0) {
                        v = -v;
                    }
                    o->f34 -= 1.6666666269302368f * v;
                }
                return;
            } else {
                z = 0.0f;
                c = p->p228;
                v = *c;
                n = c + 1;
                if (v > z) {
                    p->p228 = n;
                    if (t == 0) {
                        v = -v;
                    }
                    p->f34 += 1.6666666269302368f * v;
                }
            }
        }
    }
}
