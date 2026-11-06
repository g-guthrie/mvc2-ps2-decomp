# Exact atan2, callbacks, and motion records

The complete 828-byte native atan2 routine at 00111588 matches pinned Newlib
1.10.0's `libm/math/e_atan2.c` with native function bindings and the same IEEE
word-access union macros used by the existing math recoveries. The ordinary
EE GCC2.96 O2/G0 plus SN assembler recipe matches the full instruction span
and relocations. The complete 176-byte readonly section at 004AB660 is verified
byte for byte; it receives no reconstructed-data credit.

Upstream source: https://github.com/mirror/newlib-cygwin/blob/ffbf3c2fe5af89ba84aad3359964ead31121b7ad/newlib/libm/math/e_atan2.c

Upstream source SHA-256: `bf5676a81b587e754e2d088ee01977995e714c5105adf9b78a935932ad293bda`.
Adapted production source SHA-256: `79996fe622c7a155e8bf41ea54a5fb665e0e7ba9967812c29151a3c418a7fb8d`.
The original Sun Microsystems notice is retained in the source, with its scope
recorded in LICENSES/README.md. Whole object hashes are artifact fingerprints;
temporary compiler filenames may change them without changing native sections.

Two more C functions add 428 bytes: action-reset callback 00240850 (216 bytes,
modern Metrowerks O4,p/G0) and duration scaler 001E4480 (212 bytes, older
Metrowerks O3/Op/G0). The reset callback's state write precedes its observable
call, matching the native delay-slot store. The scaler preserves unsigned
index/divisor handling and an ordinary nonzero fallback. No BSS record extent
or new runtime-data credit is inferred from its indexed views.

Four local helper definitions in w178_d, w187_n, and q3_r now implement genuine
parent-position, motion, and state-gate behavior. Three helper bodies verify
independently against retail; w178_d retains a genuine compiler variant without
extra helper credit. Existing credited callers remain exact.

At 00464C90, four signed halfword coordinate pairs recover sixteen bytes; the
complete 0038A5A0 consumer uses the same four-byte record layout. The next
independent pointer-dispatch owner starts at 00464CA0. At 00464580, six nonzero
signed coordinate pairs recover twenty-four bytes, consumed by complete
00381550. The following eight zero bytes remain raw placeholders because their
status as records versus alignment is unproved. The independently dispatched
next table begins at 004645A0. Runtime selector ranges remain unproved; no
universal bounds are asserted.

Root checks six new/changed code units, both complete consumer CUs, three exact
helper spans, six physical data objects including raw suffix and boundaries,
fresh splitting, catalog validation, build coverage, shell syntax, and 57 tests.
All unchanged source/object/header hashes are checked before artifact reuse.
The final hybrid ROM and packed retail ELF reproduce their pinned hashes exactly.
