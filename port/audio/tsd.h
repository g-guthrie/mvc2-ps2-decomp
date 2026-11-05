/* Host reimplementation of TSNDDRV.IRX (Tamsoft Sound Driver), the IOP side
 * of the game's sound-effect / voice path. Traced from the IRX's own symbol
 * table (port/docs/AUDIO.md section 4):
 *
 *   TsndFunc / tsndReqFunc  -> tsd_exec(): the 0xFF-terminated command stream
 *   treq_TQ                 -> 0x00..0x07 play, 0x08 stop, 0x09..0x0F change
 *   Tsnd_tqreq/chg/cancel/chk, tsnd_tq, tsnd_tq_chgreq -> TQ slots + byte code
 *   treq_TQALL              -> 0x28 stop all TQ, 0x29 master volume
 *   treq_ALL                -> 0x40 stop all, 0x42 output mode, 0x43 voices off,
 *                              0x47/0x48 bank release, 0x4A port stop,
 *                              0x4D/0x4E bank load (HD, BD, TQ)
 *   TsndPutFunc (TSD\1)     -> tsd_status(): fno 4 = is-playing, fno 0xC =
 *                              pending bank transfers
 *   ATick (240 Hz timer)    -> tsd_tick()
 *
 * A port = one loaded bank (the EE's bank slot number 0..7: 0..5 players,
 * 6 = AFS01 #59, 7 = #60, 5 also menus #61/#62). Each port has 16 request
 * slots; slot i plays on synth channel i of that port.
 */
#ifndef PORT_AUDIO_TSD_H
#define PORT_AUDIO_TSD_H
#include <stddef.h>
#include <stdint.h>
#include "hdbank.h"
#include "synth.h"

#define TSD_PORTS 16
#define TSD_SLOTS 16
#define TSD_TICK_HZ 240

/* slot flag bits (byte 0 of the IRX's 24-byte tqreq_tbl entry) */
enum {
    TQF_ACTIVE = 0x01, TQF_STOP = 0x02,
    TQF_EXCL_BANK = 0x04, TQF_EXCL_HANDLE = 0x08, TQF_EXCL_SOUND = 0x10,
    TQF_VOL = 0x20, TQF_PAN = 0x40, TQF_PITCH = 0x80
};

typedef struct TqSlot {
    uint32_t flags;
    uint8_t prio;
    uint16_t wait;
    uint8_t sound, handle;
    uint8_t rvol, rpan;      /* request values (EE) */
    uint16_t rpitch;
    uint8_t svol, span;      /* sequence values (TQ byte code) */
    uint16_t spitch;
    uint16_t since_note;     /* +0xE: ticks since the last note event */
    uint32_t age;            /* +0x10 */
    uint32_t ptr;            /* +0x14: offset into the TQ */
} TqSlot;

typedef struct TsdPort {
    int loaded;
    HdBank bank;
    TqSlot slot[TSD_SLOTS];
    int active;              /* tqreq_cnt */
} TsdPort;

typedef struct Tsd {
    Synth synth;
    TsdPort port[TSD_PORTS];
    uint16_t master;         /* last 0x29 value (0x100 = unity [inferred]) */
    int stereo;
    int pending_loads;       /* reported once by status fno 0xC */
    uint32_t ticks;
    int ticks_frac;          /* frames since the last tick */
    /* EE address -> host pointer for cmd 0x4D (NULL: the address is the pointer,
     * which holds on the 32-bit game builds) */
    const void *(*resolve)(void *ctx, uint32_t ee_addr, uint32_t *size);
    void *resolve_ctx;
} Tsd;

void tsd_init(Tsd *t);
void tsd_shutdown(Tsd *t);

/* The IOP command stream (what sceSifCallRpc(TSD\0, 0) delivers). */
void tsd_exec(Tsd *t, const uint8_t *buf, size_t n);
/* TSD\1 status RPC (func_00423990 / TsndPutFunc). */
int tsd_status(Tsd *t, int fno, uint32_t arg);

/* Direct entry points (what the command bytes decode to). */
void tsd_req(Tsd *t, int bank, int sound, int handle, int vol, int pan, int pitch); /* 0x00..0x07 */
void tsd_change(Tsd *t, int bank, int sound, int handle, int vol, int pan, int pitch); /* 0x09..0x0F, -1 = keep */
void tsd_cancel(Tsd *t, int bank, int sound, int handle);  /* 0x08 */
int tsd_check(Tsd *t, int bank, int sound, int handle);    /* 1 = active */
void tsd_stop_port(Tsd *t, int bank);
void tsd_stop_all(Tsd *t);
void tsd_set_master(Tsd *t, uint16_t vol);
void tsd_set_stereo(Tsd *t, int stereo);
int tsd_load_bank(Tsd *t, int bank, const void *hd, uint32_t hd_size, const void *bd, uint32_t bd_size,
                  const void *tq, uint32_t tq_size);
void tsd_unload_bank(Tsd *t, int bank);

/* One 240 Hz driver tick: runs every active TQ slot. */
void tsd_tick(Tsd *t);
/* Render `frames` at 48 kHz, ticking every 200 frames. Adds into out. */
void tsd_render(Tsd *t, float *out, int frames);

#endif
