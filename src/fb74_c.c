typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x38]; f32 f38; } F38;

extern u8 *D_004C2840;
typedef struct { u8 pad0[0x36]; s8 f36[0x4A]; s16 f80[2]; } G6;
extern G6 *D_004C2794;
extern u8 D_004D18A0[];
extern u32 D_00446CE0[];
extern void (*D_004490C0[][22])(u8 *, u8 *);

void func_0018AD80(u8 *p, u8 *q) {
    extern void func_00190710(u8 *, u8 *);
    extern void func_0018C0B0(u8 *, u8 *);
    extern s32 func_0018BEE0(u8 *, u8 *);
    extern void func_0018C0F0(u8 *, u8 *);
    extern s32 func_00185DD0(u8 *);
    extern s32 func_0018BDA0(u8 *, u8 *);
    extern s32 func_0018BF30(u8 *, u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00190F30(u8 *, u8 *, u8 *);
    extern void func_0018B500(u8 *, u8 *);
    extern void func_0018C6F0(u8 *);
    extern void func_00185490(u8 *);
    extern void func_0016CE90(void);
    extern void func_00190C60(u8 *, u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_00184540(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_0018D240(u8 *, u8 *);
    extern void func_0018C970(u8 *, u8 *);
    extern s32 func_00190B50(u8 *);
    extern s32 func_00174170(void);
    extern void func_001E33D0(u8 *);
    extern void func_00186A60(u8 *, s32);
    extern void func_00190CC0(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018D580(u8 *, u8 *);
    u8 *s0, *r;
    u32 t;
    s32 v;

    if (*(s8 *)(p + 0x539) != 0) {
        if (p[0x473] != 0) {
            t = p[0x473];
            p[0x473] = t - 1;
        }
        if (*(s8 *)(p + 0x4BB) != 0) {
            v = *(s8 *)(p + 0x4BB);
            p[0x4BB] = v - 1;
        }
    }
    if ((*(u16 *)(q + 0x1C0) & 0x200) && q[3] == 1 && p[5] == 2 && p[0x20A] == 6) {
        return;
    }
    *(u32 *)(p + 0x1D0) = *(u32 *)(q + 0x184) + (p[0x1B6] & 0x7F) * 28;
    s0 = *(u8 **)(p + 0x1D0);
    if (*(u32 *)(p + 0x428) & 0x7000000) {
        func_00190710(p, q);
        return;
    }
    p[0x23F] = p[0x23E];
    p[0x23E] = 0;
    p[0x1B4] = s0[5];
    q[0x1B4] = s0[5];
    if (*(s8 *)(q + 0x1B0) & 1) {
        (*(u8 **)(p + 0x1CC))[0x1B4] = s0[5];
    }
    p[0x1F7] = 0;
    if (p[1] == 0xB) {
        if ((*(s32 (**)(u8 *, u8 *))(*(u8 **)(p + 0x43C) + 0x64))(p, q)) {
            func_0018C0B0(p, q);
            return;
        }
    }
    if (p[1] == 0x22) {
        if ((*(s32 (**)(u8 *, u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p, q)) {
            func_0018C0B0(p, q);
            return;
        }
    }
    if (p[1] == 0x32) {
        if ((*(s32 (**)(u8 *, u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p, q)) {
            func_0018C0B0(p, q);
            return;
        }
    }
    if (p[1] == 0x1C || p[1] == 0x1D) {
        if ((*(s32 (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p)) {
            func_0018C0B0(p, q);
            return;
        }
    }
    if (p[0x215] == 0 && (p[0x216] & 0x80) == 0) {
        if (*(s8 *)(D_004C2840 + 0xAB) == 2) {
            if (func_0018BEE0(p, q)) {
                func_0018C0F0(p, q);
                if (*(s16 *)(p + 0x434) != 0) {
                    return;
                }
            }
        }
        if ((func_00185DD0(p) && func_0018BDA0(p, q)) || func_0018BF30(p, q)) {
            func_0018C0F0(p, q);
            if (*(s16 *)(p + 0x434) != 0) {
                return;
            }
        }
    }
    if (p[5] == 0) {
        if (p[1] == 0x1C || p[1] == 0x1D) {
            if ((*(s32 (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x64))(p)) {
                func_0018C0B0(p, q);
                return;
            }
        }
    }
    func_00175C00(p, 1);
    p[0x225] = 0;
    func_00190F30(p, q, s0);
    p[0x289] = 0xFF;
    func_0018B500(p, q);
    p[0x215] = 0;
    func_0018C6F0(p);
    D_004C2794->f80[p[2] ^ 1] += 1;
    if (p[0x247] != 5 && p[0x247] != 0xC && p[0x1F5] == 0) {
        p[0x247] = 3;
    }
    if (p[0x247] != 0xC && p[0x2B3] != 0) {
        p[0x247] = 0xC;
    }
    if (p[0x20D] != 2 && p[0x247] != 5) {
        if (p[5] == 0 && p[0x1E4] == 0 && p[0x217] != 0) {
            *(f32 *)((s32)p + 0x38) = *(f32 *)(p + 0x430);
        } else if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
            p[0x20D] = 2;
        } else {
            ((F38 *)p)->f38 = *(f32 *)(p + 0x430);
        }
    }
    if (*(s16 *)(p + 0x434) == 0) {
        if (p[0x20D] == 3) {
            p[0x20D] = 1;
            func_00185490(p);
        }
        if (p[0x247] != 2) {
            p[0x242] = 0x1E;
            p[0x243] = 0xC;
            if (D_004D18A0[0] >= 6) {
                p[0x243] = 8;
            }
        }
        p[0x24D] = 0xA;
        p[0x247] = 2;
        p[0x2B3] = 0;
        if (p[0x1F0] == 0) {
            p[0x1F0] = 0xFF;
            q[0x1B4] = 0xA;
            p[0x1B4] = 0xA;
            if (*(s8 *)(q + 0x1B0) & 1) {
                (*(u8 **)(p + 0x1CC))[0x1B4] = *(s8 *)(q + 0x1B4);
            }
            func_0016CE90();
            if (D_004C2794->f36[p[2]] < 3) {
                func_00190C60(p, q);
            }
            func_001E3210(p, 0);
        }
    } else if (p[0x216] != 0) {
        if (p[5] == 2) {
            if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
                func_00184540(p);
            } else {
                func_001843A0(p);
            }
        }
        func_0018D240(p, q);
        *(u16 *)(p + 0x1C2) = *(u16 *)(q + 0x1C0);
        r = *(u8 **)(p + 0x1D0);
        if (*(u16 *)(p + 0x1C2) & 0x1000) {
            func_0018C970(p, q);
            *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
            return;
        }
        {
            s32 b3 = r[3];
            u8 k;
            if ((b3 & 0x78) != 0) {
                if ((b3 & 8) != 0) {
                    k = 4;
                } else {
                    k = ((b3 & 0x70) >> 4) - 1;
                }
            } else {
                u8 c = r[9];
                k = 0;
                if (c >= 5) {
                    k++;
                }
                if (c >= 0xC) {
                    k++;
                }
            }
            *(u32 *)(p + 0x228) = D_00446CE0[k];
        }
        goto done;
    } else if (p[0x406] != 0 && func_00190B50(p) == 0) {
        func_0018D240(p, q);
        goto done;
    }
    if (p[0x20D] != 3) {
        func_00185490(p);
    }
    func_001E3210(p, 0x2B);
    v = func_00174170();
    if ((v & 1) == 0) {
        func_001E33D0(p);
    }
    if (*(s8 *)(D_004C2840 + 0xAB) == 1) {
        p[0x203] = 0x3F;
    }
    if (p[0x1EF] != 0) {
        p[0x1EF] = 0;
        p[0x20D] = 0;
        p[0x248] = 0;
    }
    D_004490C0[p[0x20D]][p[0x247]](p, q);
    p[5] = 3;
    p[7] = 0;
    p[6] = 0;
    p[0x24C] = 0;
    p[0x13C] = 1;
    *(s32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00186A60(p, 0x20);
    func_00190CC0(p);
    if (p[0x249] != 0 || p[0x2B3] != 0) {
        func_001E3710(p, 0x28);
    }
done:
    func_0018D580(p, q);
}
