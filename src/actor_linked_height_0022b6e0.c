/* Raise the linked actor by its table-dependent height and initialize the animation. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 D_00451B20[];
extern void func_0015D010(u8 *,const float *),func_001266A0(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_0022B6E0(u8 *p)
{
 /* Native reserves three floats; the offset helper reads only the first two. */
 float offset[3];
 u8 *q;
 u32 rise;
 offset[0]=-110.0f;offset[1]=171.42855834960938f;
 func_0015D010(p,offset);
 if(p[0x425]==0)func_001266A0(p,5,5);
 p[0x1B4]=10;
 q=*(u8**)(p+0x1DC);
 rise=D_00451B20[q[1]];
 *(float*)(q+0x38)+=2.142857074737549f*rise;
 *(short*)(p+0x1C)=64;
 func_001757E0(p,15,0);
}
