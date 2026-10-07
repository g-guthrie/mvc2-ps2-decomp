/* Require the owner activity threshold before setting the interaction latch. */
typedef unsigned char u8;
extern u8 D_0044F2D0[];
extern int func_00189310(u8 *,u8 *,u8 *);
int func_001ED7C0(u8 *p) {
    if (!func_00189310(p,D_0044F2D0,p+0x3B0)) return 0;
    if (**(signed char **)(p+0x420) <= 2) return 0;
    p[0x26c] = 0xB;
    return 1;
}
extern u8 D_0044F620[];
extern int func_00189B90(u8 *,u8 *,u8 *);
int func_001EE890(u8 *p) {
    if (!func_00189B90(p,D_0044F620,p+0x3A8)) return 0;
    if (**(signed char **)(p+0x420) <= 2) return 0;
    p[0x26c] = 0x11;
    return 1;
}
extern u8 D_00453580[];
extern int func_00189EE0(u8 *,u8 *,u8 *);
int func_00254E10(u8 *p) {
    if (!func_00189EE0(p,D_00453580,p+0x3A8)) return 0;
    if (**(signed char **)(p+0x420) <= 2) return 0;
    p[0x26c] = 0x8;
    return 1;
}
extern u8 D_00457D10[];
extern int func_00189EE0(u8 *,u8 *,u8 *);
int func_0029AB80(u8 *p) {
    if (!func_00189EE0(p,D_00457D10,p+0x3C0)) return 0;
    if (**(signed char **)(p+0x420) <= 2) return 0;
    p[0x26c] = 0x8;
    return 1;
}
extern u8 D_00458F30[];
extern int func_00189EE0(u8 *,u8 *,u8 *);
int func_002B2FE0(u8 *p) {
    if (!func_00189EE0(p,D_00458F30,p+0x3C0)) return 0;
    if (**(signed char **)(p+0x420) <= 2) return 0;
    p[0x26c] = 0x10;
    return 1;
}
