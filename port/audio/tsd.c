#include "tsd.h"
#include <string.h>

void tsd_init(Tsd *t)
{
    memset(t, 0, sizeof *t);
    synth_init(&t->synth);
    t->master = 0x100;
    t->stereo = 1;
}

void tsd_shutdown(Tsd *t)
{
    for (int p = 0; p < TSD_PORTS; p++) tsd_unload_bank(t, p);
}

static TsdPort *port_of(Tsd *t, int bank)
{
    bank &= 0x7F;
    if (bank >= TSD_PORTS || !t->port[bank].loaded) return NULL;
    return &t->port[bank];
}

/* ---- Tsnd_tqreq (0x3348) ---- */
void tsd_req(Tsd *t, int bank, int sound, int handle, int vol, int pan, int pitch)
{
    TsdPort *P = port_of(t, bank);
    if (!P) return;
    int fb = (bank >> 7) & 1, fh = (handle >> 7) & 1, fs = (sound >> 7) & 1;
    sound &= 0x7F;
    handle &= 0x7F;
    int prio;
    uint32_t ofs;
    if (hd_tq_entry(&P->bank, sound, &prio, &ofs)) {
        if (sound != 0 || P->bank.tq_num != 0) return;
        prio = 0x40; /* empty table: dummy entry at +4, as the IRX does */
        ofs = 4;
    }
    int k;
    for (k = TSD_SLOTS - 1; k >= 0; k--)
        if (!(P->slot[k].flags & TQF_ACTIVE)) break;
    if (k < 0) {
        /* steal: strictly lower priority (prio-1 or less), oldest first */
        int lim = prio ? prio - 1 : 0;
        uint32_t best_age = 0;
        for (int j = TSD_SLOTS - 1; j >= 0; j--) {
            TqSlot *q = &P->slot[j];
            if (lim < q->prio) continue;
            if (best_age < q->age) { best_age = q->age; k = j; }
        }
        if (k < 0) return;
    }
    /* exclusive classes: stop older requests flagged the same way */
    for (int j = TSD_SLOTS - 1; j >= 0; j--) {
        TqSlot *q = &P->slot[j];
        if (!(q->flags & TQF_ACTIVE)) continue;
        if (fb && (q->flags & TQF_EXCL_BANK)) q->flags |= TQF_STOP;
        if (fh && (q->flags & TQF_EXCL_HANDLE) && q->handle == handle) q->flags |= TQF_STOP;
        if (fs && (q->flags & TQF_EXCL_SOUND) && q->sound == sound) q->flags |= TQF_STOP;
    }
    TqSlot *q = &P->slot[k];
    q->svol = 0x7F;
    q->span = 0x40;
    q->spitch = 0x2000;
    q->sound = (uint8_t)sound;
    q->handle = (uint8_t)handle;
    q->rvol = (uint8_t)vol;
    q->rpan = (uint8_t)pan;
    q->rpitch = (uint16_t)pitch;
    q->age = 0;
    q->ptr = ofs;
    uint32_t f = q->flags | TQF_STOP;
    f = (f & ~(uint32_t)(TQF_EXCL_BANK | TQF_EXCL_HANDLE | TQF_EXCL_SOUND)) |
        (fb ? TQF_EXCL_BANK : 0) | (fh ? TQF_EXCL_HANDLE : 0) | (fs ? TQF_EXCL_SOUND : 0) |
        TQF_VOL | TQF_PAN | TQF_PITCH;
    q->prio = (uint8_t)prio;
    q->wait = 0;
    if (!(f & TQF_ACTIVE)) P->active++;
    q->flags = (f & ~(uint32_t)TQF_STOP) | TQF_ACTIVE;
}

/* ---- Tsnd_tqchg (0x371C) ---- */
void tsd_change(Tsd *t, int bank, int sound, int handle, int vol, int pan, int pitch)
{
    TsdPort *P = port_of(t, bank);
    if (!P) return;
    sound &= 0x7F;
    handle &= 0x7F;
    for (int j = TSD_SLOTS - 1; j >= 0; j--) {
        TqSlot *q = &P->slot[j];
        if (!(q->flags & TQF_ACTIVE) || q->sound != sound || q->handle != handle) continue;
        if ((int8_t)vol >= 0) { q->rvol = (uint8_t)vol; q->flags |= TQF_VOL; }
        if ((int8_t)pan >= 0) { q->rpan = (uint8_t)pan; q->flags |= TQF_PAN; }
        if ((int16_t)pitch >= 0) { q->rpitch = (uint16_t)pitch; q->flags |= TQF_PITCH; }
    }
}

/* ---- Tsnd_tqcancel (0x3840) / Tsnd_tqchk (0x3900) ---- */
void tsd_cancel(Tsd *t, int bank, int sound, int handle)
{
    TsdPort *P = port_of(t, bank);
    if (!P) return;
    sound &= 0x7F;
    handle &= 0x7F;
    for (int j = TSD_SLOTS - 1; j >= 0; j--) {
        TqSlot *q = &P->slot[j];
        if ((q->flags & TQF_ACTIVE) && q->sound == sound && q->handle == handle) q->flags |= TQF_STOP;
    }
}

int tsd_check(Tsd *t, int bank, int sound, int handle)
{
    TsdPort *P = port_of(t, bank);
    if (!P) return 0;
    sound &= 0x7F;
    handle &= 0x7F;
    for (int j = TSD_SLOTS - 1; j >= 0; j--) {
        TqSlot *q = &P->slot[j];
        if ((q->flags & TQF_ACTIVE) && q->sound == sound && q->handle == handle) return 1;
    }
    return 0;
}

void tsd_stop_port(Tsd *t, int bank)
{
    TsdPort *P = port_of(t, bank);
    if (!P) return;
    int port = bank & 0x7F;
    for (int j = 0; j < TSD_SLOTS; j++) {
        if (P->slot[j].flags & TQF_ACTIVE) synth_cc(&t->synth, port, j, 120, 0);
        P->slot[j].flags &= ~(uint32_t)(TQF_ACTIVE | TQF_STOP);
    }
    P->active = 0;
    synth_port_off(&t->synth, port);
}

void tsd_stop_all(Tsd *t)
{
    for (int p = 0; p < TSD_PORTS; p++) tsd_stop_port(t, p);
}

void tsd_set_master(Tsd *t, uint16_t vol)
{
    /* sceHSyn_SetVolume(port, vol) on every port; 0x100 = unity [inferred] */
    t->master = vol;
    for (int p = 0; p < SY_PORTS; p++) t->synth.port_vol[p] = vol / 256.0f;
}

void tsd_set_stereo(Tsd *t, int stereo)
{
    t->stereo = stereo != 0;
    t->synth.mono = !t->stereo;
}

int tsd_load_bank(Tsd *t, int bank, const void *hd, uint32_t hd_size, const void *bd, uint32_t bd_size,
                  const void *tq, uint32_t tq_size)
{
    bank &= 0x7F;
    if (bank >= TSD_PORTS) return -1;
    tsd_unload_bank(t, bank);
    TsdPort *P = &t->port[bank];
    if (hd_bank_load(&P->bank, hd, hd_size, bd, bd_size, tq, tq_size, NULL, 0)) return -1;
    P->loaded = 1;
    memset(P->slot, 0, sizeof P->slot);
    P->active = 0;
    synth_set_bank(&t->synth, bank, &P->bank);
    t->synth.port_vol[bank] = t->master / 256.0f;
    t->pending_loads++;
    return 0;
}

void tsd_unload_bank(Tsd *t, int bank)
{
    bank &= 0x7F;
    if (bank >= TSD_PORTS || !t->port[bank].loaded) return;
    tsd_stop_port(t, bank);
    synth_set_bank(&t->synth, bank, NULL);
    hd_bank_free(&t->port[bank].bank);
    t->port[bank].loaded = 0;
}

/* ---- tsnd_tq_chgreq (0x3B50) ---- */
static int clamp(int v, int lo, int hi) { return v < lo ? lo : v > hi ? hi : v; }

static void chgreq(Tsd *t, TqSlot *q, int port, int ch)
{
    if (q->flags & TQF_VOL) {
        q->flags &= ~(uint32_t)TQF_VOL;
        synth_cc(&t->synth, port, ch, 7, clamp(q->svol * q->rvol / 127, 0, 127));
    }
    if (q->flags & TQF_PAN) {
        q->flags &= ~(uint32_t)TQF_PAN;
        synth_cc(&t->synth, port, ch, 10, clamp((int8_t)q->rpan - 64 + q->span, 0, 127));
    }
    if (q->flags & TQF_PITCH) {
        q->flags &= ~(uint32_t)TQF_PITCH;
        synth_bend(&t->synth, port, ch, clamp(q->spitch + q->rpitch - 0x2000, 0, 0x3FFF));
    }
}

static void finish(Tsd *t, TsdPort *P, TqSlot *q)
{
    q->flags &= ~(uint32_t)TQF_ACTIVE;
    P->active--;
    (void)t;
}

static inline uint32_t tq_byte(const uint8_t *tq, uint32_t n, uint32_t i) { return i < n ? tq[i] : 0xFF; }

/* ---- tsnd_tq (0x3D38): one tick of one slot ---- */
static void run_slot(Tsd *t, TsdPort *P, int port, int ch)
{
    TqSlot *q = &P->slot[ch];
    const uint8_t *tq = P->bank.tq;
    const uint32_t n = P->bank.tq_size;
    Synth *sy = &t->synth;
#define B(i) tq_byte(tq, n, (uint32_t)(i))
    if (q->flags & TQF_STOP) {
        if (B(q->ptr) == 0xFE && B(q->ptr + 1) == 0) {
            q->ptr += 2;            /* "FE 00" hold point: a stop releases it */
            q->flags &= ~(uint32_t)TQF_STOP;
        } else {
            synth_cc(sy, port, ch, 120, 0);
            finish(t, P, q);
            return;
        }
    }
    if (++q->age == 0) q->age = 0xFFFFFFFFu;
    if (++q->since_note == 0) q->since_note = 0xFFFF;
    if (q->wait) { q->wait--; chgreq(t, q, port, ch); return; }
    uint32_t p = q->ptr;
    for (int guard = 0; guard < 4096; guard++) {
        uint32_t b = B(p);
        p++;
        if (b < 0x80) {                         /* delta time */
            uint32_t m = B(p);
            if (m & 0x80) q->wait = (uint16_t)(b * 4 + 3);   /* (b+1) frames of 1/60 s */
            else { q->wait = (uint16_t)(b + m * 128); p++; } /* ticks of 1/240 s, minus one */
            break;
        }
        if (b < 0xE0) {                         /* note: key = (b & 0x7F) + 12 */
            q->since_note = 0;
            uint32_t v = B(p++);
            if (v & 0x80) v = B(p++);           /* optional extra byte (always 3 in the data) */
            int key = (int)(b & 0x7F) + 12;
            if (v) synth_note_on(sy, port, ch, key, (int)v);
            else synth_note_off(sy, port, ch, key);
            continue;
        }
        if (b < 0xEC) {
            uint32_t v;
            switch (b) {
            case 0xE0:
                q->flags &= ~(uint32_t)TQF_VOL;
                v = B(p++);
                q->svol = (uint8_t)v;
                synth_cc(sy, port, ch, 7, clamp((int)(v * q->rvol / 127), 0, 127));
                break;
            case 0xE1:
                q->flags &= ~(uint32_t)TQF_PAN;
                v = B(p++);
                q->span = (uint8_t)v;
                synth_cc(sy, port, ch, 10, clamp((int8_t)q->rpan - 64 + (int)v, 0, 127));
                break;
            case 0xE2: synth_program(sy, port, ch, (int)B(p)); p++; break;
            case 0xE3: {
                q->flags &= ~(uint32_t)TQF_PITCH;
                uint32_t lo = B(p), hi = B(p + 1);
                p += 2;
                q->spitch = (uint16_t)(lo | hi << 7);
                synth_bend(sy, port, ch, clamp(q->spitch + q->rpitch - 0x2000, 0, 0x3FFF));
                break;
            }
            case 0xE4: synth_cc(sy, port, ch, 11, (int)B(p)); p++; break;
            case 0xE5: synth_cc(sy, port, ch, 123, 0); break;
            case 0xE6: synth_cc(sy, port, ch, 120, 0); break;
            case 0xE7: synth_cc(sy, port, ch, 1, (int)B(p)); p++; break;
            case 0xE8: synth_cc(sy, port, ch, 2, (int)B(p)); p++; break;
            case 0xE9: synth_cc(sy, port, ch, 64, (int)B(p)); p++; break;
            case 0xEA: synth_cc(sy, port, ch, 84, (int)B(p)); p++; break;
            default: break;                    /* 0xEB: no-op */
            }
            continue;
        }
        if (b < 0xF0) {                         /* 0xEC..0xEE hsyn SE messages (unused by the data) */
            uint32_t v = B(p++);
            if (v & 0x80) p++;
            if (b == 0xEE) p++;
            continue;
        }
        switch (b) {
        case 0xF8: p = B(p) | B(p + 1) << 8; continue;       /* jump (TQ-relative) */
        case 0xF9: p += 1; continue;                        /* NRPN 2,0 / 2,16 = v */
        case 0xFA: p += 2; continue;                        /* NRPN 3,a / 3,a|16 = v */
        case 0xFB: synth_cc(sy, port, ch, 91, (int)B(p)); p++; continue;
        case 0xFD: q->prio = (uint8_t)B(p); p++; continue;
        case 0xFE: {
            uint32_t a = B(p);
            if (a == 0) {                       /* hold while the channel sounds */
                if (synth_chan_sounding(sy, port, ch) || q->since_note == 0) { p--; goto out; }
                p++;
                continue;
            }
            p++;
            synth_cc(sy, port, ch, a == 0xFE ? 123 : 120, 0);
            finish(t, P, q);
            goto out;
        }
        case 0xFF:                              /* end once the channel is silent */
            if (synth_chan_sounding(sy, port, ch) || q->since_note == 0) { p--; goto out; }
            synth_cc(sy, port, ch, 120, 0);
            finish(t, P, q);
            goto out;
        default: continue;                      /* F0..F7, FC: no-op */
        }
    }
out:
    q->ptr = p;
    chgreq(t, q, port, ch);
#undef B
}

void tsd_tick(Tsd *t)
{
    t->ticks++;
    for (int p = 0; p < TSD_PORTS; p++) {
        TsdPort *P = &t->port[p];
        if (!P->loaded || !P->active) continue;
        for (int ch = 0; ch < TSD_SLOTS; ch++)
            if (P->slot[ch].flags & TQF_ACTIVE) run_slot(t, P, p, ch);
    }
}

void tsd_render(Tsd *t, float *out, int frames)
{
    /* 48000 / 240 = 200 frames per driver tick */
    static const int per_tick = SY_RATE / TSD_TICK_HZ;
    int done = 0;
    while (done < frames) {
        int n = frames - done;
        int left = per_tick - (int)(t->ticks_frac);
        if (n > left) n = left;
        synth_render(&t->synth, out + 2 * done, n);
        done += n;
        t->ticks_frac += n;
        if (t->ticks_frac >= per_tick) { t->ticks_frac = 0; tsd_tick(t); }
    }
}

/* ---- TsndFunc / tsndReqFunc: the command stream ---- */
static const uint8_t *req(Tsd *t, uint8_t c, const uint8_t *p, const uint8_t *e)
{
#define NEED(k) do { if (p + (k) > e) return NULL; } while (0)
    switch (c & 0xF0) {
    case 0x00: {                                /* treq_TQ */
        NEED(3);
        int bank = p[0], sound = p[1], handle = p[2];
        p += 3;
        if (c == 0x08) { tsd_cancel(t, bank, sound, handle); return p; }
        int vol, pan, pitch;
        if (c & 8) {
            vol = -1; pan = -1; pitch = -1;
            if (c & 1) { NEED(1); vol = (int8_t)*p++; }
            if (c & 2) { NEED(1); pan = (int8_t)*p++; }
            if (c & 4) { NEED(2); pitch = (int16_t)(p[0] << 8 | p[1]); p += 2; }
            tsd_change(t, bank, sound, handle, vol, pan, pitch);
        } else {
            vol = 0x7F; pan = 0x40; pitch = 0x2000;
            if (c & 1) { NEED(1); vol = (int8_t)*p++; }
            if (c & 2) { NEED(1); pan = (int8_t)*p++; }
            if (c & 4) { NEED(2); pitch = (int16_t)(p[0] << 8 | p[1]); p += 2; }
            tsd_req(t, bank, sound, handle, vol, pan, pitch);
        }
        return p;
    }
    case 0x20:
        if (c == 0x28) { tsd_stop_all(t); return p; }               /* Tsnd_tq_allstop */
        if (c == 0x29) { NEED(2); tsd_set_master(t, (uint16_t)(p[0] << 8 | p[1])); return p + 2; }
        if (c & 8) return NULL;                                      /* tsndReqError: packet ends */
        /* 0x20..0x27 treq_BGM (MIDI-sequence BGM): not used by MvC2 (music is ADX) */
        NEED(c == 0x20 || (c >= 0x22 && c <= 0x24) ? 2 : 1);
        return p + (c == 0x20 || (c >= 0x22 && c <= 0x24) ? 2 : 1);
    case 0x40:
        switch (c) {
        case 0x40: tsd_stop_all(t); return p;
        case 0x41: NEED(1); return p + 1;                           /* SPU core attr */
        case 0x42: NEED(1); tsd_set_stereo(t, p[0] != 0); return p + 1;
        case 0x43: tsd_stop_all(t); return p;                       /* allstop_voice */
        case 0x44: NEED(5); return p + 5;                           /* reverb (treq_ALL_REV) */
        case 0x45: NEED(3); return p + 3;
        case 0x47: case 0x48: NEED(1); tsd_unload_bank(t, p[0]); return p + 1;
        case 0x49: NEED(1); return p + 1;
        case 0x4A: NEED(1); tsd_stop_port(t, p[0]); return p + 1;
        case 0x4B: NEED(2); return p + 2;
        case 0x4C: NEED(3); return p + 3;
        case 0x4D: case 0x4E: {                                     /* bank load: id + 3 x (addr, size) */
            NEED(20);
            int bank = (p[0] << 8 | p[1]) & 0xFFF;
            const void *ptr[3];
            uint32_t size[3];
            for (int k = 0; k < 3; k++) {
                const uint8_t *r = p + 2 + 6 * k;
                uint32_t w1 = (uint32_t)r[0] << 24 | (uint32_t)r[1] << 16 | (uint32_t)r[2] << 8 | r[3];
                size[k] = (w1 & 0xF) << 20 | (uint32_t)r[4] << 12 | (uint32_t)r[5] << 4;
                ptr[k] = t->resolve ? t->resolve(t->resolve_ctx, w1 & ~0xFu, &size[k])
                                    : (const void *)(uintptr_t)(w1 & ~0xFu);
            }
            if (ptr[0] && ptr[1]) tsd_load_bank(t, bank, ptr[0], size[0], ptr[1], size[1], ptr[2], ptr[2] ? size[2] : 0);
            return p + 20;
        }
        default: return NULL;
        }
    case 0x50: case 0x60: NEED(1); return p + 1;                    /* IOP-side DMA loads */
    default: return NULL;                                           /* 0x30, 0x70.. : error */
    }
#undef NEED
}

void tsd_exec(Tsd *t, const uint8_t *buf, size_t n)
{
    const uint8_t *p = buf, *e = buf + n;
    while (p && p < e && *p != 0xFF) {
        uint8_t c = *p++;
        p = req(t, c, p, e);
    }
}

int tsd_status(Tsd *t, int fno, uint32_t arg)
{
    switch (fno & 0xFF) {
    case 4: return tsd_check(t, (arg >> 16) & 0x7F, (arg >> 8) & 0x7F, arg & 0x7F);
    case 0xC: { int n = t->pending_loads; t->pending_loads = 0; return n; }
    default: return 0;
    }
}
