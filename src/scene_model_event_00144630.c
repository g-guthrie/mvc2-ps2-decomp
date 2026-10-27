#include "model_callback_api.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {u8 *actor; int zero;} Context;
typedef struct {u8 pad[0x14]; EL_d *elements; u8 pad2[4]; ND_d **nodes;} Resource;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 *D_004C2808 __attribute__((section(".sdata")));
extern void func_003DAA40(u8 *);
typedef float f32;
extern f32 data_f32_004B31E0[3], data_f32_004B31EC[3];
static void func_001444D0(u8 *p) {
    f32 *b = (f32 *)&data_f32_004B31EC;
    *(f32 *)(p + 0x34) = data_f32_004B31E0[0] + (f32)*(s16 *)(p + 0x1C) * (b[0] - data_f32_004B31E0[0]) / 60.0f;
    *(f32 *)(p + 0x38) = data_f32_004B31E0[1] + (f32)*(s16 *)(p + 0x1C) * (b[1] - data_f32_004B31E0[1]) / 60.0f;
    *(f32 *)(p + 0x3C) = data_f32_004B31E0[2] + (f32)*(s16 *)(p + 0x1C) * (b[2] - data_f32_004B31E0[2]) / 60.0f;
    *(f32 *)(p + 0x34) /= 10.0f;
    *(f32 *)(p + 0x38) /= 10.0f;
    *(f32 *)(p + 0x3C) /= 10.0f;
}

extern void func_001446F0(u8 *,u8 *,int);
/* Provisional: model resource lifetime and node bounds require complete path proof. */
void func_00144630(u8 *p)
{
    Resource *r;
    Context context;
    int timer;
    if ((s8)D_004C2840[2] != 5) {func_003DAA40(p);return;}
    timer = *(s16 *)(p+0x1c);
    if (timer != 60) {
        *(s16 *)(p+0x1c) = timer + 1;
        func_001444D0(p);
    } else {
        *(s16 *)(p+0x1e) += 20;
        if (*(s16 *)(p+0x1e) >= 360) *(s16 *)(p+0x1e)=0;
        r=*(Resource **)(p+0x84);
        context.actor=p;context.zero=0;
        func_00170E60(((Resource *)D_004C2808)->elements,r->nodes[5],r->elements,r->nodes[*(s16 *)(p+0xcc)],func_001446F0,(int)&context);
    }
}
