typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[16]; } W64;
typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0xC];
    f32 f20, f24, f28, f2C;
    u8 pad30[0x40];
    W64 m70;
    f32 mb0[3][4];
    f32 fE0, fE4, fE8, fEC;
    f32 fF0, fF4, fF8, fFC;
    f32 f100, f104, f108, f10C;
    f32 f110, f114, f118;
    u32 w11C;
    u8 m120[0x800];
} OE;
typedef struct { u8 pad[0x28]; f32 f28; } ZE;
typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x20]; ZE *p40; } AE;

extern u32 D_004C2AC0;
extern s32 D_004C2AA0;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern W64 D_0061BDE0;
typedef struct { f32 m[4][4]; } __attribute__((aligned(16))) MM;
typedef struct { f32 x, y, z, w; } V4M;
extern f32 D_0061B324[], D_0061B328[], D_0061B32C[], D_0061B388[], D_0061B38C[], D_0061B390[];
extern f32 D_0061B3EC[], D_0061B3F0[], D_0061B3F4[];
extern f32 D_0061B358[], D_0061B35C[], D_0061B360[], D_0061B364[];
extern f32 D_0061B3BC[], D_0061B3C0[], D_0061B3C4[], D_0061B3C8[];
extern f32 D_0061B3DC[], D_0061B314[], D_0061B378[], D_0061B3E0[], D_0061B318[], D_0061B37C[];
extern f32 D_0061B3E4[], D_0061B31C[], D_0061B380[];
extern f32 D_0061B2F4[], D_0061B2F8[], D_0061B2FC[], D_0061B300[];

OE *func_003E1FD0(AE *a, u8 *b)
{
    extern s32 func_003DD030(s32);
    extern OE *func_003DD160(s32, s32);
    extern void func_003DBA30(OE *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DE3A0(u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    extern void func_003DD260(MM *);
    extern void func_003DE0C0();
    extern void func_003DE230(MM *, MM *, u8 *);
    extern void func_003DE530(V4M *);
    MM m2;
    V4M *p1;
    V4M *p2;
    s32 s3;
    s32 i;
    s32 j;
    s32 off;
    OE *o;
    s3 = func_003DD030(a->w1C);
    o = func_003DD160(0x930, 0x10);
    func_003DBA30(o, 0x92, s3, 0, 0);
    func_003DBB60((u8 *)o + 0x10, 0x90, 0);
    o->w10 = 0x13000000;
    o->f20 = ((f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f) * a->p40->f28;
    o->f24 = ((f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f) * a->p40->f28;
    o->f28 = ((f32)(u8)D_004C2AC0 / 255.0f) * a->p40->f28;
    o->f2C = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    func_003DE3A0((u8 *)o + 0x30, D_0061BE20);
    i = 0;
    off = 0;
    do {
        if (D_004C2AA0 & (1 << i)) {
            func_003DE160(D_0061BEE0 + off, D_0061BEE0 + off, D_0061C720);
        }
        func_003DE3A0(o->m120 + off, D_0061BEE0 + off);
        i++;
        off += 0x40;
    } while (i < 0x20);
    o->m70 = D_0061BDE0;
    func_003DD260(&m2);
    m2.m[0][0] = -D_0061B324[0];
    m2.m[0][1] = -D_0061B328[0];
    m2.m[0][2] = -D_0061B32C[0];
    m2.m[0][3] = 0.0f;
    p1 = (V4M *)m2.m[1];
    p1->x = -D_0061B388[0];
    m2.m[1][1] = -D_0061B38C[0];
    m2.m[1][2] = -D_0061B390[0];
    m2.m[1][3] = 0.0f;
    p2 = (V4M *)m2.m[2];
    p2->x = -D_0061B3EC[0];
    m2.m[2][1] = -D_0061B3F0[0];
    m2.m[2][2] = -D_0061B3F4[0];
    m2.m[2][3] = 0.0f;
    func_003DE230(&m2, &m2, D_0061C720);
    func_003DE530((V4M *)m2.m[0]);
    func_003DE530(p1);
    func_003DE530(p2);
    func_003DE0C0(&m2);
    i = 0;
    do {
        for (j = 0; j < 4; j++) {
            o->mb0[i][j] = m2.m[i][j];
        }
        i++;
    } while (i < 3);
    o->fE0 = D_0061B2F4[0];
    o->fE4 = D_0061B2F8[0];
    o->fE8 = D_0061B2FC[0];
    o->fEC = D_0061B300[0];
    o->fF0 = D_0061B358[0];
    o->fF4 = D_0061B35C[0];
    o->fF8 = D_0061B360[0];
    o->fFC = D_0061B364[0];
    o->f100 = D_0061B3BC[0];
    o->f104 = D_0061B3C0[0];
    o->f108 = D_0061B3C4[0];
    o->f10C = D_0061B3C8[0];
    o->f110 = a->p40->f28 * (D_0061B3DC[0] + (D_0061B314[0] + D_0061B378[0]));
    o->f114 = a->p40->f28 * (D_0061B3E0[0] + (D_0061B318[0] + D_0061B37C[0]));
    o->f118 = a->p40->f28 * (D_0061B3E4[0] + (D_0061B31C[0] + D_0061B380[0]));
    o->w11C = 0x43000000;
    func_003DBB20((u8 *)o + 0x920, b);
    return o;
}
