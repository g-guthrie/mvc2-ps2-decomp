#include "runtime_stream_query.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef long long s64;
typedef unsigned long long u64;

void func_003F73F0(u8 *p)
{
    extern s32 func_00404400();
    u8 *c = p + 0x48;
    u16 *src = *(u16 **)c;
    s32 n, m, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(s32 *)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    { u16 t = src[i * 2]; d0[i] = (u16)((t << 8) | (t >> 8)); }
                    { u16 t = src[i * 2 + 1]; d1[i] = (u16)((t << 8) | (t >> 8)); }
                }
            } else {
                for (i = 0; i < n; i++) {
                    { u32 t = src[i]; t = (t >> 8) | (t << 8); d0[i] = t; }
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE) * 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

void func_003F6B30(u8 *p)
{
    extern s32 func_00404400();
    u8 *c = p + 0x48;
    u16 *src = *(u16 **)c;
    s32 n, m, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(s32 *)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    { u16 t = src[i * 2]; d0[i] = (u16)((t << 8) | (t >> 8)); }
                    { u16 t = src[i * 2 + 1]; d1[i] = (u16)((t << 8) | (t >> 8)); }
                }
            } else {
                for (i = 0; i < n; i++) {
                    { u32 t = src[i]; t = (t >> 8) | (t << 8); d0[i] = t; }
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE) * 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

