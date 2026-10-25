/* Registered by func_00330EF0 with the actor encoded as a 32-bit context.
 * Deform negative-Y samples along Z using the actor curvature and phase. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef void (*SampleCallback)(u8 *, u16, f32 *);

extern void func_0041BAD0(u8 *);
extern s32 func_0041C180(u8 *, u8 *);
extern void func_0041BB30(u8 *);
extern f32 func_00417440(u32);

void func_00331350(u8 *first,u8 *second,s32 context)
{
    u8 *actor=(u8*)(u32)context;
    f32 sample[12];
    f32 *y;
    func_0041BAD0(second);
    while(func_0041C180(first,second)) {
        SampleCallback firstSample=*(SampleCallback *)(first+0x18);
        firstSample(first,*(u16*)(first+0x10),sample);
        y=&sample[1];
        if(*y<0.0f) {
            s32 phase=*(s16*)(actor+0x1c),angle;
            u32 turn;
            phase+=(s32)*y;
            angle=(s32)(sample[0]/2.0f)+phase;
            turn=(u16)(s32)(0.5+65536.0*(f64)angle/360.0);
            sample[2]-=*(f32*)(actor+0x68)*(*y * *y)*(1.0f+func_00417440(turn));
        }
        {
            SampleCallback secondSample=*(SampleCallback *)(second+0x1c);
            secondSample(second,*(u16*)(second+0x10),sample);
        }
    }
    *(u16*)(first+0x12)=0;*(u16*)(first+0x10)=0;
    *(u16*)(second+0x12)=0;*(u16*)(second+0x10)=0;
    func_0041BB30(second);
}
