typedef unsigned char u8;
typedef short s16;
extern void func_0015D090(float *);
extern void func_001E3C40(u8 *);
void func_0015D010(u8 *p,const float *offset){
 float position[3];
 if(*(s16 *)(p+320)!=0)position[0]=*(float *)(p+52)-offset[0];
 else position[0]=*(float *)(p+52)+offset[0];
 position[1]=*(float *)(p+56)+offset[1];
 position[2]=*(float *)(p+60);
 func_0015D090(position);
 func_001E3C40(p);
}
