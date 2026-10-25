typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Both effect paths consume the complete three-float position. */
typedef struct { f32 x, y, z; } V3;
extern void func_00380160(void *, V3 *, s32, s32);
void func_003801F0(void *a, V3 *b, s32 c) {
    u32 i;
    for (i = 0; (u8)i < 6; i = (i + 1) & 0xFF) func_00380160(a, b, c, i);
}
extern void func_003AE900();
extern void (*jtbl_00473C30[])(u8 *, u8 *);
void func_003AEEA0(u8 *p, u8 *q) {
    if (p[0x20] == 0) {
        u8 *c = p;
        s32 i = 0;
        while (i < *(s8 *)(q + 0x28) + 3) {
            c = *(u8 **)(c + 0xC);
            if (*(void **)(c + 0x10) != func_003AE900) break;
            *(s16 *)(c + 0x1C) = 0;
            i++;
            c[0x13C] = 0;
        }
    }
    jtbl_00473C30[p[0x20]](p, q);
}
typedef struct { u8 x[12]; } E;
extern s16 *D_00443C70[];
extern E *D_00443CF0[];
extern u8 D_004D17C9;
extern void func_00149D70(u32, s32, E *);
void func_00149AE0(void) {
    u32 c = D_004D17C9; E *b; s16 *a; a = D_00443C70[c]; b = D_00443CF0[c]; while (*a != -1) { func_00149D70(c, *a++, b++); }
}
