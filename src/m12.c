typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

extern u8 *D_004C25D4;
extern s32 func_00125AF0(s32 a);
extern s32 func_00125C90(s32 a);
s32 func_00125F40(void) {
    if (D_004C25D4[0x25C] != 0) { return func_00125AF0(2); }
    return func_00125C90(2);
}
typedef struct { s16 v; s16 pad; } S16P;
extern S16P D_00445410[];
extern f32 D_004453B0[];
extern u32 D_004C2838;
extern void func_003DAA40();

extern s32 func_00175700(u8 *p);
extern void func_001843A0(u8 *p);
extern void func_001E3710(u8 *p, s32 a);
extern u8 *D_004C2794;

void func_001F8690(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
    if (p[0x1FC] == 2 && *(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_001E3710(p, 0x16);
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        {
            s16 *q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
            q[0x7C / 2] = q[0x7C / 2] + 1;
        }
    }
}

extern void func_002F51F0(u8 *p, s32 b);

void func_002F58D0(u8 *p, s32 b) {
    u32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6] = 0;
        func_002F51F0(p, b);
        return;
    }
    v = p[0x15B];
    if (v != 0) {
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        {
            s16 *q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
            q[0x7C / 2] = q[0x7C / 2] + 1;
        }
        p[0x15B] = 0;
    }
}

extern u8 *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern void func_003DA6F0(s32 a);
extern s32 func_0012E560();

