typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    u8 pad6[0x6];
    u8 b6;
    u8 pad34[0x2D];
    f32 f34, f38, f3C;
    u8 pad60[0x20];
    f32 f60;
    u8 pad6C[0x8];
    f32 f6C;
    u8 pad1E6[0x176];
    u8 b1E6;
    u8 pad20D[0x26];
    u8 b20D;
    u8 pad430[0x222];
    f32 f430;
} S19;
typedef struct { f32 x, y, z; } V3;
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s32 func_00175700(u8 *);
extern void func_00158C70(V3 *, s32);
extern void func_001E3A40(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
void func_0020FA50(S19 *p) {
    u32 t;
    V3 v;
    func_00175700((u8 *)p);
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->f38 <= p->f430) {
        t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20D = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        v = *(V3 *)&p->f34;
        v.x += (f32)((p->b1E6 != 0) ? -8 : 8);
        func_00158C70(&v, -1);
        func_001E3A40((u8 *)p);
        func_001757E0((u8 *)p, 0xF, 4);
    }
}
