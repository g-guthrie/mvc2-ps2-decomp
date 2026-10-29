#include "synth.h"
#include "resample.h"
#include <math.h>
#include <string.h>

#define DECLICK 64

void synth_init(Synth *s)
{
    rs_init();
    memset(s, 0, sizeof *s);
    s->declick = 1;
    for (int p = 0; p < SY_PORTS; p++) {
        s->port_vol[p] = 1.0f;
        synth_reset_channels(s, p);
    }
}

void synth_reset_channels(Synth *s, int port)
{
    for (int c = 0; c < SY_CH; c++) {
        SyChan *ch = &s->ch[port][c];
        ch->prog = 0;
        ch->vol = 100;
        ch->pan = 64;
        ch->expr = 127;
        ch->sustain = 0;
        ch->bend = 0x2000;
    }
}

void synth_set_bank(Synth *s, int port, const HdBank *b)
{
    if (port < 0 || port >= SY_PORTS) return;
    for (int i = 0; i < SY_VOICES; i++)
        if (s->v[i].active && s->v[i].port == port) s->v[i].active = 0;
    s->bank[port] = b;
    synth_reset_channels(s, port);
}

/* ---- SPU2 envelope (PSX-SPX / SPU2 ADSR semantics, evaluated at 48 kHz) ---- */
static void env_step(SyVoice *v)
{
    int rate, exp, dec;
    uint16_t a1 = v->smpl->adsr1, a2 = v->smpl->adsr2;
    switch (v->phase) {
    case 0: rate = (a1 >> 8) & 0x7F; exp = (a1 >> 15) & 1; dec = 0; break;
    case 1: rate = ((a1 >> 4) & 0xF) << 2; exp = 1; dec = 1; break;
    case 2: rate = (a2 >> 6) & 0x7F; exp = (a2 >> 15) & 1; dec = (a2 >> 14) & 1; break;
    case 3: rate = (a2 & 0x1F) << 2; exp = (a2 >> 5) & 1; dec = 1; break;
    default: return;
    }
    int shift = rate >> 2;
    int32_t step = dec ? -8 + (rate & 3) : 7 - (rate & 3);
    int32_t cycles = 1 << (shift > 11 ? shift - 11 : 0);
    step = shift < 11 ? step << (11 - shift) : step;
    if (exp && !dec && v->level > 0x6000) cycles *= 4;
    if (exp && dec) step = (int32_t)(((int64_t)step * v->level) >> 15);
    if (rate == 0x7F) return; /* "off" rate: level holds */
    if (--v->counter > 0) return;
    v->counter = cycles;
    v->level += step;
    if (v->level > 0x7FFF) v->level = 0x7FFF;
    if (v->level < 0) v->level = 0;
    if (v->phase == 0 && v->level >= 0x7FFF) { v->phase = 1; v->counter = 0; }
    else if (v->phase == 1 && (v->level >> 11) <= (a1 & 0xF)) { v->phase = 2; v->counter = 0; }
    else if (v->phase == 3 && v->level == 0) v->phase = 4;
}

/* ---- pitch / gain ---- */
static void voice_params(Synth *s, SyVoice *v)
{
    const SyChan *ch = &s->ch[v->port][v->ch];
    const HdProg *p = v->prog;
    const HdSplit *sp = v->split;
    const HdSample *sm = v->smpl;
    /* sceSdNote2Pitch(base, 0, note', fine) * rate / 48000 */
    double semis = (double)(v->note + p->transpose + sp->transpose) - sm->base;
    double fine = p->detune + sm->detune + sp->detune; /* 1/128 semitone */
    int b = (int)ch->bend - 0x2000;
    double range = (b >= 0 ? sp->bend_hi : sp->bend_lo) / 256.0;
    double bend = b / 8192.0 * range;
    double st = (double)v->src->rate / SY_RATE * pow(2.0, (semis + fine / 128.0 + bend) / 12.0);
    if (st > 0x3FFF / 4096.0) st = 0x3FFF / 4096.0; /* SPU2 pitch register limit */
    v->step = st;
    /* [inferred] linear volume product, as the SPU2 volume registers are linear */
    float g = (sm->vol / 127.f) * (sp->vol / 127.f) * (p->vol / 127.f) * (ch->vol / 127.f) *
              (ch->expr / 127.f) * s->port_vol[v->port];
    int pan = ch->pan + (p->pan - 64) + (sp->pan - 64) + (sm->pan - 64);
    if (pan < 0) pan = 0;
    if (pan > 127) pan = 127;
    /* [inferred] pan law: equal power, normalised to 0 dB at the centre */
    float th = pan / 127.f * 1.5707963f;
    float l = 1.41421356f * cosf(th), r = 1.41421356f * sinf(th);
    if (l > 1) l = 1;
    if (r > 1) r = 1;
    if (s->mono) { float m = 0.5f * (l + r); l = r = m; }
    v->gl = g * l;
    v->gr = g * r;
}

static void refresh_channel(Synth *s, int port, int ch)
{
    for (int i = 0; i < SY_VOICES; i++) {
        SyVoice *v = &s->v[i];
        if (v->active && v->port == port && v->ch == ch) voice_params(s, v);
    }
}

void synth_program(Synth *s, int port, int ch, int prog)
{
    if (port < 0 || port >= SY_PORTS || ch < 0 || ch >= SY_CH) return;
    s->ch[port][ch].prog = prog;
}

static void stop_voice(Synth *s, SyVoice *v, int hard)
{
    if (!v->active || v->kill) return;
    int fast_release = (v->smpl->adsr2 & 0x1F) < 5; /* < 64 samples to silence */
    if (hard || (s->declick && fast_release)) {
        if (!s->declick) { v->active = 0; return; }
        /* hard stop / near-instant release: 64-sample linear ramp from the current level */
        v->kill = DECLICK;
        v->kill_from = v->level * (1.0f / 32767.0f);
        v->released = 1;
    } else if (!v->released) {
        v->released = 1;
        v->phase = 3;
        v->counter = 0;
    }
}

void synth_cc(Synth *s, int port, int ch, int cc, int val)
{
    if (port < 0 || port >= SY_PORTS || ch < 0 || ch >= SY_CH) return;
    SyChan *c = &s->ch[port][ch];
    switch (cc) {
    case 7: c->vol = (uint8_t)val; break;
    case 10: c->pan = (uint8_t)val; break;
    case 11: c->expr = (uint8_t)val; break;
    case 64:
        c->sustain = (uint8_t)val;
        return;
    case 120: /* all sound off */
    case 123: /* all notes off */
        for (int i = 0; i < SY_VOICES; i++) {
            SyVoice *v = &s->v[i];
            if (v->active && v->port == port && v->ch == ch) stop_voice(s, v, cc == 120);
        }
        return;
    default: return; /* CC1/2/84/91, NRPN: no audible use in the shipped TQ data */
    }
    refresh_channel(s, port, ch);
}

void synth_bend(Synth *s, int port, int ch, int v14)
{
    if (port < 0 || port >= SY_PORTS || ch < 0 || ch >= SY_CH) return;
    s->ch[port][ch].bend = (uint16_t)v14;
    refresh_channel(s, port, ch);
}

static SyVoice *alloc_voice(Synth *s, int prio)
{
    SyVoice *best = NULL;
    for (int i = 0; i < SY_VOICES; i++)
        if (!s->v[i].active) return &s->v[i];
    /* steal: lowest priority, released before held, then oldest; never a higher priority */
    for (int i = 0; i < SY_VOICES; i++) {
        SyVoice *v = &s->v[i];
        if (v->prio > prio) continue;
        if (!best || v->prio < best->prio ||
            (v->prio == best->prio && (v->released > best->released ||
                                       (v->released == best->released && v->age < best->age))))
            best = v;
    }
    return best;
}

void synth_note_on(Synth *s, int port, int ch, int note, int vel)
{
    if (port < 0 || port >= SY_PORTS || ch < 0 || ch >= SY_CH) return;
    const HdBank *b = s->bank[port];
    if (!b) return;
    int pi = s->ch[port][ch].prog;
    if (pi < 0 || pi >= b->nprog || !b->prog[pi].valid) return;
    const HdProg *p = &b->prog[pi];
    for (int k = 0; k < p->nsplit; k++) {
        const HdSplit *sp = &p->split[k];
        if (note < sp->lo || note > sp->hi) continue;
        if (sp->sset >= b->nsset) continue;
        const HdSset *ss = &b->sset[sp->sset];
        if (vel < ss->vel_lo || vel > ss->vel_hi) continue;
        for (int j = 0; j < ss->n; j++) {
            int si = ss->idx[2 * j] | ss->idx[2 * j + 1] << 8;
            if (si >= b->nsmpl) continue;
            const HdSample *sm = &b->smpl[si];
            if (vel < sm->vel_lo || vel > sm->vel_hi) continue;
            if (sm->vag >= b->nvag || !b->vag[sm->vag].pcm) continue;
            /* exclusive sample group (MODHSYN 0x6F14); every shipped sample has group 0 */
            if (sm->group)
                for (int i = 0; i < SY_VOICES; i++)
                    if (s->v[i].active && s->v[i].port == port && s->v[i].smpl->group == sm->group)
                        stop_voice(s, &s->v[i], 1);
            SyVoice *v = alloc_voice(s, sm->prio);
            if (!v) continue;
            memset(v, 0, sizeof *v);
            v->active = 1;
            v->port = port;
            v->ch = ch;
            v->note = note;
            v->bank = b;
            v->prog = p;
            v->split = sp;
            v->smpl = sm;
            v->src = &b->vag[sm->vag];
            v->prio = sm->prio;
            v->age = ++s->age;
            v->phase = 0;
            v->level = 0;
            v->counter = 0;
            voice_params(s, v);
            v->cl = v->gl;
            v->cr = v->gr;
        }
    }
}

void synth_note_off(Synth *s, int port, int ch, int note)
{
    for (int i = 0; i < SY_VOICES; i++) {
        SyVoice *v = &s->v[i];
        if (v->active && v->port == port && v->ch == ch && v->note == note) stop_voice(s, v, 0);
    }
}

void synth_port_off(Synth *s, int port)
{
    for (int i = 0; i < SY_VOICES; i++)
        if (s->v[i].active && s->v[i].port == port) stop_voice(s, &s->v[i], 1);
}

int synth_chan_sounding(const Synth *s, int port, int ch)
{
    for (int i = 0; i < SY_VOICES; i++) {
        const SyVoice *v = &s->v[i];
        if (v->active && v->port == port && v->ch == ch) return 1;
    }
    return 0;
}

int synth_active_voices(const Synth *s)
{
    int n = 0;
    for (int i = 0; i < SY_VOICES; i++) n += s->v[i].active;
    return n;
}

/* sample at integer index with loop wrap / silence outside */
static inline float smp(const VagPcm *src, long i)
{
    if (i < 0) return 0;
    if (i >= src->len) {
        if (!src->looped) return 0;
        long body = src->len - src->loop_start;
        i = src->loop_start + (i - src->loop_start) % body;
    }
    return src->pcm[i] * (1.0f / 32768.0f);
}

void synth_render(Synth *s, float *out, int frames)
{
    float w[RS_MAX_TAPS];
    for (int vi = 0; vi < SY_VOICES; vi++) {
        SyVoice *v = &s->v[vi];
        if (!v->active) continue;
        const VagPcm *src = v->src;
        float scale = v->step > 1 ? (float)v->step : 1.0f;
        for (int o = 0; o < frames; o++) {
            /* end of a one-shot sample: the SPU2 voice stops */
            if (!src->looped && v->pos >= src->len) { v->active = 0; break; }
            float env;
            if (v->kill) {
                env = v->kill_from * (v->kill / (float)DECLICK);
                if (--v->kill == 0) { v->active = 0; break; }
            } else {
                env_step(v);
                if (v->phase == 4) { v->active = 0; break; }
                env = v->level * (1.0f / 32767.0f);
            }
            long i0 = (long)floor(v->pos);
            double frac = v->pos - (double)i0;
            float x = 0;
            if (scale == 1.0f) {
                /* polyphase fast path, rows interpolated linearly */
                double fp = frac * RS_PHASES;
                int ph = (int)fp;
                float a = (float)(fp - ph);
                const float *r0 = rs_poly[ph], *r1 = rs_poly[ph + 1];
                long base = i0 - (RS_HALF - 1);
                if (base >= 0 && base + RS_TAPS <= src->len) {
                    const int16_t *p = src->pcm + base;
                    for (int k = 0; k < RS_TAPS; k++) x += (r0[k] + a * (r1[k] - r0[k])) * p[k];
                    x *= 1.0f / 32768.0f;
                } else {
                    for (int k = 0; k < RS_TAPS; k++) x += (r0[k] + a * (r1[k] - r0[k])) * smp(src, base + k);
                }
            } else {
                int n, first = rs_weights(frac, scale, w, &n);
                for (int k = 0; k < n; k++) x += w[k] * smp(src, i0 + first + k);
            }
            /* one-pole smoothing of gain changes (CC7 fades are per 1/60 s) */
            v->cl += (v->gl - v->cl) * (1.0f / 64);
            v->cr += (v->gr - v->cr) * (1.0f / 64);
            float a = x * env;
            out[2 * o] += a * v->cl;
            out[2 * o + 1] += a * v->cr;
            v->pos += v->step;
            if (src->looped && v->pos >= src->len) {
                double body = src->len - src->loop_start;
                v->pos = src->loop_start + fmod(v->pos - src->loop_start, body);
            }
        }
    }
}
