#ifndef RUNTIME_STATE_TYPES_H
#define RUNTIME_STATE_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct RuntimeState
{
    u8 unk00[0x12];
    u8 flags;
    u8 type;
    u16 size;
};

struct RuntimeOwner
{
    u32 unk00;
    u32 unk04;
    struct RuntimeState *state;
    u32 unk0c;
    u32 unk10;
    u32 stateIndex;
};

#endif
