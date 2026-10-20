typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/w190_h.c sn 8 */

extern s32 D_004C2458;
extern u8 D_00487B60[];
extern void func_004093E8(u8 *);

void func_00409698(void) {
    s32 i, one;
    u32 row_address;
    if (--D_004C2458 == 0) {
        one = 1;
        row_address = (u32)D_00487B60;
        for (i = 7; i >= 0; i--) {
            if (*(s8 *)row_address == one) func_004093E8((u8 *)row_address);
            row_address += 0x44;
        }
    }
}
