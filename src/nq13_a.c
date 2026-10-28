typedef unsigned char u8; typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef struct { u8 pad[3]; s8 b3; s16 h4; } Q;
void func_002FC440(u8 *p, Q *q) {
    extern void func_00176160();
    extern void func_00175C00();
    if (p[0x216] != 0) {
        if (*(s16 *)(p + 0x434) == 0) {
            q->h4 = 0;
        }
        switch (q->h4) {
        default: {
            q->h4 = q->h4 - 1;
            func_00176160(p, 0, q->b3 + (p[0x25] << 5), 1);
            if (q->b3 < 7) {
                q->b3 = q->b3 + 1;
                return;
            }
            q->b3 = 0;
            return;
        }
        case 0:
            func_00175C00(p, 0);
            p[0x216] = 0;
        }
    }
}
