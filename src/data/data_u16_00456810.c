typedef unsigned short u16;

/* func_00288EE0 selects 16 low-byte state codes with (func_00174170() & 0xF).
 * Native loads read the low byte of each two-byte slot; the high bytes are zero.
 */
u16 data_u16_00456810[16] = {
    0x0005u, 0x0005u, 0x0005u, 0x0006u, 0x0006u, 0x0007u, 0x0007u, 0x0007u,
    0x0008u, 0x0008u, 0x0008u, 0x0008u, 0x0009u, 0x000Au, 0x000Au, 0x000Au,
};
