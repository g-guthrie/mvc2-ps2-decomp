typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

/* Camera position easing: move the current vector part of the way to the
 * target, publish it, and keep it as the new current value. */
typedef struct { f32 x, y, z; } V3;
extern V3 D_004C9F50; /* current */
extern V3 D_004F1FEC; /* target */
extern V3 D_004F1F4C; /* output */
extern V3 D_004C9F40;
extern V3 D_004F1FF8;
extern V3 D_004F1F94;

f32 func_001262C0(s32 a0, s32 a1) {
    f32 h;
    f32 n;
    f32 f;
    f32 k;
    n = a1;
    f = D_004F1FEC.z;
    f = (f - D_004C9F50.z) / n;
    D_004F1F4C.z = D_004C9F50.z + f;
    k = D_004C9F50.y;
    h = D_004F1FEC.y;
    h = (h - k) / n;
    D_004F1F4C.y = k + h;
    D_004C9F50.z = D_004F1F4C.z;
    return D_004C9F50.y = D_004F1F4C.y;
}

f32 func_00126380(s32 a0, s32 a1) {
    f32 h;
    f32 n;
    f32 f;
    f32 k;
    n = a1;
    f = D_004F1FF8.z;
    f = (f - D_004C9F40.z) / n;
    D_004F1F94.z = D_004C9F40.z + f;
    k = D_004C9F40.y;
    h = D_004F1FF8.y;
    h = (h - k) / n;
    D_004F1F94.y = k + h;
    D_004C9F40.z = D_004F1F94.z;
    return D_004C9F40.y = D_004F1F94.y;
}

typedef struct { f32 a, b, c, d; } HxQ4;
typedef struct { f32 a, b; } HxP2;

extern u8 D_004D1570[], D_004D1370[], D_004F7D30[];
extern u8 D_004ACDD0[], D_004ACFD0[], D_004AD030[];
extern s32 func_00127970(u8);

#define HX_COPY(dst, src) do { \
    *(HxQ4 *)(dst) = *(HxQ4 *)(src); \
    *(HxP2 *)((dst) + 0x10) = *(HxP2 *)((src) + 0x10); \
} while (0)

void func_00127990(void) {
    u8 *s0, *s1, *s2, *e;
    s32 off;
    u8 *d3, *d2, *d1;
    s32 i;
    s0 = D_004ACDD0;
    s1 = D_004ACFD0;
    s2 = D_004AD030;
    off = 0;
    i = 0;
    do {
        d1 = D_004D1570 + off;
        e = d1 + 0xC;
        HX_COPY(d1, s0);
        d2 = D_004D1370 + off;
        HX_COPY(d2, s0);
        d3 = D_004F7D30 + off;
        HX_COPY(d3, s0);
        s0 += 0x18;
        d3[0xC] = *(s8 *)&s2[0];
        d3[0xD] = *(s8 *)&s2[1];
        d3[0xE] = *(s8 *)&s2[2];
        d3[0xF] = *(s8 *)&s2[3];
        s2 += 4;
        d2[0xC] = *(s8 *)&s1[0];
        d2[0xD] = *(s8 *)&s1[1];
        d2[0xE] = *(s8 *)&s1[2];
        d2[0xF] = *(s8 *)&s1[3];
        s1 += 4;
        e[0] = func_00127970(e[0]);
        e[1] = func_00127970(e[1]);
        e[2] = func_00127970(e[2]);
        e[3] = func_00127970(e[3]);
        e = d2 + 0xC;
        e[0] = func_00127970(e[0]);
        e[1] = func_00127970(e[1]);
        e[2] = func_00127970(e[2]);
        e[3] = func_00127970(e[3]);
        e = d3 + 0xC;
        e[0] = func_00127970(e[0]);
        e[1] = func_00127970(e[1]);
        e[2] = func_00127970(e[2]);
        e[3] = func_00127970(e[3]);
        off += 0x18;
        i++;
    } while (i < 0x15);
}
