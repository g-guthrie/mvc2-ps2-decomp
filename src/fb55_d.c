typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct P {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p1[0x120];
    s16 h140;
    u8 _p2[0x72];
    u8 b1B4;
    u8 _p3[0x27];
    struct P *p1DC;
    u8 _p4[0x6];
    u8 b1E6;
    u8 _p5[0x24];
    u8 b20B;
    u8 _p6[0xAC];
    s8 b2B8[8];
    u8 _p7[2];
    u16 h2C2;
} P;

extern u16 D_004C1720[4];
extern u16 D_004C1728[4];
extern u8 D_0045D920[];

void func_0031A450(P *p)
{
    extern void func_0018C6E0(void *);
    extern void func_0015D010(P *, f32 *);
    extern void func_001757E0(P *, s32, s32);
    extern void func_003C4910(P *, s32, s32);
    extern void func_001E3210(P *, s32);
    extern void func_001266A0(P *, s32, s32);
    extern void func_00182C30(P *, s32);
    extern void func_00182DB0(P *, s32);
    P *q;
    u32 v[4];
    s8 *b;
    s8 *r;
    s8 f;

    q = p->p1DC;
    func_0018C6E0(p);
    q->b1E6 = (s8)p->b1E6 ^ 1;
    q->h140 = p->b1E6;
    p->b1B4 = 10;
    switch (p->b20B) {
    case 5:
    case 4:
    case 3:
    case 0:
        if (p->h2C2 & 0x400) {
            p->b1E6 ^= 1;
            p->h140 = p->b1E6;
            q->b1E6 ^= 1;
            q->h140 = q->b1E6;
        }
        v[0] = 0xC2BE0000;
        v[1] = 0x43092492;
        func_0015D010(p, (f32 *)v);
        b = p->b2B8;
        f = b[6];
        r = b + 6;
        func_001757E0(p, 0xF, ((u8 *)D_004C1720)[f * 2]);
        if (D_004C1728[*r] != 0) {
            func_003C4910(p, D_004C1728[*r] & 0xFF, 0);
        }
        func_003C4910(p, 0xF, 0);
        func_001E3210(p, D_0045D920[*r * 4]);
        return;
    case 1:
        func_001266A0(p, 5, 5);
        if ((p->h2C2 & 0x400) == 0) {
            p->b1E6 ^= 1;
            p->h140 = p->b1E6;
            q->b1E6 ^= 1;
            q->h140 = q->b1E6;
        }
        v[0] = 0xC2BE0000;
        v[1] = 0x43092492;
        func_0015D010(p, (f32 *)v);
        func_001757E0(p, 0xF, 2);
        break;
    case 2:
        if ((p->h2C2 & 0x800) == 0) {
            p->b1E6 ^= 1;
            p->h140 = p->b1E6;
            q->b1E6 ^= 1;
            q->h140 = q->b1E6;
        }
        q->b1E6 = (s8)p->b1E6 ^ 1;
        v[0] = 0xC2BE0000;
        v[1] = 0x43092492;
        func_0015D010(p, (f32 *)v);
        func_001757E0(p, 0xF, 3);
        func_003C4910(p, 3, 0);
        p->h1c = 8;
        p->h1e = 0x3C;
        func_00182C30(p->p1DC, 7);
        func_00182DB0(p, 4);
        break;
    }
}
