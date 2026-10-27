/* Accept a grounded input and select its requested transition kind. */
typedef unsigned char u8;
extern u8 *func_001E7FD0(u8 *);
u8 *func_0023E930(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && !p[0x212] && p[0x1b7] == 1) {
        u8 *result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x1; return result; }
    }
    return 0;
}
u8 *func_002ED160(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && !p[0x212] && p[0x1b7] == 1) {
        u8 *result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x1; return result; }
    }
    return 0;
}
u8 *func_00304300(u8 *p) {
    if ((p[0x22] = (*(unsigned short *)(p+0x20e) & 0xc00) >> 10) && !p[0x212] && p[0x1b7] == 1) {
        u8 *result = func_001E7FD0(p);
        if (result) { p[0x20b] = 0x1; return result; }
    }
    return 0;
}
