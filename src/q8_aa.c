typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001C2F70(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 c = 66.66666412353516f;
    u32 t;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (q[0x1E4] != 0x16) {
        p[7] = 4;
        return;
    }
    if (*(s16 *)(p + 0x140) == 0) {
        if (*(f32 *)(p + 0x34) <= c + *(f32 *)(q + 0x34)) {
            t = p[7];
            p[7] = t + 1;
            *(f32 *)(p + 0x34) = c + *(f32 *)(q + 0x34);
            func_001757E0(p, 0x19, 7);
        }
    } else {
        if (!(*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34) - c)) {
            t = p[7];
            p[7] = t + 1;
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - c;
            func_001757E0(p, 0x19, 7);
        }
    }
}
