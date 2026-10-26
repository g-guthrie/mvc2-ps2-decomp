typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct S3228 { u8 pad0[4]; s32 f4; s32 pad8; s32 fC; u8 pad[0x32]; s16 h42; s16 h44; } S3228;
extern s32 func_003FFF90(s32);
extern void func_003FF270(s32 *, s32, s32);
void func_00403228(S3228 *p)
{
    if (func_003FFF90(p->f4) == 1) {
        if (p->h42 == -0x80) func_003FF270((s32 *)p->fC, 0, 0);
        else func_003FF270((s32 *)p->fC, 0, p->h42);
    } else {
        if (p->h42 == -0x80) func_003FF270((s32 *)p->fC, 0, -15);
        else func_003FF270((s32 *)p->fC, 0, p->h42);
        if (p->h44 == -0x80) func_003FF270((s32 *)p->fC, 1, 15);
        else func_003FF270((s32 *)p->fC, 1, p->h44);
    }
}
