typedef unsigned char u8;
typedef signed short s16;

extern void func_003C0540(u8 *);

void func_003C04A0(u8 *p, void *context)
{
    u8 *owner = context;
    float offset = 40.0f;

    if (*(s16 *)(owner + 0x140)) offset = -offset;
    {
        float y;
        offset += *(float *)(owner + 0x34);
        y = 342.85711669921875f + *(float *)(owner + 0x38);
        *(float *)(p + 0x34) = (offset + 3.0f * *(float *)(p + 0x34)) / 4.0f;
        *(float *)(p + 0x38) = (y + 3.0f * *(float *)(p + 0x38)) / 4.0f;
    }
    {
        s16 timer = *(s16 *)(p + 0x1e) + 0x800;
        *(s16 *)(p + 0x1e) = timer;
        if (timer == 0) func_003C0540(p);
    }
}
