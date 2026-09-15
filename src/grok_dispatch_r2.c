typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00458270[];
extern DispatchFn jtbl_004C13A0[2];

void residual_0029F450(u8 *p) { jtbl_00458270[p[6]](p); }

void residual_002FA000(u8 *p) { jtbl_004C13A0[p[6]](p); }
