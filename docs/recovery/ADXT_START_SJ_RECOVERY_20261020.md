# ADXT Start-SJ Helper Recovery

`func_00401640` is the internal ADXT helper that connects a stream-join input and begins decoding. The 0xC4-byte translation reproduces the retail body exactly under the source CU compiler profile.

The native entry ABI is `(ADXT *, SJ)`: A0 is the ADXT owner, A1 is the input SJ. The helper reads the signed `maxnch` byte at `ADXT+0x03`, resets each output SJ from the pointer array at `ADXT+0x18`, and calls each handle's vtable slot at `+0x14`. It then passes `(ADXT.sjd, SJ)` to `func_003FF5D0`, saves the input at `+0x14`, and calls `func_003FF628(ADXT.sjd)`. The remaining native stores set `stat` at `+0x01` to 1, `pstready` at `+0x71` to 0, `lesct` at `+0x8C` to `0x7fffffff`, `trpnsmpl` at `+0x90` to -1, `svcnt` at `+0xA0` from `D_004C22C4`, then clear `lpcnt` at `+0x4C`, `tvofst` at `+0x9C`, and `decofst` at `+0xA4`.

The public ADX Talk header declares `ADXT_StartSj(ADXT, SJ)`. The corresponding public `adxt_start_sj` implementation in crowded-street/3s-decomp, commit `be9b9bc69dc19822a8eca9ce3e72ba560d5a3835`, was already consulted for API and semantic context during this work. The source here was written from the retail MIPS instruction sequence rather than copied from that C body. This is not a clean-room claim; treat it as a native-first re-expression and assess compatibility before distribution.

## Exact native verification

```sh
./tryee.sh src/adxt_start_sj_00401640.c sn 8 O2 "" "-mips4"
```

Result: `exact: func_00401640 (196 bytes)` and `ALL MATCHED`.

The translation contains no inline assembly or forced clobbers. Its calls preserve the native ABIs visible at the call sites: `(void *sjd, void *sj)`, `(void *sjd)`, and the indirect output-SJ vtable method taking the output-SJ handle.
