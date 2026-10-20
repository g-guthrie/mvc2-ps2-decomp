typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef long long s64;
typedef unsigned long long u64;


#include "sony29_rpc_packet_header.h"

extern s32 D_004C2458;
extern s32 D_004C2440;
extern u8 D_00487FA0[];
extern u8 D_004BD9B8[];
void func_004095C8(void)
{
    extern void func_0011EB60();
    u32 i, end;
    u8 *q;
    if (D_004C2458 == 0) {
        q = D_00487FA0;
        for (;;) {
            if (func_00106C98((SonyRpcClient *)D_00487FA0, D_004C2440, 0) < 0) {
                func_0011EB60(D_004BD9B8);
                for (;;) __asm__ volatile("nop");
            }
            if (*(s32 *)(q + 0x24) != 0) break;
            end = -1; i = 0xFFFF; do { i -= 4; __asm__ volatile("nop"); } while (i != end);
        }
    }
    D_004C2458++;
}
