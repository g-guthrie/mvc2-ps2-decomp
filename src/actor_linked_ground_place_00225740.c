/* Select the linked ground height from its native flags and place the effect. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_001266A0(u8 *,int,int),func_0015D010(u8 *,const float *),func_0018C6E0(u8 *),func_0019CD70(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00225740(u8 *p)
{
 /* Native reserves three floats; the offset helper reads only the first two. */
 float offset[3];
 u8 *q;
 func_001266A0(p,6,6);
 q=*(u8**)(p+0x1DC);
 if(*(u32*)(q+0x42C)&0x4000000)*(float*)(q+0x38)=122.14285278320312f;
 q=*(u8**)(p+0x1DC);
 if(*(u32*)(q+0x428)&0x10000000)*(float*)(q+0x38)=25.714284896850586f;
 q=*(u8**)(p+0x1DC);
 if(*(u32*)(q+0x428)&0x20000000)*(float*)(q+0x38)=55.71428298950195f;
 q=*(u8**)(p+0x1DC);
 if(*(u32*)(q+0x428)&0x400000)*(float*)(q+0x38)=30.0f;
 offset[0]=-75.0f;offset[1]=171.42855834960938f;
 func_0015D010(p,offset);
 p[0x1B4]=10;func_0018C6E0(p);func_001757E0(p,15,0);func_0019CD70(p);
}
