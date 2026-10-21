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
int func_00100A90(GsDrawEnvironment *env,short format,short width,short height,
                   short depth_mode,short depth_format)
{
    env->frame.register_id=0x4c;
    env->frame.value.raw=((u64)(((width+63)>>6)&63)<<16)|((u64)(format&15)<<24);
    env->zbuf.register_id=0x4e;
    if(depth_mode==0)
        env->zbuf.value.raw=(u64)(s64)func_001009C8(format,width,height)|((u64)(depth_format&15)<<24)|(1ULL<<32);
    else env->zbuf.value.raw=(u64)(s64)func_001009C8(format,width,height)|((u64)(depth_format&15)<<24);
    env->xyoffset.register_id=0x18;
    env->xyoffset.value.raw=((u64)(2048-(s64)(short)(width>>1))<<4)|((u64)(2048-(s64)(short)(height>>1))<<36);
    env->scissor.register_id=0x40;
    env->scissor.value.raw=((u64)(s64)(width-1)<<16)|((u64)(s64)(height-1)<<48);
    env->prmodecont.register_id=0x1a;
    env->prmodecont.value.bits.enable=1;
    env->colclamp.register_id=0x46;
    env->colclamp.value.bits.enable=1;
    env->dthe.register_id=0x45;
    if(format&2)env->dthe.value.bits.enable=1;
    else env->dthe.value.bits.enable=0;
    env->test.register_id=0x47;
    if(depth_mode)env->test.value.raw=0x10000ULL|((u64)(depth_mode&3)<<17);
    else env->test.value.raw=0x30000;
    __asm__ volatile("sync" : : : "memory");
    return 8;
}

int func_00100C78(GsRegisterPair *packet,short test,short x,short y,short width,short height,u8 red,u8 green,u8 blue,u8 alpha,u32 depth) {
 u64 color=(u64)red | ((u64)green<<8) | ((u64)blue<<16) | ((u64)alpha<<24) | 0x3f80000000000000ULL;
 u64 first=(u64)((int)x*16) | ((u64)((int)y*16)<<16) | ((u64)depth<<32);
 u64 last=(u64)(((int)x+width)*16) | ((u64)(((int)y+height)*16)<<16) | ((u64)depth<<32);
 packet[0].register_id=0x47;packet[0].value.raw=0x30000;
 packet[1].value.raw=6;packet[1].register_id=0;
 packet[2].register_id=1;packet[2].value.raw=color;
 packet[3].value.raw=first;packet[3].register_id=5;
 packet[4].register_id=5;packet[4].value.raw=last;
 packet[5].register_id=0x47;
 if(test)packet[5].value.raw=0x10000ULL|((u64)(test&3)<<17);
 else packet[5].value.raw=0x30000;
 __asm__ volatile("sync" : : : "memory");
 return 6;
}
