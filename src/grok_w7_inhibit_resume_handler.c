typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
extern u8 *func_001D45D0(u8 *, u8);
extern void func_00131AB0(u8 *, u8 *, int);
extern u8 *D_004C2794;

void func_002E6EC0(u8 *p)
{
    u8 *q = p + 0x2B8;
    u32 position[4];

    func_00175700(p);
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        *(s8 *)(p + 0x151) ^= 1;
        position[0] = 0x42855555;
        position[1] = 0x4304DB6D;
        func_001830D0(p, (f32 *)position, 3);
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }

    if ((*(s8 *)(p + 0x151) & 2) == 0) return;
    p[6]++;
    *(s8 *)(p + 0x151) ^= 2;
    func_001D45D0(p, 5);
    q[9] = 2;
    *(u16 *)(q + 0xA) = 0x1F4;
    q[8] = 0;
    q[14] = 8;
    q[15] = 0;
    func_00131AB0(p, q + 0xA, 6);
}
