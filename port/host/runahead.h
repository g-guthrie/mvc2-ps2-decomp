/* Run-ahead (port/host/runahead.c): the game state as one snapshot, and the
 * hooks that make a speculative frame safe to throw away.
 *
 * Each displayed frame the front end runs the real game step with the
 * renderer discarding its draws, saves the state, runs one more step with
 * the same input ("speculating": sound and music requests are dropped) and
 * draws that, then restores.  What is shown is the frame the next step will
 * produce, so a press shows up one frame sooner, ahead of the arcade.
 *
 * The state: the EE data image, the EE BSS, the EE heap up to the break,
 * and the host modules' own per-frame state, which each module registers
 * with RA_STATE().  Host work that cannot be undone (character bank or mesh
 * creation, memory-card files) calls ra_unsafe(): the front end only runs
 * ahead after a quiet stretch without any, and backs off when a speculative
 * frame hits one.  The renderer re-syncs whatever a speculative frame
 * uploaded (fe_render_ra_resync). */
#ifndef PORT_HOST_RUNAHEAD_H
#define PORT_HOST_RUNAHEAD_H
#include <stddef.h>

extern int mvc2_speculating;          /* inside a speculative step */

void ra_register(void *p, size_t n, const char *name);
#define RA_STATE(v) ra_register((void *)&(v), sizeof(v), #v)
#define RA_REGISTER(fn) __attribute__((constructor)) static void fn(void)

int ra_save(void);                    /* 0 = ok */
void ra_restore(void);
size_t ra_state_bytes(void);

void ra_unsafe(const char *why);      /* host work that a restore cannot undo */
unsigned long ra_unsafe_events(void); /* count, real and speculative */

/* FNV-1a over the whole state (testing: run-ahead on and off must agree) */
unsigned long long ra_state_hash(void);

#endif
