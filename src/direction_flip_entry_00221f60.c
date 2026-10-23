/* Set the facing-dependent offset and restart the animation. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_001266A0(u8 *,int,int),func_0015D010(u8 *,const float *);
extern void func_0018C6E0(void *);
extern int func_001757E0(u8 *,int,int);
void func_00221F60(u8 *p)
{
 float offset[4];
 p[0x1B4]=10;func_001266A0(p,5,5);
 *(s16*)(p+0x140)^=1;p[0x1E6]^=1;
 if(*(u16*)(p+0x20E)&0x400) {*(s16*)(p+0x140)^=1;p[0x1E6]^=1;}
 offset[0]=-80.0f;offset[1]=158.5714263916015625f;
 func_0015D010(p,offset);func_0018C6E0(p);p[6]=0;func_001757E0(p,15,2);
}
