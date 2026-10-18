typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef long long s64;
typedef unsigned long long u64;


extern s32 D_00478DF0[];
extern s32 D_004C2AAC;
void func_003EFF10(s32 n, u32 type, u8 *p, s32 *src)
{
    extern void func_003F0070();
    extern void func_003F00E0();
    s32 stride = D_00478DF0[type];
    s32 i;
    switch (type) {
    case 0:
        i = 0; if (i < n) {
 do {
            func_003F0070(*src, p + 0x40, p + 0x30);
 i++;
 p += stride;
 src++;
 } while (i < n);
 }
        break;
    case 1:
        break;
    case 2:
        i = 0; if (i < n) {
 do {
            func_003F0070(*src, p + 0x40, p + 0x30);
 i++;
 p += stride;
 src++;
 } while (i < n);
 }
        break;
    case 3:
        i = 0; if (i < n) {
 do {
            func_003F0070(*src, p + 0x40, p + 0x30);
 i++;
 p += stride;
 src++;
 } while (i < n);
 }
        break;
    case 4:
        break;
    case 5:
        i = 0; if (i < n) {
 do {
            func_003F00E0(*src, p + 0x40, p + 0x30, D_004C2AAC, p + 0x60, p + 0x50);
 i++;
 p += stride;
 src++;
 } while (i < n);
 }
        break;
    }
}
