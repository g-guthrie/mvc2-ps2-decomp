/* Report the native temporary and IOP counts for one RNA context. */
typedef unsigned char u8;typedef signed char s8;typedef int s32;
typedef struct Obj Obj;struct VT {u8 pad[0x24];s32 (*f24)(Obj*,s32);};struct Obj {struct VT *vt;};
typedef struct {u8 pad0;s8 status;u8 pad2[10];u8 *base;} Context;
extern u8 *func_0040EF88(u8*,s32),*func_0040EF70(u8*,s32);extern s32 func_00410AD0(s32,s32);extern void func_0011EB60(const char*,...);
extern char gAdxRnaTempCountsFormat_004BBF48[],gAdxRnaIopTempCountsFormat_004BBF68[],gAdxRnaStatusTotalsFormat_004BBF88[];
void func_00401050(Context *ctx){
 u8*base=ctx->base;u8*handle=func_0040EF88(base,0);Obj*o=(Obj*)func_0040EF70(base,0);
 s32 a=o->vt->f24(o,1);s32 b=o->vt->f24(o,0);
 s32 c=func_00410AD0((s32)handle,1);s32 d=func_00410AD0((s32)handle,0);
 func_0011EB60(gAdxRnaTempCountsFormat_004BBF48,a,b,a+b);
 func_0011EB60(gAdxRnaIopTempCountsFormat_004BBF68,c,d,c+d);
 func_0011EB60(gAdxRnaStatusTotalsFormat_004BBF88,ctx->status,a+b+c+d);
}
