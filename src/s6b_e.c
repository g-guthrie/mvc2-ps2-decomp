/* EE GCC 2.96: ./tryee.sh src/s6b_e.c sn 0 O2 "-fno-strength-reduce -fno-optimize-sibling-calls" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_0011FFA0(s8 *);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_004061C0(s8 *);

void func_00406688(s8 *dst, s8 *out, s8 *src)
{
    s32 i;
    s32 j;

    if (src == 0)
        return;
    i = 0;
    if (src[i] == ':' || src[i] == 0) goto done;
top:
    dst[i] = src[i];
    i++;
    if (i < 0x129 && src[i] != ':' && src[i] != 0) goto top;
done:
    if (src[i] == 0) {
        dst[i] = 0;
        memcpy(out, dst, func_0011FFA0(dst) + 1);
        dst[0] = 0;
        return;
    }
    dst[i] = 0;
    i++;
    if (i == 2) {
        dst[0] = 0;
        i = 0;
    }
    for (j = i; j < 0x129; j++) {
        if (src[j] == 0)
            break;
        out[j - i] = src[j];
    }
    out[j - i] = 0;
    func_004061C0(dst);
}
