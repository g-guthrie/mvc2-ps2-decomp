/* Require an accepted interaction and active owner before clearing the latch. */
typedef unsigned char u8;
extern u8 D_00454A80[];
extern int func_00189310(u8 *,u8 *,u8 *);
int func_00273CB0(u8 *p) {
    if (!func_00189310(p,D_00454A80,p+0x378)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x26c] = 0;
    return 1;
}
extern u8 D_0045BA00[];
extern int func_00189310(u8 *,u8 *,u8 *);
int func_002F2790(u8 *p) {
    if (!func_00189310(p,D_0045BA00,p+0x378)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x26c] = 0;
    return 1;
}
extern u8 D_0045CD40[];
extern int func_00189310(u8 *,u8 *,u8 *);
int func_003091A0(u8 *p) {
    if (!func_00189310(p,D_0045CD40,p+0x378)) return 0;
    if (!**(signed char **)(p+0x420)) return 0;
    p[0x26c] = 0;
    return 1;
}
