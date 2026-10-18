typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0013C7A0(u8 *p) {
    switch (p[4]) {
    case 0:
        break;
    case 1:
        p[4] = p[4] + 1;
    case 2:
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + 0x280;
        break;
    }
}

#pragma padloop on
extern void func_00143DA0(void);
extern void func_00144260(s32);
void func_00143D50(void) {
    s32 i;
    func_00143DA0();
    i = 0;
    do { func_00144260(i); } while (++i < 7);
}
#pragma padloop off

extern s8 *D_004C2938;
void func_00346080(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        ((s16 *)p)[14] = 2;
        *D_004C2938 = *D_004C2938 + 1;
        if (*D_004C2938 >= 8) *D_004C2938 = 5;
    }
}
