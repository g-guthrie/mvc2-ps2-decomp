typedef unsigned int u32;

/* Two adjacent 32-bit fields. Native routines read word 0 at 0x0010E740/0x0010E7C4 and word 1 at 0x0010EB68; they store word 0 at 0x0010EA1C and word 1 at 0x0010EBB0/0x0010EBE4. The next independent unit at 0x004399A8 is loaded at 0x0010E718 and 0x0010E9BC, establishing this object's eight-byte extent. */
u32 data_u32_004399A0[2] = {
    0xFFFFFFFFu, 0x00000000u,
};
