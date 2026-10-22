typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_001817E0(u8 *a, u8 *b) {
    u8 *arr[6];
    s8 sc[8];
    s32 lim;
    s32 j;
    u8 *x;
    u8 *y;
    s32 n;
    s32 i;
    u8 *p;
    s8 bonus;
    s32 t;

    n = 0;
    p = a;
    while (p != 0) {
        t = p[1];
        if (t != 0x18 && t != 0x19 && t != 0x1A) {
        } else {
            p[0x24] = 7;
            p[0x31] = 0x14;
        }
        arr[n] = p;
        sc[p[0x1B8]] = *(s8 *)(p + 0x24);
        p = *(u8 **)(p + 0xC);
        n++;
    }
    p = b;
    while (p != 0) {
        t = p[1];
        if (t != 0x18 && t != 0x19 && t != 0x1A) {
        } else {
            p[0x24] = 7;
            p[0x31] = 0x14;
        }
        arr[n] = p;
        sc[p[0x1B8]] = *(s8 *)(p + 0x24);
        p = *(u8 **)(p + 0xC);
        n++;
    }
    if (n == 0) return;

    for (i = 0; i < n; i++) {
        p = arr[i];
        t = p[0x1E4];
        bonus = 0;
        switch (t) {
        case 0x14:
            bonus = 0x10;
            break;
        case 0x15:
        case 0x1D:
            bonus = 0x20;
            break;
        case 0x20:
        case 0x12:
        case 0x17:
        case 0x13:
            bonus = -0x20;
            break;
        default:
            if (p[5] != 2 && p[0x20D] == 2) {
                bonus = 8;
            } else if (p[5] == 1) {
                bonus = -8;
            } else if (p[5] == 2) {
                bonus = -0x10;
            }
            break;
        }
        p[0x24] = *(s8 *)(p + 0x158) + bonus - *(s8 *)(p + 2) + *(s8 *)(p + 0x425) * 5 - *(s8 *)(p + 0x339);
    }

    lim = n - 1;
    for (i = 0; i < lim; i++) {
        for (j = 0; j < lim - i; j++) {
            if (arr[j + 1][0x24] < arr[j][0x24] || (arr[j][0x24] == arr[j + 1][0x24] && arr[j][0x1B8] < arr[j + 1][0x1B8])) {
                x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i][0x24] = 6 - i;
    }

    while (b != 0) {
        y = *(u8 **)(b + 0x1DC);
        if (sc[b[0x1B8]] < sc[y[0x1B8]]) {
            if (*(s8 *)(b + 0x24) > *(s8 *)(y + 0x24)) {
                s32 q = *(s8 *)(b + 0x24);
                s32 r = *(s8 *)(y + 0x24);
                y[0x24] = q;
                b[0x24] = r;
            }
        } else {
            if (*(s8 *)(b + 0x24) < *(s8 *)(y + 0x24)) {
                s32 q = *(s8 *)(b + 0x24);
                s32 r = *(s8 *)(y + 0x24);
                y[0x24] = q;
                b[0x24] = r;
            }
        }
        b = *(u8 **)(b + 0xC);
        n++;
    }
}
