#ifndef MVC2_INPUT_SCRIPT_H
#define MVC2_INPUT_SCRIPT_H
/* Input-sequence descriptors (same layout as src/data/data_rec_00452B20.c).
 * Entry points: func_00189310 / func_00189660 / func_00189B90 / func_00189EE0,
 * each called with one descriptor (a1) and the actor's sequence cursor (a2).
 * Fields read: lbu +4 compared with actor+0x45C (0x00189334, 0x00189684,
 * 0x00189BB4, 0x00189F04); lhu +2 flag bits (func_0018A460 0x0018A480,
 * func_00189500, func_0018A080); limit lhu/lb +0 (func_001893E0 0x0018945C,
 * func_001896E0 0x00189700, func_00189C10 0x00189CAC); u16 step masks at
 * +8 + index * 2 (func_00189390 0x001893A4, func_00189500 0x00189544,
 * func_00189F60 0x00189F74). Bytes +5..+7 are never read. Each descriptor is
 * passed by its own address; its step array runs to the next descriptor (the
 * zero tail words are unread). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u16 limit;
    u16 flags;
    u8 state;
    u8 unread_05[3];
    u16 step[4];
} InputScript16;
typedef struct {
    u16 limit;
    u16 flags;
    u8 state;
    u8 unread_05[3];
    u16 step[8];
} InputScript24;
typedef struct {
    u16 limit;
    u16 flags;
    u8 state;
    u8 unread_05[3];
    u16 step[12];
} InputScript32;
typedef char InputScript16_size_check[(sizeof(InputScript16) == 16) ? 1 : -1];
typedef char InputScript24_size_check[(sizeof(InputScript24) == 24) ? 1 : -1];
typedef char InputScript32_size_check[(sizeof(InputScript32) == 32) ? 1 : -1];
#endif
