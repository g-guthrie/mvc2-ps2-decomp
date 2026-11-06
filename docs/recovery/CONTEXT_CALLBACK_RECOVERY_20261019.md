# Attachment and landing callback recovery

Two complete C callbacks add 680 verified bytes. The 352-byte 0019D970 handler
receives its second argument from actor offset 0xD4 through the 0019D830 head
and slot 0044ABF4. Its actor+0x18 reference is a separate value. The recovered
code retains signed-byte clamp behavior, signed-halfword timers, and the native
attachment/release calls. Existing allocator and release interfaces now use
the actual pointer arguments, including the release handler's unused context.

The 328-byte 00215650 handler is the unary slot 00450DA8 of the 00215470 stage
dispatch. It integrates position/motion, handles landing, and decrements a signed
16-bit timer. The draft's signed-byte narrowing was wrong; the recovered C
matches the native halfword sign extension. Both callbacks use modern
Metrowerks O4,p with small-data threshold zero.

The sixteen bytes at 00461EF0 are two signed 16.16 x/y motion records: (3,3)
and (3.5,3.5). Complete consumer 003486B0 now declares and accesses the same pair
layout as the data definition. Native 00348F20 independently owns the next
callback table at 00461F00. The physical record extent is established; the
runtime selector's provenance and universal range remain unproved. No such
range is asserted, and the neighboring callback table stays a placeholder.

The observed context route for 003486B0 is now explicit: 00348520 loads A1 from
actor+0x18, dispatches through 00461EE0 to 00348800, which forwards that incoming
value through 004C19A0 indexed by actor+0x20. The head 00348800 does not reload
A1. This corrects the earlier private receipt's dispatch description.

Ten more local helper definitions now implement genuine copied state, parent
fields, counters, or predicates. Nine bodies verify independently against retail
across n7, q1_a, x3_d, x2_c, z2_b, z3_a, z3_b, and x11_e. The n6 copied-state
helper has the same token body as the complete canonical q12_e implementation;
its local compiler variant is not credited as an extra exact helper. All
credited callers continue to match. The q1_a compiler recipe now uses the older
Metrowerks O3/Op/G0 profile for the exact local body.

Root verification covers fourteen changed/new code translation units, nine
independent helper spans, the full motion data object, and its neighboring
40-byte owner. Fresh splitting, catalog checks, build coverage, shell syntax,
and 57 tests pass. Both the final hybrid ROM and packed retail ELF reproduce
the pinned SHA-256 hashes exactly. Unchanged source/object/header hashes were
checked before reusing compiled artifacts.
