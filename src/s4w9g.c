typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern volatile s32 D_004C22EC;
extern volatile s32 D_004C232C;
extern void func_00103CE0(s32, s32 *);
extern s32 func_00103D10(s32);
void func_003FEB58(void){
    if (D_004C22EC == 1) {
        s32 v[12];
        func_00103CE0(D_004C232C, v);
        if (v[0] == 4 || v[0] == 12) {
            if (func_00103D10(D_004C232C) == D_004C232C) D_004C22EC = 0;
        }
    }
}

#include "sony29_rpc_server_types.h"
extern s32 func_00103CD0(void);
extern void *func_00408F88(int, void *, int);
extern u8 D_00487FC8[];
extern u8 D_00488010[];
extern s32 D_004C2440[1];
extern volatile s32 D_004C2444;
s32 func_00409058(void){
    SonyRpcQueue a;
    SonyRpcQueue b;
    func_00107098(&a, func_00103CD0());
    func_00107098(&b, func_00103CD0());
    func_00107130((SonyRpcServer *)D_00487FC8, D_004C2440[0], func_00408F88, D_00488010, 0, 0, &a);
    D_004C2444 = 1;
    func_00107548(&a);
    return 0;
}
