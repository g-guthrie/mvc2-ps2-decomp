/* Independent dispatch entries preserve the native actor/owner arguments. */
typedef unsigned char u8;
typedef signed char s8;
typedef void (*OwnerCallback)(u8 *, void *);
extern OwnerCallback jtbl_0044A1D0[];
extern OwnerCallback jtbl_0044B060[];
extern OwnerCallback jtbl_0044E8D0[];
extern OwnerCallback jtbl_0044E520[];
extern OwnerCallback jtbl_0044E8A0[];
extern OwnerCallback jtbl_00472E00[];
extern OwnerCallback jtbl_0044EDC0[];
extern OwnerCallback jtbl_004BF674[] __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004BFAD0[] __attribute__((section(".sdata")));
void func_00194AA0(u8 *p) {
    u8 *owner = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(owner + 0x24);
    jtbl_0044A1D0[p[4]](p, owner);
}
void func_001A35F0(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    jtbl_004BF674[p[5]](p, owner);
}
void func_001A3620(u8 *p, void *owner) {
    jtbl_0044B060[p[4]](p, owner);
}

void func_001D5B00(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
    jtbl_0044E520[p[5]](p, owner);
}

void func_001DA210(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
    jtbl_0044E8A0[p[5]](p, owner);
}

void func_001DA440(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
    jtbl_0044E8D0[p[4]](p, owner);
}
void func_003A6240(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
    jtbl_00472E00[p[5]](p, owner);
}
void func_001DDC30(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004BFAD0[p[5]](p, owner);
}
void func_001DDC60(u8 *p, void *owner) {
    jtbl_0044EDC0[p[4]](p, owner);
}
