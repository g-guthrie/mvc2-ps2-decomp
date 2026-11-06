# Paired-object action dispatch at 003C32F0

The complete 180-byte dispatcher checks the other object's state and action
field before dispatching its own action state. It then combines two signed
byte offsets, wraps the stored byte as native code does, and clamps the signed
result to 0..7. The older candidate read the action field from the wrong object.
MWCCPS2 3.0.3 `-O4,p -sdatathreshold 8` reproduces the whole relocated routine.

The native indirect-call boundary carries both object pointers in A0/A1.
The source-backed handlers and their direct callers now use compatible fixed
two-pointer interfaces. Three internal helpers ignore the second pointer in
native code; their bodies remain unchanged while callers retain the actual
context value. The actor-specific handler uses a local typed object view.
All affected complete translation units were independently recompiled and
verified, including functions unrelated to these interface changes.

The existing readonly `const unsigned int` table objects retain their original
types and placement. Dispatchers load a code address from the appropriate
slice and cast that selected value to the verified callback interface. The
GP-relative annotation on the external reference emits no data section and
leaves the readonly object unchanged. Actual table aliases are exposed in the
code map with intentional duplicate-address annotations where required.

The 003C42C0 leaf also uses the fixed two-pointer entry interface. It clears the
active byte then calls the real `Object *` destroy interface through a scoped
prototype; the second callback pointer is unused. All 629 catalogued functions
in its complete source unit remain exact. This makes every real target in the
related seven-entry table compatible with the fixed callback interface.

No table ownership or matching-data credit is added. Source-less native
handlers receive no C credit from the ABI audit. The new matching-code credit
is solely the complete 180-byte dispatcher.

The callback audit covers 807 complete catalogued spans, including the new dispatcher and all 629 functions in the leaf source unit.
Fresh split, full loaded-image linkage, packed ELF identity, build coverage,
catalog validation and all 91 tests pass. SHA-256 values remain
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code is 2,035,336 / 3,293,696 bytes (61.7949%); data remains 30.2566%.
