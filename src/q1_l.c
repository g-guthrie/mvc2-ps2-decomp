typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

void func_002C6CE0(u8 *p)
{
    extern s32 func_00175700();
    extern void func_00184540();
    extern void func_001CEA00();
    switch (p[0x1FC]) {
    case 0:
        if ((s8)func_00175700(p) < 0) func_00184540(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_001CEA00(p, 4);
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_001CEA00(p, 5);
        }
        break;
    }
}

void func_00207D90(u8 *p)
{
    extern s32 func_00175700();
    extern void func_00203340();
    extern void func_00184540();
    extern void func_001266A0();
    extern void func_001E3A40();
    u8 *q = *(u8 **)(p + 0x1DC);
    s32 a;
    if (p[0x20D] != 2) {
        if ((s8)func_00175700(p) < 0) {
            func_00203340(p);
            return;
        }
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
            goto end;
        }
    }
    a = *(s8 *)(p + 0x151);
    if ((a & 0x3F) == 2) {
        *(s8 *)(p + 0x151) = a & ~0x3F;
        *(u8 **)(q + 0x1C8) = p;
        func_001266A0(p, 0, 0);
        *(s8 *)(q + 0x1E6) = *(s8 *)(p + 0x1E6) ^ 1;
        if (p[0x20D] != 2) {
            q[0x20A] = 2;
            q[0x1B5] = 0x3A;
        } else {
            q[0x20A] = 1;
            q[0x1B5] = 0x3B;
            q[0x20D] = 2;
        }
        func_001E3A40(p);
    }
end:
    return;
}

extern u8 D_00476170[];
extern void (*D_00476200[])();

void func_003C8530(u8 *p, u8 *q)
{
    extern s32 func_00175700();
    extern void func_003C8650();
    extern void func_001757E0();
    u16 *e;
    p[0x24] = *(s8 *)(q + 0x24);
    switch (p[6]) {
    case 0:
        p[6]++;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        e = (u16 *)D_00476170 + (p[0x21] * 3 + p[0x20] * 15);
        func_001757E0(p, 0x14, *(u8 *)e++);
        p[0x31] = *(s8 *)e;
        p[0x24] = *(s8 *)(q + 0x24);
        *(s16 *)(p + 0x1E) = *(s16 *)((u8 *)e + 2);
        break;
    case 1:
        D_00476200[p[0x21]](p, q);
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) func_003C8650(p, q);
        break;
    }
}
