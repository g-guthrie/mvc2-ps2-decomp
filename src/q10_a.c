typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x20]; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0xE1]; s8 b151; u8 pad4[0x2DE]; f32 f430; } O_00231B40;
extern s32 func_00175700( void *);
extern void func_00183d50( void *);
extern void func_001865B0( void *);
void func_00231B40(O_00231B40 *p) {
    func_00175700(p);
    if (p->b151 >= 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    if (p->f38 < p->f430) {
        p->f38 = p->f430;
        func_00183d50(p);
        func_001865B0(p);
    }
}

extern u8 D_004D18A3[];
extern u8 D_004D18A0[];
extern void (*D_0045DFF0[])(u8 *);
extern void func_001757E0( void *, s32, s32);
void func_00324130(u8 *p) {
    s32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (D_004D18A3[0] != 0 || D_004D18A0[0] == 5 || (t = *(s32 *)(p + 0x2D8) - 1, *(s32 *)(p + 0x2D8) = t, t <= 0)) {
        u32 v;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        v = p[6];
        p[6] = v + 1;
        func_001757E0(p, 0x16, 0xB);
    } else {
        D_0045DFF0[p[0x20]](p);
    }
}

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x20]; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0xCC]; u8 b13C; u8 pad4[0x77]; s8 b1B4; } O_003C5B20;
extern s32 func_00174240( void *);
extern void func_003C80A0( void *, s32);
void func_003C5B20(O_003C5B20 *p, s32 b) {
    s8 c = p->b1B4;
    if (c != 0) {
        p->b1B4 = c - 1;
    } else {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (func_00174240(p) != 0) {
            p->b13C = 1;
        } else {
            func_003C80A0(p, b);
        }
    }
}

extern void func_001266A0( void *, s32, s32);
void func_002523A0(u8 *p, u8 *q) {
    s8 c;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
    c = q[0xA];
    if (c < 0) {
        p[6] = 0xF;
    } else if (c != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x20;
        func_001266A0(p, 1, 1);
        func_001757E0(p, 0x16, 0xA);
    }
}

typedef struct { s32 w0; s32 w4; s32 w8; } S_003DC250;
extern s32 func_003DCFE0(s32, s32);
extern s32 func_00103AF0(s32, s32, s32);
extern void func_001049F8(s32);
void func_003DC250(S_003DC250 *s, s32 n, s32 k) {
    s32 i = 0;
    s32 off = 0;
    s->w4 = n;
    do {
        s32 r = func_003DCFE0(n << 2, 1);
        u8 *e = (u8 *)s + off;
        *(s32 *)(e + 0xC) = r;
        i++;
        off += 4;
        *(s32 *)(e + 0x14) = 0;
        *(s32 *)(e + 0x1C) = 0;
        *(s32 *)(e + 0x24) = 0;
    } while (i < 2);
    s->w8 = func_00103AF0(s->w0, k, 0);
    func_001049F8(s->w0);
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x2D]; f32 f34; f32 f38; u8 pad2[0x20]; f32 f5c; f32 f60; u8 pad3[4]; f32 f68; f32 f6c; u8 pad4[0xE1]; s8 b151; } O_00283040;
void func_00283040(O_00283040 *p) {
    s8 r = func_00175700(p);
    if (r >= 0) {
        if (p->b151 == 0) {
            p->f34 += p->f5c;
        }
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    } else {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f5c = 0.0f;
        p->f60 = 0.0f;
        p->f68 = 0.0f;
        p->f6c = 0.0f;
        func_001757E0(p, 2, 3);
    }
}
