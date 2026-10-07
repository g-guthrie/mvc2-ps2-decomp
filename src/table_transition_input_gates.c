/* Resolve the mode transition table before consuming an input request. */
typedef unsigned char u8;
extern int func_001E7FD0(u8 *);
extern int D_0045AB30[][2];
int func_002DBD20(u8 *p) {
    int result = 0;
    int kind = D_0045AB30[p[0x20d]][p[0x212]];
    if (kind) {
        unsigned int input = *(unsigned short *)(p+0x20e) & 0xc00;
        if (input) {
            p[0x22] = input >> 10;
            if (p[0x1b7] == 1) {
                result = func_001E7FD0(p);
                if (result) p[0x20b] = kind - 1;
            }
        }
    }
    return result;
}
extern int D_0045B9D0[][2];
int func_002F16F0(u8 *p) {
    int result = 0;
    int kind = D_0045B9D0[p[0x20d]][p[0x212]];
    if (kind) {
        unsigned int input = *(unsigned short *)(p+0x20e) & 0xc00;
        if (input) {
            p[0x22] = input >> 10;
            if (p[0x1b7] == 1) {
                result = func_001E7FD0(p);
                if (result) p[0x20b] = kind - 1;
            }
        }
    }
    return result;
}
extern int D_0045E090[][2];
int func_00325E50(u8 *p) {
    int result = 0;
    int kind = D_0045E090[p[0x20d]][p[0x212]];
    if (kind) {
        unsigned int input = *(unsigned short *)(p+0x20e) & 0xc00;
        if (input) {
            p[0x22] = input >> 10;
            if (p[0x1b7] == 1) {
                result = func_001E7FD0(p);
                if (result) p[0x20b] = kind - 1;
            }
        }
    }
    return result;
}
