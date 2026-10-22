typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef void (*Fn_002CB820)(u8 *);
extern Fn_002CB820 D_004C0EA8[64];
extern void func_0018C6E0(void *);
void func_002CB820(u8 *p) {
    s16 v = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = v;
    *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = v;
    func_0018C6E0(p);
    D_004C0EA8[p[0x20B] & 0x3F](p);
}
