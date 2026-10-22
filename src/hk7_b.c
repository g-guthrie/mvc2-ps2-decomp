typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Hk7qObj {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x34 - 0x07];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad70[0x140 - 0x70];
    s16 h140;
    u8 pad142[0x151 - 0x142];
    s8 b151;
    u8 pad152[0x1DC - 0x152];
    u8 *p1DC;
    u8 pad1E0[0x1FE - 0x1E0];
    u8 b1FE;
    u8 pad1FF[0x201 - 0x1FF];
    u8 b201;
    u8 pad202[0x304 - 0x202];
    s32 w304;
    u8 pad308[0x33C - 0x308];
    u8 b33C;
    u8 pad33D[0x40C - 0x33D];
    u8 b40C;
    u8 pad40D[0x430 - 0x40D];
    f32 f430;
} Hk7qObj;

void func_0029DD10(Hk7qObj *p) {
    extern void func_00175700(Hk7qObj *, s32);
    extern void func_00178F20(Hk7qObj *, u8 *);
    Hk7qObj *s0;
    s0 = (Hk7qObj *)p->p1DC;
    p->b40C = 2;
    p->b33C = 5;
    p->b1FE = 1;
    p->b201 = 2;
    func_00175700(p, 2);
    if (p->b151 != 0) {
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        if (p->b151 < 0) {
            u32 c0, c3, c2, c1, t;
            f32 k8, k16;
            p->w304 = 0x23;
            p->b151 = 0;
            c0 = 0xC0555555u;
            c3 = 0x3D555555u;
            t = p->b6;
            c2 = 0x40892492u;
            c1 = 0xBE892492u;
            k8 = 8.0f;
            k16 = 16.0f;
            p->b6 = t + 1;
            *(u32 *)&p->f5C = c0;
            *(u32 *)&p->f68 = c3;
            *(u32 *)&p->f60 = c2;
            *(u32 *)&p->f6C = c1;
            *(u32 *)&s0->f5C = 0;
            *(u32 *)&s0->f60 = 0;
            *(u32 *)&s0->f68 = 0;
            *(u32 *)&s0->f6C = 0;
            s0->f5C = (p->f34 - s0->f34) / k16;
            s0->f60 = (s0->f430 - s0->f38) / k8;
            if (p->h140 == 0) {
                p->f5C = -p->f5C;
                p->f68 = -p->f68;
            }
            return;
        }
    }
    func_00178F20(p, p->p1DC);
}
