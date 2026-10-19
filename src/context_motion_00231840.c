/* Actor/context callback: 22F160 -> 451EE8 -> 231D50 -> 452010
 * -> 231CE0 -> 451FD8. Adjacent 451FDC selects helper 231800. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_00231800(u8 *,void *);
extern s16 D_00451F98[];
#define F(o,n) (*(f32 *)((o)+(n)))
void func_00231840(u8 *p,void *context)
{
    s8 step;
    if((s8)func_00175700(p)<0) {
        p[7]++;
        func_00231800(p,context);
        return;
    }
    if(*(s8 *)(p+0x150)) {
        p[0x150]=0;
        if(*(s16 *)(p+0x140)) F(p,0x34)+=53.33333206176758f;
        else F(p,0x34)-=53.33333206176758f;
    }
    step=*(s8 *)(p+0x151)&0x7F;
    if(step) {
        if(*(s16 *)(p+0x140)) F(p,0x34)+=1.6666666269302368f*(f32)D_00451F98[(s8)step]/256.0f;
        else F(p,0x34)-=1.6666666269302368f*(f32)D_00451F98[(s8)step]/256.0f;
    }
    if(*(s8 *)(p+0x151)<0) {
        u8 *child;
        p[0x151]=0;
        child=*(u8 **)(p+0x1DC);
        *(u32 *)(child+0x1C8)=(u32)p;
        child[0x1B5]=35;
        child[0x20D]=2;
        child[0x20A]=17;
        child[0x1E6]=p[0x1E6];
        p[0x1E6]=*(s8 *)(p+0x1E6)^1;
    }
}
