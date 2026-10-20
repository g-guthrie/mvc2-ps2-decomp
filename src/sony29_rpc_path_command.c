/* Complete native guarded RPC command with a 252-byte path field. */
typedef unsigned int u32;
typedef struct {int value;char path[252];} PathCommand;
extern int D_00438318;
extern PathCommand D_004C6D80;
extern char D_004C6CC0[];
extern u32 D_004C6D00[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void(*)(void*),void *);
int func_0010AE58(const char *path,int value)
{
 int length;
 if(D_00438318<0)return 0;
 for(length=0;length<252&&(D_004C6D80.path[length]=path[length]);length++);
 if(length==252){D_004C6D80.path[251]=0;length=251;}
 D_004C6D80.value=value;
 D_004C6D80.path[251]=0;
 if(func_00106E68(D_004C6CC0,3,0,&D_004C6D80,length+5,D_004C6D00,4,0,0)<0)return -1;
 return D_004C6D00[0];
}
