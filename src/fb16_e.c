typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { unsigned char prefix[0x38]; float y; unsigned char reserved[0x3f4]; float floor; } HeightState;
static void func_00191F50(unsigned char *owner) {
 HeightState *p=(HeightState *)owner;
 if (p->y<=34.28571319580078125000f+p->floor)
  p->y=34.28571319580078125000f+p->floor;
}

void func_00192490(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00191F20(u8 *, s32);
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00191F50(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00191F20(p, p[0x22]);
    }
}
