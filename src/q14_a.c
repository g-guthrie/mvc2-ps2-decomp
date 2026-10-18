typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void *func_003DA750(void *p, s32 a, s32 b);
extern void func_0036C120(void);
void func_0036C0B0(u8 *p, s32 b, s32 c) {
    u8 *o;
    if ((o = func_003DA750(p, 1, 2)) != 0) {
        *(void**)(o+0x10) = (void*)func_0036C120;
        *(u32*)(o+0x18) = *(u32*)(p+0x18);
        *(u8**)(o+0x14) = p;
        *(u8*)(o+0x20) = b;
        *(u8*)(o+0x23) = c;
    }
}

extern void *func_003DA750(void *p, s32 a, s32 b);
extern void func_00354AB0(void);
void func_00354DD0(u8 *p, u32 q) {
    u8 *o;
    s32 i = 0;
    do {
        if ((o = func_003DA750(p, 1, 2)) == 0) return;
        *(s16*)(o+0x26) = 0x702;
        *(u8*)(o+0x20) = 1;
        *(u8*)(o+0x21) = p[0x21];
        *(s16*)(o+0x1C) = i;
        *(void**)(o+0x10) = (void*)func_00354AB0;
        i++;
        *(u32*)(o+0x18) = q;
        *(u8**)(o+0x14) = p;
    } while (i < 4);
}

extern void func_00131AB0(u8 *a, u8 *b, s32 n);
extern void func_00267E20(u8 *a);
extern void func_00191210(u8 *a);
void func_00266E20(u8 *a, u8 *b) {
    s16 v;
    a[0x40C] = 2;
    a[0x33C] = 5;
    v = *(s16*)(b + 8) - 1;
    *(s16*)(b + 8) = v;
    if (v <= 0) {
        u32 t = a[6]; a[6] = t + 1;
        a[7] = 0;
        *(s16*)(b + 0xA) = 0xF0;
        func_00131AB0(a, b + 0xA, 6);
        func_00267E20(a);
    }
    a[0x216] |= 0x80;
    a[0x1FF] = 2;
    func_00191210(a);
}

typedef struct { f32 a, b, c, d; } F4;
typedef struct { u8 pad0[0x5C]; f32 f5c; f32 f60; u32 pad64; f32 f68; f32 f6c; } O;
extern F4 D_0044FBB0[];
extern void func_001F9B00(u8 *p);
extern void func_00175700(u8 *p);
void func_001FB1A0(u8 *p) {
    O *o = (O*)p;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8*)(p + 0x151) == 0) {
        F4 *e; u32 t;
        t = p[6]; e = D_0044FBB0; p[6] = t + 1; e += p[0x1B7];
        o->f5c = e->a;
        o->f68 = e->b;
        o->f60 = e->c;
        o->f6c = e->d;
        if (p[0x1E6] == 0) {
            o->f5c = -o->f5c;
            o->f68 = -o->f68;
        }
        func_001F9B00(p);
    }
    func_00175700(p);
}

extern void func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
void func_00287CC0(u8 *p) {
    u32 *z1; u32 *z2;
    func_00175700(p); z1 = (u32*)(p + 0x60); z2 = (u32*)(p + 0x6C);
    *(f32*)(p + 0x34) += *(f32*)(p + 0x5C);
    *(f32*)(p + 0x5C) += *(f32*)(p + 0x68);
    *(f32*)(p + 0x38) += *(f32*)(p + 0x60);
    *(f32*)(p + 0x60) += *(f32*)(p + 0x6C);
    if (!(*(f32*)(p + 0x430) < *(f32*)(p + 0x38))) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
        *z1 = 0;
        *z2 = 0;
        p[0x20D] = 0;
        func_001757E0(p, 2, 2);
    }
}

extern void func_00175700(u8 *p);
extern void func_001E3A70(u8 *p);
extern void func_001843A0(u8 *p);
void func_002A0890(u8 *p) {
    func_00175700(p);
    *(f32*)(p + 0x34) += *(f32*)(p + 0x5C);
    *(f32*)(p + 0x5C) += *(f32*)(p + 0x68);
    *(f32*)(p + 0x38) += *(f32*)(p + 0x60);
    *(f32*)(p + 0x60) += *(f32*)(p + 0x6C);
    if (*(f32*)(p + 0x60) < 0.0f) {
        if (*(f32*)(p + 0x430) > *(f32*)(p + 0x38)) {
            *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
            func_001E3A70(p);
            func_001843A0(p);
        }
    }
}
