typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
typedef struct { u8 pad[0x34]; V3 pos; u8 pad2[0x10]; f32 f50, f54; } E;
extern GA *D_004C2794;

void func_00383710(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u32 t;
    f32 v;
    if ((*(u8 **)(p + 0x18))[5] != 0) {
        p[0x13C] = 0;
        t = p[4];
        p[4] = t + 1;
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    v = ((E *)(*(u8 **)(p + 0x18)))->f50 * -176.6666565f;
    if (*(s16 *)(p + 0x140) != 0) v = -v;
    ((E *)p)->pos.x += v;
    ((E *)p)->pos.y += 120.0f * ((E *)(*(u8 **)(p + 0x18)))->f54;
    if (p[5] == 0) {
        s16 c;
        func_00175700(p);
        c = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = c;
        if (c <= 0) {
            s32 n;
            *(s16 *)(p + 0x1C) = 0x10;
            n = p[7];
            p[7] = n + 1;
            p[0x1B5] = ((n + 1) & 0xFF) % 3 != 0 ? 0x3C : 0x3B;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        if (*(u16 *)(*(u8 **)(p + 0x18) + 0x168) != *(u16 *)(p + 0x1E)) {
            t = p[5];
            p[5] = t + 1;
            t = p[0x1B5];
            p[0x1B5] = t | 0x80;
            func_001757E0(p, 0x17, 0x11);
        }
        func_001E7F60(p);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
