typedef unsigned char u8;
int func_001F7260(u8 *actor) {
    u8 *owner = *(u8 **)(actor + 0x1DC);
    u8 state;
    if (actor[1] != 1) return 0;
    state = owner[0x1B5];
    if (state == 0x25 || state == 0x26 || (unsigned int)(state - 0x3D) <= 1 ||
        (unsigned int)(state - 0x41) <= 3 || (unsigned int)(state - 0x4C) <= 3 ||
        (unsigned int)(state - 0x54) <= 2 || state == 0x57) return 1;
    return 0;
}
