typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u32 D_004BA430[];

void func_003DB8E0(u8 *a) {
    s16 i;
    for (i = 0; i < 24; i++) {
        if (*(u32 *)(a + 8) & D_004BA430[i]) {
            u8 *p = a + i * 2 + 0x48;
            if (*p != 0xFF) *p = *p + 1;
        } else {
            *(s16 *)(a + i * 2 + 0x48) = 0;
        }
    }
}
