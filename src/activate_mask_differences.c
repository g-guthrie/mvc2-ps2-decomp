/* Compare two selected 32-bit masks with the record's saved words.
 * Native counters narrow to signed bytes after each increment. The loops
 * visit words 0..1 and bits 0..31, giving callback indices 0..63.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2840;
extern u32 D_00583BCC[], D_00583BD0[], D_00583BD4[], D_00583BD8[];
extern void func_0013CB50(u8);

void func_0013CC50(u8 *p)
{
    u32 mask[2];
    int player, bit;
    int offset, bitBase;
    u32 *second = mask + 1;
    int flags;

    *second = 0;
    mask[0] = 0;
    flags = *(s8 *)(D_004C2840 + 0x18);
    if (flags & 1) {
        mask[0] |= (int)D_00583BCC[0];
        *second |= (int)D_00583BD0[0];
    }
    if (flags & 2) {
        mask[0] |= (int)D_00583BD4[0];
        *second |= (int)D_00583BD8[0];
    }

    for (player = 0, offset = 0, bitBase = 0; (s8)player < 2;
         offset += 4, bitBase += 32, player = (s8)(player + 1)) {
        u32 pending;
        u32 *stored = (u32 *)(p + 0xD0 + offset);
        u32 *word = (u32 *)((u8 *)mask + offset);

        *word ^= *stored;
        pending = *word;
        if (pending != 0) {
            for (bit = 0; (s8)bit < 32; bit = (s8)(bit + 1)) {
                u32 flag = 1u << (s8)bit;

                if (flag & pending) {
                    *stored |= flag;
                    func_0013CB50((u8)((s8)bit + bitBase));
                }
            }
        }
    }
}
