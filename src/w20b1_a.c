typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern char D_0062D7E0[];
extern s32 func_0011FFA0(char *);
void func_003FB1E0(s32 n, char *buf, s32 max) {
    s32 i;
    s32 len;
    char *src;
    char *e;
    for (i = 0; i < 0x20; i++) {
        buf[i] = n % 10;
        n = n / 10;
        if (n == 0) {
            buf[i] = 0;
            break;
        }
    }
    len = func_0011FFA0(D_0062D7E0);
    len = (len < max - 1) ? len : max - 1;
    i = 0;
    if (len > 0) {
        e = D_0062D7E0 + len;
        src = e - 1;
        do {
            buf[i] = *src;
            src--;
            i++;
        } while (i < len);
    }
    buf[i] = 0;
}
