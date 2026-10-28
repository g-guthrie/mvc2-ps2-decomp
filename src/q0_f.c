typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(void *, s32, s32);
extern s32 func_00175700(void *);
extern int func_00174170(void);
extern s32 func_00186A60(void *, s32);
void func_00262070(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch ((s8)p[0x4DD]) {
    case 0:
        p[0x1FD] = 2;
        p[0x1B7] = 0;
        break;
    case 1:
        p[0x1FD] = 7;
        p[0x1B7] = 0;
        break;
    case 2:
        p[0x1FD] = 8;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}
