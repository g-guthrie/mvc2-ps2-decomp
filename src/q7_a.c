typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40(void);
extern s32 func_00175700(void *p);
extern void func_001843A0(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);

extern s32 func_001E2490(s32 a, s32 b);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_002677C0(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        u32 t;
        func_001E2490(6, 0x4C);
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x16, 0x25);
        D_004F1F45 = 2;
        D_004F1F46 = 1;
    }
}

extern void func_00282470(void *p);

void func_002823F0(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
        if (p[6] == 0) goto L;
        func_00282470(p);
        break;
    case 0:
    case 1:
    L:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}

typedef struct {
    u8 pad0[0x10]; void *f10; u8 pad14[4]; void *f18; u8 pad1c[4]; u8 b20; u8 b21; u8 pad22[4]; s16 h26;
    u8 pad28[0xA8]; u32 fD0; u32 fD4; u32 fD8;
} Obj;
typedef struct { u8 pad[0x168]; u16 h168; u8 pad16a[0x4B]; u8 b1B5; u8 pad1b6[0xE]; u32 w1C4; } Src;
extern void func_001D7D70(void);
extern void func_001D8160(void);
extern void *func_003DA750(void *pool, s32 kind, s32 flags);

Obj *func_001D7CE0(Src *a, s32 b) {
    Obj *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        void *f = (void *)func_001D7D70;
        if (b) f = (void *)func_001D8160;
        o->f10 = f;
        o->f18 = a;
        o->h26 = 0x2F05;
        o->fD0 = a->h168;
        o->fD4 = a->b1B5;
        o->b20 = b;
        o->b21 = b - 1;
        o->fD8 = a->w1C4;
    }
    return o;
}

extern void func_001CCD40(void);

u8 *func_001CCB70(u8 *p, s32 b) {
    u8 *o;
    if ((u8)b != 10) {
        if ((o = (u8 *)func_003DA750(0, 3, 0)) == 0) return 0;
    } else {
        if ((o = (u8 *)func_003DA750(0, 4, 0)) == 0) return 0;
    }
    *(void **)(o + 0x10) = (void *)func_001CCD40;
    o[0x20] = b;
    o[0x21] = 0;
    *(u8 **)(o + 0x18) = p;
    o[1] = p[1];
    *(s16 *)(o + 0x26) = 0x2200;
    *(u32 *)(o + 0xD0) = *(u16 *)(p + 0x168);
    return o;
}

extern void func_00175910(void *p, s32 a, s32 b, s32 c);
extern void func_0035A7B0(void *p, void *q);

void func_00359090(u8 *p, u8 *q, s32 c) {
    u8 *t = *(u8 **)(p + 0x18);
    *(u16 *)(q + 8) = 0xFFFF;
    *(f32 *)(p + 0x34) = *(f32 *)(t + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(t + 0x38);
    *(s16 *)(p + 0x140) = *(s16 *)(t + 0x140);
    *(u32 *)(p + 0x48) = *(u32 *)(t + 0x48);
    p[0x13C] = 1;
    p[0x169] = 0x17;
    p[0x168] = c;
    func_00175910(p, p[0x169], p[0x168], *(s8 *)(t + 0x151) & 0x7F);
    if (*(s8 *)(p + 0x151) < 0) {
        *(s8 *)(p + 0x31) = 2;
    } else {
        *(s8 *)(p + 0x31) = -2;
    }
    func_0035A7B0(p, q);
}
