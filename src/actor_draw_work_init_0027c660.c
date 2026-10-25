/* Initialize draw attributes, work counters, and mode-dependent timing. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[8];int enabled;u8 padC[4];u16 attributes[16];} DrawRecord;
extern DrawRecord D_004F54D0[];
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00175C00(u8 *,int),func_0018C4B0(u8 *,int),func_00183D10(u8 *),func_0027C7D0(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_0027C660(u8 *p,u8 *work)
{
 DrawRecord *row;
 int index,column;
 s16 duration;
 ++p[6];func_00185490(p);func_00175C00(p,1);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 index=*(s16*)(p+0x13E);index+=5;row=&D_004F54D0[index];row->enabled=1;
 for(column=13;column<=15;column++)row->attributes[column]=(row->attributes[column]&0xFFF)|0x8000;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;
 work[2]=*(s8*)(p+0x539)?12:24;
 if(p[0x1B7]==0)*(s16*)(p+0x1C)=60;else *(s16*)(p+0x1C)=90;
 duration=p[0x1B7]+5;func_0018C4B0(p,duration);
 p[0x1B5]=*(s8*)(p+0x1B7)+51;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,(u8)(p[0x1B7]+6));func_00183D10(p);func_0027C7D0(p,work);
}
