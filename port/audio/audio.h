/* Port audio engine: 48 kHz float mixer = Tamsoft SE/voice driver (tsd.h,
 * driven through the game's client boundary tsd_client.h) + one CRI ADXT
 * music player (padx_*, shaped like the ADXT calls the game makes), output
 * through SDL audio natively and on the web (SDL2 -> Web Audio).
 *
 * Threading: the SDL callback renders; every API call below takes the audio
 * device lock, so the game thread can call them at any time. With no device
 * (headless) call audio_render() yourself.
 *
 * Web: an AudioContext starts suspended until a user gesture. audio_init()
 * installs pointer/touch/key listeners that resume it (and play one silent
 * buffer, which iOS needs) on the first gesture; audio_set_paused() maps the
 * platform's on_pause callback to suspend/resume.
 */
#ifndef PORT_AUDIO_AUDIO_H
#define PORT_AUDIO_AUDIO_H
#include <stddef.h>
#include <stdint.h>

#define AUDIO_RATE 48000

/* ptid/fid -> malloc'd AFS entry (caller of the loader frees with free()). */
typedef uint8_t *(*AudioAfsLoader)(void *ctx, int ptid, int fid, size_t *size);

int audio_init(int open_device);         /* 0 = ok; open_device 0 = headless */
void audio_shutdown(void);
void audio_set_loader(AudioAfsLoader fn, void *ctx);
void audio_set_paused(int paused);       /* PlatApp.on_pause */
int audio_device_rate(void);             /* 0 when headless */
int audio_unlocked(void);                /* web: context running; native: 1 */
void audio_lock(void);
void audio_unlock(void);
/* Render `frames` stereo frames at 48 kHz (headless / tests). */
void audio_render(float *out, int frames);
void audio_set_master(float gain);       /* final gain (user option), default 1 */

/* ---- ADXT-shaped music player (the BGM boundary, AUDIO.md section 2) ----
 * stat values as CRI's: 0 STOP 1 DECINFO 2 PREP 3 PLAYING 4 DECEND 5 PLAYEND 6 ERROR */
enum { PADX_STOP, PADX_DECINFO, PADX_PREP, PADX_PLAYING, PADX_DECEND, PADX_PLAYEND, PADX_ERROR };
int padx_start_afs(int ptid, int fid);   /* ADXT_StartAfs  0x402C20 */
int padx_start_mem(const uint8_t *adx, size_t size, int take_ownership);
void padx_stop(void);                    /* ADXT_Stop      0x401868 */
int padx_get_stat(void);                 /* ADXT_GetStat   0x401920 */
void padx_set_out_vol(int vol);          /* ADXT_SetOutVol 0x4020D8, 0.1 dB, -999 = mute */
int padx_get_out_vol(void);              /* ADXT_GetOutVol 0x402118 */
void padx_pause(int sw);                 /* ADXT_Pause     0x4026B0 */
int padx_get_stat_pause(void);           /* ADXT_GetStatPause 0x4027A8 */
void padx_set_lp_flg(int on);            /* ADXT_SetLpFlg  0x4025F0 (default on) */
int padx_get_lp_cnt(void);               /* ADXT_GetLpCnt  0x4025C0 */
void padx_set_output_mono(int mono);     /* 0x402BC0 (via func_001E4260) */
/* Loop seam policy (adx.h): 0 = restore the loop-start history (default,
 * seamless), 1 = carry it like the PS2's CRI ADXT (audible transient). */
void padx_set_loop_carry(int carry);
uint32_t padx_get_time(void);            /* samples played (ADXT_GetTime numerator) */

/* The SE/voice driver lives inside the engine; tsd_client.h is bound to it by
 * audio_init(). These expose it for tools. */
struct Tsd;
struct Tsd *audio_tsd(void);

#endif
