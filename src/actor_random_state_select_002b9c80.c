#pragma padloop on
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004D18BC[][3],*D_004D18C0[][3],D_004D18E6;
extern int func_00174170(void),func_001841C0(u8*),func_001757E0(u8*,int,int);
extern void func_00185490(u8*),func_002B9E60(u8*);
typedef struct CallbackEntry CallbackEntry;
extern CallbackEntry *func_001CE4A0(void*,u8);
void func_002B9C80(u8 *p)
{
 ++p[6];*(s16*)(p+0x1E)=0;*(s16*)(p+0x1C)=func_00174170()&3;
 if(func_001841C0(p)>=2)*(s16*)(p+0x1C)=0;
 switch(*(s16*)(p+0x1C)){
 case 0:func_001757E0(p,19,0);break;
 case 1:func_001757E0(p,19,3);break;
 case 2:func_001757E0(p,19,2);break;
 case 3:
  if((*(u8**)(p+0x220))[1]==38){func_00185490(p);func_001757E0(p,19,1);}
  else {
   u32 side=p[2];
   if(D_004D18BC[side][0][1]==38||D_004D18C0[side][0][1]==38||D_004D18BC[((u8)side)^1][0][1]==38||D_004D18C0[((u8)side)^1][0][1]==38)func_001757E0(p,19,0);
   else if(D_004D18E6&&func_001CE4A0(p,1)){p[6]=2;func_002B9E60(p);}
   else func_001757E0(p,19,0);
  }break;
 }
}
