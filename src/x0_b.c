typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G1EBCE0;
extern G1EBCE0 *D_004C2794;
extern s32 D_004C28E0;

void func_001EBCE0(u8 *p) {
    extern void func_00185490();
    extern void func_0018C4B0();
    extern void func_001757E0();
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 2);
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(f32 *)(p + 0x5C) /= 16.0f;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(f32 *)(p + 0x6C) /= 64.0f;
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xE));
}

s32 func_00324930(u8 *p) {
    extern void func_00324A00();
    extern void func_001757E0();
    u32 a = *(u16 *)(p + 0x354) & 0xC00;
    s32 c;
    f32 f;
    D_004C28E0 = *(u16 *)(p + 0x356) & 0xC00;
    if (*(s8 *)(p + 0x539) != 0) {
        a = 0xC00;
        D_004C28E0 = 0xC00;
    }
    if (a == 0) {
        p[0x20] = 0;
        func_00324A00(p);
        c = 0xC;
        if ((*(u16 *)(p + 0x360) & 0x400) != 0) c = 6;
        func_001757E0(p, 0x16, (u8)c);
        return 1;
    }
    if (a != D_004C28E0) {
        f = 5.0f;
        c = 7;
        if ((*(u16 *)(p + 0x35E) & 0x400) != 0) {
            c = 0xE;
            f = -f;
        }
        *(f32 *)(p + 0x5C) = f;
        func_001757E0(p, 0x16, (u8)c);
    }
    return 0;
}
