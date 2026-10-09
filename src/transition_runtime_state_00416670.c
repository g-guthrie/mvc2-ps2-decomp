typedef unsigned char u8;
typedef unsigned int u32;

struct RuntimeState
{
    u8 unk00[0x12];
    u8 flags;
    u8 type;
};

struct RuntimeOwner
{
    u32 unk00;
    u32 unk04;
    struct RuntimeState *state;
};

void func_00416670(struct RuntimeOwner *owner)
{
    struct RuntimeState *state = owner->state;

    if (state->type == 5)
    {
        state->flags &= (u8)~0x40;
        state = owner->state;
        state->flags |= 0x80;
    }
}
