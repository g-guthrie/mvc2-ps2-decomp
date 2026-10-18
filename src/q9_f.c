typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004B8728[];
typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;
void func_0039C790(u8 *p) {
    extern void func_001757E0();
    extern void func_0039C8B0();
    u32 t = p[4]; p[4] = t + 1;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    *(s16 *)(p + 0x1C) = -1;
    func_001757E0(p, 0x17, D_004B8728[p[0x95]]);
    func_0039C8B0(p);
}


static void func_003AE2C0(u8 *p) { *(u32 *)(p + 0x100) = 0; }
static void func_003AE370(void) { }

void func_003AE390(u8 *p) {
    extern void func_001757E0();
    u32 t = p[4]; p[4] = t + 1;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x24] = 0;
    *(u32 *)(p + 0xD0) = 0;
    func_003AE2C0(p);
    func_003AE370();
    p[0x168] = 2;
    if (p[0x21] != 0) p[0x168] = 4;
    func_001757E0(p, 0x13, p[0x168]);
}


void func_003ADA70(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    u32 t = p[4]; p[4] = t + 1;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    *(s16 *)(p + 0x1E) = 0;
    p[0x22] = 0;
    if (p[0x21] == 0) p[0x24] = 0; else p[0x24] = 7;
    func_001757E0(p, 0x12, p[0x21] + 1);
}

void func_001B9E30(u8 *p) {
    extern void func_001754A0();
    extern void func_001B9F60();
    u8 *q;
    u32 t = p[4]; p[4] = t + 1;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    *(W31 *)(p + 0xEC) = *(W31 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -8;
    if (p[0x20] != 0) {
        func_001754A0(p, 0x1B, 0x14);
    } else {
        func_001754A0(p, 0x1B, 0x11);
    }
    func_001B9F60(p);
}
