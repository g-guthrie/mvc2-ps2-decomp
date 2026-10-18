typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 D_004C27A4;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00354AB0(u8 *);
extern void func_0039FD90(u8 *);
extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_002CFA20(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_001843A0(u8 *);
extern s32 func_0016A1F0(u8 *, s32);
extern s32 func_0016A130(u8 *, s32, s32);
extern void func_0015D010(u8 *, u32 *);

void func_0039FC80(u8 *p) {
    u32 i = 0;
    do {
        u8 *o = func_003DA750(0, 1, 0);
        if (o != 0) {
            *(void **)(o + 0x10) = func_0039FD90;
            *(u8 **)(o + 0x18) = p;
            *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
            o[7] = 0;
            o[0x20] = i;
            o[1] = p[1];
            *(u16 *)(o + 0x26) = 0x2A02;
        }
        i++;
    } while (i < 8);
}
