/* nearmiss: try30.sh (MW 3.0) "-O3,p -Op -sdatathreshold 0"; 9/290 words differ: loop-head temps lui a0/lbu a0 where retail uses a2 (register naming only) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 state;
    u8 pad1[3];
    s32 a;
    s32 b;
    f32 c;
    f32 d;
} SE;

extern SE D_004CBE80[];
#define ST (D_004CBE80[i].state)
#define FA (D_004CBE80[i].a)
#define FB (D_004CBE80[i].b)
#define FC (D_004CBE80[i].c)
#define FD (D_004CBE80[i].d)
#define KEY1 (((FA & 0x7F) << 16) | ((FB & 0x7F) << 8) | 1)
#define KEY2 ((i & 0x7F) | (((FA & 0x7F) << 16) | ((FB & 0x7F) << 8)))

void func_001E5230(void)
{
    extern s32 func_004230B0(u32, s32, s32, s32);
    extern s32 func_00422FB0(u32);
    s32 i = 0;
    do {
        switch (ST) {
        case 1:
            FC -= FD;
            if (!(FC <= 0.0f)) {
                func_004230B0(KEY1, (s32)FC, -1, -1);
            } else {
                if (func_00422FB0(KEY1) >= 0) {
                    ST = 0;
                    FA = 0;
                    FB = 0;
                    FC = 0.0f;
                    FD = 0.0f;
                }
            }
            break;
        case 2:
            FC -= FD;
            if (!(FC <= 0.0f)) {
                func_004230B0(KEY1, (s32)FC, -1, -1);
            } else {
                if (func_00422FB0(KEY1) >= 0) {
                    ST = 0;
                    FA = 0;
                    FB = 0;
                    FC = 0.0f;
                    FD = 0.0f;
                }
            }
            break;
        case 3:
            FC -= FD;
            if (!(FC <= 2.0f)) {
                func_004230B0(KEY1, (s32)FC, -1, -1);
            } else {
                func_004230B0(KEY1, 2, -1, -1);
                ST = 0;
                FA = 0;
                FB = 0;
                FC = 0.0f;
                FD = 0.0f;
            }
            break;
        case 4:
            FC -= 2.0f * FC / FD;
            FD -= 1.0f;
            if (!(FC <= 2.0f)) {
                func_004230B0(KEY2, (s32)FC, -1, -1);
            } else {
                func_004230B0(KEY2, 2, -1, -1);
            }
            if (FD < 0.0f) {
                if (func_00422FB0(KEY2) >= 0) {
                    ST = 0;
                    FA = 0;
                    FB = 0;
                    FC = 0.0f;
                    FD = 0.0f;
                }
            }
            break;
        case 5:
            FD -= 1.0f;
            if (FD < 0.0f) {
                if (func_00422FB0(KEY2) >= 0) {
                    ST = 0;
                    FA = 0;
                    FB = 0;
                    FC = 0.0f;
                    FD = 0.0f;
                }
            }
            break;
        }
        i++;
    } while (i < 36);
}
