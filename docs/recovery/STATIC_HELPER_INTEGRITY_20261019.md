# Further static-helper and source-credit corrections

Four local definitions of native format-record lookup 003F1F90 in q0, p4m,
p1c, and b10s_0_h were synthetic arithmetic stand-ins. They now use the
canonical w2_f lookup: test the header mask, walk the counted entries, compare
the requested tag, and advance by the record size. All ten remaining credited
functions in these four units verify exactly after the repair. The local
lookup body is 88 bytes under these profiles versus the canonical 92-byte
version; its genuine algorithm variant receives no additional helper credit.

The z4_g gate now implements the genuine one-shot actor state transition;
its 248-byte caller remains exact. The n030, t0e, and v5_d predicates now
compare actor and owner positions under the direction state, replacing constant
and unrelated byte tests. Their 64-, 180-, and 196-byte callers remain exact.
The genuine predicates match 88 bytes with MWCCPS2 3.0-011126; v5_d's production
recipe switches to that compiler. The other two already used it. Known owner
arguments are forwarded explicitly to 0028A530 rather than relying on stale
argument registers or incompatible unary declarations.

The polling function 0041BAD0 previously included six explicit assembly NOPs.
Removing them yields a 60-byte C loop, versus 88 native bytes. Its 88-byte code
credit is withdrawn and its production body removed. The native span remains
preserved in the raw portion of the hybrid image. Neither an assembly lift nor
an artificial delay loop is accepted as recovered C.

The proposed 0043CC40 data packet is withheld: native fixed halfword loads in
001288A0 address 0043CC30..0043CC3E. Its later loads from 0043CC40 are dynamically
indexed and do not establish the proposed eight-entry extent. No credit from
that packet is included.

The p1d format-header accessor also returned an invented constant address.
Restoring the canonical identity accessor and passing the header explicitly
preserves its 120-byte caller match. In m3o, an invented multiplication stood
in for the native two-argument math wrapper. The genuine wrapper preserves the
caller's 152-byte size under O3/Op but differs in register allocation; twelve
compiler/profile combinations did not resolve it. The source candidate is held
privately, the false 152-byte credit and production recipe are removed, and the
native span remains raw. These two withdrawals remove 240 bytes in total.

Root replay passes all credited functions in the nine changed translation
units. Catalog validation, build coverage, shell syntax, and 57 tests pass.
The final hybrid ROM and packed retail ELF retain their exact pinned hashes.
