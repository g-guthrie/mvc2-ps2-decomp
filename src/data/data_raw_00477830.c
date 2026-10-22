extern const unsigned int jtbl_00477470[];
extern const unsigned int jtbl_00477560[];

/* Two initial pointers to the jump tables at 0x00477470 and 0x00477560. The
   active selector reads only later pointers. */
const void * const data_raw_00477830[2] = {
    jtbl_00477470,
    jtbl_00477560,
};
