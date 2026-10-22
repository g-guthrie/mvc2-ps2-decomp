typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 b0; u8 b1; u16 h2; u32 w4; } Ent;
typedef struct {
    u32 pad0;
    u32 w4;
    u32 w8;
    u8 padc[8];
    u32 w14;
    u8 pad18;
    u8 st;
    u8 idx;
    u8 lim;
    u8 cnt;
    u8 pad1d[3];
    u32 w20;
} Obj;

extern Ent D_004CA6F0[];
extern Ent D_004CAB40[];
extern Ent D_004CA210[];
extern u32 D_004CA1F0[];
extern u32 D_0043CDA0[];
extern s32 func_00418AA0();
extern u32 func_003FCA60();
extern u32 func_003FCBC0();
extern s32 func_003FD450();
extern void func_003FD0F8(u32, s32, s32);
extern s32 func_003FD530();
extern void func_003FCCF0();
extern void func_0012E640();

s32 func_0012DF30(Obj *p) {
    Ent *e;
    s32 r;
    u32 t;
    u32 k;
    u32 st = p->st;
    switch (st) {
    case 0:
        if (p->idx == p->lim) return 0;
        p->st = st + 1;
        e = D_004CA6F0 + p->idx;
        if ((Ent *)p != D_004CAB40) e = D_004CA210 + p->idx;
        *(u8 *)&p->pad18 = e->b0;
        p->w4 = e->w4;
        p->w8 = e->h2;
        if (*(u16 *)e & 0x80) {
            func_0012E640(D_004CA1F0[e->h2], D_004CA1F0[e->w4], 0x150000);
            p->st = 0;
            p->w14 = 0;
            p->cnt--;
            p->idx++;
            p->idx &= 0x7F;
            return 0;
        }
    case 1:
        if (func_00418AA0() == 0) break;
        k = p->pad18;
        t = (u16)p->w8;
        if (k == 0) {
            p->w20 = func_003FCA60(D_0043CDA0[t], 0);
        } else {
            p->w20 = func_003FCBC0(k, t);
        }
        if (p->w20 == 0) { p->st = 3; break; }
    case 4:
        func_003FD0F8(p->w20, func_003FD450(p->w20), p->w4);
        p->st = 2;
        p->w14 = 0;
        break;
    case 2:
        p->w14++;
        r = func_003FD530(p->w20);
        if (r != 2) {
            func_003FCCF0(p->w20);
            if (r == 3) {
                p->w20 = 0;
                p->pad0 = 0;
                p->st = 0;
                p->w14 = 0;
                p->cnt--;
                p->idx++;
                p->idx &= 0x7F;
            } else {
                p->st = 3;
                p->w14 = 0;
            }
        }
        if (p->w14 >= 0x384) {
            p->st = 3;
            p->w14 = 0;
            func_003FCCF0(p->w20);
        }
        break;
    case 3:
        p->st = 0;
    default:
        return 0;
    }
    return 1;
}
