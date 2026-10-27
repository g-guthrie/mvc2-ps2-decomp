typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[9]; } Q36h;
typedef struct { Q36h q[3]; } R36h;
extern R36h D_0043FA10[];
extern R36h D_0043FA18[];
extern R36h D_0043FA1C[];
extern R36h D_0043FA24[];
extern R36h D_0043FA28[];
extern R36h D_0043FA30[];
extern u8 D_00583BC3[];

void func_00138DC0(u8 *p) {
    extern void func_0032D450(u8 *, s32, u8, f32);
    extern void func_0032D4E0(u8 *, s32, f32, u8);
    extern void func_0032D570(u8 *, s32);
    extern void func_0032D5F0(u8 *);
    extern void func_001E3CE0(s32);
    u8 x;
    switch (p[5]) {
    case 0:
        p[5]++;
        *(s16 *)(p + 0x1C) = 0x30;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (D_00583BC3[0] == 3) x = 0;
        else x = p[0xDC];
        p[6] = 0;
        switch (p[0x21]) {
        case 0:
            *(s32 *)(p + 0x70) = 0;
            *(s32 *)(p + 0x64) = 0;
            *(s32 *)(p + 0xD4) = 2;
            func_0032D450(p, *(s16 *)(p + 0x1C), 2, D_0043FA28[p[0x20]].q[x].f[0]);
            func_0032D4E0(p, *(s16 *)(p + 0x1C), D_0043FA30[p[0x20]].q[x].f[0], 2);
            break;
        case 1:
            func_001E3CE0((u8)(p[0x20] + 0x3A));
            func_0032D450(p, *(s16 *)(p + 0x1C), 2, D_0043FA1C[p[0x20]].q[x].f[0]);
            func_0032D4E0(p, *(s16 *)(p + 0x1C), D_0043FA24[p[0x20]].q[x].f[0], 2);
            *(u32 *)(p + 0x6C) = 0x3F9A4924;
            func_0032D570(p, *(s16 *)(p + 0x1C));
            *(s32 *)(p + 0xD4) = 1;
            break;
        case 2:
            func_0032D450(p, *(s16 *)(p + 0x1C), 2, D_0043FA10[p[0x20]].q[x].f[0]);
            func_0032D4E0(p, *(s16 *)(p + 0x1C), D_0043FA18[p[0x20]].q[x].f[0], 2);
            *(s32 *)(p + 0xD4) = 0;
            break;
        }
        break;
    case 1:
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
        }
        if (*(s16 *)(p + 0x1C) < 0) {
            p[5]++;
            *(u8 *)(*(u8 **)(p + 0x18) + 0x22) |= (u8)(1 << *(s8 *)(p + 0x21));
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_0032D5F0(p);
        }
        break;
    case 2:
        break;
    }
}
