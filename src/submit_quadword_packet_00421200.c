typedef unsigned int u32;
typedef signed int s32;
extern void func_003DC2F0(u32 address, void *header);
extern unsigned char D_0062BBA0[];
s32 func_00421200(u32 *tag) {
    u32 original = tag[0];
    u32 qwc = (original & 0x7FFF) + 1;
    tag[0] = original | 0x80000000;
    tag[2] = 0x13000000;
    qwc -= 1;
    tag[3] = 0x51000000 | qwc;
    func_003DC2F0(((u32)tag & 0x0FFFFFFF) | 0x30000000, D_0062BBA0);
    return 1;
}
