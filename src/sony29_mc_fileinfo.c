/* Memory-card file metadata and rename RPCs. Reconstructed from the complete native routine.
 * The packet layout and 32-byte rename field are independently corroborated
 * by ps2dev/ps2sdk libmc, revision 01d625018c3f (2004-04-15).
 * The native library additionally owns server/semaphore error handling. */
typedef struct { unsigned char header[0x24]; void *server; } McRpcClient;
typedef struct {
 int port,slot,flags,maximum_entries;
 void *table;
 char name[1024];
} McNameCommand;
typedef struct { char metadata[32]; char name[32]; } McFileInfo;
extern McRpcClient D_004C8900;
extern McNameCommand D_004C89B0;
extern McFileInfo D_004C8940;
extern int D_0043B404,D_0043B400,D_004C9EC0;
extern int func_00103E30(int);
extern int func_00103E00(int);
extern void func_00104060(int);
extern char *func_00120440(char *,const char *,unsigned int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_00111258(int port,int slot,const char *old_name,const char *new_name)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!old_name || !old_name[0] || !new_name){
  func_00103E00(D_0043B404);
  return -210;
 }
 D_004C89B0.port=port;
 D_004C89B0.slot=slot;
 D_004C89B0.flags=0x10;
 func_00120440(D_004C89B0.name,old_name,1023);
 D_004C89B0.name[1023]=0;
 func_00120440(D_004C8940.name,new_name,32);
 D_004C8940.name[31]=0;
 D_004C89B0.table=&D_004C8940;
 func_00104060(0);
 result=func_00106E68(&D_004C8900,14,1,&D_004C89B0,0x414,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=19;
 else func_00103E00(D_0043B404);
 return result;
}

extern void *memcpy(void *,const void *,unsigned int);
int func_00111090(int port,int slot,const char *name,const McFileInfo *info,unsigned int flags)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!name || !name[0]){
  func_00103E00(D_0043B404);
  return -210;
 }
 D_004C89B0.port=port;
 D_004C89B0.slot=slot;
 flags &= 7;
 D_004C89B0.flags=flags;
 memcpy(&D_004C8940,info,64);
 D_004C89B0.table=&D_004C8940;
 func_00120440(D_004C89B0.name,name,1023);
 D_004C89B0.name[1023]=0;
 func_00104060(0);
 result=func_00106E68(&D_004C8900,14,1,&D_004C89B0,0x414,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=14;
 else func_00103E00(D_0043B404);
 return result;
}

extern void func_00106578(void *,int);
extern char D_004C8EC0[];
extern unsigned int func_0011FFA0(const char *);
extern void *func_0011D740(void *,const void *,unsigned int);

/* RPC completion copies from the CPU's uncached alias of the DMA buffer. */
void func_00110C28(void *destination)
{
 unsigned int length;
 if(destination){
  length=func_0011FFA0((const char *)((unsigned int)D_004C8EC0|0x20000000))<1024
   ?func_0011FFA0((const char *)((unsigned int)D_004C8EC0|0x20000000)):1023;
  func_0011D740(destination,(const char *)((unsigned int)D_004C8EC0|0x20000000),length);
  ((char *)destination)[length]=0;
 }
}
int func_00110CB0(int port,int slot,const char *name,char *current_directory)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!name || !name[0]){func_00103E00(D_0043B404);return -210;}
 D_004C89B0.port=port;
 D_004C89B0.table=D_004C8EC0;
 D_004C89B0.slot=slot;
 func_00120440(D_004C89B0.name,name,1023);
 D_004C89B0.name[1023]=0;
 func_00106578(D_004C8EC0,1024);
 result=func_00106E68(&D_004C8900,12,1,&D_004C89B0,0x414,&D_004C9EC0,4,func_00110C28,current_directory);
 if(result==0)D_0043B400=12;
 else func_00103E00(D_0043B404);
 return result;
}
int func_00110AE0(int port,int slot,const char *name,unsigned int flags,int maximum_entries,McFileInfo *table)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!name || !name[0]){func_00103E00(D_0043B404);return -210;}
 D_004C89B0.port=port;
 D_004C89B0.slot=slot;
 D_004C89B0.flags=flags;
 D_004C89B0.maximum_entries=maximum_entries;
 D_004C89B0.table=table;
 func_00120440(D_004C89B0.name,name,1023);
 D_004C89B0.name[1023]=0;
 if(maximum_entries>=0)func_00106578(table,maximum_entries*64);
 result=func_00106E68(&D_004C8900,13,1,&D_004C89B0,0x414,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=13;
 else func_00103E00(D_0043B404);
 return result;
}
int func_00110EC0(int port,int slot,const char *name)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!name || !name[0]){func_00103E00(D_0043B404);return -210;}
 func_00120440(D_004C89B0.name,name,1023);
 D_004C89B0.port=port;
 D_004C89B0.slot=slot;
 D_004C89B0.name[1023]=0;
 D_004C89B0.flags=0;
 result=func_00106E68(&D_004C8900,15,1,&D_004C89B0,0x414,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=15;
 else func_00103E00(D_0043B404);
 return result;
}
