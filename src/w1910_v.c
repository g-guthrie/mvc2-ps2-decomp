struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 a, b; s32 c; } T3_v;
extern T3_v D_00475EB0[];
extern T3_v D_00475EB4[];
extern s8 D_00475EB8[];
extern u8 D_00475EBA[];

void func_003C5420(u8 *p, u8 *o)
{
    extern void func_003DAA40(struct Object *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    s32 v;
    f32 f;
    v = *(s8 *)(o + 0x150);
    if (v < 0) {
        func_003DAA40((struct Object *)p);
        return;
    }
    if (v != 0) {
        if (v != p[0x22]) {
            p[0x22] = v;
            f = D_00475EB0[p[0x22]].a;
            *(f32 *)(p + 0x60) = D_00475EB4[p[0x22]].a;
            *(s8 *)(p + 0x31) = *(s8 *)((u8 *)D_00475EB8 + p[0x22] * 12);
            *(s8 *)(p + 0x13C) = 1;
            func_001757E0(p, 0x19, *(u8 *)((u8 *)D_00475EBA + p[0x22] * 12));
            if (*(s16 *)(o + 0x140) != 0) f = -f;
            *(f32 *)(p + 0x5C) = f;
        }
        *(s16 *)(p + 0x140) = *(s16 *)(o + 0x140);
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        func_00175700(p);
    }
}
