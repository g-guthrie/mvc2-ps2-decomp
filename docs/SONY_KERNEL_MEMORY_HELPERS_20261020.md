# Sony kernel memory helpers

Three complete native-derived functions add 164 matching code bytes with the
existing Sony EE GCC 2.9 O2/G0 and SN assembler profile:

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| 0010CB10 | 64 | Search readable kernel words and return a match below the supplied end address. |
| 0010CB60 | 52 | Read one handler-table entry through the kernel Copy syscall. |
| 0010CE78 | 48 | Copy bytes with an unsigned loop bound and return zero. |

The search retains the native operand order: it probes the current word before
checking the end bound. The native initializer `0010CB98` installs this helper
and requests scans from `0x80000000` through `0x80080000`, within readable PS2
kernel RAM. The end word must therefore be readable even though a match there
is rejected. The reconstructed C preserves this contract, rather than silently
changing the loop to test the bound first.

The entry reader uses explicit 32-bit address arithmetic for the signed syscall
index before passing the selected physical address to Copy. It does not create
a C array extending backwards from the table base. Its pointer return and
Copy's integer return follow the existing kernel declarations.

The existing syscall-0x5A primitive now has its actual destination, source and
size arguments and explicitly returns the syscall result. All 156 functions in
its compilation unit remain exact, including the unchanged 16-byte primitive.
Two unused, incompatible declarations were removed from `sdk4.c`; all eleven
functions in that unit remain exact. These interface changes add no code credit.

The byte-copy loop explicitly retains the native unsigned interpretation of
the size bits while exposing the kernel helper's signed integer size interface.
The recovered helpers allocate no tables and add no data credit.

All three new functions pass relocated whole-function verification. Fresh
splitting, full-image hybrid linkage, packed retail ELF comparison, and all
91 tests pass for the integrated sources.
