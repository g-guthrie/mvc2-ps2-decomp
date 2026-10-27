typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34;
    f32 f38;
} Q_357B30;
typedef struct {
    u8 pad0[0x14];
    Q_357B30 *p14;
    u8 pad18[0x21 - 0x18];
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad3C[0x140 - 0x3C];
    s16 s140;
} O_357B30;
extern u8 D_004C1AC0[4];
extern u8 D_004C1AC4[4];
extern void func_001757E0();
extern s16 D_00462D80[], D_00462D82[], D_00462D90[], D_00462D92[];
static void func_003578A0(u8 *p) {
    f32 a, c;
    a = 1.666666627f * (f32)D_00462D80[p[0x21] * 2];
    if (*(s16 *)(p + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x34) += a;
    c = 2.142857075f * (f32)D_00462D82[p[0x21] * 2];
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38) + c;
}
static void func_00357B30(O_357B30 *p) {
    u32 n;
    s32 v;
    s32 i;
    f32 a, b, c;
    v = (p->p14->b7 != 0) ? p->p14->b7 : p->p14->b6;
    n = (u8)v;
    i = p->b21;
    a = 1.6666666269302368f * (f32)D_00462D90[i * 2];
    if (p->s140 == 0) a = -a;
    b = 2.1428570747375488f * (f32)D_00462D92[i * 2];
    a *= (f32)n;
    b *= (f32)n;
    p->f34 = p->p14->f34 + a;
    p->f38 = p->p14->f38 + b;
}

void func_00357F20(u8 *p) {
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    t = p[4]; p[4] = t + 1;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d++ = *s++;
    } while (--n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x24] = 10;
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    if (p[0x20] == 2) {
        func_003578A0(p);
        func_001757E0(p, 0x15, D_004C1AC0[p[0x21]]);
    } else {
        func_00357B30((O_357B30 *)p);
        func_001757E0(p, 0x15, D_004C1AC4[p[0x21]]);
    }
}

extern void func_00358430(u8 *);
extern int func_00175700(u8 *);
void func_003583A0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (q[361] != 21 || q[360] < 6 || q[360] > 9) {
        u32 t = p[4];
        p[4] = t + 1;
        func_00358430(p);
    } else {
        if (p[32] == 2) {
            func_003578A0(p);
        } else {
            func_00357B30((O_357B30 *)p);
        }
        func_00175700(p);
    }
}
