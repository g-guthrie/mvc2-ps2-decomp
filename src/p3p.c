typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x28]; s32 f28; s16 f2C; u8 pad2E[0x12]; } E3E94D0;
extern E3E94D0 D_0061C7A0[];
extern s32 D_004C2AE8;
extern void func_003DC9C0(void);
extern void func_003EBD00(E3E94D0 *);
extern void func_003DD020(s32);
extern void func_003F55B0(E3E94D0 *, s32, s32);

s32 func_003E94D0(u32 a) {
    E3E94D0 *p = &D_0061C7A0[a - 1];
    if (a == 0) return 0;
    if (a > 0x100) return 0;
    if (p->f2C == 0) return 0;
    func_003DC9C0();
    func_003EBD00(p);
    if (p->f28 != 0) func_003DD020(p->f28);
    func_003F55B0(p, 0, 0x40);
    D_004C2AE8--;
    return 1;
}
