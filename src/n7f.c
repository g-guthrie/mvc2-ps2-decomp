typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x0014D700 */
extern s32 D_004CAE80[5][20];
void func_0014D700(void) {
    s32 j; s32 i; for (i = 0; i < 5; i++) { for (j = 0; j < 20; j++) { D_004CAE80[i][j] = 0; } }
}
