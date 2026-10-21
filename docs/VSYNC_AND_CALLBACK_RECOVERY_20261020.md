# Vertical-sync wait and referenced callbacks

`00104300` returns the 64-bit value supplied through syscall 115 (`SetVSyncFlag`).
It registers a zeroed asynchronous completion flag and an output slot, clears
INTC status bit 2 at `0x1000F000` with interrupts disabled, executes the native
`sync` barrier, and restores interrupts only when previously enabled. It waits
for that status bit or the completion flag, then repeats the clear/barrier and
conditional restoration before reading the result.

The completion flag, result slot, and MMIO register are volatile for their actual
asynchronous/hardware accesses. Both inline `sync` instructions are required EE
memory barriers. The implementation is independently reconstructed C; no SDK
implementation body is imported. The syscall wrapper now declares its two real
output pointers and its void return, consistent with the kernel ABI; obsolete
unused declarations were removed from `q3.c` and `q3e.c`.

The function shares the existing `sony29_wait_vblank_00104270.c` compilation
unit. Its 164 bytes and the existing 144-byte wait routine both match under the
unchanged Sony EE GCC 2.9 O2/G0 recipe. All 156 syscall wrappers, five `q3`
functions, and the `q3e` function also pass complete relocated-object checks.

Six additional eight-byte callbacks are independently rooted:

| Entry | Native pointer reference | Behavior |
| --- | --- | --- |
| 0020ABE0 | 00450780/84/88 | Call the animation updater; discard its result |
| 00232E60 | 004520AC | Tail-call 001843A0 |
| 00277BD0 | 00454D04 | Empty state callback |
| 002F7590 | 0045BE5C | Tail-call 002F75A0 |
| 002FC910 | 0045C0CC | Tail-call 002FC920 |
| 003088A0 | 0045CBA0 | Empty callback at vector slot 0x30 |

Typed dispatch consumers establish their `void (unsigned char *)` interface;
`0017D270` calls the copied vector slot for `003088A0` with the actor pointer
and ignores its result. All six share the existing `tail_leaves.c` recipe;
all 641 functions in that object match. Residual bytes outside the eight-byte
entries remain uncredited. Entry `00372620` is held because its caller types
still need reconciliation.

The independently recovered `002B7580` adds a 364-byte actor transition. Its
first-entry branch advances the state and consumes animation bits 0 and 1;
its negative animation result transfers the actor back-reference and facing
state to the linked actor, selects the next actions, and clears the entry flag.
The remaining branch consumes bit 1, dispatches the position helper, and
publishes the two native global flags. The callback root is table slot
`004C0D1C`, selected by `002B7440`. The production source uses a real actor
pointer store at child offset `0x1C8` and the existing byte-parameter helper
signature. MWCCPS2 3.0.3 O3/G0 reproduces all 364 bytes.

This batch adds 576 code bytes. Native instruction decoding, symbol relocation,
and full function extents are verified independently from progress reporting.

Final validation: all 806 functions in the six changed/new code units and both
data objects pass complete compiled-object verification. A fresh split, full
hybrid relink, and deterministic ELF pack succeed. The 3,941,760-byte loaded
image has SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
the 3,942,320-byte ELF has SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 91 tests pass. All 14,043 other cached source/object pairs and all 45
previous headers were checked unchanged.
