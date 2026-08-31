typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF520[2];
extern DispatchFn jtbl_004BF550[2];
extern DispatchFn jtbl_004BF818[2];
extern DispatchFn jtbl_004BF970[2];
extern DispatchFn jtbl_004BFA18[2];
extern DispatchFn jtbl_004BFD40[2];
extern DispatchFn jtbl_004C0128[2];
extern DispatchFn jtbl_004C0138[2];
extern DispatchFn jtbl_004C03A8[2];
extern DispatchFn jtbl_004C1170[2];
extern DispatchFn jtbl_004C11A8[2];
extern DispatchFn jtbl_004C14B0[2];
extern DispatchFn jtbl_004C14E8[2];
extern DispatchFn jtbl_004C18E0[2];
extern DispatchFn jtbl_004C19E8[2];
extern DispatchFn jtbl_004C1AE8[2];
extern DispatchFn jtbl_004C1B20[2];
extern DispatchFn jtbl_004C1B28[2];
extern DispatchFn jtbl_004C1B30[2];

void func_00190B30(u8 *p) { jtbl_004BF520[p[661]](p); }

void func_00195230(u8 *p) { jtbl_004BF550[p[5]](p); }

void func_001ABE70(u8 *p) { jtbl_004BF818[p[7]](p); }

void func_001B85F0(u8 *p) { jtbl_004BF970[p[32]](p); }

void func_001C2C50(u8 *p) { jtbl_004BFA18[p[7]](p); }

void func_00200490(u8 *p) { jtbl_004BFD40[p[32]](p); }

void func_0022EEC0(u8 *p) { jtbl_004C0128[p[7]](p); }

void func_0022F570(u8 *p) { jtbl_004C0138[p[6]](p); }

void func_002477C0(u8 *p) { jtbl_004C03A8[p[6]](p); }

void func_002EA060(u8 *p) { jtbl_004C1170[p[6]](p); }

void func_002EC590(u8 *p) { jtbl_004C11A8[p[6]](p); }

void func_00301820(u8 *p) { jtbl_004C14B0[p[6]](p); }

void func_00303980(u8 *p) { jtbl_004C14E8[p[6]](p); }

void func_003378E0(u8 *p) { jtbl_004C18E0[p[4]](p); }

void func_0034A060(u8 *p) { jtbl_004C19E8[p[5]](p); }

void func_003593D0(u8 *p) { jtbl_004C1AE8[p[5]](p); }

void func_00359C50(u8 *p) { jtbl_004C1B20[p[5]](p); }

void func_00359EA0(u8 *p) { jtbl_004C1B28[p[5]](p); }

void func_0035A2A0(u8 *p) { jtbl_004C1B30[p[5]](p); }
