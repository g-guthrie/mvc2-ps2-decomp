typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

extern u8 *D_004C2794;
extern u64 D_00478CB0[];
extern u64 D_00478CD0[];
extern u64 D_00478CE0[];
extern u64 D_00478CF0[];
extern u64 D_00478D00[];
extern u64 D_0062BFF0[];
extern u8 D_00478C90[];
extern s32 D_0062BF84[];
extern s32 D_0062BF88[];
extern s32 D_004C2AE0;
extern s32 D_004C2AE4;

s32 func_003ED1C0(s32 a, u32 c) {
    extern void func_003DECC0();
    s32 x, y;
    switch (a) {
    case 0:
        D_00478CB0[0] = 0x3200F;
        break;
    case 1:
        D_00478CB0[0] = 0x30003;
        break;
    default:
        return 0;
    }
    x = D_0062BF84[0];
    y = D_0062BF88[0];
    D_00478CD0[0] = ((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)1 << 32);
    D_00478CE0[0] = (x << 4) | ((u64)(y << 4) << 16);
    D_00478CF0[0] = ((x + D_004C2AE4) << 4) | ((u64)((y + D_004C2AE0) << 4) << 16);
    D_00478D00[0] = D_0062BFF0[0];
    func_003DECC0(D_00478C90);
    return 0;
}
