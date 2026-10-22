typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD4;
extern f32 D_004F1FD0;
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_00329100(u8 *a0) {
    extern void func_003DAA40();
    u8 *p = *(u8 **)(a0 + 0x18);
    f32 x, y, v;
    if (p[5] == 0 && p[0x1FD] == 4 && p[0x1E4] == 0x1D && p[0x169] == 0x16) {
        x = *(f32 *)(p + 0x34);
        y = *(f32 *)(p + 0x38);
        switch (p[0x168]) {
        case 4:
        case 5:
            v = *(f32 *)(p + 0x430);
            y = D_004F1FD4;
            if (v < y) {
                *(f32 *)(p + 0x34) = x;
                goto L8;
            }
            y = v;
            break;
        case 6:
        case 7:
            y = -257.1428527832031f + D_004F1FD0;
            break;
        case 8:
        case 9:
            x = 40.0f + D_004F1FC8;
            break;
        case 10:
        case 11:
            x = -40.0f + D_004F1FCC;
            break;
        }
        *(f32 *)(p + 0x34) = x;
    L8:
        *(f32 *)(p + 0x38) = y;
    } else {
        func_003DAA40(a0);
    }
}

