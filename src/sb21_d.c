typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
/* The enable view is used only for the one-bit GS controls.
 * Field writes preserve native reserved storage without a raw-value C read. */
typedef union GsValue {
 u64 raw;
 struct { u64 enable:1; u64 reserved:63; } bits;
} GsValue;
typedef struct GsRegisterPair {GsValue value;u64 register_id;} GsRegisterPair;
typedef struct GsDrawEnvironment {
    GsRegisterPair frame,zbuf,xyoffset,scissor,prmodecont,colclamp,dthe,test;
} GsDrawEnvironment;
typedef char GsDrawEnvironment_size_check[sizeof(GsDrawEnvironment)==128?1:-1];
extern short func_001009C8(short format,short width,short height);
int func_00101E78(GsDrawEnvironment *env,short format,short width,short height,
                   short depth_mode,short depth_format)
{
    env->frame.register_id=0x4d;
    env->frame.value.raw=((u64)((width>>6)&63)<<16)|((u64)(format&15)<<24);
    env->zbuf.register_id=0x4f;
    if(depth_mode==0)
        env->zbuf.value.raw=(u64)(s64)func_001009C8(format,width,height)|((u64)(depth_format&15)<<24)|(1ULL<<32);
    else env->zbuf.value.raw=(u64)(s64)func_001009C8(format,width,height)|((u64)(depth_format&15)<<24);
    env->xyoffset.register_id=0x19;
    env->xyoffset.value.raw=((u64)(2048-(s64)(short)(width>>1))<<4)|((u64)(2048-(s64)(short)(height>>1))<<36);
    env->scissor.register_id=0x41;
    env->scissor.value.raw=((u64)(s64)(width-1)<<16)|((u64)(s64)(height-1)<<48);
    env->prmodecont.register_id=0x1a;
    env->prmodecont.value.bits.enable=1;
    env->colclamp.register_id=0x46;
    env->colclamp.value.bits.enable=1;
    env->dthe.register_id=0x45;
    if(format&2)env->dthe.value.bits.enable=1;
    else env->dthe.value.bits.enable=0;
    env->test.register_id=0x48;
    if(depth_mode)env->test.value.raw=0x10000ULL|((u64)(depth_mode&3)<<17);
    else env->test.value.raw=0x30000;
    __asm__ volatile("sync" : : : "memory");
    return 8;
}
