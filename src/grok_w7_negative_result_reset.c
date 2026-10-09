typedef unsigned char u8;
typedef unsigned int u32;

typedef signed char s8;
typedef float f32;
typedef union { f32 value; u32 bits; } FloatBits;
typedef struct { u8 prefix[0x5c]; FloatBits f5c; FloatBits f60; u32 padding; FloatBits f68; FloatBits f6c; } ActorView;
extern int func_002F4710(u8 *);
extern int func_00175700(u8 *);
extern void func_00126400(void);
extern void func_00184540(u8 *);
void func_002F48D0(u8 *p)
{
    s8 result;
    ActorView *actor = (ActorView *)p;
    func_002F4710(p);
    result = (s8)func_00175700(p);
    if (result >= 0)
        return;
    func_00126400();
    actor->f5c.bits = 0;
    actor->f60.bits = 0;
    actor->f68.bits = 0;
    actor->f6c.bits = 0;
    actor->f6c.bits = 0xBF4DB6DB;
    func_00184540(p);
}
