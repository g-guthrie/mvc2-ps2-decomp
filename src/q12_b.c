typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
typedef struct { f32 a, b, c, d; } V4;
typedef struct { u8 p0[4]; s8 b4; u8 p5[3]; s16 h8; } G;
extern G *D_004C2840;
extern f32 D_004444F0[];
extern V4 D_004443E0;
extern f32 D_00444500[];

void func_001740C0(u8 *p)
{
    s32 f;
    p[0x4D0] = 3;
    p[0x4D1] = 0;
    p[0x550] = p[0x551];
    f = 0;
    if (p[0x552] < p[0x551]) {
        p[0x550] = p[0x552];
        f = 1;
    }
    if (p[0x550] < 0x15) {
        p[0x544] = 0x2B;
        p[0x545] = 0x2B;
        p[0x546] = 0x2B;
        p[0x547] = 0x2A;
        *(s16 *)(p + 0x4D4) = 0xE10;
        *(s16 *)(p + 0x4D6) = 0x960;
        *(s16 *)(p + 0x4D8) = 0;
        *(s16 *)(p + 0x4DA) = 0x28;
        p[0x4D2] = 0;
        p[0x4D3] = 1;
        ((u8 *)D_004C2840)[0x2C] = f;
    }
}

extern void func_0012AD00(void *p);
void func_001512A0(u8 *p)
{
    func_0012AD00(p);
    if (p[0x21] == 0) {
        *(f32 *)(p + 0x38) = D_004444F0[D_004C2840->b4];
        return;
    }
    if (D_004C2840->h8 & 0x80) {
        *(V4 *)(p + 0x74) = D_004443E0;
    }
    *(f32 *)(p + 0x38) = D_00444500[D_004C2840->h8 & 0x7F];
}
