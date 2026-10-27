struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z, w; } V4b;
extern s8 D_004F7F30;
extern s8 D_004F7F32;
extern V4b D_00476B70;
extern V4b D_00476B60;

void func_003D0E10(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern void func_0012AD00();
    if (D_004F7F30 != 2) {
        func_003DAA40((struct Object *)p);
        return;
    }
    p[0x13C] = 0;
    *(V4b *)(p + 0x74) = D_00476B70;
    if (D_004F7F32 == p[0x20]) {
        p[0x13C] = 1;
        *(V4b *)(p + 0x74) = D_00476B60;
        if (p[4] == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00();
    }
}

