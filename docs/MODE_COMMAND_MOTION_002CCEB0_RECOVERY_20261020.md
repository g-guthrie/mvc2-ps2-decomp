# Exact mode command and motion update

`func_002CCEB0` matches all 368 bytes with modern MWCCPS2 3.0.3
`-O4,p -sdatathreshold 8`. Modes zero/one share their animation-command
update; mode two gates its own command on actor state and adds a signed
horizontal step when the animation flag requests it.

The source uses the native switch structure and a shared float step,
selected by orientation before a single position addition. The old candidate
used separate per-branch float additions and early returns; that produced
a different control-flow layout and a longer body. All 92 native words now
match after relocation, including complete helper calls and signed-byte
animation results. There is no padding, assembly, forced clobber, volatile
qualifier, or data credit. Root independently recompiled the production CU.
