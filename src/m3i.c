typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 a;
    u8 b;
    u8 pad;
    u8 c;
    s32 d;
} Ent;

extern Ent D_004B36E0[];
extern void func_003D7350(u8, u8, u8, u32);

void func_00148D40(u8 *p, s32 idx, s32 n) {
    Ent *e = &D_004B36E0[idx];
    s32 i;
    for (i = 0; i < n; i++) {
        func_003D7350(e->a + *(s8 *)(p + 1) * 0x35, e->b, e->c, e->d);
        e++;
    }
}
