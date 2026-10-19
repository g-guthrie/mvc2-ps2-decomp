typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern f32 func_001AC390(u8 *, int);
extern void func_001ABF50(u8 *, u8 *);
extern void func_001757E0(u8 *, int, int);

void func_001ABE90(u8 *p, u8 *q)
{
    f32 r;
    p[7]++;
    r = func_001AC390(q, 0x38);
    if (*(f32 *)(p + 0x34) < r) {
        *(u16 *)(p + 0x140) = 1;
        *(u32 *)(p + 0x5C) = 0x40FD5555;
    } else {
        *(u16 *)(p + 0x140) = 0;
        *(u32 *)(p + 0x5C) = 0xC0FD5555;
    }
    *(u32 *)(p + 0x68) = 0;
    if (p[6] != *(u32 *)(p + 0xD0))
        func_001757E0(p, 0x17, 0xD);
    func_001ABF50(p, q);
}
