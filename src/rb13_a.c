typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern void *memcpy(void *, void *, s32);
extern s32 D_00489000[4];
extern void func_00409AE0(s8 *);

s32 func_0040A610(s8 *a, s8 *str, s32 n, s32 k) {
    s32 pos;
    s32 cnt;
    s32 start;
    s32 next;
    s32 len;
    s8 *d;
    s8 *q;
    pos = 0;
    cnt = 0;
    start = 0;
    if (*str != 0) {
        d = (s8 *)(n * 8 + (s32)a);
        while (1) {
            if (str[pos] == 10 || str[pos] == 0) {
                len = pos - start;
                q = str + pos - 1;
                if (*q == 13) *q = 0;
                memcpy(d, str + start, len);
                func_00409AE0(d);
                next = pos + 1;
                d = (s8 *)(k + (s32)d + 1);
                cnt++;
                if (cnt == n) break;
                start = next;
            } else {
                next = pos + 1;
            }
            pos = next;
            if (str[pos] == 0) break;
        }
    }
    if (D_00489000[0] == 0) {
        D_00489000[3] = k;
        D_00489000[0] = (s32)a;
        D_00489000[2] = n;
        D_00489000[1] = cnt;
    }
    return cnt;
}
