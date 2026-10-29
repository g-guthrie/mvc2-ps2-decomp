/*
 * Shared helpers for the host implementations (port/host, Port J).
 *
 * Every function defined under port/host/ that replaces a game symbol is
 * listed in port/host/host_impl.csv; mvc2_host_protos.h (generated from
 * host_sigs.json) gives each its canonical prototype, so the definitions
 * here are checked against the game's callers.
 *
 * EE memory: the game's BSS (0x004C2580..0x00634380) is one host blob,
 * mvc2_ee_bss, at host address blob + (EE - 0x004C2580).  EE_BSS(T, a)
 * reads/writes a BSS variable by its EE address, which also works for
 * names the game C never mentions (and so has no alias).
 */
#ifndef PORT_HOST_H
#define PORT_HOST_H
#include <stddef.h>
#include <stdint.h>
#include "mvc2_host_protos.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern unsigned char mvc2_ee_bss[];
#define EE_BSS_START 0x004C2580u
#define EE_BSS_END 0x00634380u
#define EE_BSS_PTR(a) ((void *)(mvc2_ee_bss + ((u32)(a) - EE_BSS_START)))
#define EE_BSS(T, a) (*(T *)EE_BSS_PTR(a))

/* log once per call site / always */
void host_log(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
#define HOST_ONCE(...) do { static int once_; if (!once_) { once_ = 1; host_log(__VA_ARGS__); } } while (0)

/* port/host/boot.c */
extern int host_verbose;
void host_vsync_irq(void);           /* what func_003ECBE0 (vsync handler) does to game state */
extern void (*host_present_hook)(void); /* frontend: present the frame at flip */
extern unsigned long host_frame_count;

/* port/host/cri.c: disc access (set by the host main before platform init) */
int host_disc_open(const char *iso_path);
#endif
