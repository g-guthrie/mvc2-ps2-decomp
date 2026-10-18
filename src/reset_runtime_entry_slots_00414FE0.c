typedef unsigned int u32;
typedef signed int s32;

struct RuntimeEntrySlot
{
    s32 handle;
    u32 state;
};

extern s32 D_004C28A4;
extern struct RuntimeEntrySlot D_0057E570[];

void func_00414FE0(void)
{
    s32 index = 0;
    struct RuntimeEntrySlot *slot = D_0057E570;

    for (; index < D_004C28A4; index++, slot++)
    {
        slot->handle = -1;
        slot->state = 0;
    }

    D_004C28A4 = 0;
}
