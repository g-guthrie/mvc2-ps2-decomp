typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern void *D_004C2838;
extern void func_00162F50(u8 *);
extern void *func_003DA750(void *, s32, s32);

void func_00162DF0(V3 *pos, s32 flag, s32 type, s32 unused, u8 k) {
/*B*/
    u8 *o;
    u8 sel = (k == 9) ? 0x1D : 0x41;
    if ((o = func_003DA750(0, sel, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_00162F50;
        *(V3 *)(o + 0x34) = *pos;
        *(u32 *)(o + 0xD0) = 0x800419;
        switch (type) {
        case 9:
            *(s32 *)(o + 0x48) = flag ? 0x8000 : 0;
            break;
        case 10:
            *(s32 *)(o + 0x48) = flag ? 0xA000 : 0xE000;
            break;
        case 11:
            *(s32 *)(o + 0x48) = 0xC000;
            break;
        case 12:
            *(s32 *)(o + 0x48) = flag ? 0xE000 : 0xA000;
            break;
        case 13:
            *(s32 *)(o + 0x48) = flag ? 0 : 0x8000;
            break;
        case 14:
            *(s32 *)(o + 0x48) = flag ? 0x2000 : 0x6000;
            break;
        case 15:
            *(s32 *)(o + 0x48) = 0x4000;
            break;
        case 16:
            *(s32 *)(o + 0x48) = flag ? 0x6000 : 0x2000;
            break;
        }
        *(s16 *)(o + 0xCC) = 0x5E;
        *(void **)(o + 0x84) = D_004C2838;
    }
/*E*/
}
