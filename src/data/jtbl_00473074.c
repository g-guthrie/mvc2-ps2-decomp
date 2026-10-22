typedef signed short s16;

extern void lbl_003A8EF0(void);
extern void func_003A91C0(void);
extern void func_003A9260(void);
extern void func_003A9270(void);

/* Spans: tail of the 8-byte record table D_00473040 (6 s16), the 4-entry switch jump table jtbl_00473080 used by func_003A8ED0 (code pointers), and the head of the s16 table D_00473090 (6 s16, lh). */
typedef struct Jtbl00473074 {
    s16 rec_tail[6];
    void (*target[4])(void);
    s16 tbl_head[6];
} Jtbl00473074;
typedef char Jtbl00473074_size_check[(sizeof(Jtbl00473074) == 40) ? 1 : -1];

const Jtbl00473074 jtbl_00473074 = {
    { 0, 27, 48, 48, 0, 28 },
    { lbl_003A8EF0, func_003A91C0, func_003A9260, func_003A9270 },
    { 56, 56, 56, 56, 56, 56 },
};
