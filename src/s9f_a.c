typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef struct { u8 b0; } G94;
extern G94 *D_004C2794;
void func_0018FC10(u8 *p, u8 *q) {
    extern void func_0018F9E0();
    extern void func_00190540(u8 *, u8 *);
    extern void func_001902F0(u8 *);
    if (D_004C2794->b0 != 4 || *(s16 *)(p + 0x434) == 0) return;
    func_0018F9E0(p, q);
    if (*(s16 *)(p + 0x434) <= 0) {
        *(s16 *)(p + 0x438) = 1;
        *(s16 *)(p + 0x434) = 1;
    }
    func_00190540(p, q);
    func_001902F0(p);
}
