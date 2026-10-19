typedef unsigned char u8;

/* func_002F4390 indexes with (options & 0x3C00) >> 10, then stores the
 * selected state code and uses code/2 to select the animation strength.
 * The next native data base, jtbl_0045BC20, bounds this 16-byte lookup.
 */
u8 data_u8_0045BC10[16] = {
    0x04u, 0x04u, 0x04u, 0x04u, 0x06u, 0x06u, 0x0Cu, 0x04u,
    0x00u, 0x02u, 0x0Au, 0x04u, 0x04u, 0x04u, 0x04u, 0x04u,
};
