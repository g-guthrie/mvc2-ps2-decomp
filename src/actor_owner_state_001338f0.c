/* jtbl_0043E900: the 6-entry (u8 *, u8 *) handler slice of the table defined in
   src/data/jtbl_0043E8EC.c (func_00133950, func_00133B20, func_00133BA0, ...). */
typedef unsigned char u8; typedef signed char s8; typedef signed short s16;
typedef void (*ActorCallback)(u8 *, u8 *);
extern const ActorCallback jtbl_0043E900[6];
void func_001338F0(u8 *p, u8 *owner) {
    *(s16 *)(p+0x144) = *(s16 *)(p+0x13e);
    if (p[0x14f] < *(s8 *)(owner+0x202)) {
        p[0x14f] = *(s8 *)(owner+0x202);
        owner[0x202] = 0;
    }
    if (p[0x14f] != 0) p[0x14f]--;
    jtbl_0043E900[p[0x20]](p, owner);
}
