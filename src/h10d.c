typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern void func_001757E0();
extern void func_00175670();
extern void func_001C1330();
extern void func_00336840();
extern void func_001C33E0();
extern void (*D_0045E9B0[])(u8 *);

void func_00336760(u8 *p) {
    D_0045E9B0[p[6]](p);
    if (p[0x23] == 0) {
        u8 c = p[0x21];
        if (c < 0xD) {
            u8 t = p[0x22];
            if (t == 0) {
                p[0x21] = c + 1;
                func_00336840(p);
                p[0x22] = 0x10;
            } else {
                p[0x22] = t - 1;
            }
        }
    }
}

void func_001C3350(u8 *p, u8 *q) {
    u32 t = p[7];
    p[7] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(f32 *)(q + 0x34) <= *(f32 *)(p + 0x34)) {
        *(s16 *)(p + 0x140) = 0;
    } else {
        *(s16 *)(p + 0x140) = 1;
    }
    func_001757E0(p, 0x19, 0xE);
    func_001C33E0(p, q);
}
