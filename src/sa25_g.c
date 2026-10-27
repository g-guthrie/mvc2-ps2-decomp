typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_001E0EA0(u8 *p, u8 *q) {
    extern void func_0015B200(u8 *, V3 *, s32, s32);
    extern void func_003CDB90(u8 *, u32);
    extern void func_001E3710(u8 *, s32);
    extern u8 *func_001E0CC0(u8 *, u32);
    extern void func_001E1570(u8 *, u8 *);
    V3 vec;
    s16 h;
    u32 t;
    u32 i;
    u32 m;
    u8 *o;
    h = *(s16 *)(p + 0x1E);
    if (h != 0) {
        h = h - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h <= 0) {
            *(s16 *)(p + 0x1E) = 0;
            vec = *(V3 *)(p + 0x34);
            vec.y += 17.14285659790039f;
            func_0015B200(p, &vec, 1, 8);
            i = 0;
            m = 0;
            do {
                func_003CDB90(p, m | 0x80000001);
                i++;
                m += 0x100;
            } while (i < 8);
            func_001E3710(p, 0x49);
        }
    }
    if (*(s16 *)(p + 0x1C) < 0x3C) {
        p[0x13C] = 1;
        if ((*(s16 *)(p + 0x1C) & 1) != 0) p[0x13C] = 0;
    } else {
        t = p[0x23] + 0x20;
        p[0x23] = t;
        if ((t & 0xFF) == 0) {
            o = func_001E0CC0(q, 2);
            if (o != 0) {
                *(u32 *)&vec.x = 0x42055555;
                if (*(s16 *)(p + 0x140) != 0) vec.x = -vec.x;
                *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + vec.x;
                *(u32 *)(o + 0x38) = 0x41892492;
            }
        }
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) func_001E1570(p, q);
}
