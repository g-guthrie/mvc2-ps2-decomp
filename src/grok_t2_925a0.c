typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00184540(u8 *);
extern void func_00191F50(u8 *);

void func_001925A0(u8 *p)
{
    if (p[6] == 0) {
        f32 x;
        f32 z;
        p[6] = p[6] + 1;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        x = 13.333333015441895f;
        z = 0.3125f;
        if ((p[0x22] & 3) == 1) {
            func_001757E0(p, 20, 3);
        } else {
            x = -x;
            z = -z;
            func_001757E0(p, 20, 2);
        }
        if (p[0x1E6] != 0) {
            x = -x;
            z = -z;
        }
        *(f32 *)(p + 0x5C) = x;
        *(f32 *)(p + 0x68) = z;
    } else {
        if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_00184540(p);
        } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00191F50(p);
        }
    }
}
