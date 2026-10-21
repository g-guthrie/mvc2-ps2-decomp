# Native command-table registration types

The native command registration (`00106240`, 44 bytes) and removal (`00106270`,
40 bytes) select the system or user table from the command ID's high bit and
compute the entry byte offset with 32-bit wrapping arithmetic. The previous C
used signed multiplication/left shift and signed address addition; system
command IDs could therefore invoke undefined signed overflow.

Both methods now use unsigned 32-bit arithmetic and the shared eight-byte entry
layout: a two-argument callback followed by its context pointer. Registration
and the existing event callback caller share one declaration. Obsolete unused
table declarations were removed from `sdk3b.c`.

All 13 functions in the four affected compilation units match their complete
retail instructions and relocations with the existing production profiles.
All other 14,046 cached source/object pairs and 44 previous headers were checked
unchanged. The full hybrid image and packed ELF remain byte-identical to retail;
all 91 tests pass. This repairs existing credited C and adds no progress bytes.
