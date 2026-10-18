typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00338100(int);

typedef float f32;
extern void func_003DAA40();
extern void func_0032E690();
void func_001553B0(u8 *a0) {
    *(s16*)(a0+0x1C) += 1;
    if (*(s16*)(a0+0x1C) > 0x1E) {
        func_003DAA40();
    } else {
        func_0032E690();
        *(f32*)(a0+0x74) -= 0.01666666754f;
    }
}

void func_0033EF10(u8 *a0) {
    f32 t;
    *(f32*)(a0+0x50) += 1.0f;
    *(f32*)(a0+0x58) += 1.0f;
    t = (*(f32*)(a0+0x78) -= 0.05f);
    *(f32*)(a0+0x80) = t;
    *(f32*)(a0+0x7C) = t;
    if (*(f32*)(a0+0x78) <= 0.0f) func_003DAA40();
}
