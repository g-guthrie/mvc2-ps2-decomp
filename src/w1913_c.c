typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w1913_c.c "-O3,p -sdatathreshold 8" */
typedef struct E45 { s32 w0; s32 w4; s32 w8; s32 wC; u8 b10; u8 b11; u8 pad12[2]; } E45;
extern E45 D_004CD170[];
extern s32 D_004CD150[4];
extern s32 D_004CD160[4];
extern u8 D_004C2724[4];
extern u8 D_004C2728[4];
void func_001E4560(void) {
    extern void func_001E46D0(s32);
    s32 i;
    for (i = 0; i < 16; i++) {
        D_004CD170[i].w4 = 0;
        D_004CD170[i].wC = 0x42B40000;
        D_004CD170[i].w8 = 0;
        D_004CD170[i].b11 = 0x5A;
        D_004CD170[i].b10 = 0x5A;
    }
    func_001E46D0(0xF5);
    for (i = 0; i < 4; i++) {
        D_004CD160[i] = 0;
        D_004C2728[i] = 0x18;
        D_004CD150[i] = 0;
        D_004C2724[i] = 0x18;
    }
}

