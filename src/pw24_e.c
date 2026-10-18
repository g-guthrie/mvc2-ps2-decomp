typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x540];
    s8 f540;
    u8 pad1[0x5B8 - 0x541];
} S5B8;
extern S5B8 D_004F20B0[];
extern void func_001E3D00();

void func_0012EFB0(void) {
    s8 buf[8];
    s32 j, i;
    for (i = 0; i < 6; i++) {
        buf[i] = i;
        for (j = 0; j < i; j++) {
            if (D_004F20B0[i].f540 == D_004F20B0[j].f540) {
                buf[i] = j;
                break;
            }
        }
    }
    func_001E3D00(buf);
}
