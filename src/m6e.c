typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 (*D_0045E940[])(void *);
s32 func_00334F00(u8 *p) {
    if (D_0045E940[p[6]](p)) {
        p[6] = 0;
        return 1;
    }
    return 0;
}

extern void func_001757E0(void *, s32, s32);
extern s32 func_00175700(void *);
extern void func_001DB2E0(void *);
void func_001DB260(u8 *p) {
    u32 s = p[5];
    u8 *o = *(u8 **)(p + 0x18);
    if (s == 0) {
        if (*(u16 *)(o + 0x168) == *(u16 *)(p + 0x1C)) {
        } else {
            p[5] = s + 1;
            func_001757E0(p, 0x17, 9);
        }
        func_00175700(p);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_001DB2E0(p);
        }
    }
}
