typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044FED0[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990();
extern void func_00186A60(void *p, s32 a);
s32 func_001FC750(u8 *p) {
    if (func_00189310(p, D_0044FED0, p + 0x3C0) == 0) return 0;
    if (*(s8 *)(p + 0x1E8) != 0) {
        if (p[0x210] == 0) return 0;
    }
    p[0x1E8] = 1;
    func_0018A990(p, p + 0x3C0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xF;
    func_00186A60(p, 0x15);
    return 1;
}

extern s32 func_00174170();
extern void (*D_00458C40[])(void *);
void func_002AD360(u8 *p) {
    u8 *q;
    u32 t;
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        q = *(u8 **)(p + 0x220);
        if (q[1] == p[1]) {
            if (q[6] == 0) {
                if (func_00174170() & 1) {
                } else {
                    p[7] = 5;
                }
            } else {
                if (q[7] < 5) p[7] = 5;
            }
        }
    }
    D_00458C40[p[7]](p);
}
