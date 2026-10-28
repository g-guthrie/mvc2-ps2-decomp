typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern void *memcpy(void *, const void *, u32);
extern s32 D_004895C0[4];

s32 func_0040C178(char *dst, char *src, s32 n, s32 stride)
{
    s32 i = 0;
    s32 count = 0;
    s32 start = 0;
    s32 d;
    char *p;
    char *q;
    s32 len;

    if (src[0] != 0) {
    d = n * 8 + (s32)dst;
    for (; src[i] != 0; i++) {
        p = &src[i];
        if (*p == '\\') *p = '/';
        if (*p == '\n' || *p == 0) {
            q = p - 1;
            len = i - start;
            if (*q == '\r') *q = 0;
            memcpy((char *)d, src + start, len);
            start = i + 1;
            d = stride + d + 1;
            count++;
            if (count == n) break;
        }
    }
    }
    if (D_004895C0[0] == 0) {
        D_004895C0[3] = stride;
        D_004895C0[0] = (s32)dst;
        D_004895C0[2] = n;
        D_004895C0[1] = count;
    }
    return count;
}
