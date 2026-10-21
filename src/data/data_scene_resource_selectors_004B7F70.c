/* Index is masked with 3. Native stores the selected integer in s16 field +0xCC;
 * MWCC folds this truncating int-array read into lh at a four-byte stride. */
signed int D_004B7F70[4] = { 0x24, 0x25, 0x24, 0x26 };
