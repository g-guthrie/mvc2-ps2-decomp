/* SPU2 ADPCM ("VAG" body in a BD) decoder.
 *
 * 16-byte blocks {u8 predict<<4 | shift, u8 flags, 14 bytes = 28 nibbles,
 * low nibble first}; flags 1 = end, 2 = repeat (with end: loop), 4 = loop
 * start. Arithmetic is that of port/tools/convert/hdbd.py:
 *   s = ((nib << 12) as s16 >> shift) + ((h1*f0 + h2*f1) >> 6), clamped.
 *
 * For looping samples the decoder appends one more pass over the loop region,
 * decoded with the history carried over from the end block (as the SPU2 does
 * when it jumps), and reports that second pass as the loop body. The first
 * `first_len` samples are identical to hdbd.py's output.
 */
#ifndef PORT_AUDIO_VAG_H
#define PORT_AUDIO_VAG_H
#include <stddef.h>
#include <stdint.h>

typedef struct VagPcm {
    int16_t *pcm;
    int len;          /* total samples in pcm */
    int first_len;    /* samples of the straight first pass */
    int loop_start;   /* loop body = pcm[loop_start .. len) when looped */
    int looped;
    uint32_t rate;    /* Vagi sample rate (Hz) */
} VagPcm;

/* Decode the sample starting at bd[off] (stops at the end flag or `limit`). */
int vag_decode(const uint8_t *bd, size_t limit, uint32_t off, uint32_t rate, VagPcm *out);
void vag_free(VagPcm *v);

#endif
