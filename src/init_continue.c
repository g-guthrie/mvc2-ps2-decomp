/* Advance the step, initialize when requested, and run the update callback. */
typedef unsigned char u8;
extern void func_0024A810(u8 *);
extern void func_0024AEE0(u8 *);
extern void func_00258C00(u8 *);
extern void func_002590A0(u8 *);
extern void func_0025E120(u8 *);
extern void func_0025E340(u8 *);
extern void func_0027B7C0(u8 *);
extern void func_0027BC50(u8 *);

#define INIT_CONTINUE(name,initialize,update) \
void initialize(u8 *); \
extern void update(u8 *); \
void name(u8 *p) { \
 ++p[6]; \
 if (!p[0x20]) initialize(p); \
 update(p); \
}

INIT_CONTINUE(func_0024A7C0, func_0024AEE0, func_0024A810)
INIT_CONTINUE(func_00258BB0, func_002590A0, func_00258C00)
INIT_CONTINUE(func_0025E0D0, func_0025E340, func_0025E120)
INIT_CONTINUE(func_0027B770, func_0027BC50, func_0027B7C0)
