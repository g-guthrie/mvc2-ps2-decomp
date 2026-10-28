/* On-screen touch pad: a d-pad on the left, 6 buttons (MvC2 LP HP A1 / LK HK A2)
 * on the right and START at the top. Layout is in window (drawable) pixels and is
 * recomputed whenever the drawable size changes, so it uses the letterbox
 * areas in portrait and overlaps the picture edges in landscape.
 * Pure logic (no SDL / GL): the platform feeds fingers, the renderer draws
 * the layout through r_overlay_* (port/render/render.h).
 */
#ifndef PORT_TOUCH_H
#define PORT_TOUCH_H
#include <stdint.h>

#define TOUCH_MAX_FINGERS 10
enum { TB_LP, TB_HP, TB_A1, TB_LK, TB_HK, TB_A2, TB_START, TB_COUNT };

typedef struct TouchButton {
    float cx, cy, r;     /* circle in drawable pixels */
    uint16_t ps2_bits;   /* PadRaw bits it presses */
    const char *label;
    int held;
} TouchButton;

typedef struct TouchPad {
    int w, h;                 /* drawable size the layout was built for */
    float dcx, dcy, dr;       /* d-pad centre and radius */
    uint16_t dpad_bits;       /* current d-pad output */
    TouchButton b[TB_COUNT];
    struct { long long id; int down; float x, y; } f[TOUCH_MAX_FINGERS];
    int visible;              /* shown once a touch was seen (or forced) */
    uint16_t latched;         /* bits hit by a finger-down since the last poll (taps shorter than a frame) */
} TouchPad;

void touch_layout(TouchPad *t, int w, int h);
void touch_finger(TouchPad *t, long long id, int down, float x, float y); /* pixels */
void touch_release_all(TouchPad *t);
uint16_t touch_buttons(TouchPad *t); /* recompute held state; PS2 bits */

#endif
