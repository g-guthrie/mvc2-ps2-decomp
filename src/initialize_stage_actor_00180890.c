/* Initialize one stage actor, its indexed start coordinates, and child pointers. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern const f32 data_f32_004ACD30[6];
extern void func_00169BE0(u8 *);
extern void func_00180A30(u8 *);

void func_00180890(u8 *p)
{
    *(s8 *)(p + 7) = 0;
    *(s8 *)(p + 6) = 0;
    *(s8 *)(p + 5) = 0;
    *(s8 *)(p + 4) = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(s16 *)(p + 0x1C) = 0;
    p[0x21] = 0;
    p[0x20] = 0;
    p[0x22] = 0;
    *(u32 *)(p + 0x48) = 0;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x64) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x70) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0xDC) = 0;
    *(u32 *)(p + 0xD8) = 0;
    *(u32 *)(p + 0xD4) = 0;
    *(u32 *)(p + 0xD0) = 0;
    p[0x24] = ((s8 *)p)[0x1B8] + 1;
    p[0x31] = 0;
    *(s8 *)(p + 0x13D) = -1;

    *(f32 *)(p + 0x34) = data_f32_004ACD30[p[2] * 3];
    *(f32 *)(p + 0x38) = data_f32_004ACD30[p[2] * 3 + 1];
    *(f32 *)(p + 0x3C) = data_f32_004ACD30[p[2] * 3 + 2];
    *(f32 *)(p + 0x430) = *(f32 *)(p + 0x38);
    *(u32 *)(p + 0xFC) = 0x3FD55555;
    *(u32 *)(p + 0x100) = 0x40092492;
    *(u32 *)(p + 0x118) = 0x3F800000;
    {
        u8 mode = (u8)(((s8)p[2]) ^ 1);
        *(u8 *)(p + 0x1E6) = mode;
        *(u16 *)(p + 0x140) = mode;
    }
    *(u8 **)(p + 0x41C) = D_004C2794 + p[2] * 2 + 0x56;
    *(u8 **)(p + 0x420) = D_004C2794 + p[2] + 0x5A;

    if (p[0x425] == 0) {
        **(u16 **)(p + 0x41C) = 0;
        **(u8 **)(p + 0x420) = 1;
    }
    p[0x424] = 0;
    func_00169BE0(p);
    func_00180A30(p);
}
