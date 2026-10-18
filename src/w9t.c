typedef unsigned char u8; typedef signed char s8; typedef signed short s16; typedef signed int s32; typedef unsigned int u32;
extern u8 D_004C27D0;
extern s32 *D_00477010[];
extern void (**D_00476DB0[])(void);
extern s8 D_004F1CD8[];
void func_003D0FA0(void) {
    s32 i = 0;
    s32 idx;
    void (*f)(void);
    while ((idx = *(s32 *)((u8 *)D_00477010[D_004C27D0] + i)) != -1) {
        f = D_00476DB0[D_004C27D0][idx];
        if (f != 0) f();
        i += 4;
    }
    D_004F1CD8[0]++;
}
