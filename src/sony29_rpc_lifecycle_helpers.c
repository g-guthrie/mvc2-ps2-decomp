/* Complete native reset and default-name RPC convenience operations. */
typedef unsigned int u32;
typedef struct {u32 first,second;} ReplyPair;
extern int D_00438320;
extern u32 D_004C70A8;
extern const char D_004AB1A8[];
extern void *func_0011D8F8(void *,int,unsigned int);
extern int func_0010BBD8(const char *,const char *,ReplyPair *,int);
int func_0010B328(void)
{
 D_00438320=-1;
 func_0011D8F8(&D_004C70A8,0,4);
 return 0;
}
int func_0010BD00(const char *name,ReplyPair *reply)
{
 return func_0010BBD8(name,D_004AB1A8,reply,1);
}
