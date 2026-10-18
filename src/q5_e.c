typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 a; u8 b; } T2;
extern T2 D_004B1220[];

void func_00137140(u8 *p, u32 idx) {
    switch (D_004B1220[(u8)idx].a) {
    case 0: *(u32 *)(p + 0x44) = 0xE402; break;
    case 1: *(u32 *)(p + 0x44) = 0xEC02; break;
    case 2: *(u32 *)(p + 0x44) = 0xF402; break;
    case 3: *(u32 *)(p + 0x44) = 0xFC02; break;
    case 4: *(u32 *)(p + 0x44) = 0x3FF; break;
    case 5: *(u32 *)(p + 0x44) = 0xBFF; break;
    case 6: *(u32 *)(p + 0x44) = 0x13FF; break;
    case 7: *(u32 *)(p + 0x44) = 0x1BFF; break;
    }
}
