extern char gSystemLabel_004B8578[];
/* The eight callers of func_0038B2E0 pass a0=1 (0x00129DC0, 0x00129F50,
 * 0x0012B58C, 0x0012B71C, 0x00130E20, 0x00130FB8, 0x0041E994, 0x0041ED64).
 * Its calls to func_0038CDD0, func_0038CE40, and func_0038D010 forward that
 * selector to D_00464CA0; their table loads at 0x0038CE08, 0x0038CE68, and
 * 0x0038D044 read slot 1. */
char * const data_ptr_00464CA4[1] = { gSystemLabel_004B8578 };
