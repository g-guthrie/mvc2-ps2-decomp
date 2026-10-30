#include "touch.h"
#include "pad.h"
#include <math.h>
#include <string.h>

static const struct { uint16_t bits; const char *label; } k_btn[TB_COUNT] = {
    { PS2_SQUARE, "LP" }, { PS2_TRIANGLE, "HP" }, { PS2_L1, "A1" },
    { PS2_CROSS, "LK" }, { PS2_CIRCLE, "HK" }, { PS2_R1, "A2" },
    { PS2_START, "ST" },
};

void touch_layout(TouchPad *t, int w, int h) { touch_layout_ex(t, w, h, h > w ? w * 0.75f : 0.f); }

void touch_layout_ex(TouchPad *t, int w, int h, float picture_bottom)
{
    int visible = t->visible;
    float scale = t->scale > 0 ? t->scale : 1.f;
    long long ids[TOUCH_MAX_FINGERS];
    int downs[TOUCH_MAX_FINGERS];
    float fx[TOUCH_MAX_FINGERS], fy[TOUCH_MAX_FINGERS];
    for (int i = 0; i < TOUCH_MAX_FINGERS; i++) {
        ids[i] = t->f[i].id; downs[i] = t->f[i].down; fx[i] = t->f[i].x; fy[i] = t->f[i].y;
    }
    memset(t, 0, sizeof *t);
    t->visible = visible;
    t->scale = scale;
    for (int i = 0; i < TOUCH_MAX_FINGERS; i++) {
        t->f[i].id = ids[i]; t->f[i].down = downs[i]; t->f[i].x = fx[i]; t->f[i].y = fy[i];
    }
    t->w = w;
    t->h = h;
    t->portrait = h > w;
    t->picture_bottom = picture_bottom;
    float r, base, dpad_k = 2.2f;
    if (t->portrait) {
        /* the picture sits at the top; the pad is centred in the space below it */
        float room = (float)h - picture_bottom;
        r = (float)w * 0.085f * scale;
        if (r * 6.2f > room && room > 0) r = room / 6.2f;   /* d-pad + START must fit */
        if (r < (float)w * 0.05f) r = (float)w * 0.05f;
        dpad_k = 1.9f;                                    /* narrow screen: d-pad and buttons side by side */
        base = picture_bottom + room * 0.5f + r * 2.2f;
        if (base > (float)h - r * 1.6f) base = (float)h - r * 1.6f;
        if (base - r * 3.4f < picture_bottom) base = picture_bottom + r * 3.4f;
    } else {
        r = (float)h * 0.085f * scale;
        base = (float)h - r * 1.5f;
    }
    t->dr = r * dpad_k;
    t->dcx = t->dr + r * 0.7f;
    t->dcy = base - r * 1.15f;
    for (int i = 0; i < 6; i++) {
        int col = i % 3, row = i / 3;
        TouchButton *b = &t->b[i];
        b->r = r;
        /* arcade layout: punches on the top row, kicks below, each row slanted */
        b->cx = (float)w - r * 1.3f - (2 - col) * r * 2.3f;
        b->cy = base - (1 - row) * r * 2.3f + (2 - col) * r * 0.25f;
        b->ps2_bits = k_btn[i].bits;
        b->label = k_btn[i].label;
    }
    TouchButton *st = &t->b[TB_START];
    st->r = r * 0.62f;
    st->cx = (float)w * 0.5f;
    if (t->portrait) {
        /* between the picture and the pad */
        st->cy = (picture_bottom + (t->dcy - t->dr - r * 1.2f)) * 0.5f;
        if (st->cy < picture_bottom + st->r * 1.3f) st->cy = picture_bottom + st->r * 1.3f;
    } else {
        st->cy = st->r * 1.5f;
    }
    st->ps2_bits = k_btn[TB_START].bits;
    st->label = k_btn[TB_START].label;
}

static uint16_t hit(const TouchPad *t, float x, float y, int *button);

void touch_finger(TouchPad *t, long long id, int down, float x, float y)
{
    int slot = -1, free_slot = -1;
    for (int i = 0; i < TOUCH_MAX_FINGERS; i++) {
        if (t->f[i].down && t->f[i].id == id) slot = i;
        if (!t->f[i].down && free_slot < 0) free_slot = i;
    }
    if (slot < 0) {
        if (!down || free_slot < 0) return;
        slot = free_slot;
        int b;
        t->latched |= hit(t, x, y, &b); /* new finger: register even if lifted before the next poll */
    }
    t->f[slot].id = id;
    t->f[slot].down = down;
    t->f[slot].x = x;
    t->f[slot].y = y;
    if (down) t->visible = 1;
}

void touch_release_all(TouchPad *t)
{
    for (int i = 0; i < TOUCH_MAX_FINGERS; i++) t->f[i].down = 0;
}

/* PS2 bits under one finger; *button = touched button index or -1. */
static uint16_t hit(const TouchPad *t, float x, float y, int *button)
{
    *button = -1;
    float dx = x - t->dcx, dy = y - t->dcy, d = sqrtf(dx * dx + dy * dy);
    if (d < t->dr * 1.4f) {
        /* d-pad: 8-way by angle, dead zone 25% of the radius, generous outer edge */
        if (d <= t->dr * 0.25f) return 0;
        float a = atan2f(-dy, dx); /* 0 = right, counter-clockwise */
        int sector = (int)floorf((a + 3.14159265f / 8) / (3.14159265f / 4)) & 7;
        static const uint16_t dirs[8] = {
            PS2_RIGHT, PS2_RIGHT | PS2_UP, PS2_UP, PS2_UP | PS2_LEFT,
            PS2_LEFT, PS2_LEFT | PS2_DOWN, PS2_DOWN, PS2_DOWN | PS2_RIGHT };
        return dirs[sector];
    }
    /* buttons: nearest within 1.15 r (fingers are fat) */
    float bd = 1e30f;
    for (int k = 0; k < TB_COUNT; k++) {
        float ex = x - t->b[k].cx, ey = y - t->b[k].cy, e = sqrtf(ex * ex + ey * ey);
        if (e < t->b[k].r * 1.15f && e < bd) { bd = e; *button = k; }
    }
    return *button >= 0 ? t->b[*button].ps2_bits : 0;
}

uint16_t touch_buttons(TouchPad *t)
{
    uint16_t out = t->latched;
    t->latched = 0;
    t->dpad_bits = 0;
    for (int k = 0; k < TB_COUNT; k++) t->b[k].held = 0;
    for (int i = 0; i < TOUCH_MAX_FINGERS; i++) {
        if (!t->f[i].down) continue;
        int b;
        uint16_t bits = hit(t, t->f[i].x, t->f[i].y, &b);
        if (b >= 0) t->b[b].held = 1;
        else t->dpad_bits |= bits;
        out |= bits;
    }
    return out;
}
