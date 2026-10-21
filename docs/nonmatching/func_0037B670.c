/* Unregistered candidate: cleanup helper uses its actual two inputs. */
typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
extern void func_0037B400(u8 *, u8 *);
extern int func_00175670(u8 *);


void func_0037B670(u8 *p) {
    p[0x13C] = 1;
    if (*(s16 *)(p + 0x1C) != 0) {
        s16 v;
        *(f32 *)(p + 0x118) -= 0.125f;
        func_00175670(p);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        *(f32 *)(p + 0x50) += -0.1125f;
        *(f32 *)(p + 0x54) += 0.3125f;
    } else {
        p[0x13C] = 0;
        func_0037B400(p, 0);
    }
}
