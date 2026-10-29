/*
 * IOP-side services on the host (Port J): SIF RPC, libpad, the RTC, the
 * memory card init.
 *
 * There is no IOP.  The game reaches it through Sony's EE libraries
 * (libkernl SIF RPC, libpad, libcdvd, libmc); the host answers at those
 * libraries' API, so the game's own callers (the fl pad layer
 * func_003ED300/func_003EDA60, the Tamsoft client, ...) run unchanged.
 *
 * libpad: every port reports a DualShock (mode id 0x73, analog) that is
 * stable at once; scePadRead returns the buttons/sticks from host_pad_read()
 * (the frontend sets it from the keyboard / controller / touch overlay; with
 * no frontend nothing is pressed).
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "host.h"
#include "pad.h"

extern void func_003DCD40(void *, unsigned char, int);

/* ---- SIF RPC (libkernl) -------------------------------------------------
 * sceSifBindRpc(client, rpc_number, mode): the client struct gets a non-zero
 * server pointer at +0x24, which is what the callers poll for. */
static u8 host_rpc_server[64];

int func_00106C98(void *client, int rpc_number, int mode)
{
    (void)mode;
    HOST_ONCE("sceSifBindRpc: no IOP; binds succeed (first: 0x%08X)", (u32)rpc_number);
    *(void **)((u8 *)client + 0x24) = host_rpc_server;
    return 0;
}

/* sceSifCallRpc(client, fno, mode, send, ssize, recv, rsize, end_func, end_param):
 * nothing on the other side; the receive buffer is left as it is. */
int func_00106E68(void *client, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                  void *end_func, void *end_param)
{
    (void)client; (void)fno; (void)mode; (void)send; (void)ssize; (void)recv; (void)rsize;
    (void)end_func; (void)end_param;
    HOST_ONCE("sceSifCallRpc: no IOP; calls return at once");
    return 0;
}

/* ---- libpad ---------------------------------------------------------- */
static PadRaw host_pads[2];

void host_pad_set(int port, const PadRaw *p)
{
    if (port >= 0 && port < 2)
        host_pads[port] = *p;
}

int func_0010D360(int mode) /* scePadInit */
{
    (void)mode;
    return 1;
}

int func_0010D5C0(int port, int slot, int dma_buf) /* scePadPortOpen */
{
    (void)port; (void)slot; (void)dma_buf;
    return 1;
}

int func_0010D990(int port, int slot) /* scePadGetState: 6 = STABLE */
{
    (void)slot;
    return (port == 0 || port == 1) ? 6 : 0;
}

int func_0010DD70(int port, int slot, int term, int offs) /* scePadInfoMode */
{
    (void)port; (void)slot; (void)offs;
    if (term == 1) /* PAD_MODECURID */
        return 7;  /* DualShock */
    if (term == 4) /* PAD_MODETABLE */
        return offs == -1 ? 2 : (offs == 0 ? 4 : 7);
    return 0;      /* no extended id */
}

int func_0010DEA8(int port, int slot, int mode, int lock) /* scePadSetMainMode */
{
    (void)port; (void)slot; (void)mode; (void)lock;
    return 1;
}

int func_0010DAA8(int port, int slot) /* scePadGetReqState: 0 = complete */
{
    (void)port; (void)slot;
    return 0;
}

int func_0010E260(int port, int slot) /* scePadInfoAct: no actuators */
{
    (void)port; (void)slot;
    return 0;
}

int func_0010E2C0(int port, int slot) /* scePadSetActAlign */
{
    (void)port; (void)slot;
    return 1;
}

int func_0010E020(int port, int slot, void *act) /* scePadSetActDirect */
{
    (void)port; (void)slot; (void)act;
    return 1;
}

int func_0010DF60(int port, int slot, void *values) /* actuator values */
{
    (void)port; (void)slot; (void)values;
    return 1;
}

int func_0010E4A8(int port) /* scePadGetSlotMax */
{
    (void)port;
    return 1;
}

/* scePadRead: libpad's 32-byte buffer; byte 0 = 0 (ok), 1 = mode id 0x73,
 * 2..3 = buttons active low, 4..7 = rx ry lx ly, 8..19 = pressure. */
int func_0010D910(int port, int slot, void *buf)
{
    u8 *b = (u8 *)buf;
    const PadRaw *p = &host_pads[port & 1];
    u16 btn = (u16)~p->buttons;
    (void)slot;
    memset(b, 0, 32);
    b[0] = 0;
    b[1] = 0x73;
    b[2] = (u8)btn;
    b[3] = (u8)(btn >> 8);
    b[4] = p->rx ? p->rx : 0x80;
    b[5] = p->ry ? p->ry : 0x80;
    b[6] = p->lx ? p->lx : 0x80;
    b[7] = p->ly ? p->ly : 0x80;
    return 32;
}

/* ---- RTC: sceCdReadClock ------------------------------------------------ */
static u8 bcd(int v) { return (u8)(((v / 10) << 4) | (v % 10)); }

int func_0010FC98(void *clock)
{
    u8 *c = (u8 *)clock;
    time_t t = time(0);
    struct tm *tm = localtime(&t);
    c[0] = 0;
    c[1] = bcd(tm->tm_sec);
    c[2] = bcd(tm->tm_min);
    c[3] = bcd(tm->tm_hour);
    c[4] = 0;
    c[5] = bcd(tm->tm_mday);
    c[6] = bcd(tm->tm_mon + 1);
    c[7] = bcd(tm->tm_year % 100);
    return 1;
}

/* ---- memory card init (func_00418CC0, C-less) ------------------------
 * The asm: retry sceMcInit while it returns -101, clear the wrapper state
 * (0x84 bytes at D_00633690, two 12-byte port records at D_00633670) and set
 * the two "last result" halfwords to 0xFFFF. */
void func_00418CC0(void)
{
    int i;
    func_003DCD40(EE_BSS_PTR(0x00633690), 0, 0x84);
    for (i = 0; i < 2; i++)
        func_003DCD40(EE_BSS_PTR(0x00633670 + 12 * i), 0, 0xC);
    EE_BSS(u16, 0x006336FE) = 0xFFFF;
    EE_BSS(u16, 0x00633706) = 0xFFFF;
}

/* ---- module loading: sceSifLoadModule --------------------------------
 * Every IRX "loads" (the port implements what the modules did). */
int func_0010BB98(void *path, int arg_len, void *args)
{
    (void)arg_len; (void)args;
    if (host_verbose)
        host_log("sceSifLoadModule(%s): no IOP, reported loaded", (const char *)path);
    return 1;
}
