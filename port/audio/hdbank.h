/* AFS01 sound bank: Sony IECS HD (Prog / Sset / Smpl / Vagi), BD (SPU2
 * ADPCM) and the two Tamsoft blocks.
 *
 * AFS01 entry = 8 x {u32 offset, u32 size}:
 *   [0] HD, [1] BD,
 *   [2] TQ ("RDST" "qesT"): the Tamsoft sound table sent to the IOP with the
 *       bank (cmd 0x4D). +0x0E u16 count, +0x10 u32 entry[count] =
 *       priority << 24 | offset; offset -> TQ byte code (port/docs/AUDIO.md).
 *   [3] EE table: 16-byte records the EE turns into the 512-byte per-slot
 *       table at D_004CC150 (func_001E5710): rec[0] valid, rec[3] layered
 *       continuation, rec[4] bit7 = fixed pan (rec[4] & 0x7F), rec[0xE].
 *
 * HD record layouts (verified against all 63 banks, see AUDIO.md section 3):
 *   Prog  : u32 splitOfs (rel. to the prog), u8 nSplit, u8 splitSize(20),
 *           u8 vol, u8 pan, s8 transpose, s8 detune, s8 keyFollowPan,
 *           u8 keyFollowPanCenter, ... (LFO fields, unused by the data)
 *   Split : u16 sset, u8 lo, u8 crossfade, u8 hi, u8 number, u16 bendLo,
 *           u16 bendHi, 6 x key-follow bytes, u8 vol, u8 pan, s8 transpose,
 *           s8 detune
 *   Sset  : u8 velCurve, u8 velLo, u8 velHi, u8 n, u16 smpl[n]
 *   Smpl  : u16 vag, u8 velLo, u8 velCrossfade, u8 velHi, 6 x vel-follow,
 *           u8 baseNote, s8 detune, u8 pan, u8 group, u8 prio, u8 vol, u8 -,
 *           u16 adsr1, u16 adsr2, 10 x ADSR key-follow, LFO, u8 lfoAttr,
 *           u8 spuAttr   (0x2A bytes)
 *   Vagi  : u32 bdOffset, u16 rate, u8 loop, u8 0xFF
 * Detune units are 1/128 semitone (sceSdNote2Pitch "fine").
 */
#ifndef PORT_AUDIO_HDBANK_H
#define PORT_AUDIO_HDBANK_H
#include <stddef.h>
#include <stdint.h>
#include "vag.h"

typedef struct HdSample {
    uint16_t vag;
    uint8_t vel_lo, vel_hi, base;
    int8_t detune;
    uint8_t pan, group, prio, vol;
    uint16_t adsr1, adsr2;
} HdSample;

typedef struct HdSplit {
    uint16_t sset;
    uint8_t lo, hi;
    uint16_t bend_lo, bend_hi; /* semitones << 8 */
    uint8_t vol, pan;
    int8_t transpose, detune;
} HdSplit;

typedef struct HdSset {
    uint8_t vel_lo, vel_hi;
    int n;
    const uint8_t *idx; /* n x u16 LE */
} HdSset;

typedef struct HdProg {
    int valid, nsplit;
    uint8_t vol, pan;
    int8_t transpose, detune, kf_pan;
    uint8_t kf_pan_center;
    HdSplit *split;
} HdProg;

typedef struct HdBank {
    uint8_t *mem;          /* owned copy of HD | BD | TQ | EE table */
    const uint8_t *hd, *bd, *tq, *tbl;
    uint32_t hd_size, bd_size, tq_size, tbl_size;
    int nprog, nsset, nsmpl, nvag;
    HdProg *prog;
    HdSset *sset;
    HdSample *smpl;
    VagPcm *vag;
    int tq_num;            /* sounds in the TQ */
} HdBank;

/* Parse from separate blocks (what cmd 0x4D hands the IOP); copies them. */
int hd_bank_load(HdBank *b, const void *hd, uint32_t hd_size, const void *bd, uint32_t bd_size,
                 const void *tq, uint32_t tq_size, const void *tbl, uint32_t tbl_size);
/* Parse a whole AFS01 entry. */
int hd_bank_load_afs01(HdBank *b, const uint8_t *entry, size_t size);
void hd_bank_free(HdBank *b);

/* TQ entry for a sound: priority, byte offset into tq; -1 if absent */
int hd_tq_entry(const HdBank *b, int sound, int *prio, uint32_t *ofs);

#endif
