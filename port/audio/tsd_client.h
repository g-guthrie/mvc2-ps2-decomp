/* EE side of the Tamsoft sound driver: the game's sound boundary.
 *
 * Same functions, signatures, queue semantics and byte protocol as the game's
 * client at 0x422BE0..0x423E30 (decompiled C in src/, serializer 0x423E30
 * traced from asm). The link step can point the game's calls at these:
 *
 *   func_00422CC0  tsdc_reset            clear the 64-entry queue
 *   func_00422DB0  tsdc_init             "bind TSD\0 / TSD\1" (attach to the host driver)
 *   func_00422EA0  tsdc_play             id, vol(s8), pan(s8), pitch(s16); <0 = default
 *   func_00422FB0  tsdc_stop             id; cancels queued commands for id
 *   func_004230B0  tsdc_change           id, vol, pan, pitch; <0 = keep; 1 = nothing to send
 *   func_004231D0  tsdc_stop_all_tq      0x28
 *   func_00423240  tsdc_master_volume    0x29 vol
 *   func_004232C0  tsdc_cmd77            0x77 (sent once at boot; the IRX rejects it)
 *   func_00423480  tsdc_load_bank        0x4D slot + HD/BD/TQ (address, size)
 *   func_004235D0  tsdc_unload_bank      0x48 slot
 *   func_00423650  tsdc_stop_all         0x40
 *   func_004236C0  tsdc_set_stereo       0x42 flag
 *   func_00423750  tsdc_flush            serialise the queue and "sceSifCallRpc" it
 *   func_00423990  tsdc_status           TSD\1 query: fno 4 = playing?, 0xC = loads pending
 *   func_00423E30  (internal)            entry -> bytes serializer
 *
 * id = (bank & 0x7F) << 16 | (sound & 0x7F) << 8 | handle; bit 7 of each byte
 * selects an exclusive class on the IOP (never set by MvC2).
 */
#ifndef PORT_AUDIO_TSD_CLIENT_H
#define PORT_AUDIO_TSD_CLIENT_H
#include <stddef.h>
#include <stdint.h>

/* Where flushed packets and status queries go (the "IOP"). */
typedef struct TsdcSink {
    void (*rpc)(void *ctx, const uint8_t *buf, size_t n);
    int (*status)(void *ctx, int fno, uint32_t arg);
    void *ctx;
} TsdcSink;

void tsdc_set_sink(const TsdcSink *sink);
void tsdc_reset(void);
int tsdc_init(void);
int tsdc_play(uint32_t id, int a1, int a2, int a3);
int tsdc_stop(uint32_t id);
int tsdc_change(uint32_t id, int vol, int pan, int pitch);
int tsdc_stop_all_tq(void);
int tsdc_master_volume(uint32_t value);
int tsdc_cmd77(uint32_t a0, uint32_t a1, uint32_t a2);
int tsdc_load_bank(uint32_t slot, uint32_t hd, int32_t hd_size, uint32_t bd, int32_t bd_size,
                   uint32_t tq, int32_t tq_size);
int tsdc_unload_bank(uint32_t slot);
int tsdc_stop_all(void);
int tsdc_set_stereo(int enabled);
int tsdc_flush(int wait);
int tsdc_status(int fno, int arg);

/* Host convenience: pass real pointers (64-bit safe; registers address tokens
 * that the driver resolves with tsdc_resolve). */
int tsdc_load_bank_ptr(uint32_t slot, const void *hd, int32_t hd_size, const void *bd, int32_t bd_size,
                       const void *tq, int32_t tq_size);
uint32_t tsdc_addr(const void *p, uint32_t size);
/* Tsd.resolve: token -> pointer; clamps *size to the registered length */
const void *tsdc_resolve(void *ctx, uint32_t ee_addr, uint32_t *size);

/* introspection for tests */
int tsdc_queue_used(void);

#endif
