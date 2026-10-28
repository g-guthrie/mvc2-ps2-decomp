/*
 * ps2_compat.h - force-included (-include) into every game/data TU of the
 * HOST port build (port/CMakeLists.txt).  Never used by the matching build.
 *
 * Neutralises Metrowerks / EE-GCC / R5900-isms so the decompiled C can be
 * compiled by a host clang/gcc for a 32-bit target (i386 or wasm32).
 *
 * Coverage of this header vs. what still needs the source filter
 * (port/tools/hostify.py) is documented in port/docs/HOST_BUILD_ISSUES.md.
 */
#ifndef PS2_COMPAT_H
#define PS2_COMPAT_H

#define MVC2_HOST 1

/* ---- pointer model ---------------------------------------------------- */
/* The game stores pointers in u32 fields everywhere; a 32-bit target keeps
 * that representation intact.  Fail loudly on an LP64 host. */
#if defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ != 4
#error "mvc2 host port: build for a 32-bit target (i386 / wasm32)"
#endif

/* ---- 128-bit integers (R5900 GPRs, lq/sq quadwords) ------------------- */
/* Sources spell quadwords as `__attribute__((mode(TI)))` (accepted by clang
 * on both targets) or `__int128` (keyword missing on i386).  On i386 the
 * keyword is mapped onto the TI-mode spelling; arithmetic on it needs
 * compiler-rt's __multi3/__udivti3 at link time. */
#if !defined(__SIZEOF_INT128__)
#define __int128 int __attribute__((mode(TI)))
#endif

/* ---- inline assembly ---------------------------------------------------- */
/* port/tools/hostify.py rewrites every PS2 asm statement into a call to
 * ps2_asm_stmt() (see R4/R5 there).  The platform layer decides what each
 * one means on the host (sync/ei/di: nothing; COP0 status reads: constants;
 * VU0 macro-mode blocks: a C VU0 emulation keyed by file:line).  Outputs of
 * the original statement are zeroed before the call. */
#ifdef __cplusplus
extern "C" {
#endif
void ps2_asm_stmt(const char *file, int line, const char *tmpl);
#ifdef __cplusplus
}
#endif

/* FN(name, body) whole-function assembly placeholders (uncredited, listed by
 * port/tools/list_c_less.py) are dropped by hostify R6; the macro expands to
 * a harmless declaration so `FN(...);` stays valid at file scope. */
#define PS2_TOPLEVEL_ASM_DROPPED(name) extern int ps2_dropped_asm_##name

/* ---- Metrowerks / EE GCC extensions ---------------------------------- */
/* EE GCC varargs save-area builtin (sdk_format_message_003f5540.c). */
#ifndef __builtin_args_info
#define __builtin_args_info(n) 0
#endif

#endif /* PS2_COMPAT_H */
