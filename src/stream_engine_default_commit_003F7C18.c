#include "runtime_stream_query.h"
typedef unsigned char u8;
typedef signed int s32;
void func_003F7C18(u8 *p, s32 unused, s32 amount)
{
    s32 read_position = *(s32 *)(p + 0x8C);
    s32 consumed = *(s32 *)(p + 0x88);
    read_position += amount;
    consumed += amount;
    *(s32 *)(p + 0x8C) = read_position;
    *(s32 *)(p + 0x88) = consumed;
}
