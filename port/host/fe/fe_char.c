/*
 * Frontend: the character sprite path (Port J).
 *
 * func_00411C10 (credited C) registers a sprite bank (section 0 of a
 * PLxxPAK) in one of the 16 slots D_00632610[] and builds its 16 CLUT
 * records from the bank's ARGB1555 palettes.  func_00412260 (asm only, a
 * VU1/GIF packet builder with a PSMT4 tile cache in VRAM) draws one frame
 * of a slot with a matrix, a colour and a palette.  Here a slot also gets a
 * port/render FlCharBank (tiles decoded into an index atlas on first use)
 * and func_00412260 draws through fl_char_draw, with the palettes taken
 * from the game's own CLUT records each draw (so hit flashes and colour
 * changes the game writes there show).  func_004120A0 releases the slot.
 */
#include <string.h>
#include "../host.h"
#include "../../render/render.h"

extern int func_003DD030(int);
void fe_sync_state(void);
int fe_pal_rgba16(u32 pi, u8 rgba[64]);

static struct {
    const u8 *bank;
    FlCharBank *fb;
    u8 pal[16][64];
    u8 pal_ok[16];
} S[16];

static void slot_free(int i)
{
    if (S[i].fb)
        fl_char_bank_destroy(S[i].fb);
    memset(&S[i], 0, sizeof S[i]);
}

int func_00411C10(void *a, int mode)
{
    int n = func_00411C10__game(a, mode);
    if (n >= 1 && n <= 16) {
        slot_free(n - 1);
        S[n - 1].bank = (const u8 *)a;
        /* the bank's extent is not passed; its tables are checked against 16 MB */
        S[n - 1].fb = fl_char_bank_create((const u8 *)a, 16u << 20);
        if (!S[n - 1].fb)
            HOST_ONCE("character bank %p: not a sprite bank", a);
    }
    return n;
}

int func_004120A0(int n)
{
    if (n >= 1 && n <= 16)
        slot_free(n - 1);
    return func_004120A0__game(n);
}

int func_00412260(int slot, int frame, void *mp, unsigned int urgba, int palette)
{
    int m = (int)(uintptr_t)mp, rgba = (int)urgba;
    u8 *s;
    int i, *t;
    if ((unsigned)(slot - 1) >= 16)
        return 0;
    s = (u8 *)EE_BSS_PTR(0x00632610) + (slot - 1) * 16;
    if (*(u32 *)s == 0)
        return 0;
    i = slot - 1;
    if (!S[i].fb || S[i].bank != (const u8 *)(uintptr_t)*(u32 *)s) {
        slot_free(i);
        S[i].bank = (const u8 *)(uintptr_t)*(u32 *)s;
        S[i].fb = fl_char_bank_create(S[i].bank, 16u << 20);
        if (!S[i].fb)
            return 0;
    }
    /* the slot's 16 CLUT records (s->d) */
    t = (int *)(uintptr_t)func_003DD030(*(s32 *)(s + 0xC));
    if (t) {
        int j;
        for (j = 0; j < 16; j++) {
            u8 c[64];
            if (t[j] && fe_pal_rgba16((u32)t[j], c) == 0 &&
                (!S[i].pal_ok[j] || memcmp(c, S[i].pal[j], 64) != 0)) {
                memcpy(S[i].pal[j], c, 64);
                S[i].pal_ok[j] = 1;
                fl_char_set_palette_rgba(S[i].fb, j, c);
            }
        }
    }
    fe_sync_state();
    fl_char_draw(S[i].fb, frame, (const float *)(uintptr_t)m, (u32)rgba, palette);
    return 0;
}
