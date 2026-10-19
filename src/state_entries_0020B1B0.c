typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0018C4B0(void *, int);
extern void func_00185490(void *);
extern void func_00183D10(void *);
extern int func_001757E0(void *, int, int);

void func_0020B1B0(u8 *p) {
    p[6]++;
    func_0018C4B0(p, 4);
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 20;
    func_00183D10(p);
    func_001757E0(p, 0x15, 2);
}
