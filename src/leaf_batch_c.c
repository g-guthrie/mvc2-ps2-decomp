typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;

/* ---- externs ---- */


typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; } Rec8;















/* func_003DBBD0 */
void *func_003DBBD0(s32 *p, u32 a1) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = a1 | 0x51000000;
    return (u8 *)p + 16;
}

/* func_003DD2B0 */
void func_003DD2B0(s32 *p) {
    p[0] = 0x3F800000;
    p[1] = 0;
    p[2] = 0;
    p[4] = 0;
    p[5] = 0x3F800000;
    p[6] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0x3F800000;
}

/* func_003DDB60 */
void func_003DDB60(u8 *p, f32 a, f32 b, f32 c) {
    *(f32 *)(p + 48) = a;
    *(f32 *)(p + 52) = b;
    *(f32 *)(p + 56) = c;
}

/* func_003DF7B0 */
/* func_003DF7B0 - dropped: hardware register read, unreachable via plain C */

/* func_003ED2E0 */

/* func_003ED8E0 */

/* func_003F0A20 */

/* func_003F7BE8 */

/* func_003FC900 */

/* func_003FF3B0 */

/* func_004000E0 */

/* func_00400B98 */

/* func_00404388 */

/* func_004044D0 */

/* func_00404CA8 */

/* func_004052C0 */

/* func_004052F8 */

/* func_00405308 */

/* func_004084D0 */

/* func_00408930 */

/* func_00408948 */

/* func_00408EC8 */

/* func_00409AC8 */

/* func_0040A2F8 */

/* func_0040ADF0 */

/* func_0040B3A0 */

/* func_0040CBB0 */

/* func_0040CBC0 */

/* func_0040EA48 */

/* func_0040EE98 */

/* func_0040EF70 */

/* func_0040EF88 */

/* func_0040EFD0 */

/* func_0040EFE0 */

/* func_0040F1D0 */

/* func_0040F728 */

/* func_0040FCE8 */

/* func_00411270 */

/* func_00411898 */

/* func_004118A8 */

/* func_00416770 */

/* func_00416AC0 */

/* func_0041CB30 */

/* func_0041DB80 */

/* func_00420A00 */

/* func_00420B00 */
