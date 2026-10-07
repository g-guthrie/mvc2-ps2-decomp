/* Dispatch the effect state after pending or accepted contact handling. */
typedef unsigned char u8;
typedef void (*Callback)(u8 *);
extern void func_003BD480(u8 *);
extern int func_003BD4C0(u8 *);
extern void func_003BD4A0(u8 *);
extern Callback D_004C2058[6];
void func_003BA480(u8 *p) {
 if (*(signed char *)(p+0x1B3)) func_003BD480(p);
 else if (func_003BD4C0(p)) func_003BD4A0(p);
 else D_004C2058[p[5]](p);
}
extern void func_003BD480(u8 *);
extern int func_003BD4C0(u8 *);
extern void func_003BD4A0(u8 *);
extern Callback D_004C2070[4];
void func_003BABF0(u8 *p) {
 if (*(signed char *)(p+0x1B3)) func_003BD480(p);
 else if (func_003BD4C0(p)) func_003BD4A0(p);
 else D_004C2070[p[5]](p);
}
extern void func_003BD480(u8 *);
extern int func_003BD4C0(u8 *);
extern void func_003BD4A0(u8 *);
extern Callback D_004C2080[4];
void func_003BB000(u8 *p) {
 if (*(signed char *)(p+0x1B3)) func_003BD480(p);
 else if (func_003BD4C0(p)) func_003BD4A0(p);
 else D_004C2080[p[5]](p);
}
