typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct {
    s32 a;
    f32 b;
    u8 pad;
    u8 r, g, bl;
} Rec;

extern Rec D_00477060[];
extern u8 D_004C27D0;
extern struct {
    f32 c0, c1, c2;
    u8 pad[8];
    u8 on;
    u8 pad21[3];
    s32 id;
    u8 pad28;
    u8 r, g, b;
    f32 sc;
} D_004F1D0C;
extern s32 func_00119098(f32);

void func_003D1040(void)
{
    Rec *s0 = &D_00477060[D_004C27D0];
    if (s0->a == -1) {
        D_004F1D0C.on = 0;
        return;
    }
    D_004F1D0C.on = 1;
    D_004F1D0C.sc = s0->b;
    D_004F1D0C.id = s0->a;
    D_004F1D0C.r = (u8)func_00119098(D_004F1D0C.c0 * (f32)s0->r);
    D_004F1D0C.g = (u8)func_00119098(D_004F1D0C.c1 * (f32)s0->g);
    D_004F1D0C.b = (u8)func_00119098(D_004F1D0C.c2 * (f32)s0->bl);
}
