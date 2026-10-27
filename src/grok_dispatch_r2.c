typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00458270[];
typedef void (*ContextDispatchFn)(u8 *, void *);
extern ContextDispatchFn jtbl_004C13A0[2];

void func_0029F450(u8 *p) { jtbl_00458270[p[6]](p); }

void func_002FA000(u8 *p, void *context) { jtbl_004C13A0[p[6]](p, context); }
