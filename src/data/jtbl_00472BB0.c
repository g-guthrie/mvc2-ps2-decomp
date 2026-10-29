/* (const void *)0x... entries are literal words (no code reads them as addresses), not code labels. */
/* Jump table: 4 code addresses, then one literal word. */
extern char func_003A3420[];
extern char func_003A37F0[];
extern char lbl_003A3340[];
extern char lbl_003A3620[];
const void * const jtbl_00472BB0[5] = {
    lbl_003A3340,
    func_003A3420,
    lbl_003A3620,
    func_003A37F0,
    (const void *)0x00240000u,
};
