typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad1[0xD0 - 2];
    s32 wD0;
    u8 pad2[0x214 - 0xD4];
    u8 b214;
    u8 pad3;
    u8 b216;
    u8 pad4[2];
    u8 b219;
    u8 b21A;
    u8 pad5[0x2BC - 0x21B];
    s32 w2BC;
    u8 pad6[0x2E4 - 0x2C0];
    s32 w2E4;
    s32 w2E8;
    s32 w2EC;
    s32 w2F0;
    s32 w2F4;
    s32 w2F8;
    s32 w2FC;
    s32 w300;
    s32 w304;
    u8 pad7[0x434 - 0x308];
    s16 h434;
    s16 pad8;
    s16 h438;
} PK;

extern s8 D_00451C20[];
extern void func_001906C0(u8 *, s32, s32, s32);
extern void func_0018C4B0(u8 *, s32);
extern void func_00131AB0(u8 *, s32 *, s32);

void func_0022C220(PK *p, u8 *q)
{
    s32 c;
    s32 s0;
    s32 *s1;
    s32 t;
    s32 k;

    p->b21A = 0;
    p->w304 = p->w2E4 = p->w2E8 = p->w2EC = p->w2FC = p->w2F0 = p->w2F4 = p->w300 = p->w2F8 = p->b219 = 0;
    p->b216 = 0;
    c = p->w2BC;
    s0 = D_00451C20[c];
    if ((u8 *)p != q) {
        if (q[0x406] == 1) {
            s0 = 4;
        }
    }
    t = q[0x216];
    if (t != 0) {
        if (((u8)t & 0x80) != 0) {
            s0 = 7;
        } else {
            s0 = 8;
        }
    }
    switch (c) {
    case 0xB:
        if (q[0x2C6] == 0) {
            s0 = 1;
        }
        break;
    case 0x12:
        if (*(s16 *)(q + 0x2B8) > 0) {
            s0 = 1;
        }
        break;
    case 0x22:
        if (*(s32 *)(q + 0xD0) != 0) {
            s0 = 1;
        }
        break;
    case 0x29:
        if (*(s8 *)(q + 0x2BD) != 0) {
            s0 = 1;
        }
        break;
    case 0x2D:
        if (*(s8 *)(q + 0x2C1) != 0) {
            s0 = 1;
        }
        if (*(s8 *)(q + 0x2C8) != 0) {
            s0 = 2;
        }
        break;
    case 0x2F: {
        s32 x = *(s32 *)(q + 0x2D4);
        if (x == 3) {
            s0 = 1;
        }
        if (x == 1) {
            s0 = 3;
        }
        break;
    }
    case 0x31:
        if (*(s16 *)(q + 0x2C6) > 0) {
            if (q[0x402] != 0) {
                s0 = 1;
            }
            if (q[0x214] != 0) {
                s0 = 3;
            }
        }
        if (q[0x2CE] != 0) {
            s0 = 5;
        }
        break;
    case 0x37:
        if (q[0x2C0] != 0) {
            s0 = 9;
        }
        break;
    }
    p->w2BC = p->b1;
    p->wD0 = s0;
    switch (s0) {
    case 1:
        p->w2E4 = 0x384;
        p->b219 = 0x28;
        s1 = &p->w2E4;
        k = 0;
        break;
    case 2:
        p->w2E8 = 0x384;
        p->b21A = 0x10;
        s1 = &p->w2E8;
        k = 1;
        break;
    case 3:
        p->w2EC = 0x258;
        p->b214 = 1;
        s1 = &p->w2EC;
        k = 2;
        break;
    case 4:
        p->w2F4 = 0x384;
        func_001906C0((u8 *)p, 0x384, 0, 0);
        s1 = &p->w2F4;
        k = 3;
        break;
    case 5: {
        s32 v = (p->h438 - p->h434) << 3;
        p->w2FC = v;
        if (v != 0) {
            s1 = &p->w2FC;
            k = 4;
        } else {
            p->wD0 = 0;
            s0 = 0;
        }
        break;
    }
    case 6:
        func_0018C4B0((u8 *)p, 0x90);
        k = 5;
        break;
    case 7:
        p->w2F8 = 0x384;
        s1 = &p->w2F8;
        k = 8;
        p->b216 |= 0x80;
        break;
    case 8:
        p->w2F0 = 0x384;
        p->b216 = 1;
        s1 = &p->w2F0;
        k = 7;
        break;
    case 9:
        p->w300 = 0x384;
        p->b219 = 0x28;
        p->b21A = 0x28;
        func_001906C0((u8 *)p, 0x384, 0, 0);
        s1 = &p->w300;
        k = 9;
        break;
    }
    if (s0 != 0) {
        p->w304 = 10;
        func_00131AB0((u8 *)p, s1, k);
    }
}
