typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

#define SETCMD(cmd) \
    p[0x1B5] = cmd; \
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0; \
    *(s32 *)(p + 0x1D8) = 0; \
    offset = p[2] * 2; \
    offset += (u32)D_004C2794; \
    ++*(s16 *)(offset + 0x7C);

void func_002A1E20(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    u32 offset;
    switch (p[0x1FC]) {
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (p[6] != 0) {
            switch (*(s8 *)(p + 0x151)) {
            case 1:
                p[0x151] = 0;
                SETCMD(0x1A)
                break;
            case 2:
                p[0x151] = 0;
                SETCMD(0x1B)
                break;
            }
        } else {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                SETCMD(0x19)
            }
        }
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}
