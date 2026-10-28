/* func_001E6D80 indexes the first three characters with selector values 0..2
 * (lbu D_004B7060 + s3 - 10 at 0x001E72C0). The fourth character 'S' and the NUL are
 * not read; they are kept as the tail of the same "WINS" string. */
char gScoreboardWinPrefix_004B7060[5] = "WINS";
