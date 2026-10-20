/* Reconstructed Sony pad RPC setting requests; complete native functions. */
extern unsigned char D_004C85C0[];
typedef struct { int command,port,slot; unsigned char values[6]; int result; } DirectRequest;
typedef struct { int command,port,slot; unsigned char values[12]; int reserved24,result; } VrefRequest;
extern char D_004C8380[];
extern int func_00106E68(void *,int,int,void *,int,void *,int,void (*)(void *),void *);
extern int func_0010DA40(int,int,int);
extern void *memcpy(void *,const void *,unsigned int);
int func_0010E020(int port,int slot,const unsigned char *actuators)
{
 DirectRequest *packet=(DirectRequest *)D_004C85C0;
 int i,ret;
 packet->command=8;
 packet->port=port;
 packet->slot=slot;
 for(i=0;i<6;i++)packet->values[i]=actuators[i];
 if(func_00106E68(D_004C8380,1,0,packet,128,packet,128,0,0)<0)return 0;
 ret=packet->result;
 if(ret==1){func_0010DA40(port,slot,2);ret=packet->result;}
 return ret;
}
int func_0010E370(int port,int slot,const unsigned char *parameters)
{
 VrefRequest *packet=(VrefRequest *)D_004C85C0;
 int ret;
 packet->port=port;
 packet->command=11;
 packet->slot=slot;
 memcpy(packet->values,parameters,12);
 if(func_00106E68(D_004C8380,1,0,packet,128,packet,128,0,0)<0)return 0;
 ret=packet->result;
 if(ret==1){func_0010DA40(port,slot,2);ret=packet->result;}
 return ret;
}
