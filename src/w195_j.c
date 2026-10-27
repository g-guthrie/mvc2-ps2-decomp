typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q {
    u8 pad0[5];
    u8 b5;
    u8 pad1[0x1C - 6];
    s16 s1C;
    s16 s1E;
    u8 pad2[0x34 - 0x20];
    f32 f34;
    f32 f38;
    u8 pad3[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad4[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad5[0xD0 - 0x70];
    s32 iD0;
    u8 pad6[0x140 - 0xD4];
    s16 s140;
    u8 pad7[0x1B2 - 0x142];
    u8 b1B2;
} Q;

extern void func_00175700(Q *);
extern void func_001E3710(Q *, s32);
extern void func_001E7F60(Q *);

void func_003BEC60(u8 *actor, void *owner) {
    Q *p = (Q *)actor;
    f32 d;
    f32 z;
    f32 k;
    s16 h;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    h = p->s1E + 0x2000;
    p->s1E = h;
    if (h == 0) {
        p->b1B2 = 0;
    }
    d = p->f34 - (f32)p->iD0;
    z = 0.0f;
    if (d < z) {
        d = -d;
    }
    k = 13.333333015441895f;
    if (d < k) {
        p->b5++;
        p->s1C = 0x1E;
        if (p->s140 != 0) {
            k = -k;
        }
        p->f34 = (f32)p->iD0 + k;
        func_001E3710(p, 0x31);
    }
    func_001E7F60(p);
}
