/* v2_d: mw -O3 -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern u8 *volatile D_004C2840;
extern u8 D_004F7F30[];
extern u8 D_004F7F50[];
extern void func_003DA410();
extern void func_003D51E0(u8 *);
extern void func_003D33B0(u8 *);
extern void func_00122840(unsigned int);
extern void func_001E40E0();
extern void func_001E4140();
extern void func_001E4150();
extern void func_0012E6B0();
extern void func_0012E780(int);
void func_003D5360(void) {
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x91] = 0;
    D_004C2840[0x92] = 0;
    D_004C2840[0x19] = 1;
    func_003DA410();
    func_003D51E0(D_004F7F30);
    func_003D33B0(D_004F7F50);
    func_00122840(0xFF000000);
    func_001E40E0();
    func_001E4140();
    func_001E4150();
    func_0012E6B0();
    func_0012E780(12);
}

