typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3_nq93a;

void func_003C06A0(u8 *p)
{
    extern void func_00175670(u8 *);
    extern void func_003DAA40(u8 *);
    u8 *s;
    u8 *t;
    float offset;

    func_00175670(p);
    s = *(u8 **)(p + 0x18);
    offset = 40.0f;
    t = *(u8 **)(p + 0xD8);
    *(V3_nq93a *)(p + 0x34) = *(V3_nq93a *)(s + 0x34);
    if (*(s16 *)(t + 0x140)) offset = -offset;
    {
        float y;
        offset += *(float *)(t + 0x34);
        y = 342.85711669921875f + *(float *)(t + 0x38);
        offset = (offset - *(float *)(p + 0x34)) / 8.0f;
        y = (y - *(float *)(p + 0x38)) / 8.0f;
        *(float *)(p + 0x34) += offset * (f32)(u32)p[0x20];
        *(float *)(p + 0x38) += y * (f32)(u32)p[0x20];
    }
    p[0x15D] = (s[0x22] & 0x1F) >> 1;
    if (s[4] > 1) {
        p[0x13C] = 0;
        func_003DAA40(p);
    }
}
