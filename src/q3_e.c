struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_00175670(u8 *);
extern void func_0032E690();
extern void func_003DAA40(struct Object *);
extern void func_001BB8D0(u8 *, u8 *);
extern void func_0037D1B0(u8 *);

void func_001597D0(u8 *p) {
    *(s16 *)(p + 0x1C) += 1;
    if (*(s16 *)(p + 0x1C) > 0x1E) {
        func_003DAA40((struct Object *)p);
        return;
    }
    func_0032E690();
    *(f32 *)(p + 0x74) -= 0.03333333507f;
}

void func_0013FDA0(u8 *p) {
    switch (p[4]) {
    case 0:
        if (p[0x20] != 0) {
            f32 v;
            u32 t;
            *(f32 *)(p + 0x74) += 1.39999997616f; v = *(f32 *)(p + 0x74);
            if (!(v < 0.69999998808f)) {
                t = p[4];
                p[4] = t + 1;
                *(f32 *)(p + 0x74) = 0.69999998808f;
            }
        } else {
            f32 v;
            u32 t;
            *(f32 *)(p + 0x74) += 0.20000000298f; v = *(f32 *)(p + 0x74);
            if (!(v < 1.0f)) {
                t = p[4];
                p[4] = t + 1;
                *(f32 *)(p + 0x74) = 1.0f;
            }
        }
        break;
    case 1:
        break;
    }
}
