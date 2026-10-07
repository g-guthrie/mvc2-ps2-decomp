/* Stop at the first accepted input check, preserving the retail priority. */
typedef unsigned char u8;
extern int func_00203B70(u8 *);
extern int func_00203BD0(u8 *);
extern int func_00203C30(u8 *);
extern int func_00203C90(u8 *);
extern int func_00254CE0(u8 *);
extern int func_00254D40(u8 *);
extern int func_00254DA0(u8 *);
extern int func_00254E10(u8 *);
extern int func_0025C9A0(u8 *);
extern int func_0025CA00(u8 *);
extern int func_0025CA60(u8 *);
extern int func_0025CAC0(u8 *);
extern int func_0029AB80(u8 *);
extern int func_0029ABF0(u8 *);
extern int func_0029AC50(u8 *);
extern int func_0029ACB0(u8 *);
extern int func_0030CD80(u8 *);
extern int func_0030CC60(u8 *);
extern int func_0030CCC0(u8 *);
extern int func_0030CD20(u8 *);

#define ORDERED_CHECKS(name, first, second, third, fourth) \
int name(u8 *p) { \
    if (first(p)) return 1; \
    if (second(p)) return 1; \
    if (third(p)) return 1; \
    return fourth(p) != 0; \
}

ORDERED_CHECKS(func_00203B00, func_00203B70, func_00203BD0, func_00203C30, func_00203C90)
ORDERED_CHECKS(func_00254C70, func_00254CE0, func_00254D40, func_00254DA0, func_00254E10)
ORDERED_CHECKS(func_0025C930, func_0025C9A0, func_0025CA00, func_0025CA60, func_0025CAC0)
ORDERED_CHECKS(func_0029AB10, func_0029AB80, func_0029ABF0, func_0029AC50, func_0029ACB0)
ORDERED_CHECKS(func_0030CBF0, func_0030CD80, func_0030CC60, func_0030CCC0, func_0030CD20)
