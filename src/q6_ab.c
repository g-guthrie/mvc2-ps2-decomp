typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;

void func_00378400(u8 *p) {
    extern void func_001E7F60(u8 *);
    extern void func_00175700(u8 *);
    s16 t = *(s16 *)(p + 0x1C) - 1;
    u32 x, y;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0 || *(s8 *)(p + 0x1B3) != 0) {
        x = p[5];
        p[5] = x + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(s16 *)(p + 0x1E) += 1;
        if (*(s16 *)(p + 0x1E) >= 8) {
            *(s16 *)(p + 0x1E) = 0;
            y = p[0x21];
            y = y - 1;
            p[0x21] = y;
            if ((y & 0xFF) == 0) {
                x = p[5];
                p[5] = x + 1;
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x6C) = 0;
                *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
                return;
            }
            p[0x1B5] = 0x30;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            *(s16 *)(p + 0x1C0) = 0x1000;
        }
    }
    func_001E7F60(p);
    func_00175700(p);
}
