typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001A9B70(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    if (q[0] != 0) {
        if (q[0x425] == 0) {
            p[0] = 1;
            p[0x13C] = 1;
            if (*(s16 *)(q + 0x140) == 0) *(f32 *)(p + 0x34) = 80.0f + *(f32 *)(q + 0x34);
            else *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 80.0f;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            func_001757E0(p, 0x17, 0);
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 7;
            p[7] = 0;
        } else if (q[0x269] == 5) {
            if (q[0x1E4] == 0x1D) {
                p[0] = 1;
                p[0x13C] = 1;
                if (*(s16 *)(q + 0x140) == 0) *(f32 *)(p + 0x34) = 80.0f + *(f32 *)(q + 0x34);
                else *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 80.0f;
                *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
                func_001757E0(p, 0x17, 0);
                switch (q[0x1FD]) {
                case 5:
                    *(u32 *)(p + 0xD0) = p[6];
                    *(u32 *)(p + 0xD4) = p[7];
                    p[6] = 0xF;
                    p[7] = 0;
                    return;
                case 4:
                    *(u32 *)(p + 0xD0) = p[6];
                    *(u32 *)(p + 0xD4) = p[7];
                    p[6] = 0x11;
                    p[7] = 0;
                    return;
                }
                return;
            }
        }
    }
}
