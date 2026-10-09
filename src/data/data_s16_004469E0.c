typedef signed short s16;
/* func_00171110 reads threshold[0] at 0x00171148. func_003D2520 clears the six 0x5B8-byte owners; func_00173F90 leaves +0x522 untouched. The only later stores are inside func_00171110, whose map selector cannot advance from the zeroed field value, so the remaining thresholds stay raw. */
s16 data_s16_004469E0[1] = { 79 };
