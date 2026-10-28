typedef float f32;
/* Sixteen 28-byte records. func_00260070 (0x00260090-0x00260134) and
 * func_002601B0 (0x0026020C-0x00260278) index them with
 * (actor+0x354 & 0x3C00) >> 10 (0-15) * 28; func_0025F8C0 (0x0025F924-0x0025F9A8)
 * and func_002611C0 (0x00261224-0x002612A8) select record 1 or 2 (+7 / +14 words).
 * +0/+4/+8/+C are copied to actor+0x5C/+0x68/+0x60/+0x6C, +0x10 is tested
 * against 0.0 (0x002600C8) and +0x14 / +0x18 are passed to func_00119098. */
typedef struct {
    f32 velocityX;
    f32 accelX;
    f32 velocityY;
    f32 accelY;
    f32 enable;
    f32 param14;
    f32 param18;
} ActorMotionRecord28;
typedef char data_rec_00453BA0_size_check[(sizeof(ActorMotionRecord28) == 28) ? 1 : -1];
ActorMotionRecord28 data_rec_00453BA0[16] = {
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 22.5f, -0.0065104165f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f },
    { -22.5f, 0.0065104165f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, -28.92857f, 0.0f, 1.0f, -1.0f, 2.0f },
    { 15.0f, 0.0f, -19.285713f, 0.0f, 1.0f, 1.0f, 1.0f },
    { -15.0f, 0.0f, -19.285713f, 0.0f, 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 28.92857f, -0.008370535f, 1.0f, -1.0f, 4.0f },
    { 15.0f, -0.0065104165f, 19.285713f, -0.008370535f, 1.0f, 1.0f, 3.0f },
    { -15.0f, 0.0065104165f, 19.285713f, -0.008370535f, 1.0f, 0.0f, 3.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }
};
