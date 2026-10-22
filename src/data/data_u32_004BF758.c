typedef short s16;
/* 8-byte records reached through pointer tables (e.g. D_0044B3D0 / the table at 0x0044B2A0)
   and read by func_001A6A70 with lh at +0, +2, +4:
     +0 start position (converted to float, wrapped at 256.0)
     +2 multiplier applied to the step toward the next position
     +4 frame count stored to actor +0x1C
   Field names are descriptive guesses from that reader; +6 is never read (always 0 here). */
typedef struct { s16 start; s16 scale; s16 frames; s16 unused; } PosStepRec;
typedef char PosStepRec_size_check[(sizeof(PosStepRec) == 8) ? 1 : -1];
PosStepRec data_u32_004BF758[3] = {
    { 0, 1, 1, 0 },
    { 208, -1, 16, 0 },
    { 64, -64, 0, 0 },
};
