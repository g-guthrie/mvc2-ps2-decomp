/* MWCCPS2 3.0: -O3,p -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

typedef struct { u8 b[8]; u8 *p; } E12;
typedef struct { u8 b0; u8 b1; u16 h; s16 r[14]; } T32;
typedef struct { s16 h[4]; } T8;
typedef struct { u64 q[4]; } __attribute__((aligned(16))) T32A;
typedef struct { u8 pad[4]; u8 b4; u8 b5; u8 rest[0x2E]; } Y34;

extern s32 D_004C2B00;
extern T8 D_004C2200;
extern u8 D_004C2AF0[5];
extern u8 D_004C2AF8[5];
extern E12 D_0062C090[];
extern u8 D_0062C400[];
extern u8 D_0062C300[];
extern u8 D_0062C200[];
extern u8 D_0062C100[];
extern T32 D_0062C640[];
extern T8 D_0062C500[];
extern Y34 D_0062C530[];

s32 func_003ED300(void) {
    extern s32 func_0010D360();
    extern void func_003ED880();
    extern void func_003ED820();
    extern s32 func_0010E4A8(s32);
    T32A t;
    T8 u;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    D_004C2B00 = -1;
    if (func_0010D360(0) != 1) return 0;
    func_003ED880();
    D_0062C640[0].b0 = 0xFF;
    D_0062C640[0].h = 0xFFFF;
    t = *(T32A *)&D_0062C640[0];
    D_0062C640[1] = *(T32 *)&t;
    D_0062C640[2] = *(T32 *)&t;
    D_0062C640[3] = *(T32 *)&t;
    D_0062C640[4] = *(T32 *)&t;
    D_0062C640[5] = *(T32 *)&t;
    D_0062C090[0].b[0] = 0;
    D_0062C090[0].p = D_0062C400;
    D_0062C090[1].p = D_0062C300;
    D_0062C090[2].p = D_0062C200;
    D_0062C090[3].p = D_0062C100;
    D_0062C090[0].b[1] = 0;
    D_0062C090[0].b[2] = 0;
    D_0062C090[0].b[3] = 0;
    D_0062C090[0].b[5] = 0;
    D_0062C090[1].b[0] = 0;
    D_0062C090[1].b[1] = 0;
    D_0062C090[1].b[2] = 0;
    D_0062C090[1].b[3] = 0;
    D_0062C090[1].b[5] = 0;
    D_0062C090[2].b[0] = 0;
    D_0062C090[2].b[1] = 0;
    D_0062C090[2].b[2] = 0;
    D_0062C090[2].b[3] = 0;
    D_0062C090[2].b[5] = 0;
    D_0062C090[3].b[0] = 0;
    D_0062C090[3].b[1] = 0;
    D_0062C090[3].b[2] = 0;
    D_0062C090[3].b[3] = 0;
    D_0062C090[3].b[5] = 0;
    D_0062C090[4].b[0] = 0;
    D_0062C090[4].b[1] = 0;
    D_0062C090[4].b[2] = 0;
    D_0062C090[4].b[3] = 0;
    D_0062C090[4].b[5] = 0;
    if (D_004C2B00 == -1) {
        func_003ED820(0, 0, &D_0062C090[0]);
        func_003ED820(1, 0, &D_0062C090[1]);
    } else {
        s2 = 0;
        s1 = func_0010E4A8(D_004C2B00);
        for (s0 = 0; s0 < 2; s0++) {
            if (s0 == D_004C2B00) {
                for (s3 = 0; s3 < s1; s3++) {
                    func_003ED820(D_004C2B00, s3, &D_0062C090[s2++]);
                }
            } else {
                func_003ED820(D_004C2B00 ^ 1, 0, &D_0062C090[s2++]);
            }
        }
    }
    u = D_004C2200;
    D_0062C500[0] = u;
    D_004C2AF0[0] = 0;
    D_004C2AF8[0] = 0;
    D_0062C530[0].b4 = D_0062C090[0].b[2];
    D_0062C530[0].b5 = D_0062C090[0].b[3];
    D_0062C500[1] = u;
    D_004C2AF0[1] = 0;
    D_004C2AF8[1] = 0;
    D_0062C530[1].b4 = D_0062C090[1].b[2];
    D_0062C530[1].b5 = D_0062C090[1].b[3];
    D_0062C500[2] = u;
    D_004C2AF0[2] = 0;
    D_004C2AF8[2] = 0;
    D_0062C530[2].b4 = D_0062C090[2].b[2];
    D_0062C530[2].b5 = D_0062C090[2].b[3];
    D_0062C500[3] = u;
    D_004C2AF0[3] = 0;
    D_004C2AF8[3] = 0;
    D_0062C530[3].b4 = D_0062C090[3].b[2];
    D_0062C530[3].b5 = D_0062C090[3].b[3];
    D_0062C500[4] = u;
    D_004C2AF0[4] = 0;
    D_004C2AF8[4] = 0;
    D_0062C530[4].b4 = D_0062C090[4].b[2];
    D_0062C530[4].b5 = D_0062C090[4].b[3];
    return 1;
}
