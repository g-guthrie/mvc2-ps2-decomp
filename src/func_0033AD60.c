typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { u8 *actor; u32 phase; } WaveContext;
typedef void (*SampleCallback)(u8 *, u16, f32 *);

extern void func_0041BAD0(u8 *);
extern s32 func_0041C180(u8 *, u8 *);
extern void func_0041BB30(u8 *);
extern f32 func_00417440(u32);

void func_0033AD60(u8 *first, u8 *second, s32 contextAddress)
{
    WaveContext *context = (WaveContext *)(u32)contextAddress;
    u8 *actor = context->actor;
    u32 phase = context->phase;
    f32 sample[12];

    func_0041BAD0(second);
    while (func_0041C180(first, second) != 0) {
        SampleCallback firstSample = *(SampleCallback *)(first + 0x18);
        firstSample(first, *(u16 *)(first + 0x10), sample);

        if (!(sample[1] <= 10.0f)) {
            u32 angleBits = (u32)(s32)*(s16 *)(actor + 0x1c) + phase;
            s32 angle = (s32)angleBits;
            u32 turn = (u16)(u32)(s32)(0.5 + (65536.0 * (f64)angle) / 360.0);
            sample[2] += 0.00019999999494757503f * sample[1] * sample[1] * func_00417440(turn);
        }

        phase += 30;
        {
            SampleCallback secondSample = *(SampleCallback *)(second + 0x1c);
            secondSample(second, *(u16 *)(second + 0x10), sample);
        }
    }

    context->phase = phase;
    *(u16 *)(first + 0x12) = 0;
    *(u16 *)(first + 0x10) = 0;
    *(u16 *)(second + 0x12) = 0;
    *(u16 *)(second + 0x10) = 0;
    func_0041BB30(second);
}
