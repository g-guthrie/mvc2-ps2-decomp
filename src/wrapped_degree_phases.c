/* Update a fixed-turn angle and advance its wrapped degree phase. */
typedef unsigned char u8;
void func_00339770(u8 *p) {
    switch (p[4]) {
    case 0: {
        double degrees = *(short *)(p+0x1c);
        *(int *)(p+0x40) = (unsigned short)(0.5 + 65536.0 * degrees / 360.0);
        *(short *)(p+0x1c) += 0x3;
        if (*(short *)(p+0x1c) >= 360) *(short *)(p+0x1c) %= 360;
        break;
    }
    }
}
void func_0033A000(u8 *p) {
    switch (p[4]) {
    case 0: {
        double degrees = *(short *)(p+0x1c);
        *(int *)(p+0x40) = (unsigned short)(0.5 + 65536.0 * degrees / 360.0);
        *(short *)(p+0x1c) += 0x2;
        if (*(short *)(p+0x1c) >= 360) *(short *)(p+0x1c) %= 360;
        break;
    }
    }
}
void func_0033A190(u8 *p) {
    switch (p[4]) {
    case 0: {
        double degrees = *(short *)(p+0x1c);
        *(int *)(p+0x40) = (unsigned short)(0.5 + 65536.0 * degrees / 360.0);
        *(short *)(p+0x1c) += 0x1;
        if (*(short *)(p+0x1c) >= 360) *(short *)(p+0x1c) %= 360;
        break;
    }
    }
}
