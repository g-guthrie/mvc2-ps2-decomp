# Motion bank and actor callbacks, 2026-10-21

This checkpoint reconstructs 4,804 DATA bytes within the former raw owner
[0x004747D8, 0x00475AB4). Three eight-byte regions remain raw and uncredited.
The adjacent four-byte owner starting at 0x00475AB4 is unchanged.

| Address | Reconstructed layout | Bytes |
| --- | --- | ---: |
| 0x004747E0 | 23 pairs of floating-point position parameters | 184 |
| 0x004748A0 | 23 velocity/acceleration quadruples, vx/ax/vy/ay | 368 |
| 0x00474A10 | 59 pairs of horizontal clamp and vertical motion parameters | 472 |
| 0x00474BF0 | 59 actor blocks, each with eight packed motion samples | 3,776 |
| 0x00475AB0 | Two signed halfwords, guarded selector access | 4 |

Each packed sample contains signed 16-bit x/y positions, an unsigned flip byte,
a signed output-layer byte and an unsigned animation byte. Its natural C size
is eight bytes; the last byte is implicit padding and zero in all 472 records.
The native consumers use eight-byte sample and 64-byte block strides.
The two formerly separate byte/interior-pointer views in q2_e and w1812_b now
use the same two-dimensional array and record layout. All twelve functions in
those units remain exact after relocation. Their object files differ because
symbol names/addends changed; raw object identity is not claimed.

The position and motion inventories have 23 populated paired entries. Native
factory code uses the same 5*type+subindex selector with strides eight and
sixteen. Fourteen direct factory callers and bounded loops corroborate the
role and indexing, but do not execute every inventory entry. Ordinary C section
alignment reproduces the starts of these tables without alignment attributes.
The extra eight-byte zero tails remain raw: original source array bounds versus
alignment cannot be uniquely recovered. The 59 actor domain is independently
supported by the native 0..58 loop and existing actor directory. This is layout
and consumer evidence, not a claim to recover original translation units or
prove universal indirect-call reachability. The working ClampPair field names
upper/lower do not establish two geometric bounds; the native roles are the
horizontal clamp and vertical motion parameters stated above.

Three actor callbacks add 1,024 exact CODE bytes: 0x00246960 (260), 0x00356770
(368), and 0x0035C610 (396). Recovery preserves signed timer and phase behavior,
unsigned frame comparisons, callback owner/context inputs, and the distinct
capture target. Existing empty/free helper declarations now accept actual actor
inputs, and a callback directory extern preserves the provider's const pointer
elements. The simple_leaves, tail_leaves and argument_dispatch_heads objects
remain byte-identical; their 396, 641 and 303 registered functions remain exact.

Production compilers and verification commands are registered in
`tools/compile_matching.sh`. Private retail/toolchain files and independent
review receipts remain excluded from Git. Reconstructed DATA credit requires
both exact object bytes and the typed ownership evidence above; the three raw
gaps do not receive credit.
