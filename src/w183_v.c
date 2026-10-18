typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 pad[5]; s16 a; s16 c; s16 e; s16 pad2; s16 h12; } Q;

void func_00236A10(u8 *o, Q *q) {
    extern void func_00175700(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_00182C30(u8 *, s32);
    extern s32 func_00182E20(u8 *);
    extern void func_00182DB0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *e;
    s32 v;
    s32 m;
    s32 f;
    s16 w;
    s16 w2;
    u32 t;
    o[0x1FE] = 1;
    o[0x206] = 3;
    e = *(u8 **)(o + 0x1DC);
    e[0x208] = 2;
    func_00175700(o);
    if (func_00182D30(e)) {
        q->c += 2;
        q->a -= 1;
        q->e -= 1;
        func_00182C30(e, 0x10);
    }
    if (func_00182E20(o)) {
        q->c -= 4;
        q->a += 2;
        q->e += 2;
        func_00182DB0(o, 0xA);
    }
    v = q->a >> 1;
    if (v < 0) {
        q->a = 0;
        v = 0;
    }
    m = *(s8 *)(o + 0x152);
    if (!(v < m)) v = m - 1;
    *(s8 *)(o + 0x152) -= v;
    f = *(s8 *)(o + 0x151);
    if (f & 1) {
        *(s8 *)(o + 0x151) = f ^ 1;
        w = q->e - 2;
        q->e = w;
        if (w > 0) {
            w2 = q->h12 - 1;
            q->h12 = w2;
            if (w2 != 0) return;
        }
        {
            t = o[7];
            o[7] = t + 1;
            func_001757E0(o, 0xF, 4);
        }
    }
}
