# I/O thread stack storage recovery

Five native thread constructors explicitly identify the complete storage bank
`[0x0047D100, 0x00484100)`. Each stores a stack base at descriptor offset `+8`
and its byte length at `+0xC`, then calls `0x00103BE0`. That wrapper executes
syscall `0x20`, `CreateThread`. The descriptor offsets and syscall identity agree
with the open [PS2SDK thread interface](https://github.com/ps2dev/ps2sdk/blob/master/ee/kernel/include/kernel.h)
and [syscall definitions](https://github.com/ps2dev/ps2sdk/blob/master/ee/kernel/include/syscallnr.h).

| Constructor | Stack base | Bytes |
| --- | --- | ---: |
| `0x003FE258` | `0x0047D100` | 4,096 |
| `0x003FE2F0` | `0x0047E100` | 4,096 |
| `0x003FE368` | `0x0047F100` | 4,096 |
| `0x003FE3E0` | `0x00480100` | 8,192 |
| `0x003FE468` | `0x00482100` | 8,192 |

The recovered sources declare these five byte buffers with their actual runtime
storage capacities and zero initializers. Every byte of each complete compiled
object matches the retail image. The lengths come from the thread API calls,
not from gaps between neighboring symbols. No assumptions about how many threads
execute are needed to establish this physical ownership.

This replaces the old opaque 28,676-byte unit with five reconstructed stack
owners totaling 28,672 bytes and a separate four-byte opaque prefix at
`0x0047D0FC`. The typed pool beginning at `0x00484100` remains its existing owner.
The four prefix bytes earn no reconstructed-data credit. These declarations do
not claim all possible runtime aliases or kernel accesses have been enumerated.
