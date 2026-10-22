typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 a; s32 b; s32 c; s32 d; } Slot;
extern Slot D_00632610[16];
extern char D_004BEC40[];
extern char D_004BEC70[];
extern char D_004BECA0[];

s32 func_00411C10(u8 *a, s32 mode)
{
    extern s32 func_003DCFE0(s32, s32);
    extern s32 func_003DD030(s32);
    extern void func_003ED0D0(char *);
    extern s32 func_003E8B30(s32 *, s32);
    extern s32 func_003E9010(s32 *, s32);
    extern void func_003E95E0(s32, s32, s32 *, s32);
    extern void func_003EA0D0(s32);
    s32 pb[18];
    s32 pa[20];
    s32 buf[20];
    s32 j;
    s32 n;
    u8 *src;
    s32 *q;
    Slot *s;
    s32 k;
    s32 i;
    s32 *r;
    s32 *t;

    s = D_00632610;
    n = 0;
    do {
        if (s->a == 0) {
            s->a = (s32)a;
            if (mode == 1) {
            s->b = func_003DCFE0(0x740, 1);
            if (s->b == 0) func_003ED0D0(D_004BEC40);
            s->c = func_003DCFE0(0x68, 1);
            if (s->c == 0) func_003ED0D0(D_004BEC70);
            s->d = func_003DCFE0(0x40, 1);
            if (s->d == 0) func_003ED0D0(D_004BECA0);
            func_003DD030(s->b);
            r = (s32 *)func_003DD030(s->c);
            t = (s32 *)func_003DD030(s->d);
            q = (s32 *)func_003DD030(s->b);
            i = 0; do { *q++ = 0; i++; } while (i < 0x1D0);
            pa[1] = 0x80; pa[2] = 0x80; pa[3] = 0x40; pa[0] = 0x14; pa[5] = 0; pa[4] = 0;
            for (i = 0; i < 0x1A; i++) r[i] = func_003E8B30(pa, 3);
            } else return 0;
            pb[2] = 1; pb[5] = 4; pb[1] = 0x10; pb[4] = 0; pb[0] = 0; pb[3] = 0x40; pb[6] = 8; pb[8] = 0xFF; pb[16] = 0x18; pb[9] = 8; pb[10] = 8; pb[11] = 0xFF; pb[12] = 8; pb[15] = 8; pb[13] = 0; pb[14] = 0xFF; pb[17] = 0xFF; pb[7] = 0x10;
            src = a + *(s32 *)(a + 0x14);
            for (j = 0; j < 0x10; j++) {
                s32 *dst, *o;
                s16 *sp;
                t[j] = func_003E9010(pb, 3);
                func_003E95E0(0, t[j], buf, 3);
                dst = (s32 *)buf[4];
                for (k = 0; k < 16; k++) {
                    u32 c = ((u16 *)src)[k];
                    dst[k] = (((c >> 15) & 1) << 31) | (((c >> 10) & 0x1F) << 3) | (((c >> 5) & 0x1F) << 11) | ((c & 0x1F) << 19);
                }
                func_003EA0D0(t[j]);
                src += 0x20;
            }
            return n + 1;
        }
        n++;
        s++;
    } while (n < 0x10);
    return 0;
}
