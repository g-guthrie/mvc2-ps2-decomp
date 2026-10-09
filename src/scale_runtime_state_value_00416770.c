typedef unsigned int u32;
typedef signed int s32;

struct RuntimeOwner
{
    u32 unk00[5];
    u32 stateIndex;
};

extern const s32 D_004BEDC0[];

s32 func_00416770(struct RuntimeOwner *owner, s32 scale)
{
    s32 factor = D_004BEDC0[owner->stateIndex];
    return (scale * factor) >> 3;
}
