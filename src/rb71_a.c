typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x23D]; s8 b; } O;

typedef struct { u8 pad[0x60]; f32 f60; u8 pad2[8]; f32 f6c; } SP;
void func_001D02E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00174170(void);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern void func_0015B200(u8 *, u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    u8 *o;
    s8 t;
    u32 u;
    f32 a;
    f32 tt;
    SP *sp = (SP *)p;
    s32 ang;
    o = *(u8 **)(p + 0x18);
    p[0x24] = ((s8 *)o)[0x24];
    func_00175700(p);
    if (o[5] != 3 || o[0x247] != 0xF) {
        u = p[4];
        p[4] = u + 1;
        p[5] = 0;
        p[0x13C] = 0;
        if ((((O *)o)->b -= 1) < 0) *(s8 *)((s32)o + 0x23D) = 0;
        if (*(s8 *)((s32)o + 0x23D) > 2) return;
        {
            func_0015B200(o, p + 0x34, 1, 8);
            func_001E3710(p, 0x49);
        }
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    if (p[5] == 0) {
        p[5] = p[5] + 1;
        u = o[0x14C];
        a = (f32)u;
        sp->f60 = 2.142857074737549f * a / 2.0f;
        sp->f6c = sp->f60 / 2.0f;
        ang = func_00174170() << 8;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x6C) * func_00417500(ang) + *(f32 *)(p + 0x6C) * func_00417440(ang) / 8.0f;
        *(f32 *)(p + 0x60) += -*(f32 *)(p + 0x6C) * func_00417440(ang) + *(f32 *)(p + 0x6C) * func_00417500(ang);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
}
