typedef unsigned char u8;
typedef float f32;
/* func_003C8A70 (src/actor_palette_motion_init_003c8a70.c), index p[0x20] << 4:
 * lbu +0..+3 -> p[0x14C..0x14F], +4 non-zero flips facing, +6 is the motion passed to
 * func_001757E0, lwc1 +8 (x speed, negated when facing left) and +0xC (y speed).
 * Bytes +5 and +7 are not read. */
typedef struct {
    u8 color[4];
    u8 flip;
    u8 unk_05;
    u8 motion;
    u8 unk_07;
    f32 vx;
    f32 vy;
} PaletteMotionInit476140;
typedef char PaletteMotionInit476140_size_check[(sizeof(PaletteMotionInit476140) == 16) ? 1 : -1];
PaletteMotionInit476140 data_rec_00476140[3] = {
    { { 0x70u, 0x00u, 0x70u, 0x70u }, 0u, 0x00u, 6u, 0x00u, -26.666666f, 8.571428f },
    { { 0x70u, 0x00u, 0x60u, 0x40u }, 0u, 0x00u, 12u, 0x00u, -6.6666665f, 34.285713f },
    { { 0x70u, 0x00u, 0x70u, 0x70u }, 1u, 0x00u, 18u, 0x00u, -26.666666f, 12.857142f },
};
