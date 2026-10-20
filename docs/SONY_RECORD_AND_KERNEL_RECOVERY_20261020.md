# Sony record RPCs and kernel-hook setup

Five complete native functions match 1072 bytes with Sony EE GCC 2.9 O2/G0 and SNAS G0:

- `0010B800` (160 bytes): operation 9 with one bounded and terminated 252-byte name.
- `0010BBD8` (260 bytes): two bounded names and a two-word result, preserving the native zero-result error and output ordering.
- `0010BD28` (236 bytes): scalar read for width selectors zero/one/two, preserving native unsigned validation and byte/halfword/word stores through the caller's correctly aligned output pointer.
- `0010BE18` (220 bytes): corresponding scalar write, preserving the observed request writes before width validation and transport error handling.
- `0010C2F8` (196 bytes): installs the existing kernel-hook table, copies the existing 0x330-byte kernel payload to its native destination, flushes caches, applies the remaining hooks and stores the resulting handler pointer.

The RPC source uses typed unions for the actual alternate scalar and name views of the existing 512-byte shared record. No new record storage is defined. The kernel source invokes the existing syscall stubs under the temporary contracts established by the hook table; it adds no syscall assembly or fabricated helper implementation. The referenced existing kernel payload remains native data/code and receives no reconstructed C or data credit from this packet. The hook table is read through its real key/handler record shape; no table storage is defined or credited.

Each final translation unit passes the standard verifier across all its complete functions. The RPC object contains exactly four native bodies, and the kernel object exactly one. Neither object emits allocated readonly, data or BSS sections. Existing assembly syscall wrappers remain outside this source-credit packet; the declarations in the initializer describe their actual observed temporary kernel ABI.
