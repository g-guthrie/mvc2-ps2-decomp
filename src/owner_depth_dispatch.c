/* Dispatch the child state and clamp its owner-relative depth to 0..7. */
typedef unsigned char u8;
typedef void (*ChildHandler)(u8 *);
extern ChildHandler D_0044CA50[];
void func_001C1700(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    D_0044CA50[p[4]](p);
    p[0x24] = *(signed char *)(owner+0x24) + *(signed char *)(p+0x31);
    if (*(signed char *)(p+0x24) > 7) p[0x24] = 7;
    if (*(signed char *)(p+0x24) < 0) p[0x24] = 0;
}
extern ChildHandler D_00471AA0[];
void func_0038F960(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    D_00471AA0[p[4]](p);
    p[0x24] = *(signed char *)(owner+0x24) + *(signed char *)(p+0x31);
    if (*(signed char *)(p+0x24) > 7) p[0x24] = 7;
    if (*(signed char *)(p+0x24) < 0) p[0x24] = 0;
}
extern ChildHandler D_00471AF0[];
void func_00390370(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    D_00471AF0[p[4]](p);
    p[0x24] = *(signed char *)(owner+0x24) + *(signed char *)(p+0x31);
    if (*(signed char *)(p+0x24) > 7) p[0x24] = 7;
    if (*(signed char *)(p+0x24) < 0) p[0x24] = 0;
}
