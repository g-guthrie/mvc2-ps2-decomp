typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x9C]; s8 f9C; } GE;
typedef struct { s32 f0; s32 f4; s32 f8; } TE;
extern GE *D_004C2840;
extern u8 D_004C27D0;
extern TE D_00477060[];
extern u8 D_004D18A6[];
extern u8 D_004F1D20[];

void func_003DAA40(u8 *p);
void func_00161380(u8 *p);
void func_00161010(u8 *p);
void func_00161F20(u8 *p);
void func_001621F0(u8 *p);

void func_00161C40(u8 *p)
{
    TE *tab;
    s32 v;
    s8 sv;
    f32 r;

    tab = &D_00477060[D_004C27D0];
    sv = D_004C2840->f9C;
    p[0x13C] = sv;
    if (sv == 0 || ((D_004C2840->f9C & 0xF) == 1 && D_004D18A6[0] != 0)) {
        if (tab->f0 != -1) D_004F1D20[0] = 1;
        p[0x13C] = 0;
        *(s32 *)(p + 0x78) = 0;
        *(s32 *)(p + 0x7C) = 0;
        *(u32 *)(p + 0x80) = 0x3F800000;
        p[7] = 0;
        p[0x23] = 0;
        if (p[0x20] == 1) *(s32 *)(p + 0xD4) = 0;
        return;
    }
    if (tab->f0 != -1) D_004F1D20[0] = 0;
    if (D_004C2840->f9C == 0) {
        func_003DAA40(p);
        return;
    }
    func_00161380(p);
    if (p[0x20] != 0) {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
        if (p[0x20] == 2) {
            if (*(s16 *)(p + 0x1E) >= 0xA0) *(s16 *)(p + 0x1E) = 0;
        } else {
            if (*(s16 *)(p + 0x1E) >= 0x28) *(s16 *)(p + 0x1E) = 0;
        }
        if (p[0x20] == 2) {
            r = -(f32)(1.0 - 0.00625 * (double)*(s16 *)(p + 0x1E));
        } else {
            r = -(f32)(1.0 - 0.025 * (double)*(s16 *)(p + 0x1E));
        }
        *(s32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = r;
    }
    if (p[0x20] == 1 && p[5] < 2) {
        v = *(s32 *)(p + 0xD4);
        if (v != 0) {
            *(s32 *)(p + 0xD4) = v - 1;
        } else {
            *(s32 *)(p + 0xD4) = 0x28;
            func_00161010(p);
        }
    }
    if (p[0x20] == 2) {
        if (p[5] < 3) {
            v = *(s32 *)(p + 0xD4);
            if (v != 0) {
                *(s32 *)(p + 0xD4) = v - 1;
            } else {
                *(s32 *)(p + 0xD4) = 10;
                func_00161F20(p);
            }
        }
        if (p[6] < 3) {
            v = *(s32 *)(p + 0xD8);
            if (v != 0) {
                *(s32 *)(p + 0xD8) = v - 1;
            } else {
                *(s32 *)(p + 0xD8) = 0x32;
                func_001621F0(p);
            }
        }
    }
}
