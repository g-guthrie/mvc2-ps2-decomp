#include "sony_pad_slot.h"
extern char D_004C8380[];
extern int D_004C85C0[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010D4A0(void)
{
 int i;
 for(i=0;i<4;++i){
  D_004C83D0[0][i].enabled=0;
  D_004C83D0[0][i].tail[1]=0;
  D_004C83D0[0][i].tail[0]=0;
  D_004C83D0[1][i].enabled=0;
  D_004C83D0[1][i].tail[1]=0;
  D_004C83D0[1][i].tail[0]=0;
 }
 D_004C85C0[0]=16;
 D_004C85C0[4]=0;
 if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;
 return D_004C85C0[3];
}
