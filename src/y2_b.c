struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F44;
extern u8 D_004F1F43;
extern u8 D_004D18B8[];
extern u8 D_004D18BC[];
extern u8 D_004D18C0[];

void func_001833C0(u8 *p)
{
    extern void func_0018C6B0();
    extern u8 *func_00327CF0(u8 *, u8);
    extern void func_00183A70();
    extern void func_00175C00();
    func_0018C6B0(p, 1);
    if (func_00327CF0(p, 4) != 0) {
        func_00183A70(p);
        D_004F1F44 = 1;
        D_004F1F43 = 1;
        func_00175C00(*(u32 *)(D_004D18B8 + (p[2] ^ 1) * 12), 2);
        func_00175C00(*(u32 *)(D_004D18BC + (p[2] ^ 1) * 12), 2);
        func_00175C00(*(u32 *)(D_004D18C0 + (p[2] ^ 1) * 12), 2);
    }
}

typedef struct { f32 x, y, z; } V3;
extern s8 D_004F7F30;
extern s8 D_004F7F32;
extern V3 D_00476BB0[];
extern V3 D_00476C10[];

void func_003D0850(u8 *p)
{
    extern void func_003DAA40(struct Object *);
    extern void func_0012AD00();
    if (D_004F7F30 != 2) { func_003DAA40((struct Object *)p); return; }
    p[0x13C] = 0;
    if (D_004F7F32 == 7) return;
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = D_00476BB0[D_004F7F32];
    *(V3 *)(p + 0x50) = D_00476C10[D_004F7F32];
    if (p[4] == 0) { p[4]++; *(s16 *)(p + 0x1E) = 0; }
    func_0012AD00();
}
