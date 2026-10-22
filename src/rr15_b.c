typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2e;
extern G2e *D_004C2794;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x24]; f32 f5c; u8 pad2[0x08]; f32 f68; } F2e;

void func_002E1990(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001757E0();
    extern void func_001D36E0();
    extern void func_001E3710();
    s16 h;
    u32 t;
    f32 z;
    f32 c;
    if (p[0x1FC] == 2) {
        if (p[0x20D] == 1) {
            if (p[6] == 0) {
                func_00175700(p);
                if (*(s8 *)(p + 0x151) != 0) {
                    p[0x151] = 0;
                    t = p[6];
                    p[6] = t + 1;
                    *(s16 *)(p + 0x1E) = 4;
                    c = 8.333333015f;
                    *(f32 *)(p + 0x5C) = c;
                    c = -0.2083333283662796f;
                    *(f32 *)(p + 0x68) = c;
                    if (*(s16 *)(p + 0x140) == 0) {
                        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
                    }
                }
            } else if ((u8)p[6] == 1) {
                h = *(s16 *)(p + 0x1E) - 1;
                *(s16 *)(p + 0x1E) = h;
                if (h < 0) {
                    *(s16 *)(p + 0x1E) = 6;
                    func_001D36E0(p, 0);
                }
                func_00175700(p);
                z = 0.0f;
                ((F2e *)p)->f34 += ((F2e *)p)->f5c;
                ((F2e *)p)->f5c += ((F2e *)p)->f68;
                if (!(((F2e *)p)->f5c * ((F2e *)p)->f68 < z)) {
                    t = p[6];
                    p[6] = t + 1;
                    func_001757E0(p, 10, 3);
                }
            } else {
                if (func_00175700(p) < 0) {
                    func_001843A0(p);
                }
            }
        } else {
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            } else if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                func_001E3710(p, 0x16);
                p[0x1B5] = 0x19;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
        }
    } else {
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
    }
}
