typedef unsigned char u8; typedef signed short s16; typedef float f32;
extern void func_0015D010(u8 *,const f32 *);
extern void func_0018C6E0(void *);
extern void func_001266A0(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_00214AA0(u8 *p) { f32 offset[3];offset[0]=53.333332061767578125f;offset[1]=171.428558349609375f;func_0015D010(p,offset);p[0x1b4]=10;func_0018C6E0(p);func_001757E0(p,15,0);}
void func_00269F50(u8 *p) { f32 offset[3];offset[0]=-53.333332061767578125f;offset[1]=171.428558349609375f;func_0015D010(p,offset);p[0x1b4]=10;func_0018C6E0(p);func_001266A0(p,13,6);p[0x20d]=2;func_001757E0(p,15,0);}
void func_0024D060(u8 *p) {if(p[0x22]&1){p[0x1e6]^=1;*(s16 *)(p+0x140)=p[0x1e6];}func_0018C6E0(p);func_001757E0(p,15,0);}
