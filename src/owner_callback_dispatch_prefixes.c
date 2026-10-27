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

extern OwnerCallback jtbl_004C1B68[] __attribute__((section(".sdata")));
extern void (*const jtbl_004C1B78[2])(u8 *, u8 *) __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C1B94[] __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C1B98[] __attribute__((section(".sdata")));
extern void (*const jtbl_004C1B58[7])(u8 *, u8 *) __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C1C00[] __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C1E38[] __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C1F08[] __attribute__((section(".sdata")));
extern OwnerCallback jtbl_004C20E8[] __attribute__((section(".sdata")));
void func_0035D850(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    jtbl_004C1B68[p[5]](p, owner);
}
void func_0035DD10(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    jtbl_004C1B78[p[5]](p, owner);
}
void func_0035E3A0(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    jtbl_004C1B94[p[5]](p, owner);
}
void func_0035E660(u8 *p, void *owner) {
    u8 *q = owner;
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    jtbl_004C1B98[p[5]](p, owner);
}
/* Provisional: upstream callback table and state bounds require reconciliation. */
void func_0035CF70(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004C1B58[p[5]](p, owner);
}
void func_003616A0(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004C1C00[p[5]](p, owner);
}
void func_00396A40(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004C1E38[p[5]](p, owner);
}
void func_003A8150(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004C1F08[p[5]](p, owner);
}
void func_003C0FC0(u8 *p, void *owner) {
    u8 *q = owner;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004C20E8[p[5]](p, owner);
}

extern OwnerCallback D_004BF794[] __attribute__((section(".sdata")));
void func_001A7500(u8 *p, void *owner) {
 u8 *q=owner;
 *(float *)(p+0x34)=*(float *)(q+0x34)+*(float *)(p+0x5C);
 *(float *)(p+0x38)=*(float *)(q+0x38)+*(float *)(p+0x60);
 D_004BF794[p[5]](p,owner);
}

/* This state releases only its actor; the retail entry is a unary tail call. */
typedef struct Object Object;
extern void func_003DAA40(Object *);
void func_001D04F0(u8 *p) { func_003DAA40((Object *)p); }

void func_003C3A50(u8 *p, void *owner) {
    p[0x13C] = 0;
    func_003DAA40((Object *)p);
}
