/* Metrowerks 3.0: ./try.sh src/grok_nopm_315250.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_001E7FD0();

s32 func_00315250(u8 *p)
{
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    s32 r;
    u32 a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 1; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 0; return r; }
        }
    }
    return 0;
}
