/* Native SIF RPC server queue operations and received CALL dispatch.
 * The server and queue layouts are corroborated by public SIF RPC headers. */
#include "sony29_rpc_packet_header.h"
typedef struct RpcServer RpcServer;
typedef struct SonyRpcQueue RpcQueue;
struct RpcServer {
 int sid;void *(*function)(int,void *,int);void *buffer;int size;
 void *(*callback)(int,void *,int);void *callback_buffer;int size2;
 SonyRpcClient *client;void *packet;int number;
 void *receive_buffer;int receive_size,receive_mode,rpc_id;
 RpcServer *link,*next;RpcQueue *queue;
};
struct SonyRpcQueue {int thread,active;RpcServer *servers,*first,*last;RpcQueue *next;};
extern int func_0010CA20(void);
extern void func_0010CA68(void);
RpcServer *func_00107200(RpcServer *server,RpcQueue *queue)
{
 RpcServer *current;
 func_0010CA20();
 current=queue->servers;
 if(current==server)queue->servers=current->link;
 else{
  while(current){
   if(current->link==server){current->link=server->link;break;}
   current=current->link;
  }
 }
 func_0010CA68();return current;
}

extern SonyRpcPacketPool D_004C5480;
RpcQueue *func_00107298(RpcQueue *queue)
{
 RpcQueue *current;
 func_0010CA20();
 current=D_004C5480.queues;
 if(current==queue)D_004C5480.queues=current->next;
 else{
  while(current){
   if(current->next==queue){current->next=queue->next;break;}
   current=current->next;
  }
 }
 func_0010CA68();return current;
}
