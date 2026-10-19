typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00191EF0(u8 *, s32);
extern void func_001D5670(u8 *, s32, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001E3270(u8 *, s32, f32);

void residual_00192360(u8 *p)
{
    u8 id;
    p[6]++;
    *(s16 *)(p + 0x1C) = 4;
    func_00191EF0(p, p[0x22]);
    if (p[1] == 0x2E && p[0x215] == 0)
        func_001D5670(p, 4, 0);
    id = p[1];
    if (id == 0xF)
        func_001E3210(p, 0x24);
    else if (id == 0x33)
        goto same;
    else if (id == 0x2E) {
    same:
        func_001E3210(p, 0x22);
        func_001E3270(p, 0x22, 3.0f);
    }
}
