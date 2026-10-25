/* Initialize the draw record and its attribute range before the action transition. */
#pragma padloop on
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef struct {u8 pad[8];int enabled;u8 padC[4];u16 attributes[16];} DrawRecord;
extern DrawRecord D_004F54D0[];
extern void func_00185490(u8 *),func_00175C00(u8 *,int),func_0018C4B0(u8 *,int),func_001E3210(u8 *,u8),func_00183D10(u8 *),func_0027BF30(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_0027BD90(u8 *p)
{
 DrawRecord *row;
 int column,index;
 ++p[6];*(int*)(p+0x2F8)=0;func_00185490(p);func_00175C00(p,0);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x118)=1;
 index=*(s16*)(p+0x13E);index+=3;row=&D_004F54D0[index];row->enabled=1;
 for(column=4;column<=15;column++)row->attributes[column]=(row->attributes[column]&0xFFF)|0x8000;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;
 func_0018C4B0(p,5);func_001757E0(p,3,0);func_001E3210(p,10);func_00183D10(p);func_0027BF30(p);
}
