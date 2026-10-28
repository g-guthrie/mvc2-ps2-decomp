typedef unsigned char u8;typedef signed char s8;typedef int s32;
#include "data/button_config_render.h"
extern ButtonConfigRenderRecord data_button_config_render_004B36E0[];
extern s8 D_00443BE0[];
extern char gPlayerFormat_004B3890[];
extern void func_003D7350(u8,u8,u8,const char *,...);
extern void func_00148D40(u8 *,s32,s32);
void func_00149690(u8 *p) {
 s32 i,y; ButtonConfigRenderRecord *r;
 func_003D7350((u8)(30+53*(s8)p[1]),36,(u8)(32+(s8)p[1]),gPlayerFormat_004B3890,(s8)p[1]+1);
 func_00148D40(p,12,8);func_00148D40(p,38,4);
 p[12]=D_00443BE0[(s8)p[0]*2];
 for(i=0,y=0;i<8;i++,y+=4){
  r=&data_button_config_render_004B36E0[(s8)p[4+i]+22];
  func_003D7350((u8)(r->rendererArgs[0]+53*(s8)p[1]),(u8)(r->rendererArgs[1]+y),(u8)(r->rendererArgs[3]+i),(const char *)r->resource);
 }
 r=&data_button_config_render_004B36E0[(s8)p[2]+34];
 func_003D7350((u8)(r->rendererArgs[0]+53*(s8)p[1]),r->rendererArgs[1],r->rendererArgs[3],(const char *)r->resource);
 r=&data_button_config_render_004B36E0[(s8)p[3]+36];
 func_003D7350((u8)(r->rendererArgs[0]+53*(s8)p[1]),r->rendererArgs[1],r->rendererArgs[3],(const char *)r->resource);
}
