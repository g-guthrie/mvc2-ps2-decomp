/*
 * EE kernel syscalls on the host (Port J).
 *
 * src/grok_tiny_leaves.c credits these as `addiu v1, r0, N; syscall` stubs;
 * hostify turned them into no-op hooks, but their callers use $v0 (found by
 * the $v0 dataflow, BOOT_NOTES.md #7), e.g. func_003F0470 loops until
 * _DisableDmac returns 0.  The host is single-threaded with no interrupt
 * controller: handlers are "added", interrupts are "disabled" (0 = it was
 * already off), threads are bookkeeping only.  The void-declared ones are
 * listed in host_impl.csv with ret=int.  Semaphores stay in port/stubs/ps2_kernel.c.
 */
#include "host.h"

extern int func_00103E20(int);
static int thread_ids = 1;
static int next_thread(void) { return ++thread_ids; }

int func_00100580(void) { return 0; } /* 128: kernel call 128 */
int func_001039E0(void) { return 0; } /* 2: SetGsCrt */
int func_00103A00(void) { return 0; } /* 4: Exit */
int func_00103A20(void) { return 0; } /* 6: LoadExecPS2 */
int func_00103A90(void) { return 0; } /* 13: syscall 13 */
int func_00103AA0(void) { return 0; } /* 14: syscall 14 */
int func_00103AC0(void) { return 1; } /* 16: AddIntcHandler */
int func_00103AE0(void) { return 0; } /* 17: RemoveIntcHandler */
int func_00103AF0(void) { return 1; } /* 18: AddDmacHandler */
int func_00103B10(void) { return 0; } /* 19: RemoveDmacHandler */
int func_00103B60(void) { return 1; } /* 252: SetAlarm */
int func_00103B80(void) { return 0; } /* -26: iEnableIntc */
int func_00103B90(void) { return 0; } /* -27: iDisableIntc */
int func_00103BA0(void) { return 0; } /* -28: iEnableDmac */
int func_00103BB0(void) { return 0; } /* -29: iDisableDmac */
int func_00103BE0(void) { return next_thread(); } /* 32: CreateThread */
int func_00103C00(void) { return 0; } /* 34: StartThread */
int func_00103C20(void) { return 0; } /* 36: ExitDeleteThread */
int func_00103C70(void) { return 0; } /* 41: ChangeThreadPriority */
int func_00103C90(void) { return 0; } /* 43: RotateThreadReadyQueue */
int func_00103CD0(void) { return 1; } /* 47: GetThreadId */
int func_00103CE0(void) { return 0; } /* 48: ReferThreadStatus */
int func_00103CF0(void) { return 0; } /* -49: iReferThreadStatus */
int func_00103D00(void) { return 0; } /* 50: SleepThread */
int func_00103D10(void) { return 0; } /* 51: WakeupThread */
int func_00103D50(void) { return 0; } /* 55: SuspendThread */
int func_00103D70(void) { return 0; } /* 57: ResumeThread */
int func_00103E80(void) { return 0; } /* 74: syscall 74 */
int func_00103E90(void) { return 0; } /* 75: syscall 75 */
int func_001040B0(void) { return 0; } /* 107: syscall 107 */
int func_00104100(void) { return 0; } /* 112: GsGetIMR */
int func_00104120(void) { return 0; } /* 113: GsPutIMR */
int func_001041C0(void) { return 0; } /* 120: SifSetReg */
int func_001041D0(void) { return 0; } /* -120: iSifSetReg */
int func_001041E0(void) { return 0; } /* 121: SifGetReg */
int func_001041F0(void) { return 0; } /* 122: syscall 122 */
int func_00104200(void) { return 0; } /* 123: syscall 123 */
int func_00104240(void) { return 0; } /* 127: syscall 127 */
int func_00104250(void) { return 0; } /* 130: syscall 130 */
int func_0010C290(void) { return 0; } /* 90: kernel patch 90 */
int func_0010C2D8(void) { return 0; } /* 91: kernel patch 91 */
int func_0010C2E8(void) { return 0; } /* 116: kernel patch 116 */
int func_00103B20(int a0) { (void)a0; return 0; } /* 20: _EnableIntc */
int func_00103B30(int a0) { (void)a0; return 0; } /* 21: _DisableIntc */
int func_00103B40(int a0) { (void)a0; return 0; } /* 22: _EnableDmac */
int func_00103B50(int a0) { (void)a0; return 0; } /* 23: _DisableDmac */
int func_00103D20(int a0) { (void)a0; return 0; } /* -52: iWakeupThread */
int func_00103D60(int a0) { (void)a0; return 0; } /* -56: iResumeThread */
int func_00103E30(int id) { return func_00103E20(id); } /* 69: PollSema */
int func_00104180(int a0) { (void)a0; return -1; } /* 118: SifDmaStat */
int func_001041A0(void *a0, int a1) { (void)a0; (void)a1; return 1; } /* 119: SifSetDma */
int func_001041B0(void *a0, int a1) { (void)a0; (void)a1; return 1; } /* -119: iSifSetDma */
