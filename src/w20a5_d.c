typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

typedef struct { f32 x, y, z; } V3;
typedef void (*Fn)(void);

extern s32 D_004C2A5C;
extern s32 D_004C2A58;
extern Fn D_004C2A48;
extern s32 D_004C2A4C;
extern s32 D_004C2AEC;
extern s32 D_004C2AD0;
extern Fn D_0058C800[];
extern u8 D_0058CC40[];
extern V3 D_0058C778;
extern u8 D_0058C7A0[];
extern s32 D_004F1CC0[];

void func_003D7400(void)
{
    extern void func_00123090();
    extern void func_003DD260();
    extern void func_003DF850(s32, void *);
    extern void func_003DE680();
    extern void func_0016E8F0();
    extern s32 func_003DD160();
    extern void func_00420970();
    extern void func_00420980();
    extern void func_00420A50();
    extern void func_00420AB0();
    extern void func_003E0DB0();
    extern void func_00420B00();
    extern void func_00420B30();
    extern void func_0016D4B0(u8 *, s32, f32);
    extern void func_00420BA0();
    extern void func_00421270();
    extern void func_004209F0();
    extern void func_0016E950();
    extern void func_003D63B0();
    extern void func_00153750();
    s32 n;
    Fn *fp;
    u8 *s0;
    s32 s1;
    s32 s2;
    f32 buf4[4];
    f32 m[16];
    u64 q[2];
    V3 v;
    f32 f20;
    f32 k;
    n = D_004C2A5C;
    fp = D_0058C800;
    D_004C2A48 = 0;
    if (n != 0) {
        do {
            (*fp)();
            n--;
            fp++;
        } while (n != 0);
    }
    s1 = D_004C2A58;
    s0 = D_0058CC40;
    func_00123090();
    v = D_0058C778;
    k = 0.9f;
    v.z = -k;
    func_003DD260(m);
    func_003DF850(0x19, &m[0]);
    func_003DE680(buf4, &v);
    f20 = buf4[2];
    func_0016E8F0();
    s2 = func_003DD160(0x20000, 0x40);
    func_00420970(D_0058C7A0);
    func_00420980(D_0058C7A0, s2, 0x20000);
    func_00420A50(D_0058C7A0);
    func_00420AB0(D_0058C7A0, 0, 0x5C);
    func_00420AB0(D_0058C7A0, 8, 5);
    func_003E0DB0(D_004C2AEC, &q[0], &q[1], D_004C2AD0);
    func_00420AB0(D_0058C7A0, 6, q[0]);
    func_00420B00(D_0058C7A0);
    func_00420B30(D_0058C7A0, 0x521521D21D21ULL, 0xC);
    if (s1 != 0) {
        do {
            func_0016D4B0(s0, 1, f20);
            s1--;
            s0 += 0x40;
        } while (s1 != 0);
    }
    func_00420BA0(D_0058C7A0);
    func_00421270(D_0058C7A0);
    func_004209F0(D_0058C7A0);
    func_0016E950();
    if (D_004C2A4C != 0) func_003D63B0();
    if (D_004C2A48 != 0) D_004C2A48();
    if (D_004F1CC0[0] != 0) func_00153750();
}
