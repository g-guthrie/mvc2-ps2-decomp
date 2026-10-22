typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y; } TabA;
extern TabA D_0044BA90[];
extern u8 *D_004C26D8;

extern void func_00175670(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001AFC90(u8 *);
void func_001AEEA0(u8 *a) {
    u8 *p = *(u8 **)(a + 0x18);
    s32 i;
    f32 f;
    a[0x24] = *(s8 *)(p + 0x24);
    switch (p[0x20D]) {
    case 0: i = 0; break;
    case 1: i = 1; break;
    case 2: i = 2; break;
    case 3: default: i = 3; break;
    }
    a[0x13C] = 1;
    if (p[0x1E6] != 0) {
        f = D_0044BA90[i].x;
    } else {
        f = -D_0044BA90[i].x;
    }
    *(f32 *)(a + 0x34) = *(f32 *)(p + 0x34) + f;
    *(f32 *)(a + 0x38) = *(f32 *)(p + 0x38) + D_0044BA90[i].y;
    func_00175670(a);
    if (*(s8 *)(D_004C26D8 + 5) == 0 || (p[0x1E4] == 0x15 && p[0x1FD] == 4)) {
        func_001E3210(a, 0x27);
        func_001AFC90(a);
    }
}
