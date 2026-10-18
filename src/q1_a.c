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
static void func_001CB680(u8 *p, u8 *q) { p[0x10] = 0; }
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

