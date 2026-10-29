/* Minimal RIFF/WAVE (PCM16) writer and reader for the audio tools/tests. */
#ifndef PORT_AUDIO_WAV_H
#define PORT_AUDIO_WAV_H
#include <stdint.h>

/* interleaved int16, optional smpl loop chunk (loop_end inclusive, -1 = none) */
int wav_write16(const char *path, const int16_t *pcm, int frames, int channels, int rate,
                long loop_start, long loop_end);
/* float [-1,1] -> PCM16 (round to nearest), stereo */
int wav_write_float_stereo(const char *path, const float *pcm, int frames, int rate);
/* read a PCM16 WAV; malloc'd samples */
int16_t *wav_read16(const char *path, int *frames, int *channels, int *rate);

#endif
