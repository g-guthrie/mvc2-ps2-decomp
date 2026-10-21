# Actor dispatch data and transition callback

The 28-byte owner at `0044ECB0` contains two adjacent dispatch tables: four
first-stage callbacks followed by three mode callbacks at `0044ECC0`. Its C
initializer now uses symbolic function pointers with each target's actual
signature. Initialization and update consume object and owner pointers; the
empty callback takes no arguments; termination and the three mode callbacks
consume the object. The four bytes after this owner remain uncredited.

The identified creator's three call sites supply modes 0, 1 and 2. Allocation
clears the object before initialization, and the observed first-stage lifecycle
uses slots 0 and 1; termination advances the state and frees the object. The
native dispatchers have no local bounds checks. These are scoped lifecycle
bounds, not a proof covering arbitrary objects or aliasing writes. The two
other first-stage slots remain real, addressable table entries.

The new 520-byte C body at `002C0E00` selects animation state, chooses one of
six command views, clears transition state and advances a signed halfword
counter. Its helper declarations agree with native argument and result use,
including the existing owner-plus-float threshold interface. A byte readback
and writeback preserves the native access; the counter increment preserves
the signed halfword load, integer increment and truncated store.

This callback adds CODE credit only. Its external float view has no recovered
DATA extent. The flexible counter view avoids inventing an array capacity;
valid object and counter allocation/index preconditions remain open. The
recovery does not claim global caller or arbitrary-alias safety.

Root independently compiled and verified the complete 520-byte function and
28-byte data object. All 118 tests, a fresh split, full hybrid linkage and
packed retail ELF byte identity passed. This bank reaches 2,081,820 matching
CODE bytes (63.2062%) and 259,227 reconstructed DATA bytes (40.0002%). The
next fixed CODE milestone remains 2,113,447 bytes.
