typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_00185490();
extern void func_0018C4B0(void *p, s32 a);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001B3E30(void *p, s32 a, s32 b);
extern void func_00183D10(void *p);
extern u8 *D_004C2794;
void func_00265B30(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 5);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    (*(s16 **)&D_004C2794)[p[2] + 0x3E]++;
    *(s16 *)(p + 0x1C) = 0x3C;
    func_001757E0(p, 0xF, 4);
    func_001B3E30(p, 0xA, 3);
    func_00183D10(p);
}

typedef struct { u8 pad[0x2B8]; u8 b[0x20]; } S2E4;
extern void func_002E7700();
extern void func_002E4D60(void *p);
extern void func_002E4ED0(void *p);
extern u8 *D_004C2840;
void func_002E4CB0(S2E4 *p) {
    u8 *s = p->b;
    if (*((s8 *)p + 0x2C1) != 0 && *((u8 *)p + 0x1FC) == 2) {
        func_002E7700();
        if (*(u16 *)((*((u8 *)p + 2) << 1) + (u32)D_004C2840 + 0x106) != 0) {
            s[0x11] = 1;
        }
        return;
    }
    if (*((u8 *)p + 0x212) == 0) {
        func_002E4D60(p);
        s[0x11] = 0;
    } else {
        func_002E4ED0(p);
        s[0x11] = 0;
    }
}
