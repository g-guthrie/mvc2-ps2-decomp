typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 *D_004C2708;

/* 0x001C88F0 static copy (real body, verified in src/g0c.c) */
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } S1C8;
static void func_001C88F0(S1C8 *p)
{
    p->f34 = (*(S1C8 **)((u8 *)p + 0x18))->f34;
    p->f38 = (*(S1C8 **)((u8 *)p + 0x18))->f38;
    if (*(s16 *)((u8 *)p + 0x140))
        p->f34 += D_004C2708[0];
    else
        p->f34 -= D_004C2708[0];
    p->f38 += D_004C2708[1];
}

typedef struct { u32 x[0x31]; } S31;
typedef struct { f32 x, y, z; } V3;
/* 0x001C8960 */
extern void func_001757E0(u8 *, s32, s32);
void func_001C8960(u8 *p) {
    u32 t = p[4];
    p[4] = t + 1;
    *(S31 *)(p + 0xEC) = *(S31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x13C] = 1;
    *(s8 *)(p + 0x24) = (p[0x21] != 0) ? 0 : 0xB;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(s16 *)(p + 0x1C) = 0;
    *(u32 *)D_004C2708 = 0;
    ((u32 *)D_004C2708)[1] = 0;
    func_001C88F0((S1C8 *)p);
    func_001757E0(p, 0x17, p[0x21] << 1);
}
