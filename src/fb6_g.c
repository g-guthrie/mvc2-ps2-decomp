typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define SWAP32(x) ((((u32)(x) >> 24) | ((x) << 24)) | ((((x) << 8) & 0xFF0000) | (((x) >> 8) & 0xFF00)))

extern void func_003FB128(void *);
extern void func_00401868(u8 *);
extern void func_003F9630(void);
extern void func_003F9660(void);
extern void *func_0040F0B8(u8 *, s32);
extern void func_00401640();
extern char D_004BC728[];
extern char D_004BC758[];

void func_00402EB8(u8 *a, s32 *b, s32 c) {
    void *r;
    if (a == 0 || b == 0 || c < 0) {
        func_003FB128(D_004BC728);
        return;
    }
    func_00401868(a);
    if (c < (s32)SWAP32(b[1]) && c >= 0) {
        func_003F9630();
        r = func_0040F0B8((u8 *)b + SWAP32(b[2 + c * 2]), 0x40000000);
        if (r == 0) {
            func_003F9660();
            func_003FB128(D_004BC758);
            return;
        }
        func_00401640(a, r);
        a[2] = 2;
        a[0x98] = 0;
        func_003F9660();
        return;
    }
}
