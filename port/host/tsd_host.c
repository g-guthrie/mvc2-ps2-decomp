/*
 * The Tamsoft sound driver client (0x422BE0..0x423E30) on the host (Port J).
 *
 * port/audio/tsd_client.c is a C port of the whole EE client (same queue,
 * byte protocol and serializer 0x423E30); the game's entry points forward to
 * it.  Without a frontend the flushed packets go nowhere (no sink); the
 * frontend binds the sink to the port's IOP driver (port/audio/tsd.c), which
 * plays them.
 *
 * Every command entry is also logged for the oracle comparison (HOST_SND,
 * port/tools/oracle/dump_format.h "Sound commands").
 */
#include "host.h"
#include "../audio/tsd_client.h"

void func_00422BE0(void) {}                         /* empty in the game too */
void func_00422C70(void) {}                         /* semaphore lock/unlock: single-threaded */
void func_00422CC0(void) { tsdc_reset(); }
int func_00422DB0(void) { return tsdc_init(); }
int func_00422EA0(int id, int a1, int a2, int a3)
{
    HOST_SND(0x00422EA0u, id, a1, a2, a3);
    return tsdc_play((u32)id, a1, a2, a3);
}
int func_00422FB0(int id)
{
    HOST_SND(0x00422FB0u, id, 0, 0, 0);
    return tsdc_stop((u32)id);
}
int func_004230B0(int id, int vol, int pan, int pitch)
{
    HOST_SND(0x004230B0u, id, vol, pan, pitch);
    return tsdc_change((u32)id, vol, pan, pitch);
}
int func_004231D0(void)
{
    HOST_SND(0x004231D0u, 0, 0, 0, 0);
    return tsdc_stop_all_tq();
}
int func_00423240(int v)
{
    HOST_SND(0x00423240u, v, 0, 0, 0);
    return tsdc_master_volume((u32)v);
}
int func_004232C0(int a0, int a1, int a2)
{
    HOST_SND(0x004232C0u, a0, a1, a2, 0);
    return tsdc_cmd77((u32)a0, (u32)a1, (u32)a2);
}
int func_00423480(int slot, int hd, int hd_size, int bd, int bd_size, int tq, int tq_size)
{
    host_snd_log(0x00423480u, (u32)slot, (u32)hd, (u32)hd_size, (u32)bd, (u32)bd_size, (u32)tq, (u32)tq_size);
    return tsdc_load_bank((u32)slot, (u32)hd, hd_size, (u32)bd, bd_size, (u32)tq, tq_size);
}
int func_004235D0(int slot)
{
    HOST_SND(0x004235D0u, slot, 0, 0, 0);
    return tsdc_unload_bank((u32)slot);
}
int func_00423650(void)
{
    HOST_SND(0x00423650u, 0, 0, 0, 0);
    return tsdc_stop_all();
}
int func_004236C0(int en)
{
    HOST_SND(0x004236C0u, en, 0, 0, 0);
    return tsdc_set_stereo(en);
}
int func_00423750(int wait) { return tsdc_flush(wait); }
int func_00423990(int fno, int arg) { return tsdc_status(fno, arg); }
int func_004238A0(int a0, int a1) { (void)a0; (void)a1; return 0; } /* driver thread priority */
