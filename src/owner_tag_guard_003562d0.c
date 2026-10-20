typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

void func_003562D0(u8 *actor)
{
    if (actor[0x20] == 6 && actor[5] != 0)
        return;

    if (*(u16 *)(*(u8 **)(actor + 0x18) + 0x168) !=
        *(s16 *)(actor + 0x1C)) {
        if (actor[4] < 2)
            actor[4] = 2;
        actor[0x13C] = 0;
    }
}
