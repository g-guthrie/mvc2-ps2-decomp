typedef unsigned char u8;typedef short s16;typedef float f32;
extern void func_001266A0(u8 *,int,int),func_002FFB00(u8 *,u8 *),func_0018C6E0(void *),func_0015D010(u8 *,const float *),func_001D91E0(u8 *,u8,u8);
extern int func_001757E0(u8 *,int,int);
void func_002FF410(u8 *p) { f32 v[3];func_001266A0(p,5,5);*(f32 *)(p+0x5c)=0;*(f32 *)(p+0x60)=0;*(f32 *)(p+0x68)=0;*(f32 *)(p+0x6c)=0;p[0x1b4]=10;func_001757E0(p,15,0);func_002FFB00(p,(u8 *)((int)p+0x2b8));v[0]=-85.0f;v[1]=177.8571319580078f;v[2]=0;func_0015D010(p,v);func_0018C6E0(p);*(s16 *)(p+0x1c)=60;func_001D91E0(p,2,0);func_001D91E0(p,2,1);(*(u8 **)(p+0x220))[0x21]=1;}
