/* Host replacement for Sony MODHSYN as TSNDDRV drives it: per bank "port"
 * 16 MIDI-style channels, HD program -> split -> sample set -> sample key-on,
 * SPU2 ADSR, 48 voices with priority stealing, rendered at 48 kHz float with
 * windowed-sinc pitch interpolation (resample.h).
 *
 * Traced (MODHSYN key-on 0x658C and pitch 0x4404..0x4578, AUDIO.md section 4):
 *   - every split of the channel's program whose [lo, hi] holds the note
 *     sounds (layering); then sset velocity range, then sample velocity range;
 *   - pitch = sceSdNote2Pitch(baseNote, 0, note + progTranspose +
 *     splitTranspose, progDetune + sampleDetune + splitDetune + bend)
 *     * vagRate / 48000  (fine unit 1/128 semitone);
 *   - voice allocation by sample priority (byte 0xF).
 * Inferred (marked in AUDIO.md): the volume product and the pan law.
 */
#ifndef PORT_AUDIO_SYNTH_H
#define PORT_AUDIO_SYNTH_H
#include <stdint.h>
#include "hdbank.h"

#define SY_RATE 48000
#define SY_PORTS 16
#define SY_CH 16
#define SY_VOICES 48

typedef struct SyChan {
    int prog;
    uint8_t vol, pan, expr, sustain;
    uint16_t bend;   /* 14-bit, 0x2000 centre */
} SyChan;

typedef struct SyVoice {
    int active;
    int port, ch, note;
    int released;
    const HdBank *bank;
    const HdProg *prog;
    const HdSplit *split;
    const HdSample *smpl;
    const VagPcm *src;
    double pos, step;
    /* SPU2 ADSR */
    int phase;       /* 0 attack 1 decay 2 sustain 3 release 4 off */
    int32_t level;   /* 0..0x7FFF */
    int32_t counter;
    float gl, gr;    /* target gains */
    float cl, cr;    /* current gains (smoothed) */
    int prio;
    uint32_t age;
    int kill;        /* > 0: declick ramp samples left, then off */
    float kill_from; /* envelope level when the ramp started */
} SyVoice;

typedef struct Synth {
    SyChan ch[SY_PORTS][SY_CH];
    const HdBank *bank[SY_PORTS];
    float port_vol[SY_PORTS];
    SyVoice v[SY_VOICES];
    int mono;
    int declick;     /* 1 = minimum 64-sample release / stop ramp (default) */
    uint32_t age;
} Synth;

void synth_init(Synth *s);
void synth_set_bank(Synth *s, int port, const HdBank *b); /* NULL = unload (stops voices) */
void synth_reset_channels(Synth *s, int port);
void synth_program(Synth *s, int port, int ch, int prog);
void synth_cc(Synth *s, int port, int ch, int cc, int val);   /* 7, 10, 11, 64, 120, 123 */
void synth_bend(Synth *s, int port, int ch, int v14);
void synth_note_on(Synth *s, int port, int ch, int note, int vel);
void synth_note_off(Synth *s, int port, int ch, int note);
void synth_port_off(Synth *s, int port);                       /* all voices of a port */
int synth_chan_sounding(const Synth *s, int port, int ch);     /* hsyn GetChStat */
int synth_active_voices(const Synth *s);
/* Mix `frames` stereo frames into out (adds). */
void synth_render(Synth *s, float *out, int frames);

#endif
