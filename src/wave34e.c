typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00175700(void);
void func_001757E0(u8 *a, s32 b, s32 c);
void func_003C1530(u8 *a);
void func_003C15F0(u8 *a, u8 *b);
void func_003C12D0(u8 *a, s32 b, s32 c);
void func_003C17A0(u8 *a, u8 *b) {
    func_003C1530(a);
    func_003C15F0(a, b);
    func_00175700();
    if (--*(s16*)(a + 0x1C) == 0) {
        u32 t = a[5];
        a[5] = t + 1;
        func_001757E0(a, 0x16, 0x17);
        func_003C12D0(a, 9, 0);
    }
}

