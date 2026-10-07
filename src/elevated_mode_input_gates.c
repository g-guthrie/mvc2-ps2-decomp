/* Accept elevated mode-one input while preserving the requested transition kind. */
typedef unsigned char u8;
extern int func_001E7FD0(u8 *);
int func_001ED0B0(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && p[0x212] == 1 && p[0x1b7] == 1 && !(*(float *)(p+0x38) <= 137.142852783203125f)) {
        int result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x2; return result; }
    }
    return 0;
}
int func_00221E90(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && p[0x212] == 1 && p[0x1b7] == 1 && !(*(float *)(p+0x38) <= 137.142852783203125f)) {
        int result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x2; return result; }
    }
    return 0;
}
int func_002D54A0(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && p[0x212] == 1 && p[0x1b7] == 1 && !(*(float *)(p+0x38) <= 137.142852783203125f)) {
        int result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x2; return result; }
    }
    return 0;
}
