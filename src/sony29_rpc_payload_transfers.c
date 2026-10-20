/* Complete native Sony RPC operations with bounded inline payloads. */
typedef unsigned char u8;
typedef struct {int value,length;char name[252];u8 payload[252];} PayloadPacket;
extern PayloadPacket D_004C6E80;
extern u8 D_004C7080[];
extern int func_0010B198(void);
extern int func_0010B298(void);
extern void *memcpy(void *,const void *,unsigned int);
extern void *func_0011D740(void *,const void *,unsigned int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010B360(int value,int size,const void *data,int *length)
{
 int result;
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 D_004C6E80.value=value;
 if(data){
  if(size>=253){memcpy(D_004C6E80.payload,data,252);D_004C6E80.length=252;}
  else{func_0011D740(D_004C6E80.payload,data,size);D_004C6E80.length=size;}
 }else D_004C6E80.length=0;
 if(func_00106E68(D_004C7080,6,0,&D_004C6E80,512,&D_004C6E80,8,0,0)<0)return -65537;
 result=D_004C6E80.value;
 *length=D_004C6E80.length;
 return result;
}
int func_0010B568(int value,int size,const void *data,int *length)
{
 int result;
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 D_004C6E80.value=value;
 if(data){
  if(size>=253){memcpy(D_004C6E80.payload,data,252);D_004C6E80.length=252;}
  else{func_0011D740(D_004C6E80.payload,data,size);D_004C6E80.length=size;}
 }else D_004C6E80.length=0;
 if(func_00106E68(D_004C7080,7,0,&D_004C6E80,512,&D_004C6E80,8,0,0)<0)return -65537;
 result=D_004C6E80.value;
 *length=D_004C6E80.length;
 return result;
}

extern char *func_00120440(char *,const char *,unsigned int);
int func_0010B970(const char *name,int size,const void *data,int *length,int operation)
{
 int result;
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 func_00120440(D_004C6E80.name,name,252);
 D_004C6E80.name[251]=0;
 if(data){
  if(size>=253){memcpy(D_004C6E80.payload,data,252);D_004C6E80.value=252;}
  else{func_0011D740(D_004C6E80.payload,data,size);D_004C6E80.value=size;}
 }else{
  D_004C6E80.payload[0]=0;
  D_004C6E80.value=0;
 }
 if(func_00106E68(D_004C7080,operation,0,&D_004C6E80,512,&D_004C6E80,8,0,0)<0)return -65537;
 result=D_004C6E80.value;
 *length=D_004C6E80.length;
 return result;
}
