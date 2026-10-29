/* Band-limited interpolation for the audio layer.
 *
 * One Kaiser-windowed sinc kernel (RS_HALF taps each side at unity rate,
 * tabulated at RS_RES points per input sample, linearly interpolated) serves
 * both the per-voice VAG pitch shifting in synth.c and the streaming stereo
 * converter used for the device rate and for ADX streams that are not 48 kHz.
 * When the step (input samples per output sample) exceeds 1 the kernel is
 * widened by the step, so pitching up or converting down never aliases.
 * Weights are renormalised per output sample, so DC gain is exactly 1.
 *
 * This replaces the SPU2's 4-point Gaussian interpolation (part of the
 * "muffled" PS2 sound); see port/docs/AUDIO.md.
 */
#ifndef PORT_AUDIO_RESAMPLE_H
#define PORT_AUDIO_RESAMPLE_H
#include <stdint.h>

#define RS_HALF 16     /* half width in input samples at step <= 1 */
#define RS_RES 512     /* table resolution per input sample */
#define RS_MAX_STEP 4  /* SPU2 pitch limit is 0x3FFF ~= 4x */

void rs_init(void);    /* idempotent */
float rs_kernel(float x); /* x in input samples (|x| < RS_HALF), cutoff 0.95 of Nyquist */

/* Polyphase table for step <= 1 (the common case: every VAG voice plays below
 * 48 kHz): row p holds the normalised taps for frac = p / RS_PHASES at input
 * offsets -(RS_HALF-1) .. RS_HALF from floor(pos). Interpolate rows p, p+1. */
#define RS_PHASES 256
#define RS_TAPS (2 * RS_HALF)
extern float rs_poly[RS_PHASES + 1][RS_TAPS];

/* Weights for an output sample at fractional input position `frac` (0..1)
 * relative to input index i0 = floor(pos). Fills w[0..*n) for input indices
 * first..first+*n-1 and returns `first` relative to i0. scale = max(1, step). */
int rs_weights(double frac, float scale, float *w, int *n);
#define RS_MAX_TAPS (2 * RS_HALF * RS_MAX_STEP + 2)

/* Streaming stereo converter (input rate -> output rate). The caller supplies
 * input through a pull callback that writes up to `max` interleaved stereo
 * frames and returns how many it wrote (0 = no more input right now, which
 * is treated as silence). */
typedef int (*RsPull)(void *ctx, float *dst, int max);

#define RS_BUF 4096
typedef struct RsStream {
    double step;            /* in_rate / out_rate */
    double pos;             /* read position in buf (frames) */
    int fill;               /* frames valid in buf */
    float buf[2][RS_BUF];
    int passthrough;        /* step == 1: copy exactly */
} RsStream;

void rs_stream_init(RsStream *s, double in_rate, double out_rate);
void rs_stream_reset(RsStream *s);
/* Produce `frames` interleaved stereo frames into out (overwrites). */
void rs_stream_run(RsStream *s, RsPull pull, void *ctx, float *out, int frames);

#endif
