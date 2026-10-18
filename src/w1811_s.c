typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 s1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad70[0x269 - 0x70];
    u8 b269;
    u8 pad26A[0x33C - 0x26A];
    u8 b33C;
    u8 pad33D[0x404 - 0x33D];
    u8 b404;
    u8 b405;
    u8 pad406[0x40C - 0x406];
    u8 b40C;
} O;

void func_002BC920(O *p) {
    extern void func_00175700(O *);
    extern void func_001830D0(O *, f32 *, s32);
    extern void func_001266A0(O *, s32, s32);
    extern void func_001E3210(O *, s32);
    extern void func_001757E0(O *, s32, s32);
    f32 *v1, *a0;
    f32 vec[3];
    s16 s;
    u32 t;
    p->b40C = 2;
    p->b33C = 5;
    p->b405 = (p->b269 == 6) ? 2 : 0;
    func_00175700(p);
    v1 = &p->f60;
    a0 = &p->f6C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->f60 < 0.0f) {
        *v1 = 0.0f;
        *a0 = 0.0f;
    }
    s = p->s1C - 1;
    p->s1C = s;
    if (s > 0) {
        if (p->s1C == 0x1C) {
            func_001266A0(p, 1, 1);
        }
        return;
    }
    t = p->b6;
    p->b6 = t + 1;
    p->b404 = 0;
    p->b405 = 0;
    vec[0] = 38.33333206176758f;
    vec[1] = 68.57142639160156f;
    vec[2] = 0.0f;
    func_001830D0(p, vec, 1);
    func_001E3210(p, 0xB);
    func_001757E0(p, 0x16, 2);
}
