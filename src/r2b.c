struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2998;
extern void (*D_004642E0[])(u8 *);
extern void (*D_004642F0[])(u8 *);
extern s8 *D_004C2840;
extern void func_003DAA40(struct Object *);

/* Recipe 2: real body of the callee func_00157250. */
static void func_00157250(u8 *p) {
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 60) += *(float *)(p + 100);
}

void func_00157290(u8 *p) {
    func_00157250(p);
    *(f32 *)(p + 0x50) -= 0.03333333507180214f;
    *(f32 *)(p + 0x54) -= 0.03333333507180214f;
    *(f32 *)(p + 0x58) -= 0.03333333507180214f;
    if (D_004C2840[0x91]) {
        func_003DAA40((struct Object *)p);
    } else {
        if (*(s16 *)(p + 0x1C) >= 0xF) {
            func_003DAA40((struct Object *)p);
        } else {
            *(s16 *)(p + 0x1C) += 1;
        }
    }
}
