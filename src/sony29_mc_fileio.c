/* Reconstructed Sony memory-card file RPCs. Packet layouts are independently
 * corroborated by ps2dev/ps2sdk libmc revision
 * 01d625018c3fde3044292446c910b8ea508adfdc (2004-04-15).
 * The native library has its own server checks and semaphore ownership. */
typedef struct { unsigned char header[0x24]; void *server; } McRpcClient;
typedef struct {
 int port,slot,flags,maximum_entries;
 void *table;
 char name[1024];
} McNameCommand;
typedef struct {
 int fd,port,slot,size,offset,origin;
 void *buffer,*parameter;
 char data[16];
} McFileCommand;
extern McRpcClient D_004C8900;
extern McNameCommand D_004C89B0;
extern McFileCommand D_004C8980;
extern char D_004C8E00[];
extern int D_0043B404,D_0043B400,D_004C9EC0;
extern int *D_004C8928,*D_004C892C,*D_004C8930;
extern int func_00103E30(int);
extern int func_00103E00(int);
extern void func_00106578(void *,int);
extern void func_00104060(int);
extern char *func_00120440(char *,const char *,unsigned int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
extern void func_00110428(void *);
extern void func_00110898(void *);
extern int func_00107058(void *);
extern void func_00110770(unsigned short);

int func_00110070(int priority)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 D_004C8980.port=priority;
 result=func_00106E68(&D_004C8900,21,0,&D_004C8980,48,&D_004C9EC0,4,0,0);
 if(result!=0){func_00103E00(D_0043B404);return result;}
 func_00103E00(D_0043B404);
 return D_004C9EC0;
}
int func_00110138(int port,int slot,const char *name,int flags)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 if(!name || !name[0]){func_00103E00(D_0043B404);return -210;}
 func_00120440(D_004C89B0.name,name,1023);
 D_004C89B0.port=port;
 D_004C89B0.flags=flags;
 D_004C89B0.slot=slot;
 D_004C89B0.name[1023]=0;
 result=func_00106E68(&D_004C8900,2,1,&D_004C89B0,0x414,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=2;
 else func_00103E00(D_0043B404);
 return result;
}
int func_001104B8(int fd,void *buffer,int size)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 D_004C8980.fd=fd;
 D_004C8980.parameter=D_004C8E00;
 D_004C8980.buffer=buffer;
 D_004C8980.size=size;
 func_00106578(buffer,size);
 func_00106578(D_004C8E00,192);
 result=func_00106E68(&D_004C8900,5,1,&D_004C8980,48,&D_004C9EC0,4,func_00110428,D_004C8E00);
 if(result==0)D_0043B400=5;
 else func_00103E00(D_0043B404);
 return result;
}
int func_001107B8(int mode,int *command,int *result)
{
 int busy;
 if(!D_0043B400)return -1;
 busy=func_00107058(&D_004C8900);
 if(mode==0 && busy){
  while(func_00107058(&D_004C8900))func_00110770(60);
  busy=0;
 }
 busy=!busy;
 if(command)*command=D_0043B400;
 if(busy){
  D_0043B400=0;
  if(result)*result=D_004C9EC0;
  func_00103E00(D_0043B404);
 }
 return busy;
}
int func_001108F0(int port,int slot,int *type,int *free_space,int *formatted)
{
 int result;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 D_004C8980.port=port;
 D_004C8980.slot=slot;
 D_004C8980.parameter=D_004C8E00;
 if(type)D_004C8980.origin=1;else D_004C8980.origin=0;
 if(free_space)D_004C8980.offset=1;else D_004C8980.offset=0;
 if(formatted)D_004C8980.size=1;else D_004C8980.size=0;
 D_004C8928=type;
 D_004C892C=free_space;
 D_004C8930=formatted;
 func_00106578(D_004C8E00,192);
 result=func_00106E68(&D_004C8900,1,1,&D_004C8980,48,&D_004C9EC0,4,func_00110898,D_004C8E00);
 if(result==0)D_0043B400=1;
 else func_00103E00(D_0043B404);
 return result;
}
