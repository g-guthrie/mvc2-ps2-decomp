# Sony runtime address mode setters

Five C functions reproduce complete retail spans with Sony EE GCC
2.9-991111 `-O2 -G0 -ffunction-sections` and the existing SN assembler:

| Function | Bytes | Address field | Mode bits set after clearing bits 2 and 3 |
| --- | ---: | --- | --- |
| 001028B0 | 104 | +0x30 | 0x105 |
| 00102918 | 116 | +0x10 | 0x101 |
| 00102990 | 116 | +0x10 | 0x109 |
| 00102A50 | 124 | +0x10 | 0x100; also clear bit 0 |
| 00102AD0 | 128 | +0x10 | 0x108; also clear bit 0 |

Each first remaps its address argument with the existing 00102520 provider,
calls the reset helper, and replaces the listed address field unless its
current value is the unsigned all-ones sentinel. The first writes zero at
+0x20; the other four write their supplied value there. The shared structure
describes these observed fields and intervening unknown bytes. The newly
observed field at +0x30 accounts for the extra prefix span; no unused tail
padding is present. Address values and mapping results use unsigned 32-bit
values consistent with the existing provider.

The compiler directly emits native 64-bit register saves at 16-byte spacing.
No assembly or object output is rewritten. All five functions independently
pass whole-span relocated-object verification after sharing the same source
unit. No new data credit is added.

The first two recovered setters contributed 252 bytes at checkpoint `14296d5e`.
The three additional setters contribute 336 bytes. Before this extension,
13,734 other source/object pairs and all 37 shared headers were checked
unchanged against `19f9e919`; the existing two setters were recompiled and
reverified with the new three.

The complete five-function unit and the new input-direction recovery pass the
full hybrid link and packed retail ELF comparison. All 91 tests and catalog
validation pass; production coverage includes 4,112 source units. The loaded
image SHA-256 is `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and packed ELF SHA-256 is `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The catalog now credits 2,031,768 / 3,293,696 code bytes (61.6866%);
reconstructed data remains 195,314 / 648,064 bytes (30.1381%).
