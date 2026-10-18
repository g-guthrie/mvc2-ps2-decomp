typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* MW 3.0.3: ./try.sh src/r5_d.c "-O3 -Op -fp off -sdatathreshold 8" */

extern void func_003DDD00(void *, float);
extern s32 D_004C2B40;
extern char D_006327B0[];
void func_00417270(u16 a) {
    s32 i = a;
    func_003DDD00(D_006327B0 + (D_004C2B40 << 6), (float)(6.283185307179586 * i / 65536.0));
}
