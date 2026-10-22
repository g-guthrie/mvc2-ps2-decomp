typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct E45 { s32 w0; s32 w4; s32 w8; s32 wC; u8 b10; u8 b11; u8 pad12[2]; } E45;
extern u8 D_004CC150[];
extern E45 D_004CD170[];
extern s32 D_0044F1C0[];

s32 func_001E59E0(u32 chan, u32 slot, s32 x, s32 a3)
{
    extern s32 func_00423990(s32, s32);
    extern s32 func_00422FB0(u32);
    extern s32 func_00422EA0(u32, s32, s32, s32);
    u8 *e;
    s32 i;
    u32 id;
    u32 id2;
    s32 j;

    e = D_004CC150 + chan * 512 + slot * 4;
    for (;;) {
        if (slot >= 0x80) break;
        if (e[0] == 1) {
            if ((e[1] & 0x80) != 0) {
                x = e[1] & 0x7F;
            } else {
                x = D_0044F1C0[x];
            }
            a3 = D_004CD170[chan].w4;
            switch (chan) {
            case 0: case 1: case 2: case 3: case 4: case 5:
                switch (a3) {
                case 0x0:
                    if (slot == 0x19) goto L6;
                    break;
                case 0x1:
                    if (slot == 0x15) goto L6;
                    if (slot == 0x16) goto L6;
                    if (slot == 0x19) goto L6;
                    break;
                case 0x5:
                    if (slot == 0x1E) goto L6;
                    if (slot == 0x1F) goto L6;
                    break;
                case 0x10:
                    if (slot == 0x17) goto L6;
                    if (slot == 0x19) goto L6;
                    if (slot == 0x1A) goto L6;
                    if (slot == 0x1B) goto L6;
                    if (slot == 0x1C) goto L6;
                    break;
                case 0x14:
                    if (slot == 0x1B) goto L6;
                    break;
                case 0x1E:
                    if (slot == 0x16) goto L6;
                    break;
                case 0x1F:
                    if (slot == 0x15) goto L6;
                    if (slot == 0x18) goto L6;
                    if (slot == 0x1E) goto L6;
                    if (slot == 0x24) goto L6;
                    break;
                case 0x22:
                    if (slot == 0xB) goto L6;
                    if (slot == 0xC) goto L6;
                    if (slot == 0xD) goto L6;
                    break;
                case 0x28:
                    if (slot == 0x19) goto L6;
                    break;
                case 0x26:
                    if (slot == 0x3) goto L6;
                    break;
                case 0x2B:
                    if (slot == 0x18) goto L6;
                    break;
                case 0x37:
                    if (slot == 0x17) goto L6;
                    if (slot == 0x1A) goto L6;
                    break;
                case 0x38:
                    if (slot == 0x10) goto L6;
                    if (slot == 0x19) goto L6;
                    if (slot == 0x1A) goto L6;
                    if (slot == 0x1B) goto L6;
                    break;
                case 0x3A:
                    if (slot == 0xD || (slot >= 0x16 && slot <= 0x1B)) goto L6;
                    break;
                }
                if (slot < 0x1E) {
                    for (i = 0; i <= 5; i++) {
                        id = ((chan & 0x7F) << 16) | ((i & 0x7F) << 8) | 1;
                        if (func_00423990(4, id) != 0) func_00422FB0(id);
                    }
                    for (j = 10; j <= 0x1D; j++) {
                        id2 = ((chan & 0x7F) << 16) | ((j & 0x7F) << 8) | 1;
                        if (func_00423990(4, id2) != 0) func_00422FB0(id2);
                    }
                    goto L6;
                }
                if (slot >= 0x30) {
                    id = ((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1;
                    if (func_00423990(4, id) != 0) func_00422FB0(id);
                }
                if (slot == 0x1B) goto L6;
                id = ((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1;
                if (func_00423990(4, id) != 0) func_00422FB0(id);
            case 6:
            L6:
                switch (slot) {
                case 0x46:
                    func_00422FB0(((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1);
                case 0x48:
                    func_00422FB0(((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1);
                case 0x4B:
                    func_00422FB0(((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1);
                default:
                    break;
                }
            case 7:
            default:
                func_00422EA0(((chan & 0x7F) << 16) | ((slot & 0x7F) << 8) | 1, -1, (s8)x, -1);
            }
        }
        if (e[3] == 0) break;
        slot++;
        e += 4;
    }
    return 0;
}
