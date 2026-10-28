typedef signed int s32;

/* func_0016E080 selects one packed color word per pass (passes 0..6) and
 * writes it to the signed color member at vertex-record offset 0x14. The
 * eighth word (0xFF777777) is not loaded by that loop; it is typed from its
 * neighbours and equals the gray immediate the same function stores into the
 * following color slots. */
s32 data_packed_vertex_color_words_004B52D0[8] = {
    -1,  /* 0xFFFFFFFF */
    -1509114,  /* 0xFFE8F906 */
    -1255895,  /* 0xFFECD629 */
    -816268,  /* 0xFFF38B74 */
    -504908,  /* 0xFFF84BB4 */
    -316205,  /* 0xFFFB2CD3 */
    -1,  /* 0xFFFFFFFF */
    -8947849,  /* 0xFF777777 */
};
