typedef signed int s32;
typedef signed short s16;
extern s32 D_004C2238;
extern s16 D_0062CFE0[0x400];
void func_003F78F0(void){
    if (++D_004C2238 == 1) {
        s16 *p = D_0062CFE0;
        s32 n = 0;
        s32 a, d;
        for (a = 0x4000; a < 0x7FFF; a++) {
            for (d = 2; d < a; d++)
                if (a % d == 0) break;
            if (a == d) {
                n++;
                *p = a;
                p++;
                if (n >= 0x400) break;
            }
        }
    }
}
