#pragma padloop on
typedef unsigned char u8;typedef signed char s8;
typedef struct {int value[3];} Codes;
typedef struct {float value[3];} Positions;
typedef struct {u8 pad[0x34];float x;} MenuPosition;
extern MenuPosition *D_004CAE80[][20];
extern Codes D_004440E8 __attribute__((aligned(8)));
extern Codes D_004440F8 __attribute__((aligned(8)));
extern Positions D_00444108 __attribute__((aligned(8)));
extern void func_0014C100(u8*);
static int func_0014C1D0(int i,int j) {
 float f=D_004CAE80[i][j]->x;
 if(f==-18.0f)return 0;
 if(f==-7.5f)return 1;
 if(f==0.0f)return 2;
 if(f==7.5f)return 3;
 return 4;
}
void func_0014C280(int i,int j,int k) {
 Codes first __attribute__((aligned(16)))=D_004440E8;
 Codes second __attribute__((aligned(16)))=D_004440F8;
 Positions position __attribute__((aligned(16)))=D_00444108;
 int state=func_0014C1D0(i,j);
 u8 *p=(u8*)D_004CAE80[i][j];s8 next;
 if(state>0 && state<4)next=first.value[k]+state;
 else {next=second.value[k];*(float*)(p+0x34)=position.value[k];}
 p[4]=first.value[k];p[5]=next;p[6]=1;p[7]=i;
 *(void**)(p+0x10)=(void*)func_0014C100;
}
