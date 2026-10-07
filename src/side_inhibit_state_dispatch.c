/* The inhibit mask occupies ordinary BSS beyond the GP small-data range. */
typedef unsigned char u8;
typedef void (*Callback)(u8 *,u8 *);
extern u8 D_004D18A6 __attribute__((section(".bss")));
extern Callback D_004BF7C8[2];
extern Callback D_004BF7D0[2];
extern Callback D_004BF7D8[2];
void func_001A84F0(u8 *p,u8 *owner) {
 if (!(D_004D18A6 & (1 << (owner[2] ^ 1)))) D_004BF7C8[p[5]](p,owner);
}

void func_001A8670(u8 *p,u8 *owner) {
 if (!(D_004D18A6 & (1 << (owner[2] ^ 1)))) D_004BF7D0[p[5]](p,owner);
}

void func_001A8840(u8 *p,u8 *owner) {
 if (!(D_004D18A6 & (1 << (owner[2] ^ 1)))) D_004BF7D8[p[5]](p,owner);
}
