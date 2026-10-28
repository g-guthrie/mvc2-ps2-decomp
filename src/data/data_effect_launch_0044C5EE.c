typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;

/* One 10-byte EffectLaunch record of the table D_0044C530 (index = task byte
 * +0x20). func_001C0A90 (lui/addiu 0x001C0AEC/0x001C0AF4) scales the index by
 * 10 (sll 2/addu/sll 1, 0x001C0B54-0x001C0B60) and reads lb +0 (flags), lb +1
 * (paletteDelta), lb +2 (pose), lh +4 (velocityX), lh +6 (velocityY), lbu +8
 * (animation), lbu +9 (variant); same layout as EffectLaunch in
 * src/payload_placement_initializers_001a79b0.c. Byte +3 is the s16 alignment
 * slot: no reader touches it, but retail stores a non-zero value there, so it
 * is spelled as an explicit unread member. */
typedef struct { s8 flags; s8 paletteDelta; s8 pose; u8 unread3; s16 velocityX; s16 velocityY; u8 animation; u8 variant; } EffectLaunchRecord;
EffectLaunchRecord data_effect_launch_0044C5EE = { 0, 0, -2, 0xFFu, 89, -3, 27, 27 };
