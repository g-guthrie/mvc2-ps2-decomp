#pragma padloop on
typedef unsigned char u8;
typedef short s16;
typedef struct {u8 prefix[0x5C];float vx,vy,offset,distance;} Motion;
extern float D_004F1FC8,D_004F1FCC;
extern float func_00117078(float);
extern int func_00175700(u8*),func_001757E0(u8*,int,int);
extern void func_0034C020(u8*,int,int),func_001E7F60(u8*);
void func_0034C450(u8 *p)
{
 float travelled;int advance=0;u8 *parent=*(u8**)(p+0x18);Motion *motion=(Motion*)p;
 if(*(s16*)(p+0x140)){
  if(*(float*)(p+0x34)>D_004F1FCC-106.66666412353516f)advance=1;
 }else if(*(float*)(p+0x34)<106.66666412353516f+D_004F1FC8)advance=1;
 if(advance){++p[6];*(s16*)(p+0x1C)=8;func_001757E0(p,22,18);}
 motion->offset+=motion->vx;*(float*)(p+0x34)=*(float*)(parent+0x34)+motion->offset;
 travelled=func_00117078(motion->vx);travelled=motion->distance+travelled;motion->distance=travelled;
 if(travelled>80.0f){
  motion->distance=travelled-80.0f;++p[0x22];func_0034C020(p,1,p[0x22]);
 }
 func_00175700(p);func_001E7F60(p);
}
