typedef unsigned char u8;
/* Byte +3 of EffectLaunch record 52 of D_0044C530 (10-byte records indexed by task +0x20 and
 * read by func_001C0A90: lb +0/+1/+2, lh +4/+6, lbu +8/+9). The record's header is
 * data_effect_launch_header_0044C738 (pose -2); byte +3 is the unread alignment slot before
 * the s16 velocityX, which retail fills with 0xFF here (the high byte of a sign-extended
 * pose), as in data_effect_launch_0044C5A8. */
typedef struct {
    u8 unread3;
} EffectLaunchAlignSlot;
typedef char EffectLaunchAlignSlot_size_check[(sizeof(EffectLaunchAlignSlot) == 1) ? 1 : -1];
EffectLaunchAlignSlot data_raw_0044C73B = { 0xFFu };
