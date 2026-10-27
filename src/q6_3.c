typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_004C2794;
extern u32 D_00455458[];
extern s32 func_001757E0();
extern s32 func_00280E70(u8 *);
extern void func_0032D5F0(u8 *);
extern s32 func_001E7FD0(u8 *);
extern void func_00185490(u8 *);
extern s32 func_00178B00(u8 *);
extern void func_00178D80(u8 *, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, float *);
extern void func_0018C6E0(void *);
extern void func_001830D0();
extern void func_0036BFF0(u8 *, s32, s32, s32);
extern u32 D_004C2838;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0015D6A0();
extern void func_00356980(u8 *);
extern void func_0018C8A0(u8 *);
extern s32 func_00153AA0();
extern void func_00170DA0(u32, s32, s32, s16);
typedef struct { float a, b; } E8;
extern E8 D_004B3CB0[];
typedef struct { float x, y, z; } V3;
extern s32 func_00175700();
extern u32 D_0044B770[];
extern u8 D_004531C0[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_004F1F40[];
extern void func_00183d50();
extern void *func_0034A0D0(u8 *);
extern void func_00137E60();
extern void func_00137DF0();
typedef struct { u8 *ptr; u8 pad[0x5B8 - 4]; } T5B8;
extern T5B8 D_004F20C8[];
extern u8 D_00583B92[];
extern s8 D_00583BC0[];
extern void func_003A6DC0();
extern s32 func_00174170();
extern void func_00169C90();
extern void func_0015DFC0();

void func_0015DBE0(float *src, s16 val) {
    u8 *o;
    u32 d;
    if ((o = func_003DA750(0, 9, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0015DFC0;
        *(s16 *)(o + 0xCC) = 0xB4;
        *(u32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)src;
        *(u32 *)(o + 0xD0) = 0x800025;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(s32 *)(o + 0x74) = 0;
        *(s16 *)(o + 0x140) = val;
        if (*(s16 *)(o + 0x140) != 0) { d = 0x8000; } else { d = 0; } *(u32 *)(o + 0x44) += d;
    }
}

void func_00178770(u8 *p) {
    u16 f;
    func_00185490(p);
    if (func_00178B00(p) == 0) {
        f = *(u16 *)(p + 0x354);
        if (f & 0x2000) {
            func_00178D80(p, 3);
        } else if (f & 0x1000) {
            func_00178D80(p, 2);
        } else if ((f & 0xC00) || *(s8 *)(p + 0x539) != 0) {
            func_00178D80(p, 6);
        }
    }
}

s32 func_0024DDB0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_004531C0, p + 0x3B8) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (*(s8 *)(q + 9) != 0) {
        return 0;
    }
    func_0018A990(p, p + 0x3B8);
    q[5] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x1D);
    return 1;
}
