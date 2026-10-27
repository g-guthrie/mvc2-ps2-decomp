struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3c;
extern s8 D_004F7F4C[];
extern s8 D_004F7F31[];
extern s8 D_004C2190[8];
extern V3c D_00476800[];
extern V3c D_00476700[];

void func_003CE8B0(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern void func_0012AD00();
    if (D_004F7F4C[0] != 2) {
        func_003DAA40((struct Object *)p);
        return;
    }
    *(V3c *)(p + 0x34) = D_00476800[D_004F7F31[0]];
    *(V3c *)(p + 0x50) = D_00476700[D_004C2190[D_004F7F31[0]]];
    if (p[4] == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1E) = 0;
    }
    func_0012AD00();
}

