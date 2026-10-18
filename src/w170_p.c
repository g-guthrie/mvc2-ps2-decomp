typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



typedef struct { s32 pad0[0x1C / 4]; s32 f1C; } HP;
extern HP *D_004C2840;
extern u8 D_004BFAD8[8];
void func_001E1430(u8 *p, u8 *q) {
    extern u8 *func_001E0CC0();
    extern s32 func_00174170();
    extern void func_001E1570();
    s16 h = *(s16 *)(q + 0x434);
    s32 t;
    u8 *s0;
    u32 x;
    f32 f2, y;
    if (h >= 0x20) {
        *(u32 *)(q + 0xD4) = 0;
        goto call;
    }
    t = (D_004C2840->f1C + q[0x1B8]) & 0x7F;
    if ((t & 0xF) == 0 && h < D_004BFAD8[t >> 4] && q[0x1E4] == 0) {
        if ((s0 = func_001E0CC0(q, 2)) != 0) {
            x = (func_00174170() & 0xF) - 8;
            y = (f32)x;
            f2 = 1.6666666269302368f * y;
            if (*(s16 *)(p + 0x140) != 0) f2 = -f2;
            *(f32 *)(s0 + 0x34) = *(f32 *)(q + 0x34) + f2;
            *(f32 *)(s0 + 0x38) = 68.57142639160156f + *(f32 *)(q + 0x38);
        }
    }
    if (q[0x1F0] == 0) return;
call:
    func_001E1570(p, q);
}
