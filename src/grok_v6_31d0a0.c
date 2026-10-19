typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void residual_0031D0A0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        if (p[0x214] == 0) {
            *(f32 *)(p + 0x5C) = 20.0f;
            *(f32 *)(p + 0x68) = -0.8035714030265808f;
            *(f32 *)(p + 0x60) = 5.0f;
            *(f32 *)(p + 0x6C) = -0.5357142686843872f;
        } else {
            *(f32 *)(p + 0x5C) = 25.0f;
            *(f32 *)(p + 0x68) = -0.8035714030265808f;
            *(f32 *)(p + 0x60) = 6.666666507720947f;
            *(f32 *)(p + 0x6C) = -0.8035714030265808f;
        }
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
