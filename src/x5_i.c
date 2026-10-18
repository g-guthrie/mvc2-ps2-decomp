typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { V3 v; u8 pad[24]; } TV;
extern s16 D_0043EA50[];
extern TV D_0043EA60[];
extern u32 D_0043EAD0[];
extern s32 D_004C2834;
extern u8 *func_003DA750();
extern void func_00135230();
extern void func_001352A0();
void func_00135150(s32 n) {
    u8 *o;
    func_00135230(n);
    o = func_003DA750(0, 0xD, 1);
    if (o != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = func_001352A0;
        *(s16 *)(o + 0xCC) = *(s16 *)((u8 *)D_0043EA50 + n * 4);
        *(s32 *)(o + 0x84) = D_004C2834;
        *(s32 *)(o + 0xD0) = 5;
        *(V3 *)(o + 0x34) = D_0043EA60[n].v;
        *(u32 *)(o + 0x44) = D_0043EAD0[n];
        o[0x20] = n;
        *(u32 *)(o + 0x74) = 0x3F800000;
        if (o[0x20] == 0) {
            *(s32 *)(o + 0xD4) = 0x50;
        } else {
            *(s32 *)(o + 0xD4) = 0;
        }
    }
}
