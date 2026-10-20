typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_00463D80[])();
extern s32 func_0016A130(u8 *, s32, s32);
extern s32 func_0016A1F0(u8 *, s32);
extern s32 func_00169BC0(u8 *, s32, s32);
extern s32 func_00169AE0(u8 *, s32);
extern void func_00169E50(u8 *, s32);
typedef struct { f32 x, y, z; } CopyV3;
static void func_001CB680(u8 *p, u8 *o) {
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(CopyV3 *)(p + 80) = *(CopyV3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}
extern void func_001754A0(u8 *, s32, s32);
extern s32 func_00175670(u8 *);
extern s32 func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_00385A20(u8 *);
extern void func_001C09A0(u8 *, s32);

typedef struct { u8 pad[0x2B8]; u8 b[2]; } S2B8;
void func_0036D980(u8 *p)
{
    S2B8 *q;
    u8 *r;
    q = *(S2B8 **)(p + 0x18);
    D_00463D80[p[5]](p, q);
    r = q->b;
    if (r[1] != 0) {
        p[4]++;
        p[0x13C] = 0;
        *r = 0;
    }
}

s32 func_00169400(u8 *p, s32 n)
{
    u8 *r = *(u8 **)(p + 0x220);
    if (n > 3) return 0;
    if (p[0x215] == 0 && p[0x20D] != 2 && r[0x1E4] == 3) return func_0016A130(p, 12, 3);
    return func_0016A1F0(p, 12);
}


void func_001CBC80(u8 *p, u8 *q)
{
    if (p[4] == 0) {
        func_001CB680(p, q);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        func_001754A0(p, 0x1B, 0x63);
    }
    if ((s8)func_00175670(p) < 0) p[4]++;
}

