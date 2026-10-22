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

int func_001105D0(int fd,unsigned char *buffer,int size)
{
 int result;
 unsigned int i;
 if(!D_004C8900.server)return -100;
 if(func_00103E30(D_0043B404)<0)return -200;
 D_004C8980.fd=fd;
 if(size<=16){
  D_004C8980.origin=size;
  D_004C8980.size=0;
  D_004C8980.buffer=0;
 }else{
  unsigned int b=(unsigned int)buffer;
  unsigned int t=b-16;
  int head=((b-1)&0xFFFFFFF0u)-t;
  D_004C8980.size=size-head;
  D_004C8980.origin=head;
  D_004C8980.buffer=buffer+head;
 }
 for(i=0;i<D_004C8980.origin;i++)D_004C8980.data[i]=buffer[i];
 func_00104060(0);
 result=func_00106E68(&D_004C8900,6,1,&D_004C8980,48,&D_004C9EC0,4,0,0);
 if(result==0)D_0043B400=6;
 else func_00103E00(D_0043B404);
 return result;
}
