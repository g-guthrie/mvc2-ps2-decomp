typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[49]; } S1A;
typedef struct { f32 x, y, z; } V3;

void func_001A2200(u8 *a, u8 *b) {
    extern void func_00185960();
    u8 *last;
    s32 i;
    s32 n = *(s16 *)(a + 0x1E);
    u8 *cur = a;
    i = 0;
    if (0 < n) do {
        last = cur;
        *(S1A *)(cur + 0xEC) = *(S1A *)(b + 0xEC);
        cur[0x13C] = 1;
        cur[2] = b[2];
        cur[1] = b[1];
        *(f32 *)(cur + 0x50) = *(f32 *)(b + 0x50);
        *(f32 *)(cur + 0x54) = *(f32 *)(b + 0x54);
        cur[0x1B7] = b[0x1B7];
        cur[0x1B8] = b[0x1B8];
        *(s8 *)(cur + 0x30) = *(s8 *)(b + 0x30);
        *(V3 *)(cur + 0x50) = *(V3 *)(b + 0x50);
        *(s8 *)(cur + 0x24) = *(s8 *)(b + 0x24);
        *(s8 *)(cur + 0x24) = 7;
        *(V3 *)(cur + 0x34) = *(V3 *)(b + 0x34);
        cur = *(u8 **)(cur + 0xC);
        i++;
    } while (i < n);
    func_00185960(b, last);
    *(s8 *)(last + 0x16A) = -1;
}
