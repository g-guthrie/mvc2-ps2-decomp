typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004BA430[];

void func_003DB780(u8 *arr, u8 val, u32 mask) {
    s32 i = 0;
    s32 off = 0;
    do {
        u8 *d = arr + i;
        u32 *t = (u32 *)((u8 *)D_004BA430 + off);
        if (mask & *t) {
            if (*d < val) *d = val;
            mask ^= *t;
            if (mask == 0) break;
        }
        i++;
        off += 4;
    } while (i < 16);
}
