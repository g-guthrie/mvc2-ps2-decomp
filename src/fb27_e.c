typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x18]; u8 *o[8][3]; } GE;
typedef struct { u8 pad[0x57]; s8 b57; } HE;

extern HE *D_004C2840;
extern GE *D_004C2794;
extern u8 D_004D18A0[];
typedef struct { f32 x, y, z; } V3E;
extern void (*D_004490C0[][22])(u8 *, u8 *);
extern void func_00185490(u8 *p);
extern void func_001E3210(u8 *p, s32 a);
extern void func_00186A60(u8 *p, s32 a);

void func_001902F0(u8 *p) {
    u8 *o;
    s32 i;
    if (D_004C2840->b57 != 0) {
        i = 0;
        do {
            o = D_004C2794->o[p[2]][(p[0x425] + i + 1) % 3];
            *(s16 *)(o + 0x434) = *(s16 *)(p + 0x434);
            *(s16 *)(o + 0x438) = *(s16 *)(p + 0x438);
            if (*(s16 *)(o + 0x434) == 0 && o[0x1F0] == 0 && o[0] != 0 && o[5] != 2) {
                if (o[5] == 0 && (s8)o[0x1B3] == 0) {
                    *(u32 *)(o + 0x1C8) = *(u32 *)(p + 0x1C8);
                    o[0x1B6] = p[0x1B6];
                    o[0x247] = p[0x247];
                    *(u32 *)(o + 0x1CC) = *(u32 *)(p + 0x1CC);
                    o[0x1BA] = (*(u8 **)(p + 0x1CC))[0x1E6];
                    o[0x1B9] = p[0x1E6];
                    o[0x1B3] = *(s8 *)(p + 0x1B3);
                }
                if (o[0x20D] == 3) {
                    o[0x20D] = 1;
                    func_00185490(o);
                }
                if (o[0x247] != 2) {
                    o[0x242] = 0x1E;
                    o[0x243] = 0xC;
                    if (D_004D18A0[0] >= 6) o[0x243] = 8;
                }
                o[0x24D] = 0xA;
                o[0x247] = 2;
                o[0x2B3] = 0;
                o[0x1F0] = 0xFF;
                func_001E3210(o, 0);
                *(u8 **)(o + 0x1D0) = (u8 *)((s32)*(u8 **)(*(u8 **)(o + 0x1C8) + 0x184) + (o[0x1B6] & 0x7F) * 28);
                D_004490C0[o[0x20D]][o[0x247]](o, *(u8 **)(o + 0x1C8));
                o[5] = 3;
                o[7] = 0;
                o[6] = 0;
                o[0x24C] = 0;
                o[0x13C] = 1;
                *(u32 *)(o + 0x48) = 0;
                *(V3E *)(o + 0x50) = *(V3E *)(o + 0x298);
                *(u32 *)(o + 0x118) = 0x3F800000;
                func_00186A60(o, 0x20);
            }
            i++;
        } while (i < 2);
    }
}
