/* PS2 pad model the game expects, and the conversions the fl layer does.
 *
 * Three layers, all derived from the decomp:
 *
 * 1. PadRaw: what libpad returns (scePadRead buffer bytes 2..7), active-HIGH
 *    after the fl layer inverts it (func_003EDA60 does ~btns):
 *      0x0001 SELECT 0x0002 L3 0x0004 R3 0x0008 START
 *      0x0010 UP     0x0020 RIGHT 0x0040 DOWN 0x0080 LEFT
 *      0x0100 L2     0x0200 R2  0x0400 L1  0x0800 R1
 *      0x1000 TRIANGLE 0x2000 CIRCLE 0x4000 CROSS 0x8000 SQUARE
 *    plus analog sticks as bytes (0x80 = centre, 0 = left/up).
 *
 * 2. fl device word (D_0062C530[i]+8, copied to DEVICES[i].buttons by
 *    func_003DAE90): bit j set when raw & D_00478D50[j].mask, i.e.
 *      0x1 UP 0x2 DOWN 0x4 LEFT 0x8 RIGHT 0x10 CROSS 0x20 CIRCLE
 *      0x40 R2 0x80 L2 0x100 SQUARE 0x200 TRIANGLE 0x400 R1 0x800 L1
 *      0x1000 L3 0x2000 R3 0x4000 SELECT 0x8000 START
 *    then func_003ED920 cancels opposite directions (D_00478DE0) and ORs the
 *    left stick direction nibble <<16 and the right stick nibble <<20
 *    (func_003EE690, table D_00478D10).
 *
 * 3. game word (D_004F4480[i].buttons, func_0012F0B0): directions
 *    0x2000 UP 0x1000 DOWN 0x0800 LEFT 0x0400 RIGHT (stick nibble used when
 *    the d-pad is idle and the pad is analog), and buttons
 *    0x8000<-START 0x0002<-SELECT 0x0200<-SQUARE 0x0100<-TRIANGLE
 *    0x0080<-L1 0x0040<-CROSS 0x0020<-CIRCLE 0x0010<-R1 0x0008<-R2 0x0004<-L2.
 *
 * The port fills PadRaw from keyboard / SDL game controller / touch overlay
 * and can hand the game either layer.
 */
#ifndef PORT_PAD_H
#define PORT_PAD_H
#include <stdint.h>

enum {
    PS2_SELECT = 0x0001, PS2_L3 = 0x0002, PS2_R3 = 0x0004, PS2_START = 0x0008,
    PS2_UP = 0x0010, PS2_RIGHT = 0x0020, PS2_DOWN = 0x0040, PS2_LEFT = 0x0080,
    PS2_L2 = 0x0100, PS2_R2 = 0x0200, PS2_L1 = 0x0400, PS2_R1 = 0x0800,
    PS2_TRIANGLE = 0x1000, PS2_CIRCLE = 0x2000, PS2_CROSS = 0x4000, PS2_SQUARE = 0x8000
};

typedef struct PadRaw {
    uint16_t buttons;      /* active-high PS2 bits above */
    uint8_t rx, ry, lx, ly;/* analog, 0x80 = centre (libpad byte order 4..7) */
    uint8_t connected;
    uint8_t analog;        /* 1 = DualShock analog mode (fl flags & 0x30) */
} PadRaw;

/* func_003EE690: stick (x, y in -127..127) -> direction code (bits as fl word 0..3). */
uint32_t pad_stick_dir(int x, int y);
/* fl device word, layer 2. */
uint32_t pad_fl_word(const PadRaw *p);
/* game button word, layer 3 (func_0012F0B0). */
uint16_t pad_game_word(const PadRaw *p);

/* Per-player held/pressed/released, as the game's Input record keeps them. */
typedef struct PadEdge {
    uint16_t buttons, previous, pressed, released;
} PadEdge;
void pad_edge_update(PadEdge *e, uint16_t now);

#endif
