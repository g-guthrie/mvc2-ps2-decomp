typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 velocity,acceleration; } MotionPair;
extern MotionPair D_004535B0[];
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8 *);
#define RESET_ACTION(value) do { \
    u32 offset; \
    p[0x1B5]=(value); \
    p[0x1B2]=*(u16 *)(p+0x1C0)=0; \
    *(u32 *)(p+0x1D8)=0; \
    offset=p[2]*2; offset+=(u32)D_004C2794; offset+=0x7C; \
    ++*(s16 *)offset; \
} while(0)
void func_00259400(u8 *p)
{
    MotionPair *motion;
    p[6]++;
    if (p[0x269]==3) {
        RESET_ACTION(85);
    } else {
        RESET_ACTION(*(s8 *)(p+0x1B7)+50);
    }
    motion=D_004535B0;
    motion+=p[0x1B7];
    *(f32 *)(p+0x5C)=p[0x1E6] ? -motion->velocity : motion->velocity;
    *(f32 *)(p+0x68)=p[0x1E6] ? -motion->acceleration : motion->acceleration;
    func_00183D10(p);
}
