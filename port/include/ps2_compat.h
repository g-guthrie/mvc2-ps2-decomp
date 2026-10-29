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

/* ---- link aliases (hostify R11) --------------------------------------- */
/* A catalog name inside a credited data unit is a weak data symbol at
 * unit+offset in the unit's own object (wasm32 cannot express symbol+offset
 * across objects).  Other names of a credited function are weak function
 * aliases in the owning object. */
#if defined(__wasm__)
#define PS2_DATA_ALIAS(name, base, off, size) \
    __asm__(".weak " #name "\n.set " #name ", " #base "+" #off "\n");
#else
#define PS2_DATA_ALIAS(name, base, off, size) \
    __asm__(".weak " #name "\n.type " #name ",@object\n.set " #name ", " #base "+" #off \
            "\n.size " #name ", " #size "\n");
#endif
#define PS2_TEXT_ALIAS(name, target) \
    extern __typeof__(target) name __attribute__((weak, alias(#target)));

/* ---- call arguments of a disagreeing caller (hostify R12) ------------ */
/* Where a caller passed a float to a pointer parameter (or the reverse) the
 * MIPS callee read an unrelated register; on the host the value is
 * converted so the call still compiles with the callee's real prototype. */
#define PS2_TO_PTR(x) _Generic((x), float: (void *)(int)(x), double: (void *)(int)(x), \
                               long double: (void *)(int)(x), default: (x))
#define PS2_TO_F32(x) _Generic((x), float: (x), double: (x), long double: (x), \
                               default: (float)(long long)(x))
#define PS2_TO_F64(x) _Generic((x), float: (x), double: (x), long double: (x), \
                               default: (double)(long long)(x))

/* ---- EE varargs walkers (hostify R15) -------------------------------- */
/* `(T *)__builtin_next_arg(last) - K` (a pointer into the EE register save
 * area) becomes a host va_start; va_list is a plain pointer on i386 and
 * wasm32, and the game's vfprintf reads it with __builtin_va_arg. */
#define PS2_VA_START_HERE(last) \
    ({ __builtin_va_list ps2_va_; __builtin_va_start(ps2_va_, last); (void *)ps2_va_; })

/* ---- Metrowerks / EE GCC extensions ---------------------------------- */
/* EE GCC varargs save-area builtin (sdk_format_message_003f5540.c). */
#ifndef __builtin_args_info
#define __builtin_args_info(n) 0
#endif

#endif /* PS2_COMPAT_H */
