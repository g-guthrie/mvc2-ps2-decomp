/* Descriptors D_00452B20-D_00452BB0 for the move handlers at 0x00243800-0x00243DF0
 * (every one is passed to func_00189310 by its own address; func_00243800 passes
 * the unit start, src/accepted_transition_resets.c).
 *
/* Input-sequence descriptors. func_00189310 (0x00189310) and func_00189660
 * (0x00189660) are the entry points: each is called with a pointer to one
 * descriptor (a1) and the actor's sequence cursor (a2) and dispatches on cursor[0]
 * through D_00448F10 (func_00189310) or D_00448F30 (func_00189660). Fields read
 * from a descriptor: lbu +4 compared with actor+0x45C (0x00189334, 0x00189684);
 * lhu +0 (func_001893E0 0x0018945C, func_001899D0 0x00189A18; lb +0 in
 * func_001896E0 0x00189700); lhu +2 flag bits (func_0018A460 0x0018A480, tested
 * with 0x4000/0x2000/0x1000/0x800/0x100/0x80/0x40/0x20); and lhu step masks at
 * +8 + index * 2 (func_00189390 0x001893A4, func_001893E0 0x00189438,
 * func_00189500 0x00189544, func_00189790 0x0018979C; +0xA func_00189830
 * 0x00189860; +0xC func_001898E0 0x00189914). Bytes +5..+7 are never read.
 * Each descriptor is passed by its own address. Step counts are the live
 * masks plus the zero tail up to the next 16-byte slot (the tail words are
 * unread). */
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
    u16 step[12];
} InputScript32;
typedef char InputScript16_size_check[(sizeof(InputScript16) == 16) ? 1 : -1];
typedef char InputScript32_size_check[(sizeof(InputScript32) == 32) ? 1 : -1];
typedef struct {
    InputScript16 d_452B20; /* 0x00452B20 */
    InputScript32 d_452B30; /* 0x00452B30 */
    InputScript32 d_452B50; /* 0x00452B50 */
    InputScript32 d_452B70; /* 0x00452B70 */
    InputScript16 d_452B90; /* 0x00452B90 */
    InputScript16 d_452BA0; /* 0x00452BA0 */
    InputScript16 d_452BB0; /* 0x00452BB0 */
} Data00452B20;
typedef char data_rec_00452B20_size_check[(sizeof(Data00452B20) == 0xA0) ? 1 : -1];

Data00452B20 data_rec_00452B20 = {
    { 0x0003, 0x0000, 0, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0005, 0x0000, 1, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0005, 0x1000, 2, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0005, 0x8100, 3, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x9100, 4, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0003, 0x9100, 5, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 0x0003, 0x8000, 8, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0060 } }
};
