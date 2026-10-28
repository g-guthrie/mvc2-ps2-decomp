/* nq94_a: MW 3.0.3: ./try.sh src/nq94_a.c "-O3 -Op -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x34]; f32 x; } P34;

void func_002D4870(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_00126470();
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u8 *q;
    f32 k1, k2, a;
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_00126470();
        func_001757E0(p, 0x15, 0x12);
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] = *(s8 *)(p + 0x140);
        if (*(s16 *)(p + 0x1C) != 0) {
            if ((s8)p[0x539] != 0) {
                if (p[0x212] != 0) {
                } else {
                    goto calc;
                }
            } else if ((*(u16 *)(p + 0x35E) & 0x400) == 0) {
                goto calc;
            }
            *(s16 *)(p + 0x1C) = *(s16 *)((s32)p + 0x1C) - 1;
            p[6] = 2;
            *(u32 *)(p + 0x60) = 0x41AB6DB6;
            *(u32 *)(p + 0x6C) = 0xBF092492;
            switch (p[0x1E6]) {
            default:
                *(u32 *)(p + 0x5C) = 0x41FCD000;
                break;
            case 0:
                *(u32 *)(p + 0x5C) = 0xC1FCD000;
                break;
            }
            *(u32 *)(p + 0x68) = 0;
            return;
        }
      calc:
        q = *(u8 **)(p + 0x220);
        k1 = 26.66666603088379f;
        k2 = 53.33333206176758f;
        a = ((P34 *)q)->x - ((P34 *)p)->x;
        a /= k1;
        *(f32 *)(p + 0x5C) = a;
        a /= k2;
        *(f32 *)(p + 0x68) = -a;
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        *(s16 *)(p + 0x1C) = 0;
    }
}
