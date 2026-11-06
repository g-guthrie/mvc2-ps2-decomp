# Newlib and fdlibm exact-source receipts

This receipt restores four source units recovered on 2026-10-19 from the repository's shared Git objects. The four C functions come from the pinned source-only commits listed below; the current source files differ only by whitespace cleanup. Those commits remain as provenance. The source functions are registered in the code-match catalog; their compiler constant pools receive no reconstructed-data credit.

| Unit | Source span | Receipt commit | Compiler and options | Object SHA-256 |
| --- | ---: | --- | --- | --- |
| `func_0011EBD0` qsort | 0x9EC (2,540 bytes) | `8edf5d202fc2a0234129ba52680a23b5cc25c081` | EE GCC 2.96 `-O3 -G0` | `e51cb1c0c48f002afa373e8938aa71be652cea818e986af25817c6afa524c9e4` |
| `func_001145D0` `__kernel_rem_pio2` | 0xB4C (2,892 bytes) | `a62e97c911ea0a985727e422acde280efa017e70` | EE GCC 2.96 `-O2 -G0` | `fd733ddee7e36c57eaa40f8b7dee2f338bd1b11e493e0413726c9ddf0d8b9563` |
| `func_00116710` floor | 0x214 (532 bytes) | `0abd2e4e972658d0ba3d8921795d8268ed03f424` | EE GCC 2.96 `-O2 -G0` | `70657cc5de9f11c2fd9b0f4bc8d483b298a9292eb37fbdf2a0ca04db89990abc` |
| `func_001169B0` scalbn | 0x1E4 (484 bytes) | `0abd2e4e972658d0ba3d8921795d8268ed03f424` | EE GCC 2.96 `-O2 -G0` | `f9f0d44e3ec2ec5f8a34b75ff630860e204106598b1fb819e05c504e7c3e8f36` |

All four objects passed `tools/verify_object.py` against the private `SLUS_204.86.rom`. The tool reported each complete function span exact after relocation. Verification uses the project match catalog, explicit symbol aliases, and the strict readonly map. The existing `func_00116568` implementation in `src/q0e.c` supplies scalbn's `copysign` call. `__kernel_rem_pio2`'s external `scalbn` reference resolves to `func_001169B0` for verification.

The SHA-256 fingerprints below identify the committed, whitespace-cleaned source text. The adjacent Git blob IDs identify the verbatim blobs from the source-only receipt commits above, before whitespace cleanup. These are separate provenance records. The object-file SHA-256 values identify the assembled ELF artifacts; the exactness claim is the verifier's complete relocated-function-span result, not byte identity of the whole ELF container. The compiler records a temporary preprocessing filename, so container fingerprints may differ between otherwise identical builds.

| Source | Current source SHA-256 | Original blob ID |
| --- | --- | --- |
| `src/newlib_qsort_0011EBD0.c` | `7e3b218c82595b67205f4bcb67a53b6c0884e67de95779fbf7e4aa15cc6b31bf` | `2090d236d3391497038fbbd142262eacf706f0f0` |
| `src/newlib_k_rem_pio2_001145D0.c` | `4a4f3d2499f60d1a4f0d92da0abada309a0c5267774021d67c79f4bd36d0b8d9` | `5c6340289be097e94a077f8b2087462f97fe69d9` |
| `src/newlib_floor_00116710.c` | `117644ea7422c7912da24056db9666f9ab4d925b6419ae610b90589144ad0cab` | `373b6e8438f76e697b23b3deac88e5a5c01106e0` |
| `src/newlib_scalbn_001169B0.c` | `f6079e3535841770c95fe6a894ef808ff180ec2ed30e30df4f55315b315697d6` | `a0bce6e117fc63455e70117c4c0456408650b004` |


The verifier's readonly map now includes only the compiler constants needed by these C units:

| Source | Section | Retail address | Size |
| --- | --- | ---: | ---: |
| `src/newlib_k_rem_pio2_001145D0.c` | `.rodata` | `0x004AC028` | `0x70` |
| `src/newlib_floor_00116710.c` | `.rodata` | `0x004AC250` | `0x10` |
| `src/newlib_scalbn_001169B0.c` | `.rodata` | `0x004AC260` | `0x30` |

`verify_object.py` validates each complete readonly section against the target when verifying its source, then uses it to resolve relocations. The constants are not entered in `config/data_matches.csv` and receive no data credit.

## Reproduction

Source `private/build.env` from the original private checkout so `WIBO`, `SNCPP`, `SNAS`, `EE96CC1`, and `PYTHON` point to the authorized local tools. The EE GCC 2.96 wrapper uses the running `mvc2-probes` Colima VM on macOS. From this worktree, preprocess each source, compile with the listed optimization and `-G0`, assemble with SNAS, then verify the full span:

```sh
mkdir -p build/sdk_receipts
"$WIBO" "$SNCPP" -P src/newlib_qsort_0011EBD0.c build/sdk_receipts/newlib_qsort_0011EBD0.i
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O3 --extra-flags="" build/sdk_receipts/newlib_qsort_0011EBD0.i build/sdk_receipts/newlib_qsort_0011EBD0.s
"$WIBO" "$SNAS" -G0 -o build/sdk_receipts/newlib_qsort_0011EBD0.o build/sdk_receipts/newlib_qsort_0011EBD0.s
"$PYTHON" tools/verify_object.py build/sdk_receipts/newlib_qsort_0011EBD0.o /path/to/SLUS_204.86.rom --source src/newlib_qsort_0011EBD0.c
```

Repeat with `newlib_k_rem_pio2_001145D0`, `newlib_floor_00116710`, and `newlib_scalbn_001169B0`, changing `--opt` to `O2`. The production symbol map resolves `scalbn = 0x001169B0`, `floor = 0x00116710`, and `func_00116568 = 0x00116568`. Use the original private image as the verifier target.

## Upstream and license notices

The source adaptations identify Newlib 1.10.0, sourceware tag `newlib-1_10_0`, commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`. The Berkeley 4-clause BSD notice and Sun Microsystems fdlibm permission notice are reproduced in `LICENSES/BSD-4-Clause-qsort.txt` and `LICENSES/Sun-fdlibm.txt`, with scope listed in `LICENSES/README.md`. The imported C files have whitespace cleaned; all license words and notices remain intact.

Required qsort public acknowledgement: `This product includes software developed by the University of California, Berkeley and its contributors.`
