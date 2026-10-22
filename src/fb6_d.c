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

void func_001926F0(u8 *p) {
    extern void func_001928E0(u8 *, s32, s32);
    extern void func_00191EF0(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_00184540(u8 *);
    f32 *a1, *a2, *a3, *t0;
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x18;
        func_001928E0(p, 0x4E2, 0x14);
        func_00191EF0(p, p[0x22]);
    }
    func_00175700(p);
    a1 = (f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x68);
    a2 = (f32 *)(p + 0x60);
    t0 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00191F50(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            *(u32 *)a1 = 0;
            *(u32 *)a2 = 0;
            *(u32 *)a3 = 0;
            *(u32 *)t0 = 0;
            func_00184540(p);
        }
    }
}
