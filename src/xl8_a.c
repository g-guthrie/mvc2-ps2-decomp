typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 _p0[0x1B4];
    s8 f1B4;
    u8 _p1B5[0x3F];
    s8 f1F4;
    u8 _p1F5[0x5];
    s16 f1FA;
    u8 _p1FC[0x3];
    s8 f1FF;
    s8 f200;
    s8 f201;
    s8 f202;
    s8 f203;
    s8 f204;
    s8 f205;
    s8 f206;
    s8 f207;
    s8 f208;
    u8 _p209[0x42];
    s8 f24B;
    u8 _p24C[0x7];
    s8 f253;
    u8 _p254[0x3A];
    s8 f28E;
    u8 _p28F[0xA9];
    s8 f338;
    u8 _p339[0x3];
    s8 f33C;
    u8 _p33D[0xBB];
    s16 f3F8;
    s16 f3FA;
    s16 f3FC;
    s16 f3FE;
    s16 f400;
    u8 _p402[0x3];
    s8 f405;
    u8 _p406[0x6];
    s8 f40C;
} SS;

extern u8 D_004D18A1[];
extern u8 D_004D18D8[];
extern void (*D_00448A10[])(u8 *);
extern s8 *D_004C2840;

void func_00179590(u8 *p)
{
    extern void func_00183E30(u8 *);
    extern void func_0016A000(u8 *);
    extern void func_00168C10(u8 *);
    extern void func_00181C40(u8 *);
    extern void func_00187A20(u8 *);
    extern void func_00187A70(u8 *);
    extern void func_001827B0(u8 *);
    extern void func_00182ED0(u8 *);
    extern void func_00190580(u8 *);
    extern void func_00183C40(u8 *);
    extern void func_001823C0(u8 *);
    extern void func_001825F0(u8 *);
    extern void func_00190C10(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00190B30(u8 *);
    extern void func_0018D290(u8 *);
    SS *q = (SS *)p;
    s32 v;
    u32 t;
    s16 hv;
    s8 bv;
    s32 id;

    id = p[1];
    if (id == 0x1A) {
        p[0x24] = 0x1D;
        p[0x31] = 0x14;
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
        return;
    }
    if (id == 0x18 || id == 0x19 || id == 0x1A) {
        p[0x24] = 0x1D;
        p[0x31] = 0x14;
    }
    func_00183E30(p);
    func_0016A000(p);
    if (*(s8 *)(p + 0x539) != 0) {
        func_00168C10(p);
    }
    if (p[0x425] == 0) {
        func_00181C40(p);
    }
    if ((D_004D18A1[0] & 2) || (D_004D18D8[0] & (1 << p[2]))) {
        t = *(u16 *)(p + 0x354);
        *(u16 *)(p + 0x354) = t & 0x8000;
        *(u16 *)(p + 0x362) = 0;
        *(u16 *)(p + 0x35E) = 0;
        *(u16 *)(p + 0x35C) = 0;
    } else if (D_004D18A1[0] & 4) {
        t = *(u16 *)(p + 0x354);
        *(u16 *)(p + 0x354) = t & 0xC00;
        t = *(u16 *)(p + 0x35C);
        *(u16 *)(p + 0x35C) = t & 0xC00;
        t = *(u16 *)(p + 0x356);
        *(u16 *)(p + 0x356) = t & 0xC00;
        t = *(u16 *)(p + 0x35E);
        *(u16 *)(p + 0x35E) = t & 0xC00;
        t = *(u16 *)(p + 0x362);
        *(u16 *)(p + 0x362) = t & 0xC00;
        t = *(u16 *)(p + 0x360);
        *(u16 *)(p + 0x360) = t & 0xC00;
    }
    p[0x268] = 0;
    func_00187A20(p);
    if (p[0x40D] != 0) {
        func_00187A70(p);
    }
    v = q->f253;
    if (v != 0) {
        q->f253 = v - 1;
    }
    if (*(*(u8 **)(p + 0x220) + 0x249) != 0) {
        func_001827B0(p);
    }
    if (p[0x268] != 0) {
        return;
    }
    (**(void (***)(u8 *))(p + 0x43C))(p);
    p[0x2B2] = 0;
    func_00182ED0(p);
    v = q->f1FA;
    if (v != 0) {
        q->f1FA = v - 1;
    }
    v = q->f1B4;
    if (v != 0) {
        q->f1B4 = v - 1;
        t = *(u16 *)(p + 0x364);
        *(u16 *)(p + 0x364) = t | *(u16 *)(p + 0x354);
        t = *(u16 *)(p + 0x366);
        *(u16 *)(p + 0x366) = t | *(u16 *)(p + 0x35C);
        func_00190580(p);
        if (p[5] != 3) {
            func_00183C40(p);
        }
        if (p[5] == 1) {
            p[0x1FE] = 1;
        }
        if (p[1] == 0x3A) {
            if ((p[0x216] & 0x80) != 0) {
                *(u16 *)(p + 0x356) = 0;
                *(u16 *)(p + 0x35C) = 0;
                *(u16 *)(p + 0x354) = 0;
                *(u16 *)(p + 0x360) = 0;
                *(u16 *)(p + 0x362) = 0;
                *(u16 *)(p + 0x35E) = 0;
                *(u16 *)(p + 0x366) = 0;
                *(u16 *)(p + 0x364) = 0;
            }
        }
        goto tail;
    } else {
        v = q->f201; if (v != 0) q->f201 = v - 1;
        v = q->f1FF; if (v != 0) q->f1FF = v - 1;
        v = q->f24B; if (v != 0) q->f24B = v - 1;
        v = q->f200; if (v != 0) q->f200 = v - 1;
        v = q->f1F4; if (v != 0) q->f1F4 = v - 1;
        v = q->f203; if (v != 0) q->f203 = v - 1;
        v = q->f202; if (v != 0) q->f202 = v - 1;
        v = q->f204; if (v != 0) q->f204 = v - 1;
        v = q->f205; if (v != 0) q->f205 = v - 1;
        v = q->f206; if (v != 0) q->f206 = v - 1;
        v = q->f207; if (v != 0) q->f207 = v - 1;
        bv = q->f33C;
        if (bv != 0) {
            bv = bv - 1;
            q->f33C = bv;
            if (bv <= 0) {
                p[0x33C] = 0;
                p[0x33B] = 0;
            }
        }
        v = q->f3FE; if (v != 0) q->f3FE = v - 1;
        v = q->f400; if (v != 0) q->f400 = v - 1;
        if (q->f3FE > 0 || q->f400 > 0) {
            p[0x214] = 1;
        } else {
            p[0x214] = 0;
        }
        hv = q->f3FA;
        if (hv != 0) {
            hv = hv - 1;
            q->f3FA = hv;
            if (hv == 0) p[0x402] = 0;
        }
        hv = q->f3FC;
        if (hv != 0) {
            hv = hv - 1;
            q->f3FC = hv;
            if (hv == 0) p[0x403] = 0;
        }
        bv = q->f405;
        if (bv != 0) {
            bv = bv - 1;
            q->f405 = bv;
            if (bv <= 0) p[0x404] = 0;
        }
        bv = q->f40C;
        if (bv != 0) {
            bv = bv - 1;
            q->f40C = bv;
            if (bv <= 0) p[0x40D] = 0;
        }
        v = q->f28E; if (v > 0) q->f28E = v - 1;
        D_00448A10[p[5]](p);
        v = q->f208; if (v != 0) q->f208 = v - 1;
        v = q->f338; if (v != 0) q->f338 = v - 1;
        if (*(*(u8 **)(p + 0x220) + 0x249) != 0) {
            goto done;
        }
    }
tail:
    func_001823C0(p);
    func_001825F0(p);
done:
    if (p[0x216] == 0) {
        hv = q->f3F8;
        if (hv != 0) {
            if (q->f1B4 == 0) {
                hv = hv - 1;
                q->f3F8 = hv;
                if (hv <= 0) {
                    p[0x406] = 0;
                    func_00190C10(p);
                    func_00175C00(p, 1);
                } else {
                    p[0x406] = 1;
                }
            }
        }
    }
    if (D_004C2840[0xB7] != 0 && p[0x216] == 0 && p[0x406] == 0) {
        p[0x406] = 2;
    }
    if (p[0x216] != 0 || p[0x406] != 0) {
        func_00190B30(p);
    }
    func_0018D290(p);
    *(s8 *)(p + 0x1B0) = -0x80;
    if (q->f200 != 0) {
        p[0x1B0] = 0;
    }
    *(s8 *)(p + 0x1B1) = -0x80;
    if (q->f201 != 0 || (p[5] == 1 || (p[5] == 2 && p[0x20A] == 0))) {
        p[0x1B1] = 0;
    }
}
