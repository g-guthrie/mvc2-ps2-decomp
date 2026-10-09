typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;

struct RuntimeState
{
    u32 unk00[5];
    u16 size;
};

struct RuntimeOwner
{
    u32 unk00;
    u32 unk04;
    struct RuntimeState *state;
};

extern s32 func_004166B0(struct RuntimeOwner *owner);

s32 func_00416730(struct RuntimeOwner *owner)
{
    s32 value = owner->state->size * func_004166B0(owner);
    return value / 8;
}
