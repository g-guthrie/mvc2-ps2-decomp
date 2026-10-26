typedef unsigned char u8;typedef signed char s8;
extern int func_00175700(u8*);
extern void func_001843A0(u8*),func_0015D010(u8*,const float*),func_00126400(void);
void func_0024D1E0(u8*p){
 float offset[3];
 if((s8)func_00175700(p)<0){func_001843A0(p);return;}
 if(*(s8*)(p+0x150)==1){p[0x150]=0;offset[0]=-126.66666412353516f;offset[1]=90;func_0015D010(p,offset);p[0x1B4]=10;}
 if(*(s8*)(p+0x151)==1){
  u8*owner;int direction;
  p[0x151]=0;owner=*(u8**)(p+0x1DC);*(u8**)(owner+0x1C8)=p;direction=*(s8*)(p+0x1E6)^1;owner[0x1E6]=direction;
  owner[0x20D]=2;owner[0x1B5]=32;owner[0x20A]=1;func_00126400();
 }
}
