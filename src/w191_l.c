typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x34 - 3];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad70[0x1B7 - 0x70];
    u8 b1B7;
    u8 pad1B8[0x20D - 0x1B8];
    u8 b20D;
    u8 pad20E[0x212 - 0x20E];
    u8 b212;
    u8 pad213[0x2B8 - 0x213];
    s8 s2B8[0x20];
} P2E5;

typedef struct {
    u8 pad[0x106];
    u16 h106[1];
} T2E5;

extern T2E5 *D_004C2840;

/* Provisional: team index bounds and state ownership require proof. */
void func_002E50C0(P2E5 *p)
{
    extern void func_001863F0(u8 *);
    extern void func_002E7740(P2E5 *);
    extern void func_002E51F0(P2E5 *);
    extern void func_002E5230(P2E5 *);
    extern void func_002E52E0(P2E5 *);
    extern void func_002E5390(P2E5 *);
    s8 *q = p->s2B8;

    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001863F0((u8 *)p);
    if (q[9] != 0 && p->b1B7 != 0) {
        if (*(u16 *)((p->b2 << 1) + (u32)D_004C2840 + 0x106) != 0) {
            if (q[0x11] != 0) {
                func_002E7740(p);
                return;
            }
        } else {
            func_002E7740(p);
            return;
        }
    }
    if (p->b212 == 0) {
        if (p->b20D == 0) {
            func_002E51F0(p);
        } else {
            func_002E5230(p);
        }
    } else {
        if (p->b20D == 0) {
            func_002E52E0(p);
        } else {
            func_002E5390(p);
        }
    }
}
