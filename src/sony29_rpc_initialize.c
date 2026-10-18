typedef struct {
 int reserved[4];
 int first;
 int second;
 int third;
} Slot;
extern Slot D_004C83D0[];
extern char D_004C8380[];
extern int D_004C85C0[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010D4A0(void)
{
 int i;
 for(i=0;i<4;++i){
  D_004C83D0[i].first=0;
  D_004C83D0[i].third=0;
  D_004C83D0[i].second=0;
  D_004C83D0[i+4].first=0;
  D_004C83D0[i+4].third=0;
  D_004C83D0[i+4].second=0;
 }
 D_004C85C0[0]=16;
 D_004C85C0[4]=0;
 if(func_00106E68(D_004C8380,1,0,D_004C85C0,128,D_004C85C0,128,0,0)<0)return 0;
 return D_004C85C0[3];
}
