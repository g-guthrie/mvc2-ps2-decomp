# Sony runtime wait, semaphore and slot copy recovery

Three native-first C reconstructions add 292 matching bytes using Sony EE GCC
2.9-991111 at `-O2 -G0 -ffunction-sections` and the existing SN assembler:

| Function | Bytes | Behavior |
| --- | ---: | --- |
| 00102428 | 112 | Wait for a shared busy flag to clear; diagnose and cancel on countdown expiry |
| 00107A68 | 76 | Create and store a semaphore handle when the stored handle is -1 |
| 00103418 | 104 | Copy four independent 16-byte source slots into consecutive destination slots |

The wait routine preserves the opaque pointer interface used by existing
callers and reads the shared status word through a local volatile view. Its
cancellation provider clears that status bit while coordinating the native
hardware/interrupt state. The diagnostic callback uses its existing variadic
interface. The semaphore handle needs no added volatility: removing the
scratch qualifier retains the complete 76-byte match. Only the three native
semaphore parameter fields are assigned, preserving the actual call setup.

The slot-copy wrapper's five pointers follow the native A0/A1/A2/A3/T0 flow.
Its final call remains a tail jump. The existing 00102F20 callee is still an
uncredited assembly placeholder; this recovery credits only the 104-byte C
wrapper, without claiming its callee or adding data ownership.

Each scratch candidate was independently recompiled and verified from the
production source against the canonical target and symbols. The previous
13,737 source/object pairs and 37 shared headers remain unchanged from
checkpoint `78414b10`. No compiler output, assembly or object bytes are edited.

Production coverage includes 4,116 sources; catalog validation and all 91 tests
pass. The full loaded image and deterministic packed ELF remain byte-exact:

- 3,941,760 bytes, SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- 3,942,320 bytes, SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

The catalog credits 2,032,268 / 3,293,696 code bytes (61.7017%) and
195,314 / 648,064 reconstructed data bytes (30.1381%).
