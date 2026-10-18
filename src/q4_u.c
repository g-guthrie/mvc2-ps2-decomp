typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3u;
extern s32 D_004C2A50;
extern s32 D_004C2A54;
extern s32 D_004C2890;
extern void (*D_0058C7C0[])(void);
extern u8 D_0058C840[];
extern V3u D_0058C788;

void func_003D7640(void)
{
    extern void func_00123090(void);
    extern void func_003DD260(u8 *);
    extern void func_003DF850(s32, ...);
    extern void func_003DE680(f32 *, V3u *);
    extern void func_003EA660(s32, s32 *);
    extern void func_0016D4B0(u8 *, s32, f32);
    V3u a;
    f32 v[4];
    u8 m[0x40];
    s32 n;
    void (**fp)(void);
    u8 *q;
    s32 k;
    f32 z;
    f32 h;
    n = D_004C2A50;
    fp = D_0058C7C0;
    if (n != 0) {
        do {
            (*fp)();
            n--;
            fp++;
        } while (n != 0);
    }
    k = D_004C2A54;
    q = D_0058C840;
    func_00123090();
    a = D_0058C788;
    h = 0.5f;
    a.z = -h;
    func_003DD260(m);
    func_003DF850(0x19, (u8 *)((s32)m + 0));
    func_003DE680(v, &a);
    z = v[2];
    func_003DF850(0xD, 0);
    func_003DF850(0x5D, 0x32);
    func_003EA660(1, &D_004C2890);
    func_003DF850(4, D_004C2890);
    func_003DF850(0x62, 1);
    if (k != 0) {
        do {
            func_0016D4B0(q, 0, z);
            k--;
            q += 0x40;
        } while (k != 0);
    }
}
