typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern char D_004BDBA8[];
extern char D_004BDBC0[];
extern char D_004BDBE0[];
extern u8 D_00489010[];
extern s32 D_00489014;

s32 func_00409F88(u8 *h, s32 n, s32 buf) {
    extern void func_004098A8();
    extern s32 func_00407BF8();
    extern void func_00104818();
    extern s32 func_00407D28();
    extern void func_00408628();
    extern void func_004084E8();
    extern void func_00407FC8();
    extern void func_00407C80();
    s32 avail, cnt, r, one;
    if (h == 0) {
        func_004098A8(h, D_004BDBA8);
        return 0;
    }
    if (n < 0) {
        func_004098A8(h, D_004BDBC0);
        return 0;
    }
    if (buf == 0) {
        func_004098A8(h, D_004BDBE0);
        return 0;
    }
    if (*(s8 *)(h + 2) == 2) return 0;
    if (n == 0) {
        h[2] = 1;
        return 0;
    }
    r = func_00407BF8();
    *(s32 *)(h + 0x1C) = r;
    if (r == 0) return 0;
    avail = *(s32 *)(h + 8) - *(s32 *)(h + 0xC);
    h[0x44] = D_00489010[0];
    cnt = (n < avail) ? n : avail;
    h[0x45] = D_00489010[1];
    h[0x46] = D_00489010[2];
    *(s32 *)(h + 0x18) = buf;
    *(s32 *)(h + 0x10) = cnt;
    func_00104818(buf, buf + (cnt << 11) - 1);
    if (func_00407D28(*(s32 *)(h + 0x1C), *(s32 *)(h + 0x20) + *(s32 *)(h + 0xC), *(s32 *)(h + 0x10), *(s32 *)(h + 0x18), h + 0x44) == 0) return 0;
    one = D_00489014;
    if (one == 1) {
        func_00408628();
        func_004084E8();
        func_00407FC8(*(s32 *)(h + 0x1C));
        func_00407C80(*(s32 *)(h + 0x1C));
        *(s32 *)(h + 0x1C) = 0;
        *(s32 *)(h + 0x14) = n;
        h[2] = one;
        *(s32 *)(h + 0xC) += *(s32 *)(h + 0x10);
    } else {
        h[2] = 2;
    }
    return *(s32 *)(h + 0x10);
}
