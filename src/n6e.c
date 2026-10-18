typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))


extern double func_00119058(float);
void func_00297120(u8 *a0) {
    f32 *f = (f32 *)a0;
    f32 v = f[0x18];
    f32 w;
    f[0xE] += v;
    w = f[0x1B]; w = f[0x18] + w;
    f[0x18] = w;
    if (func_00119058(v) > 0.0 && func_00119058(w) < 0.0) {
        ((u32 *)f)[0x1B] = 0xBFCDB6DB;
    }
}
