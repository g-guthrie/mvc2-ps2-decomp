typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

/* Real body of the leaf (matches retail at 0x00299010); kept static so the
   caller sees that it preserves $a0. */
static void func_00299010(u8 *p) {
    int command = p[0x15b];
    if (command) {
        unsigned int offset;
        p[0x1b5] = command;
        p[0x1b2] = *(unsigned short *)(p + 0x1c0) = 0;
        *(int *)(p + 0x1d8) = 0;
        offset = p[2] * 2; offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7c);
        p[0x15b] = 0;
    }
}

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
void func_00299400(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_00299010(p);
    if (*(s8 *)(p + 0x151) == 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        func_00186A20(p);
    }
}
