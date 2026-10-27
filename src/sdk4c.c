typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
extern s32 D_004C22C4;
extern void func_00402498(void);
void func_003FD9E0(void) { D_004C22C4++; func_00402498(); }

extern u16 D_004C2248, D_004C224A, D_004C224C;
extern void func_003F79A8(s8 *, s16 *, s16 *, s16 *);
void func_003F8240(void *a) { func_003F79A8((s8 *)a, (s16 *)&D_004C2248, (s16 *)&D_004C224A, (s16 *)&D_004C224C); }

extern s32 D_004C2288;
extern void func_004112B0(void);
void func_003F9660(void) { if (--D_004C2288 == 0) func_004112B0(); }

extern volatile s32 D_004C2388;
extern void func_003FD928(void);
s32 func_003FEC10(void) {
    if (D_004C2388 == 0) { D_004C2388 = 1; func_00402498(); func_003FD928(); D_004C2388 = 0; }
    return 0;
}
