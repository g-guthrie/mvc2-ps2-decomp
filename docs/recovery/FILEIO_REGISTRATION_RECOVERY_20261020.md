# Exact file-service registration helpers

`func_00107AF8` (152 bytes) replaces the completion hook and context while
preserving interrupt state, then returns the previous function pointer.
Native hook dispatch at `0x00107B90` establishes the actual one-pointer
callback ABI. `func_001075E8` (136 bytes) reserves the first inactive slot
in the bounded 32-entry, 16-byte descriptor array while holding the native
semaphore, or returns null when none is available.

Both complete C functions independently match retail under Sony EE GCC 2.9
`-O2 -G0 -ffunction-sections -quiet` and SN assembler G0. The descriptor
member types match the already verified descriptor lookup provider. No
existing body, header, compiler profile, data credit, or architecture
primitive changes are required. The source uses no synthetic padding,
assembly, volatile qualifiers, or fake helper clobbers.
