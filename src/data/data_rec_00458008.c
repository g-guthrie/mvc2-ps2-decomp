/* Descriptors D_00458008-D_004580C0 for the move handlers at
 * 0x0029B280-0x0029B970 (func_0029B590 / func_0029B610 / func_0029B690 pass
 * D_00458008/18/28 to func_00189660; the others pass their descriptor to
 * func_00189310).
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
    InputScript16 d_458008; /* 0x00458008 */
    InputScript16 d_458018; /* 0x00458018 */
    InputScript16 d_458028; /* 0x00458028 */
    u8 pad_38[8];                /* 0x00458038 */
    InputScript16 d_458040; /* 0x00458040 */
    InputScript16 d_458050; /* 0x00458050 */
    InputScript16 d_458060; /* 0x00458060 */
    InputScript16 d_458070; /* 0x00458070 */
    InputScript32 d_458080; /* 0x00458080 */
    InputScript32 d_4580A0; /* 0x004580A0 */
    InputScript16 d_4580C0; /* 0x004580C0 */
} Data00458008;
typedef char data_rec_00458008_size_check[(sizeof(Data00458008) == 0xC8) ? 1 : -1];

Data00458008 data_rec_00458008 = {
    { 0x0028, 0x1000, 6, { 0, 0, 0 }, { 0x0400, 0x0800, 0x0300, 0x0000 } },
    { 0x0028, 0x1000, 7, { 0, 0, 0 }, { 0x0400, 0x0800, 0x0060, 0x0000 } },
    { 0x0028, 0x1000, 8, { 0, 0, 0 }, { 0x1000, 0x2000, 0x0300, 0x0000 } },
    { 0 },
    { 0x0003, 0x1000, 5, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0300 } },
    { 0x0003, 0x0000, 12, { 0, 0, 0 }, { 0x0800, 0x1000, 0x1800, 0x0060 } },
    { 0x0003, 0x1000, 4, { 0, 0, 0 }, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0x0003, 0x9100, 1, { 0, 0, 0 }, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 0x0005, 0x9100, 0, { 0, 0, 0 }, { 0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0005, 0x9100, 3, { 0, 0, 0 }, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 } },
    { 0x0003, 0x9000, 9, { 0, 0, 0 }, { 0x1000, 0x0000, 0x1000, 0x0060 } }
};
