/* The game's main loop on the host (port/host/game_loop.c) and the host
 * services a host main sets up (Port J). */
#ifndef PORT_HOST_LOOP_H
#define PORT_HOST_LOOP_H
#include "../platform/pad.h"
extern const char *volatile mvc2_host_step;
extern volatile long mvc2_host_frame;
extern int mvc2_trace_state;           /* log game state changes (default 1) */
int mvc2_boot(int run_platform_init);  /* main's init calls; returns platform init's result */
void mvc2_frame(void);                 /* one iteration of main's 60 Hz loop (ends in the flip) */
int mvc2_game_state(void);             /* g[0] << 16 | g[1] << 8 | g[2] */
int host_disc_open(const char *iso_path);
void host_pad_set(int port, const PadRaw *p);
extern int host_verbose;
extern void (*host_present_hook)(void);
extern unsigned long host_frame_count;
extern int mvc2_unlock_all; /* "unlock everything", default 1 */
#endif
