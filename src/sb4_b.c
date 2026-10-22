typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x28]; u8 *p28; } SS;

extern u8 D_004734C0[];
extern void func_00126470();
extern void func_003ACEB0(u8 *, u8 *, u8 *);
extern s32 func_001748C0(V3 *, u8 *);
extern void func_003AB950(u8 *, u8 *, u8);
extern void func_003ACCC0(u8 *, u8 *, u8 *, u8 *);
extern void func_0015B200(u8 *, V3 *, s32, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001266A0(u8 *, s32, s32);

void func_003AC020(u8 *x, u8 *y)
{
    u8 *o;
    u8 *cnt;
    s32 i;
    u8 *head;
    u8 *e;
    u8 *tgt;
    s32 sel;
    s8 k;
    s32 v;
    u8 ang;
    s32 d;
    u8 d2;
    s32 a0;
    f32 z;
    f32 df;
    V3 vv;
    volatile f32 *pvx;
    f32 fa;
    s32 c0;

    o = *(u8 **)(x + 0x18);
    c0 = *(s8 *)(y + 0xF);
    if (c0 != 14) {
        if (c0 < 14) y[0xF] = c0 + 1;
        else y[0xF] = c0 - 1;
    }
    sel = *(s8 *)(o + 0x151);
    if (sel < 0) {
        func_00126470();
        e = *(u8 **)(y + 0x24);
    } else {
        k = sel;
        e = D_004734C0 + k * 14;
        *(u8 **)(y + 0x24) = e;
        if (*(s8 *)e < 0) {
            func_00126470();
        } else {
            func_003ACEB0(x, y, e);
            x[0x13C] = 1;
            head = x;
            cnt = y;
            tgt = *(u8 **)(o + 0x1DC);
            for (i = 0; i < *(s8 *)(cnt + 0xF); i++) {
                vv = *(V3 *)(x + 0x34);
                pvx = &vv.x;
                fa = *pvx;
                vv.x = fa + (f32)*(s16 *)(y + 0);
                vv.y -= (f32)*(s16 *)(y + 2);
                ang = func_001748C0(&vv, tgt + 0x34);
                a0 = *(s8 *)(x + 0x22);
                d = (u8)(a0 - (s8)ang);
                if (d != 0) {
                    if (*(s16 *)(o + 0x140) == 0) {
                        if ((u8)d > 0xC) ang = a0 - 0xC;
                    } else {
                        if ((u8)d < 0xF4) ang = a0 + 0xC;
                    }
                }
                a0 = (u8)(*(s8 *)(head + 0x22) + 0x80);
                v = a0;
                if (*(s16 *)(o + 0x140) != 0) v = (u8)((s8)a0 + 0x80);
                if ((s8)((u8)v - (u8)ang) >= 0) ang = a0;
                x = *(u8 **)(x + 0xC);
                y = x + 0x88;
                func_003AB950(x, y, ang);
            }
            func_003ACCC0(x, y, *(u8 **)(cnt + 0x28), o);
            df = *(f32 *)(x + 0x34) - *(f32 *)(y + 0x2C);
            z = 0.0f;
            if (df != z) {
                *(f32 *)(o + 0x34) += df;
                for (i = 0; i < *(s8 *)(cnt + 0xF); i++) {
                    *(f32 *)(head + 0x34) += df;
                    head = *(u8 **)(head + 0xC);
                }
            }
            return;
        }
    }
    *(s8 *)(o + 0x151) = -1;
    func_003ACEB0(x, y, e);
    x[0x13C] = 1;
    head = x;
    cnt = y;
    for (i = 0; i < *(s8 *)(cnt + 0xF); i++) {
        head = *(u8 **)(head + 0xC);
        ang = x[0x22];
        d2 = head[0x22];
        y = head + 0x88;
        if (*(s16 *)(o + 0x140) != 0) {
            if ((u8)(d2 - (u8)ang) > 0x11) ang = (u8)(d2 - 0x11);
        } else {
            if ((u8)((u8)ang - d2) > 0x11) ang = (u8)(d2 + 0x11);
        }
        func_003AB950(head, y, ang);
    }
    func_003ACCC0(head, y, *(u8 **)(cnt + 0x28), o);
    df = *(f32 *)(head + 0x34) - *(f32 *)(y + 0x2C);
    z = 0.0f;
    if (df != z) {
        *(f32 *)(o + 0x34) += df;
        head = x;
        for (i = 0; i < *(s8 *)(cnt + 0xF); i++) {
            *(f32 *)(head + 0x34) += df;
            head = *(u8 **)(head + 0xC);
        }
    }
    if (head[0x22] != x[0x22]) {
        u8 *t = *(u8 **)(cnt + 0x28);
        if (t == 0 || !(*(f32 *)(t + 0x38) <= *(f32 *)(o + 0x430))) goto end;
        if (x[5] == 3) {
            func_001E3210(o, 7);
            goto end;
        }
    }
    {
        u8 *t;
        u8 *q;
        V3 w;
        w = *(V3 *)(*(u8 **)(o + 0x1DC) + 0x34);
        w.y = *(f32 *)(*(u8 **)(o + 0x1DC) + 0x430);
        func_0015B200(*(u8 **)(o + 0x1DC), &w, 1, 0x179);
        t = *(u8 **)(o + 0x1DC);
        *(u8 **)(t + 0x1C8) = o;
        if (o[0x425] == 0) t[0x20A] = 1;
        else t[0x20A] = 0x10;
        t[0x1E6] = o[0x1E6];
        t[0x1B5] = 0x2A;
        func_001266A0(o, 0xD, 6);
        x[5] = 2;
        cnt[9] = *(s8 *)(cnt + 0xF);
        cnt[8] = 0;
        *(s16 *)(cnt + 0xA) = x[0x22];
        cnt[0x33] = 0;
        q = *(u8 **)(cnt + 0x28);
        if (q != 0) {
            q[4] = 2;
            ((SS *)cnt)->p28 = 0;
        }
    }
end:
    return;
}
