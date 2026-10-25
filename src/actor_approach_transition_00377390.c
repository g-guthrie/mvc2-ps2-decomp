/* Approach the target's open horizontal interval, or wait for the timer.
 * Keep the two native comparisons and their shared half-width explicit. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8 *), func_001757E0(u8 *, int, int), func_003777B0(u8 *);
extern void func_001E7F60(u8 *);

void func_00377390(u8 *p, u8 *owner)
{
    if ((s8)func_00175700(p) < 0) --*(s16 *)(p + 0x1C);
    if (func_003777B0(p)) return;
    if (*(s8 *)(p + 0x151)) {
        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    } else {
        u8 *target = *(u8 **)(owner + 0x220);
        float center = *(float *)(target + 0x34),
              actorX = *(float *)(p + 0x34), halfWidth = 80.0f;
        if ((center - halfWidth < actorX && !(center + halfWidth <= actorX)
             && target[0x20D] != 2) || *(s16 *)(p + 0x1C) == 1) {
            ++p[5];
            if (!owner[0x1B7]) func_001757E0(p, 23, 8);
            else func_001757E0(p, 23, 9);
        } else {
            *(float *)(p + 0x60) = 4.821428298950195f;
            *(float *)(p + 0x6C) = -0.8035714030265808f;
        }
    }
    func_001E7F60(p);
}
