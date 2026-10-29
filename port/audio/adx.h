/* CRI ADX (type 3, 4-bit, fixed-coefficient prediction) streaming decoder.
 *
 * Same arithmetic as port/tools/convert/adx.py (verified sample-exact by
 * `soundtest --verify`): s = nib*scale + ((c1*h1 + c2*h2) >> 12), clamped,
 * with c1/c2 from the highpass frequency and `scale` the raw 16-bit word.
 *
 * Streaming: frames are read on demand through a read callback with a small
 * read-ahead cache, so the source can be a memory buffer or the disc image.
 * Looping follows the header's loop block: when the output position reaches
 * loopEnd (exclusive) decoding continues at loopStart. Two history policies:
 *   ADX_LOOP_RESTORE (default): the predictor history saved when the first
 *     pass reached loopStart is restored, so every loop repeats pass 1
 *     exactly (what vgmstream does; v4 headers store this history for the
 *     same reason).
 *   ADX_LOOP_CARRY: the history at loopEnd is carried into loopStart. This is
 *     what the PS2's CRI ADXT does for these v3 files (adxt_trap_entry
 *     0x403020 only resets the ADXSJD position counters), and it leaves a
 *     decaying transient after the jump; see AUDIO.md section 6.
 */
#ifndef PORT_AUDIO_ADX_H
#define PORT_AUDIO_ADX_H
#include <stddef.h>
#include <stdint.h>

typedef struct AdxHeader {
    uint32_t data_off;     /* copyrightOffset + 4 */
    int enc, block, bits, channels;
    uint32_t rate, total;  /* total = samples per channel */
    int highpass, version, flags;
    int c1, c2;
    int has_loop;
    uint32_t loop_start, loop_start_byte, loop_end, loop_end_byte;
    int loop_align;        /* v3 0x14 */
} AdxHeader;

int adx_parse_header(const uint8_t *d, size_t n, AdxHeader *h); /* 0 = ok */

typedef size_t (*AdxRead)(void *ctx, uint64_t off, void *dst, size_t n);

#define ADX_CACHE 16384
typedef struct AdxStream {
    AdxHeader h;
    AdxRead read;
    void *ctx;
    uint64_t size;
    const uint8_t *mem;    /* memory source (read == NULL) */
    uint8_t cache[ADX_CACHE];
    uint64_t cache_off;
    size_t cache_len;
    int32_t hist[2][2];    /* h1, h2 per channel */
    int16_t frame[2][32];
    int frame_len, frame_pos;
    uint32_t next_frame;   /* frame index to decode next */
    uint32_t pos;          /* index of the next sample to output (per channel) */
    int loop;              /* follow the loop block */
    int loop_mode;         /* ADX_LOOP_RESTORE / ADX_LOOP_CARRY */
    int saved_ok;
    int32_t saved[2][2];   /* history at loopStart, first pass */
    uint32_t loops;        /* loop jumps taken */
    int ended;
} AdxStream;

enum { ADX_LOOP_RESTORE = 0, ADX_LOOP_CARRY = 1 };

int adx_open_mem(AdxStream *s, const uint8_t *data, size_t size, int loop);
int adx_open_reader(AdxStream *s, AdxRead read, void *ctx, uint64_t size, int loop);
/* Decode up to `frames` sample frames, interleaved (1 or 2 channels).
 * Returns frames produced (< frames only at the end of a non-looping stream). */
int adx_decode(AdxStream *s, int16_t *out, int frames);

#endif
