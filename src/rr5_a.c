typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 p0[0x98];
    s32 f98;
    u8 p9C[0xB1 - 0x9C];
    s8 fB1;
} G5a;

extern s8 D_004C27C4[2];
extern s8 D_004C27C0[2];
extern G5a *D_004C2840;
extern s32 D_004C28BC;
extern s32 D_004C28B8;
extern u8 D_004C27D0;

void func_001E74C0(void)
{
    s32 v;
    extern void func_001E7410(void);
    extern void func_001E7420(void);
    extern s32 func_00416180(s32, s32);
    extern void func_001E5F40(s32, s32);
    extern void func_00417FE0(s32);

    if (D_004C27C4[0] != 0) {
        v = D_004C27C0[0];
        switch (v) {
        case 1:
            func_001E7410();
            break;
        case 2:
            func_001E7420();
            break;
        case 3:
            func_001E7410();
            D_004C27C4[0] = 1;
            D_004C27C0[0] = 2;
            return;
        case 4:
        case 5:
            func_001E5F40(0x81C, func_00416180(D_004C28BC, v - 4));
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            func_001E5F40(v + 0x817, D_004C28BC + 0x300000 + ((v - 6) << 17));
            break;
        case 11:
        case 12:
            func_00417FE0(0);
            switch (D_004C2840->fB1) {
            case 0:
                func_001E5F40(0x816, D_004C2840->f98 + 0x20000);
                func_001E5F40(0x817, D_004C2840->f98 + 0x30000);
                break;
            case 1:
                func_001E5F40(0x81B, D_004C2840->f98 + 0x20000);
                break;
            case 2:
                func_001E5F40(0x816, D_004C2840->f98 + 0x20000);
                func_001E5F40(0x817, D_004C2840->f98 + 0x30000);
                break;
            }
            break;
        case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
        case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28:
            {
                s32 r = func_00416180(D_004C2840->f98, v - 13);
                func_001E5F40(((D_004C27C0[0] - 13) & 1) + 0x910, r);
            }
            break;
        case 29:
            {
                s32 r = func_00416180(D_004C28B8 + 0x67000, D_004C27D0);
                func_001E5F40(0x914, r);
            }
            break;
        case 30:
            func_001E5F40(0x918, D_004C28B8);
            break;
        case 31:
            func_001E5F40(0x910, D_004C28B8);
            break;
        }
    }
    D_004C27C4[0] = 0;
    D_004C27C0[0] = 0;
}
