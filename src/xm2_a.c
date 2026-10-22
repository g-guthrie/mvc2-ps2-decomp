typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 *p0;
    u8 pad4[0xE];
    s16 h12;
    s16 h14[4];
    u8 pad1c[0x36 - 0x1C];
    s16 h36;
    s16 h38;
} G;

extern s16 D_004CA078[];

static s16 func_0012B8D0(s16 a, s16 b)
{
    if (b >= 3) return 4;
    return (a + b + 4) % 4;
}

s32 func_0012C5C0(G *p, s32 mode, s32 flag)
{
    extern void func_0012C470();
    extern void func_001E3CE0();
    s16 s0;
    s32 r;
    s16 a0;
    s32 i;

    r = 0;
    if (mode < 2) {
        i = 4;
        if (p->h36 == i) {
            p->h12 = 3;
            func_0012C470(p);
            return 0;
        }
        s0 = p->h12;
        a0 = p->h38;
        if (s0 == 3) {
            i = 4;
        } else {
            i = 0;
            do {
                if (mode == 0) {
                    s0++;
                    if (s0 == 3) {
                        r = -1;
                        s0 = 2;
                        a0 = (a0 + 5) % 4;
                    }
                    if (p->h14[func_0012B8D0(a0, s0)] != -1) break;
                } else {
                    s0--;
                    if (s0 < 0) {
                        r = 1;
                        s0 = 0;
                        a0 = (a0 + 3) % 4;
                    }
                    if (p->h14[func_0012B8D0(a0, s0)] != -1) break;
                }
                i++;
            } while (i < 4);
        }
        if (i < 4) {
            switch (r) {
            case -1:
                D_004CA078[0] = (D_004CA078[0] + 5) % 4;
                break;
            case 1:
                D_004CA078[0] = (D_004CA078[0] + 3) % 4;
                break;
            }
        } else {
            p->h12 = 3;
            func_0012C470(p);
            return 0;
        }
    } else if (mode == 2) {
        s0 = 3;
    } else if (mode == 3) {
        s16 t[4] = {1, 0, 2, 3};
        i = 0;
        s0 = p->h12;
        do {
            s16 a3 = t[i];
            if (p->h14[(p->h38 + a3 + 4) % 4] != -1) {
                s0 = a3;
                break;
            }
            i++;
        } while (i < 4);
        if (i < 4) {
            if (s0 == 3) {
                s0 = 2;
                r = 1;
            }
        } else {
            p->h12 = s0;
            func_0012C470(p);
            return 0;
        }
    } else {
        return 0;
    }
    *(u32 *)(p->p0 + 0x74) = 0x3F7D70A4;
    *(s16 *)(p->p0 + 0x1E) = -9;
    if (flag != 0) func_001E3CE0(1);
    p->h12 = s0;
    func_0012C470(p);
    return r;
}
