#pragma padloop on
typedef unsigned char u8;
typedef short s16;
typedef struct {float x,y,z;} V3;
typedef struct {int mode;V3 position;} Spawn;
extern Spawn D_00460890[][10];
extern int D_004F1CDC;
extern void func_00342880(V3*,int),func_00342CA0(V3*,int),func_003DAA40(u8*);
void func_00343770(u8 *p)
{
 int j,i;
 switch(p[4]){
 case 0:++p[4];break;
 case 1:if(D_004F1CDC==1)++p[4];break;
 case 2:
  if(++*(s16*)(p+0x1C)>p[0x20]*30){
   ++p[4];
   for(i=0;i<10;++i){
    switch(D_00460890[p[0x20]][i].mode){
    case 0:for(j=0;j<4;++j)func_00342880(&D_00460890[p[0x20]][i].position,j);break;
    case 1:for(j=0;j<5;++j)if(D_00460890[p[0x20]][i].position.z < -900.0f)func_00342CA0(&D_00460890[p[0x20]][i].position,j);break;
    }
   }
  }break;
 case 3:func_003DAA40(p);break;
 }
}
