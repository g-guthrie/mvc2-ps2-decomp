typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60; u8 pad64[4]; f32 f68, f6c; u8 pad70[0x24C]; f32 f2bc; } PK;
typedef struct { u8 pad[0x160]; s8 b[0x10]; } PB;
void func_0029EDC0(s32 a, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_00179160(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0, *s1, *s2, *s3;
    u8 *p;
    s8 *s5;
    p = (u8 *)a;
    func_00175700(p);
    s0 = (s32 *)(p + 0x5C);
    s2 = (s32 *)(p + 0x68);
    s1 = (s32 *)(p + 0x60);
    ((PK *)p)->f34 += *(f32 *)(p + 0x5C);
    ((PK *)p)->f5c += ((PK *)p)->f68;
    ((PK *)p)->f38 += *(f32 *)(p + 0x60);
    ((PK *)p)->f60 += ((PK *)p)->f6c;
    s3 = (s32 *)(p + 0x6C);
    if (!(((PK *)p)->f2bc <= ((PK *)p)->f38)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x2BC);
        func_001E3210(p, 0x24);
        ((PB *)p)->b[0] = 0x21;
        *(s8 *)((s32)p + 0x16A) = -1;
        s5 = ((PB *)p)->b;
        func_00179160(p, q);
        *s5 = 0;
        *(s8 *)(p + 0x16A) = -1;
        *(s16 *)(p + 0x1C) = 0x60;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 0x16, 0xC);
        func_00175700(p);
        {u32 t = p[7]; p[7] = t + 1;}
    }
}
