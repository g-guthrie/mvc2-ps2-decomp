# Verified publication checkpoint: 61.1803% code

Linked matching code is 2,015,092 / 3,293,696 bytes (61.1803%), covering
17,326 / 20,300 functions. Reconstructed linked data is
195,314 / 648,064 bytes (30.1381%). The current batch adds 13 complete
functions / 5,668 code bytes over `f8437a50`; five already credited path
wrappers move compilation units without adding credit.

The new file-service functions cover bounded path, metadata, descriptor and
buffer requests, with their actual wire layouts, cache extents, semaphore
ownership and error paths. The runtime descriptor lookup uses the literal
EE96 G0 profile and a correct variadic logger declaration. Root independently
recompiled every new function and all changed providers. All fifteen
remaining Grok function bodies and their relocation targets are unchanged.
No new data, readonly, or BSS credit is claimed by this batch.

Publication validation completed with a fresh target split, full hybrid
relink, packed retail ELF, all 88 tests, catalog validation, production
coverage for 4,082 credited sources, shell syntax, and unchanged prior
source/object/header cache verification. The exact full-image identities are:

- ROM: 3,941,760 bytes; SHA-256
  `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- ELF: 3,942,320 bytes; SHA-256
  `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

The fixed publication threshold was 2,014,636 code bytes; this checkpoint
exceeds it by 456 bytes. The following scheduled threshold is 2,047,573
verified code bytes. Full decompilation remains incomplete. Rebuilt-image
identity does not grant credit to the unmatched bytes retained from retail.
