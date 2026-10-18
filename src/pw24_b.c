typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00191210(void *);
extern s32 D_004C0680[2];

void func_00267750(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    ((void (*)(u8 *, u8 *))D_004C0680[p[7]])(p, p + 0x2B8);
    p[0x216] |= 0x80;
    p[0x1FF] = 2;
    func_00191210(p);
}
