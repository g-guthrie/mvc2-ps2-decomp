typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C283C;
extern void func_0033AD60();
extern void func_00170E60(s32 a, s32 b, s32 c, s32 d, void *e, void *f);


typedef struct { u8 a[6]; u8 pad[2]; u8 b[6]; } G;
extern G D_004C2680;
extern u32 D_004F4420[];
extern void func_0010E020(s32 a, s32 b, G *c);

void func_0016ED00(void) {
    s32 i = 0;
    s32 off = 0;
    D_004C2680.a[0] = 0;
    D_004C2680.b[0] = 0;
    D_004C2680.a[1] = 1;
    D_004C2680.b[1] = 0;
    D_004C2680.a[2] = 0xFF;
    D_004C2680.b[2] = 0;
    D_004C2680.a[3] = 0xFF;
    D_004C2680.b[3] = 0;
    D_004C2680.a[4] = 0xFF;
    D_004C2680.b[4] = 0;
    D_004C2680.a[5] = 0xFF;
    D_004C2680.b[5] = 0;
    do {
        u32 *e = (u32 *)((u8 *)D_004F4420 + off);
        e[0] = 0;
        e[1] = 0;
        func_0010E020(i, 0, &D_004C2680);
        i++;
        off += 8;
    } while (i < 2);
}
