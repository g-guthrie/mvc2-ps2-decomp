typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_00175670();
extern void func_001CE9E0();

void func_001CE650(u8 *p) {
    if (p[5] == 0) {
        u32 t;
        f32 f;
        if (*(s8 *)(*(u8 **)(p + 0x18) + 0x151) == 0) {
            p[0x13C] = 1;
            return;
        }
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1E) = 0x3C;
        f = (*(s16 *)(p + 0x140) != 0) ? -3.3333332538604736f : 3.3333332538604736f;
        *(f32 *)(p + 0x5C) = f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x60) = 12.857142448425293f;
        *(f32 *)(p + 0x6C) = -0.5357142686843872f;
    }
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v < 0) {
            func_001CE9E0(p);
            return;
        }
    }
    if (*(s16 *)(p + 0x1E) > 0x28) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = (D_004C2840[0x1C] & 1) ^ p[2];
    }
}
