typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00416490(u8 *p) {
    extern s32 func_004166F0(u8 *);
    s32 *arr = *(s32 **)(p + 0x14);
    s32 n = func_004166F0(p);
    u8 *h = *(u8 **)(p + 8);
    u32 k = (h[0x12] << 8) | h[0x13];
    s32 i; s32 j; s32 t;
    switch (k) {
    case 0x4104:
    case 0x4204:
    case 0x4304:
    case 0x105:
    case 0x205:
    case 0x305:
        for (i = 0; i < n; i++) {
            s32 m = i & 0x1F;
            if (m >= 8 && m < 16) {
                j = i + 8;
                t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
        break;
    default:
        break;
    }
}
