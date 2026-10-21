typedef unsigned char u8;
typedef signed int s32;
extern s32 func_00188690(u8 *);
extern s32 func_00188ED0(u8 *);
extern s32 func_00188C70(u8 *);
extern s32 func_00189130(u8 *);
extern s32 func_001EE480(u8 *);
extern s32 func_001EE390(u8 *);
extern s32 func_001EDE70(u8 *);
extern s32 func_001EDF70(u8 *);
extern s32 func_001EE260(u8 *);
extern s32 func_001EE560(u8 *);
extern s32 func_001EE320(u8 *);
extern s32 func_001EE1F0(u8 *);
extern s32 func_001EE410(u8 *);
extern s32 func_001EE6D0(u8 *);
extern s32 func_001EE070(u8 *);
extern s32 func_001EE130(u8 *);
extern s32 func_001EE5E0(u8 *);
extern s32 func_001EE660(u8 *);
extern s32 func_001EE750(u8 *);
extern s32 func_001EE7C0(u8 *);
extern s32 func_001EE500(u8 *);
extern void func_00187BB0(u8 *);
extern int func_00188330(u8 *);
void func_001EDC90(u8 *p)
{
    if (func_00188690(p)) return;
    if (func_00188ED0(p)) return;
    if (func_00188C70(p)) return;
    if (func_00189130(p)) return;
    if (p[0x216] == 0) {
        if (func_001EE480(p)) return;
        if (func_001EE390(p)) return;
        if (func_001EDE70(p)) return;
        if (func_001EDF70(p)) return;
        if (func_001EE260(p)) return;
        if (func_001EE560(p)) return;
        if (func_001EE320(p)) return;
        if (func_001EE1F0(p)) return;
        if (func_001EE410(p)) return;
    } else {
        if (func_001EE6D0(p)) return;
        if (func_001EE390(p)) return;
        if (func_001EE070(p)) return;
        if (func_001EE130(p)) return;
        if (func_001EE260(p)) return;
        if (func_001EE5E0(p)) return;
        if (func_001EE320(p)) return;
        if (func_001EE410(p)) return;
        if (func_001EE660(p)) return;
    }
    if (func_001EE750(p)) return;
    if (func_001EE7C0(p)) return;
    if (func_001EE500(p)) return;
    func_00187BB0(p);
    func_00188330(p);
}
