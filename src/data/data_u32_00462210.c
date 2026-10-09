typedef unsigned int u32;
/* func_0034D5C0 seeds field22 with 0 or 16 from its mode (0x0034D7E0-EC). func_0034D890 advances it modulo 32 when its two-step timer expires (0x0034D948-5C). func_0034DC30 indexes this table with field22 directly, or with ((field22 ^ 0x1F) + 1) & 0x1F when the alternate mode is enabled (0x0034DC38-64). Both selector paths stay within all 32 entries. */
u32 data_u32_00462210[32] = {
    0x00000008u, 0x00000007u, 0x00000006u, 0x00000005u, 0x00000004u, 0x00000003u, 0x00000002u, 0x00000001u, 
    0x00000000u, 0x0000001Fu, 0x0000001Eu, 0x0000001Du, 0x0000001Cu, 0x0000001Bu, 0x0000001Au, 0x00000019u, 
    0x00000018u, 0x00000017u, 0x00000016u, 0x00000015u, 0x00000014u, 0x00000013u, 0x00000012u, 0x00000011u, 
    0x00000010u, 0x0000000Fu, 0x0000000Eu, 0x0000000Du, 0x0000000Cu, 0x0000000Bu, 0x0000000Au, 0x00000009u, 
};
