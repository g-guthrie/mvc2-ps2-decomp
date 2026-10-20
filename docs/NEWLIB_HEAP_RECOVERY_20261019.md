# Newlib heap core recovery

Four complete functions from Doug Lea's public-domain allocator 2.6.4 match 3,552 native bytes:

| Native entry | Routine | Bytes |
| --- | --- | ---: |
| 0011BAE0 | `_free_r` | 756 |
| 0011BDD8 | `_malloc_trim_r` | 364 |
| 0011CC10 | `malloc_extend_top` | 600 |
| 0011CE68 | `_malloc_r` | 1832 |

`src/newlib_heap_core.c` retains the original public-domain attribution and genuine algorithms from Newlib `mallocr.c`, upstream commit `91a8d90babddd48b5ce982eaddeff0c94640d7c8`. It selects the original malloc/free components and uses external declarations for the already present heap state. It introduces no initialized data, BSS or readonly pool.

The native configuration uses 16-byte allocation alignment, 32-bit `size_t` and 64-bit `long`. The source's documented `SIZE_T_SMALLER_THAN_LONG` option preserves signed differences between chunk sizes. Native request rounding adds 0x13 and masks by ~0xF, confirming alignment. State comprises the original 258 bin pointers at 0043B708, 64-bit threshold/padding/maxima, the sbrk base and the original mallinfo fields. The existing physical state receives no additional data credit.

The production path is SNCPP, EE GCC 2.96 `-O2 -G0 -ffunction-sections` with no extra flags, then SNAS `-G0`. Standard object verification checks every byte of all four functions and their real internal call relocation. Existing allocator callers include 0011CB98 into malloc; malloc calls the complete extension helper at 0011D418; free calls trim at 0011BB88.
