/* Complete native Sony string-record and scalar-access RPC operations. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {u8 byte;u16 half;u32 word;} Scalar;
typedef struct {
 Scalar value;u32 width;
 union {char name[252];Scalar scalar;} input;
 char second[252];
} RpcPacket;
typedef struct {u32 first,second;} ReplyPair;
extern RpcPacket D_004C6E80;
extern u8 D_004C7080[];
extern int func_0010B198(void);
extern int func_0010B298(void);
extern char *func_00120440(char *,const char *,unsigned int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
int func_0010B800(const char *name)
{
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 func_00120440(D_004C6E80.input.name,name,252);
 D_004C6E80.input.name[251]=0;
 if(func_00106E68(D_004C7080,9,0,&D_004C6E80,512,&D_004C6E80,4,0,0)<0)return -65537;
 return D_004C6E80.value.word;
}
int func_0010BBD8(const char *name,const char *second,ReplyPair *reply,int operation)
{
 u32 first;
 if(func_0010B198()<0)return -65536;
 if(func_0010B298())return -65540;
 func_00120440(D_004C6E80.input.name,name,252);
 D_004C6E80.input.name[251]=0;
 func_00120440(D_004C6E80.second,second,252);
 D_004C6E80.second[251]=0;
 if(func_00106E68(D_004C7080,operation,0,&D_004C6E80,512,&D_004C6E80,16,0,0)<0)return -65537;
 first=D_004C6E80.value.word;
 if(!first)return -65539;
 reply->first=first;
 reply->second=D_004C6E80.width;
 return 0;
}
int func_0010BD28(u32 address,void *destination,unsigned int width)
{
 if(func_0010B198()<0)return -65536;
 if(width>=3)return -65538;
 D_004C6E80.value.word=address;
 D_004C6E80.width=width;
 if(func_00106E68(D_004C7080,3,0,&D_004C6E80,32,&D_004C6E80,32,0,0)<0)return -65537;
 if(width==0)*(u8 *)destination=D_004C6E80.value.byte;
 else if(width==1)*(u16 *)destination=D_004C6E80.value.half;
 else if(width==2)*(u32 *)destination=D_004C6E80.value.word;
 else return -65538;
 return 0;
}
int func_0010BE18(u32 address,const void *source,unsigned int width)
{
 if(func_0010B198()<0)return -65536;
 D_004C6E80.value.word=address;
 D_004C6E80.width=width;
 if(width==0)D_004C6E80.input.scalar.byte=*(const u8 *)source;
 else if(width==1)D_004C6E80.input.scalar.half=*(const u16 *)source;
 else if(width==2)D_004C6E80.input.scalar.word=*(const u32 *)source;
 else return -65538;
 if(func_00106E68(D_004C7080,2,0,&D_004C6E80,32,&D_004C6E80,16,0,0)<0)return -65537;
 return 0;
}
