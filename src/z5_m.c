struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s8 D_004F7F4C[];
extern s8 D_004F7F32[];
extern s8 D_004C2198[8];
extern V3 D_00476AA0[];
extern V3 D_00476700[];

void func_003CF7C0(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern void func_0012AD00();
    u32 t;
    if (D_004F7F4C[0] != 3) {
        func_003DAA40((struct Object *)p);
        return;
    }
    *(V3 *)(p + 0x34) = D_00476AA0[D_004F7F32[0]];
    *(V3 *)(p + 0x50) = D_00476700[D_004C2198[D_004F7F32[0]]];
    t = p[4];
    if (t == 0) {
        p[4] = t + 1;
        *(s16 *)(p + 0x1E) = 0;
    }
    func_0012AD00();
}
