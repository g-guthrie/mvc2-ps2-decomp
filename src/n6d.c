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


extern s32 func_001E7FD0(void);
s32 func_0026E8B0(u8 *a0) {
    u8 t = (U16(a0, 0x20E) & 0xC00) >> 10;
    s32 r;
    U8(a0, 0x22) = t;
    if (t != 0 && U8(a0, 0x212) == 0) {
        if (U8(a0, 0x1B7) == 1) {
            if (!(F32(a0, 0x38) <= 137.14285f)) {
                r = func_001E7FD0();
                if (r != 0) {
                    U8(a0, 0x20B) = 0;
                    return r;
                }
            }
        }
    }
    return 0;
}

extern f32 D_00462440[];
void func_0034F900(u8 *a0) {
    f32 v;
    if (S16(a0, 0x140) != 0) {
        v = 26.666666f;
    } else {
        v = -26.666666f;
    }
    F32(PTR(a0, 0x18), 0x34) = F32(a0, 0x34) + v;
    F32(PTR(a0, 0x18), 0x38) = F32(a0, 0x38) + D_00462440[S8(a0, 0x151) >> 1];
}

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00324CB0(u8 *);
void func_00324C10(u8 *a0) {
    a0[0x33C] = 5;
    if ((s8)func_00175700(a0) < 0) {
        f32 f1;
        f32 f0;
        a0[6]++;
        S16(a0, 0x1C) = 0x78;
        f1 = 10.0f;
        if (S16(a0, 0x140) == 0) {
            f1 = -f1;
        }
        f0 = 2.0f;
        f0 *= f1;
        F32(a0, 0x60) = f1;
        F32(a0, 0x5C) = f1;
        U32(a0, 0x68) = 0;
        F32(a0, 0x6C) = f0;
        func_001757E0(a0, 0x16, 0xF);
        func_00324CB0(a0);
    }
}
