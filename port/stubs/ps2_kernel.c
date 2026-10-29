/*
 * EE kernel pieces the host link cannot take from game C (Port G):
 *  - the five semaphore syscall stubs and Deci2Call, credited as assembly
 *    (src/sony29_kernel_semaphore_calls.S, src/sony_deci2_call.S);
 *  - the three whole-function-asm kernel helpers credited with FN()
 *    (src/k2s.c, src/k5h.c, src/s0h.c), dropped by hostify R6.
 * The host is single-threaded with interrupts notionally always enabled:
 * a semaphore is a counter, and a wait that would block returns at once
 * (logged; the first such hit names the caller that needs a real thread).
 */
#include <stdio.h>
#include "mvc2_stubs.h"

/* ps2sdk ee_sema_t */
struct ee_sema { int count, max_count, init_count, wait_threads; unsigned attr, option; };

#define MAX_SEMA 256
static struct { int used, count, max; } sema[MAX_SEMA];

/* CreateSema (syscall 0x40) */
int func_00103DE0(struct ee_sema *p)
{
    int i;
    MVC2_STUB_ENTER("func_00103DE0", 0x00103DE0u, "syscall CreateSema");
    for (i = 1; i < MAX_SEMA; i++)
        if (!sema[i].used) {
            sema[i].used = 1;
            sema[i].count = p ? p->init_count : 0;
            sema[i].max = p ? p->max_count : 1;
            return i;
        }
    return -1;
}

/* DeleteSema (0x41) */
int func_00103DF0(int id)
{
    MVC2_STUB_ENTER("func_00103DF0", 0x00103DF0u, "syscall DeleteSema");
    if (id <= 0 || id >= MAX_SEMA || !sema[id].used)
        return -1;
    sema[id].used = 0;
    return id;
}

static int signal_sema(int id)
{
    if (id <= 0 || id >= MAX_SEMA || !sema[id].used)
        return -1;
    if (sema[id].max <= 0 || sema[id].count < sema[id].max)
        sema[id].count++;
    return id;
}

/* SignalSema (0x42) */
int func_00103E00(int id)
{
    MVC2_STUB_ENTER("func_00103E00", 0x00103E00u, "syscall SignalSema");
    return signal_sema(id);
}

/* iSignalSema (-0x43) */
int func_00103E10(int id)
{
    MVC2_STUB_ENTER("func_00103E10", 0x00103E10u, "syscall iSignalSema");
    return signal_sema(id);
}

/* WaitSema (0x44): never blocks on the host. */
int func_00103E20(int id)
{
    MVC2_STUB_ENTER("func_00103E20", 0x00103E20u, "syscall WaitSema");
    if (id <= 0 || id >= MAX_SEMA || !sema[id].used)
        return -1;
    if (sema[id].count > 0)
        sema[id].count--;
    else
        MVC2_STUB_ENTER("WaitSema-would-block", 0x00103E20u, "semaphore wait with count 0 (single-threaded host)");
    return id;
}

/* Deci2Call (0x7C): no DECI2 debug channel on the host. */
int func_00104210(int request, void *param)
{
    (void)request;
    (void)param;
    MVC2_STUB_ENTER("func_00104210", 0x00104210u, "syscall Deci2Call");
    return -1;
}

/* COP0 Status read, returns 1 when Status.IE is clear.  Host: IE set. */
int func_001048B0(void)
{
    MVC2_STUB_ENTER("func_001048B0", 0x001048B0u, "kernel COP0 Status.IE probe");
    return 0;
}

/* Interrupt-enable state behind DI()/EI(): Status.EIE (bit 16). */
static int eie = 1;

/* EI() wrapper: sets EIE, returns its previous value. */
int func_0010CA68(void)
{
    int old = eie;
    MVC2_STUB_ENTER("func_0010CA68", 0x0010CA68u, "kernel EI wrapper");
    eie = 1;
    return old;
}

/* DI() wrapper: clears EIE, returns its previous value. */
int func_0010CA20(void)
{
    int old = eie;
    MVC2_STUB_ENTER("func_0010CA20", 0x0010CA20u, "kernel DI wrapper");
    eie = 0;
    return old;
}
