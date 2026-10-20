/* Complete native SIF RPC server and queue registration. */
#include "sony29_rpc_server_types.h"
extern SonyRpcPacketPool D_004C5480;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
void func_00107098(SonyRpcQueue *queue,int thread)
{
 SonyRpcQueue *current;
 func_0010CA20();
 queue->thread=thread;queue->active=0;queue->servers=0;queue->first=0;queue->last=0;queue->next=0;
 if(!D_004C5480.queues)D_004C5480.queues=queue;
 else{
  for(current=D_004C5480.queues;current->next;current=current->next);
  current->next=queue;
 }
 func_0010CA68();
}
void func_00107130(SonyRpcServer *server,int sid,SonyRpcFunction function,void *buffer,SonyRpcFunction callback,void *callback_buffer,SonyRpcQueue *queue)
{
 SonyRpcServer *current;
 func_0010CA20();
 server->next=0;server->link=0;server->sid=sid;
 server->function=function;server->buffer=buffer;server->callback=callback;server->callback_buffer=callback_buffer;server->queue=queue;
 if(!queue->servers)queue->servers=server;
 else{
  for(current=queue->servers;current->link;current=current->link);
  current->link=server;
 }
 func_0010CA68();
}
