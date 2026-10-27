typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 t; s32 idx; } A_l;
typedef struct { s32 t; u8 a; u8 b; u8 pad[6]; } T_l;
typedef struct { s8 mode; } M_l;
typedef struct { u8 pad[0x539]; s8 f539; u8 pad2[0x5B8 - 0x53A]; } X_l;
#include "input_device_view.h"

extern A_l D_004F4420[];
extern T_l D_00446790[];
extern M_l *D_004C2840;
extern X_l D_004F20B0[];
extern s8 D_004F7F50[];
extern void *D_004C2A68;
extern u8 D_004C2688[2];

void func_0016EEC0(void) {
    extern void func_0010DF60();
    s32 i;
    s32 idx;
    for (i = 0; i < 2; i++) {
        if (D_004F4420[i].t < 0) {
            D_004F4420[i].t = D_00446790[idx].t;
            if ((D_004C2840->mode == 2 && D_004F20B0[i].f539 == 0) || D_004C2840->mode == 3 || D_004F7F50[0] != 0) {
                if (((InputDeviceView *)D_004C2A68)[i].state == 1) {
                    idx = D_004F4420[i].idx;
                    D_004F4420[i].t = D_00446790[idx].t;
                    D_004C2688[0] = D_00446790[idx].a;
                    D_004C2688[1] = D_00446790[idx].b;
                    func_0010DF60(i, 0, D_004C2688);
                }
            }
        }
        if (D_004F4420[i].t > 0) {
            D_004F4420[i].t = D_004F4420[i].t - 1;
            if (D_004F4420[i].t == 0) {
                D_004C2688[0] = 0;
                D_004C2688[1] = 0;
                func_0010DF60(i, 0, D_004C2688);
            }
        }
    }
}
