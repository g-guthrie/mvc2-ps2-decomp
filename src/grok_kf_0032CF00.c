/* ./try.sh src/grok_kf_0032CF00.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001237A0(void);
extern void func_0016CDA0(void);
extern void func_003298B0(s32, s32, s32);
extern void func_0012E780(s32);
extern s32 func_0032C180(s32);
extern void func_0032CFE0(void);
extern u8 *D_004C2840;
extern f32 D_004F1F54[];
extern s8 D_004F1F47[];
extern s8 D_00583BC7[];

void func_0032CF00(void)
{
    func_001237A0();
    if (D_004F1F54[0] < 40.0f) {
        D_004C2840[0x19] = 1;
        D_004F1F54[0] = 10.0f;
    }
    if (D_004F1F47[0] == 2) {
        D_004C2840[4] = D_004C2840[4] + 1;
        func_0016CDA0();
        func_003298B0(-1, 0x14, 1);
        *(s16 *)(D_004C2840 + 8) = 0x14;
        D_004C2840[0x19] = 1;
        func_0012E780(D_00583BC7[0] + 13);
        func_0012E780(2);
        func_0032CFE0();
    } else {
        func_0032C180(1);
    }
}
