typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;
extern u8 D_004B7170[];
typedef struct { u8 pad[0x38]; f32 f38; } S3c;

void func_00220840(u8 *p) {
    extern s32 func_00417A40();
    extern void func_0019BA70(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_00175700(u8 *);
    extern s32 func_00220260(u8 *, s32);
    extern void func_002206A0(u8 *);
    extern void func_002207B0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002202B0(u8 *);
    u8 *r;
    *(u16 *)(p + 0x2DC) -= 1;
    r = p + 0x2B8;
    if (*(u16 *)(p + 0x2DC) > 0) {
        if (*(u16 *)(p + 0x2DC) < 10 && (*(u16 *)(p + 0x35E) & 0x360) != 0) p[7] = 1;
        if ((func_00417A40() & 3) == 0) func_0019BA70(p, 0xFF);
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = D_004B7170[*(u16 *)(r + 0x1C)];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
            ((S3c *)p)->f38 = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            switch (*(u16 *)(r + 0x1C)) {
            case 9:
            case 1:
                *(u16 *)(r + 0x1C) = func_00220260(p, 0x800);
                func_002206A0(p);
                break;
            case 5:
                *(u16 *)(r + 0x1C) = func_00220260(p, 0x400);
                func_002206A0(p);
                break;
            }
        }
    } else {
        s32 t;
        if (p[7] != 0) {
            t = r[8];
            r[8] = t - 1;
            if (r[8] != 0) goto L_A08;
        }
        func_002207B0(p);
        return;
    L_A08:
        func_001757E0(p, 0x15, 0x21);
        p[0x1B5] = D_004B7170[*(u16 *)(r + 0x1C)];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        t = p[6];
        p[6] = t - 1;
        func_002202B0(p);
    }
}
