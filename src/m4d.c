typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern u8 *func_003DA750(s32 a, s32 b, s32 c);



extern void func_002DB0E0(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001D18E0(void *p);
void func_002DAD20(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 v;
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x20;
        *(s16 *)(p + 0x1E) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_002DB0E0(p);
        v = p[0x22];
        if (*(s16 *)(p + 0x140) != 0) v = (0x20 - v) & 0x1F;
        func_001757E0(p, 0x16, (u8)((v >> 2) + 1));
        func_001D18E0(p);
    }
}

extern void func_00192E00(void);
void func_00192D60(u8 *a, s32 b) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_00192E00;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 1;
        o[0x20] = b;
        o[0x21] = 0;
    }
    o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_00192E00;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 1;
        o[0x20] = b;
        o[0x21] = 1;
    }
}

void func_003C1CF0(u8 *p, u8 *q) {
    u8 *v = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x34) = *(f32 *)(v + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(v + 0x38) + *(f32 *)(p + 0x60);
    func_00175700(p);
    if (q[0x2C5] != 0) p[0x13C] = 0;
}

extern void func_00290E30(void *p);

extern void func_00294B20(void *p, void *q);
extern void func_00294BC0(void *p);
extern void func_001C09A0(void *p, s32 n);
extern void func_00385A20(void *p, s32 n);
extern u8 D_00456DB0[];
void func_00290D50(u8 *p) {
    func_00290E30(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_00294B20(p, D_00456DB0);
        func_00294BC0(p);
        func_001C09A0(p, 5);
        func_00385A20(p, 4);
    }
}

extern void func_00174910(void *p, s32 n);
extern s32 func_00118FA8(f32 f);
extern void func_00355BD0(void *p);
extern s16 D_004B8390[];
void func_00355B60(u8 *p) {
    func_00174910(p, D_004B8390[*(s32 *)(p + 0xDC)]);
    *(s32 *)(p + 0xD4) += func_00118FA8(*(f32 *)(p + 0x5C));
    *(s32 *)(p + 0xD8) += func_00118FA8(*(f32 *)(p + 0x60));
    func_00355BD0(p);
}

extern void func_001BAD70();
extern s32 func_00175670();
typedef struct { f32 x, y, z; } V3;
void func_001BAB10(u8 *p, u8 *q) {
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (p[1] != q[1]) {
        func_001BAD70(p, q);
        return;
    }
    if ((s8)func_00175670(p) < 0) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    *(f32 *)(p + 0x118) -= 0.03125f;
}

void func_001C63B0(u8 *p, u8 *q) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(p + 0x1C) = 0x20;
        func_00175700(p);
    }
}

extern void func_0039E450(void *p);
extern void (*D_004727D0[])(void *p);
void func_0039DE20(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[5] != 0 || q[0x1E4] != 0x1D) {
        func_0039E450(p);
    } else {
        D_004727D0[p[4]](p);
    }
}

extern s32 func_00175670();
extern void (*D_0044A670[])(void *p);
void func_00198CE0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s8 *)(q + 0x161) != 0x24) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        func_00175670(p);
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
        *(f32 *)(p + 0x34) += *(f32 *)(q + 0x64);
        D_0044A670[p[5]](p);
    }
}

extern void func_00176160(void *p, s32 a, s32 b, s32 c);
extern u8 D_00462AE0[];
extern u8 D_00462AE1[];
void func_00353690(u8 *p, s8 *a, s8 *b) {
    s8 v = *a - 1;
    *a = v;
    if (v <= 0) {
        *a = D_00462AE0[*b * 2];
        func_00176160(*(void **)(p + 0x18), 2, D_00462AE1[*b * 2], 1);
        *b = (*b + 1) % 5;
    }
}
