/* newlib struct lconv returned by localeconv() (func_0011C960 returns &D_004AC870):
 * ten string pointers ("." and ""), then eight char fields set to CHAR_MAX. */
extern const char D_004AC8A8[];
extern const char data_raw_004AC8A0[];
struct lconv {
    const char *decimal_point;
    const char *thousands_sep;
    const char *grouping;
    const char *int_curr_symbol;
    const char *currency_symbol;
    const char *mon_decimal_point;
    const char *mon_thousands_sep;
    const char *mon_grouping;
    const char *positive_sign;
    const char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
};
typedef char lconv_size_check[(sizeof(struct lconv) == 48) ? 1 : -1];
const struct lconv D_004AC870 = {
    D_004AC8A8, data_raw_004AC8A0, data_raw_004AC8A0, data_raw_004AC8A0, data_raw_004AC8A0,
    data_raw_004AC8A0, data_raw_004AC8A0, data_raw_004AC8A0, data_raw_004AC8A0, data_raw_004AC8A0,
    127, 127, 127, 127, 127, 127, 127, 127,
};
