#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 prefix[0x38];float y;u8 pad3C[0x24];float vy;} Motion;
extern float D_0045E48C;
extern int func_003D90A0(int),func_00417A40(void),func_00119BC0(double);
extern double func_00119B08(int);
void func_0032FC00(u8 *p)
{
 Motion *motion=(Motion*)p;
 switch(p[4]){
 case 0:
  if(func_003D90A0(0)){
   ++p[4];motion->vy=20.0f;
   *(unsigned int*)(p+0x40)=(u16)func_00119BC0(0.5+65536.0*func_00119B08(func_00417A40()%5)/360.0);
   *(int*)(p+0x48)=*(int*)(p+0x40)/30;
  }break;
 case 1:
  motion->y+=motion->vy;
  if(motion->vy<=0.0f)motion->vy+=-0.4000000059604645f;
  else{motion->vy+=-2.0f;*(int*)(p+0x44)+=*(int*)(p+0x40);*(int*)(p+0x40)-=*(int*)(p+0x48);}
  if(motion->y<50.0f+D_0045E48C&&motion->vy<0.0f){++p[4];motion->y=50.0f+D_0045E48C;motion->vy=0.0f;}
  break;
 case 2:
  motion->y+=motion->vy;motion->vy+=-0.4000000059604645f;
  if(motion->y<D_0045E48C){motion->y=D_0045E48C;p[4]=0;}
  break;
 }
}
