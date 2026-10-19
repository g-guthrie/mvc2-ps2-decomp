typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern f32 func_00417500(u32);
extern f32 func_00417440(u32);
void func_00237D40(u8 *p, u8 direction)
{
    s16 angle = ((80-direction)&0x3F)<<10;
    *(f32 *)(p+0x5C)=*(f32 *)(p+0x68)+1.6666666269302368f*(665600.0f*(1000.0f*func_00417500(angle))/100000.0f/256.0f);
    *(f32 *)(p+0x60)=*(f32 *)(p+0x6C)+2.142857074737549f*(665600.0f*(1000.0f*func_00417440(angle))/125000.0f/256.0f);
}
