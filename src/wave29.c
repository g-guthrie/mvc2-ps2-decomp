typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern s8 *D_004C2840;
void func_00161760(s32 a0);
void func_00161690(s32 a0);

extern u8 D_004C2A34;

void func_003D7190(u8 *p) {
    u32 t = D_004C2A34;
    D_004C2A34 = t + 1;
    if (D_004C2A34 % 60 == 0) {
        D_004C2A34 = 0;
        t = p[1];
        p[1] = t + 1;
        if (p[1] == 60) {
            p[1] = 0;
            t = p[2];
            p[2] = t + 1;
            if (p[2] == 60) {
                p[2] = 0;
                t = p[3];
                p[3] = t + 1;
                if (p[3] == 24) {
                    p[3] = 0;
                }
            }
        }
    }
}
