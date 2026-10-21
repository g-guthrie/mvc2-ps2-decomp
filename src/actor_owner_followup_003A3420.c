typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
extern int func_00185980(u8 *);
extern int func_003A3810(u8 *, u8 *);
extern void func_003A3880(u8 *, u8 *);
extern void func_00185870(u8 *, u8 *);
extern void func_00182C30(u8 *, int);
extern void func_001E7F60(u8 *);
extern void func_00174910(u8 *, int);
extern int func_00175700(u8 *);
extern signed char D_00472BA0[];
void func_003A3420(u8 *p, u8 *q)
{
    u8 *r;
    s16 timer1c;
    s16 timer1e;
    s32 counter;
    s8 angleDelta;
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (!func_00185980(p)) {
            func_003A3880(p, q);
            return;
        }
        if (*(u8 **)(p + 0x1C4) == *(u8 **)(q + 0x220)) {
            r = *(u8 **)(q + 0x220);
            if (*(s16 *)(r + 0x434) == 0) {
                func_003A3880(p, q);
                goto special_exit;
            }
            *(s8 *)(q + 0x2C0) = -1;
            q[0x20B] = 0xC1;
            (*(u8 **)(q + 0x220))[0x20B] = 0xC1;
            func_00185870(p, *(u8 **)(q + 0x220));
            (*(u8 **)(q + 0x220))[0x20A] = 6;
            (*(u8 **)(q + 0x220))[0x20D] = 2;
            *(s32 *)(p + 0xD4) = 0x320;
            *(s16 *)(p + 0x1C) = 0x40;
            *(s16 *)(p + 0x1E) = 0;
            p[5]++;
            func_00182C30(*(u8 **)(q + 0x220), 0x10);
        special_exit:
            return;
        }
    }
    if (!func_003A3810(p, q))
        goto failed;
    timer1c = (s16)(*(s16 *)(p + 0x1C) - 1);
    *(s16 *)(p + 0x1C) = timer1c;
    if (timer1c < 0)
        goto failed;
    goto advance;
failed:
    func_003A3880(p, q);
    return;
advance:
    timer1e = (s16)(*(s16 *)(p + 0x1E) - 1);
    *(s16 *)(p + 0x1E) = timer1e;
    if (timer1e < 0) {
        *(s16 *)(p + 0x1E) = 0x10;
        if (*(s8 *)(q + 0x539) == 0) {
            if ((*(u16 *)(q + 0x354) & 0x3C00) != 0) {
                angleDelta = (s8)(D_00472BA0[(*(u16 *)(q + 0x354) & 0x3C00) >> 10] - (s8)p[0x22]);
                angleDelta &= 0x1F;
                if (angleDelta >= 0x10)
                    p[0x22]--;
                else
                    p[0x22]++;
                p[0x22] &= 0x1F;
            }
        }
    }
    counter = (s32)((unsigned int)*(s32 *)(p + 0xD8) - 1u);
    *(s32 *)(p + 0xD8) = counter;
    if (counter < 0) {
        *(s32 *)(p + 0xD8) = 3;
        func_001E7F60(p);
    }
    func_00174910(p, *(s16 *)(p + 0xD4));
    func_00175700(p);
}
