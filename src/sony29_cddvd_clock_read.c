/* Complete native CD/DVD clock reply: eight bytes after the status word. */
typedef unsigned char u8;
typedef unsigned int u32;
/* Eight-byte sceCdCLOCK layout, corroborated by public PS2SDK
 * libcdvd-common.h at 329e2bb43287e16af16c4dde1c614e2662c24468. */
typedef struct {u8 stat,second,minute,hour,pad,day,month,year;} SonyCdClock;
extern int D_00439990,D_004399AC;
extern u8 D_0043AB80[],D_0043B3C8[];
extern char D_004AB598[],D_004AB5B8[];
extern int func_0010F258(int),func_00103E00(int),func_00105E80(const char *,...);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void(*)(void*),void *);
extern void *memcpy(void *,const void *,unsigned int);
int func_0010FC98(SonyCdClock *clock)
{
 int result;
 if(!func_0010F258(15))return 0;
 if(D_00439990>0)func_00105E80(D_004AB598);
 if(func_00106E68(D_0043B3C8,1,0,0,0,D_0043AB80,16,0,0)<0){func_00103E00(D_004399AC);return 0;}
 memcpy(clock,(void *)((u32)(D_0043AB80+4)|0x20000000u),sizeof(*clock));
 if(D_00439990>0)func_00105E80(D_004AB5B8);
 result=*(int *)((u32)D_0043AB80|0x20000000u);
 func_00103E00(D_004399AC);return result;
}
