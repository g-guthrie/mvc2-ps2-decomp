typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7c]; s16 count[2]; } GameStateE;
extern GameStateE *D_004C2794;

void func_001F9E80(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001FA3B0(u8 *);
    extern void func_00347F90(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_00347AA0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;

    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) >= 0) {
        func_001FA3B0(p);
        if (((s8 *)p)[0x161] & 1) *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            func_00347F90(p, 1);
        }
        return;
    }
    t = p[6];
    if (t == 2) {
        p[6] = t + 1;
        if (p[0x1E6] != 0) *(u32 *)(p + 0x5C) = 0x41055555;
        else *(u32 *)(p + 0x5C) = 0xC1055555;
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[p[2]]++;
        *(s16 *)(p + 0x1C) = 0;
        func_00183D10(p);
        func_00347AA0(p);
        func_001757E0(p, 0x16, 2);
        return;
    }
    {
        p[6] = t + 1;
        p[0x1B5] = 0x36;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[p[2]]++;
        *(s16 *)(p + 0x1C) = 0;
        if (p[0x1E6] != 0) {
            *(u32 *)(p + 0x5C) = 0x41D55555;
            *(u32 *)(p + 0x68) = 0xBFA00000;
        } else {
            *(u32 *)(p + 0x5C) = 0xC1D55555;
            *(u32 *)(p + 0x68) = 0x3FA00000;
        }
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_00347F90(p, 1);
        func_001757E0(p, 0x16, 3);
    }
}
