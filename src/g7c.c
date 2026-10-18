typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00178F20();

void func_001943B0(u8 *a0, u8 *a1) {
    u8 *a2 = *(u8 **)(a1 + 0x1DC);
    u8 *q = a1 + 0x2B8;
    if (*(s8 *)(a2 + 0x211) != 0 || a0[0x21] >= 0x80) {
        u32 t = a0[5];
        a0[5] = t + 1;
    } else {
        if (*(s8 *)(q + 0x1B) == 0) func_00178F20(a0, a2);
    }
}

extern u8 D_004CAB5A, D_004CAB5B, D_004CAB0A, D_004CAB0B, D_004CAB7A, D_004CAB7B, D_004CAB32, D_004CAB33;

s32 func_0012E560(void) {
    if (D_004CAB5A != D_004CAB5B) return 0;
    if (D_004CAB0A != D_004CAB0B) return 0;
    if (D_004CAB7A != D_004CAB7B) return 0;
    return !(D_004CAB32 != D_004CAB33);
}
