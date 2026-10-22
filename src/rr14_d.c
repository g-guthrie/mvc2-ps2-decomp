typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[2]; u8 f2; u8 pad3[0x4A1]; u32 f4A4; } PA;
typedef struct { u8 pad0[3]; u8 f3; u8 pad4[0x156]; u8 f15A; u8 pad15B[0x29]; u8 *f184; u8 pad188[0x2D]; u8 f1B5; } OA;
extern s8 D_004C2798[2];
extern OA *D_004D3170[];

OA *func_0016A3F0(PA *p) {
    extern s32 func_0016A5A0(PA *, OA *, u8 *, s32);
    u8 *e;
    OA *o;
    s32 r;
    s32 n;
    OA *found;
    s32 i;
    s32 hit;
    hit = 0;
    p->f4A4 = 0x475553AA;
    n = D_004C2798[p->f2 ^ 1];
    for (i = 0; i < n; i++) {
        o = ((OA **)((u8 *)D_004D3170 + (p->f2 ^ 1) * 0x178))[i];
        if (o->f3 == 0 || o->f3 == 1 || o->f3 == 3) {
            if ((o->f15A & 0xE0) >= 0x80) {
                e = o->f184;
                e += (o->f1B5 & 0x7F) * 28;
                r = func_0016A5A0(p, o, e, e[0x10]);
                r |= func_0016A5A0(p, o, e, e[0x11]);
                switch (r) {
                case 1:
                case 3:
                    p->f4A4 = 0;
                    return o;
                case 2:
                    found = o;
                    hit = 1;
                    break;
                }
            }
        }
    }
    return hit ? found : 0;
}
