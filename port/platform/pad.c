#include "pad.h"

/* D_00478D50[j].mask: raw PS2 bit that sets fl bit j. */
static const uint16_t k_fl_src[16] = {
    0x0010, 0x0040, 0x0080, 0x0020, 0x4000, 0x2000, 0x0200, 0x0100,
    0x8000, 0x1000, 0x0800, 0x0400, 0x0002, 0x0004, 0x0001, 0x0008,
};
/* D_00478DE0: cancel UP+DOWN and LEFT+RIGHT. */
static const uint8_t k_cancel[16] = { 0, 1, 2, 0, 4, 5, 6, 4, 8, 9, 10, 8, 0, 1, 2, 0 };
/* D_00478D10: 8x8 stick direction grid, row = y, column = x. */
static const uint8_t k_stick[64] = {
    5, 5, 1, 1, 1, 1, 9, 9,
    5, 5, 5, 1, 1, 9, 9, 9,
    4, 5, 5, 0, 0, 9, 9, 8,
    4, 4, 0, 0, 0, 0, 8, 8,
    4, 4, 0, 0, 0, 0, 8, 8,
    4, 6, 6, 0, 0, 10, 10, 8,
    6, 6, 6, 2, 2, 10, 10, 10,
    6, 6, 2, 2, 2, 2, 10, 10,
};

uint32_t pad_stick_dir(int x, int y)
{
    if (x < -127) x = -127;
    if (x > 127) x = 127;
    if (y < -127) y = -127;
    if (y > 127) y = 127;
    return k_stick[((y + 127) / 32) * 8 + (x + 127) / 32];
}

uint32_t pad_fl_word(const PadRaw *p)
{
    if (!p->connected) return 0;
    uint32_t w = 0;
    for (int j = 0; j < 16; j++)
        if (p->buttons & k_fl_src[j]) w |= 1u << j;
    w = (w & 0xFFF0) | k_cancel[w & 0xF];
    if (p->analog) {
        /* func_003EDA60 clamps (byte - 0x80) to >= -0x7F */
        int lx = p->lx - 0x80, ly = p->ly - 0x80, rx = p->rx - 0x80, ry = p->ry - 0x80;
        w |= (pad_stick_dir(lx < -127 ? -127 : lx, ly < -127 ? -127 : ly) & 0xF) << 16;
        w |= (pad_stick_dir(rx < -127 ? -127 : rx, ry < -127 ? -127 : ry) & 0xF) << 20;
    }
    return w;
}

uint16_t pad_game_word(const PadRaw *p)
{
    uint32_t raw = pad_fl_word(p);
    uint16_t f = 0;
    if (!p->connected) return 0;
    if (raw & 1) f |= 0x2000;
    if (raw & 2) f |= 0x1000;
    if (raw & 4) f |= 0x0800;
    if (raw & 8) f |= 0x0400;
    if (p->analog && !f) {
        if (raw & 0x10000) f |= 0x2000;
        if (raw & 0x20000) f |= 0x1000;
        if (raw & 0x40000) f |= 0x0800;
        if (raw & 0x80000) f |= 0x0400;
    }
    if (raw & 0x8000) f |= 0x8000;
    if (raw & 0x4000) f |= 0x0002;
    if (raw & 0x0100) f |= 0x0200;
    if (raw & 0x0200) f |= 0x0100;
    if (raw & 0x0800) f |= 0x0080;
    if (raw & 0x0010) f |= 0x0040;
    if (raw & 0x0020) f |= 0x0020;
    if (raw & 0x0400) f |= 0x0010;
    if (raw & 0x0040) f |= 0x0008;
    if (raw & 0x0080) f |= 0x0004;
    return f;
}

void pad_edge_update(PadEdge *e, uint16_t now)
{
    e->previous = e->buttons;
    e->buttons = now;
    e->pressed = (uint16_t)(~e->previous & now);
    e->released = (uint16_t)(e->previous & ~now);
}
