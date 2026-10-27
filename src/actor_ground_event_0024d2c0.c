typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef float f32;
extern int func_00175700(u8 *);extern void func_0015D010(u8 *,const f32 *);extern void func_00184540(void *);
static void func_0024B9B0(u8 *a0)
{
    *(f32 *)(a0 + 52) += *(f32 *)(a0 + 92);
    *(f32 *)(a0 + 92) += *(f32 *)(a0 + 104);
    *(f32 *)(a0 + 56) += *(f32 *)(a0 + 96);
    *(f32 *)(a0 + 96) += *(f32 *)(a0 + 108);
    if (*(f32 *)(a0 + 1072) >= *(f32 *)(a0 + 56)) {
        *(f32 *)(a0 + 56) = *(f32 *)(a0 + 1072);
    }
}
void func_0024D2C0(u8 *p) {u8 *q;f32 offset[3];func_0024B9B0(p);func_00175700(p);if(*(s8 *)(p+0x150)==1){p[0x150]=0;offset[0]=-101.66666412353515625f;offset[1]=124.28571319580078f;func_0015D010(p,offset);p[0x1b4]=10;}if(*(s8 *)(p+0x151)!=0){p[6]++;q=*(u8 **)(p+0x1dc);*(u8 **)(q+0x1c8)=p;q[0x20a]=1;q[0x20d]=2;q[0x1b5]=33;q[0x1e6]=*(s8 *)(p+0x1e6)^1;if(*(u16 *)(p+0x160)==0)func_00184540(p);}}
