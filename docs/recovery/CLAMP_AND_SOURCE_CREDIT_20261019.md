# Exact clamp recovery and source credit audit

The 108-byte camera-bound clamp 00178DA0 is now pure matching C. It computes
low = camera - 320 + 35 and high = camera + 320 - 35, then clamps the actor's
x coordinate using the native ordered comparisons. The older Metrowerks
3.0-011126 compiler with O4,p / small-data threshold zero reproduces the entire
function. Its source replaces a literal assembly placeholder, adding 108 bytes.
Native caller 00177550 supplies the actor pointer before its state dispatch.

Five format-header identity-accessor callers now use the actual pointer-returning
003F1F00(void *file) interface. All nine functions across those changed units
and the clamp pass the literal production compiler recipes. This fixes source
contracts without changing their existing credit.

At 004399A0, native word accesses identify two fixed 32-bit initialization
fields. The first word is read at 0010E740/0010E7C4 and written at 0010EA1C;
the second is read at 0010EB68 and written at 0010EBB0/0010EBE4. Independently
referenced semaphore IDs at 004399A8 bound these eight recovered bytes. Those
IDs were already reconstructed; overlapping proposed work adds no credit.

The source audit removes 1,296 bytes of unsupported C credit. COP2 algorithm
streams 003DE160 (204 bytes) and 003DE3D0 (172 bytes) remain literal assembly
placeholders. The explicit NOP-bearing functions 003F0470 (88), 00418B10 (60),
003DC950 (100), 00394CD0 (208), 003DCAD0 (212), and 00170C30 (252) likewise remain
placeholders pending genuine source/compiler recovery. Some contain meaningful
polling conditions, but inserting assembly padding is not proof of exact C.
Their native bytes remain in the rebuilt image and receive zero C credit.
The 162 kernel syscall wrappers remain under the documented CPU-operation
exception; algorithmic instruction streams do not qualify for that exception.

This checkpoint is published early to correct the public source accounting.
The next ordinary push threshold remains 1,981,699 verified code bytes rather
than resetting the percentage grid after this correctness publication.

Root validation passes the nine affected code functions, both physical data
objects, 57 tests, catalog checks, and build coverage. Both the hybrid ROM
and packed retail ELF reproduce their pinned SHA-256 hashes exactly.
