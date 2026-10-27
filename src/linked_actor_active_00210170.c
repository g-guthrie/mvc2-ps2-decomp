typedef unsigned char u8;

extern void func_00178F20(u8 *actor, u8 *linked);

/* The parent dispatcher checks this linked actor before calling the handler. */
void func_00210170(u8 *actor)
{
    u8 *linked = *(u8 **)(actor + 0x1DC);
    if (linked[6] > 1)
        func_00178F20(linked, actor);
}
