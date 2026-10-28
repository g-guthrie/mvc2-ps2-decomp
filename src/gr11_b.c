typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 b0; u8 pad[0x35]; s8 f36[4]; } G94;
extern G94 *D_004C2794;
extern u8 *D_004C2840;

void func_0018FCA0(u8 *p, u8 *q) {
    extern void func_0018F9E0();
    extern void func_0018FEB0(u8 *);
    extern void func_0016CE90();
    extern void func_00190C60(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00190540(u8 *, u8 *);
    extern void func_001902F0(u8 *);
    if (D_004C2794->b0 != 4 || *(s16 *)(p + 0x434) == 0) return;
    func_0018F9E0(p, q);
    if (*(s16 *)(p + 0x434) <= 0 && *(s8 *)(D_004C2840 + 0xAA) != 0) {
        *(s16 *)(p + 0x434) = 1;
        if (*(s16 *)(p + 0x438) <= 0) *(s16 *)(p + 0x438) = 1;
    }
    if (*(s16 *)(p + 0x434) <= 0) {
        if (p[0x1F0] == 0) {
            p[0x1F0] = 0xFF;
            func_0018FEB0(p);
            func_0016CE90();
            if (D_004C2794->f36[p[2]] < 3) func_00190C60(p, 0);
            func_001E3210(p, 0);
        }
    }
    func_00190540(p, q);
    func_001902F0(p);
}
