# Signed double conversion helper normalization

The compiler emits `dptoli` for signed double-to-integer conversions and
`dptoul` for unsigned conversions. The native callsites covered here target
00119BC0, whose reconstructed implementation converts to signed 32-bit.
The genuine unsigned helper is at 00119CE8. The legacy code map currently
binds both compiler names to the signed implementation; byte comparisons
alone therefore cannot establish that an unsigned C cast has the right
language semantics for a negative input.

This change makes 37 conversions in 29 source files explicitly signed before
unsigned low-bit wrapping or masking. One existing explicit software-helper
call is renamed to the real signed helper with its signed return type. The
bounded inputs fit signed 32-bit; negative phases are wrapped only after the
signed conversion. This does not add matching bytes to the catalog.

Each changed file was independently compiled with its current production
compiler and flags, and every catalogued function in that file was verified
in full (including unrelated functions sharing the same compilation unit).
An independent ELF relocation audit found exactly 37 `dptoli` relocations in
these objects and no `dptoul`; the 37 corresponding retail instructions were
also read directly and all call 00119BC0.

The global alias remains unchanged while the remaining 15 legacy callsites
are investigated. In particular, `z13_g.c` still needs its selector invariant
proved, and one entry in `t7_e.c` still lacks a traced input producer. Neither
file is modified by this checkpoint. The explicitly unsigned conversions
calling 00119CE8 remain unsigned.

The table below records the input evidence used for these changes. Signed-16
input bounds cover the entire type range, including negative values. Math
bounds apply to the game’s finite angle inputs. Table interpolation bounds
include the full signed-16 frame range rather than assuming a normal frame.

| Source | Input bound |
| --- | --- |
| `src/L0_f.c` | s16 degrees, rounded 65536*degrees/360; max absolute intermediate 5,965,233. Input is signed 16-bit at +0x1E. |
| `src/L3_b.c` | Caller func_00154120 passes i=0..5; c*60 gives 0..300 degrees; rounded turn value <=54,614. |
| `src/bobbing_position_003421e0.c` | Signed-16 degree field; rounded 65536*degrees/360 <=5,965,233. |
| `src/grok_dw_338050.c` | Signed-16 degree field times 1.5; rounded result <=8,947,850. |
| `src/grok_dw_3395e0.c` | Signed-16 degree field times 0.5; rounded result <=2,982,617. |
| `src/grok_fl_36dde0.c` | Signed-16 angle at +0x1E, rounded 65536*degrees/360 <=5,965,233; explicit helper call renamed dptoul to dptoli. |
| `src/h5e.c` | Exact caller func_00333180 fills f50 from D_004B7A60 {-50,-19}; result <=9,103 degrees-turn units. Complete source/data available in relative_scale_interpolation.c and src/data/relative_scale_factors_004B7A60.c. |
| `src/m99f.c` | Exact caller func_00333710 fills f50 from D_004B7990 {-60,-20,20,0}; result <=10,924. Complete source/data available in relative_scale_interpolation.c and src/data/relative_scale_factors_004B7990.c. |
| `src/q14_c.c` | Signed-16 degree field; rounded result <=5,965,233. |
| `src/q1h.c` | func_003DE700 aliases atan2f (source wrapper -> func_001173E8 -> atan2f); for finite inputs range [-pi,pi], formula yields about [-128,128]. |
| `src/q6_ad.c` | D_00444FB0 interpolation keys (0,0)->(20,-240), frame is signed16 and capped above at 12; linear extrapolation down to s16 min gives about -393,216 degrees, scaled magnitude <=71,582,789. |
| `src/s39c.c` | func_003DE700 aliases atan2f; finite output [-pi,pi], 65536/(2pi) gives [-32768,32768]. |
| `src/s4w9mw.c` | func_003DE6F0 aliases atanf; finite output [-pi/2,pi/2], turn scaling gives [-16384,16384]. |
| `src/v12_f.c` | Signed-16 angle field; rounded result <=5,965,233. |
| `src/v13_b.c` | Exact caller interpolation table D_00444F80 keys (0,0)->(20,240); frame signed16, capped above at 12; lowest extrapolation gives magnitude <=71,582,789 after turn scaling. |
| `src/w1710_h.c` | D_004450C0 has keypoints (0,0)->(15,180); frame signed16, capped above at 15; lower signed16 extrapolation gives scaled magnitude <=71,582,789. |
| `src/w178_f.c` | Byte source values: first expression uses 6*byte (<=1530 deg), second uses (byte+60*(byte%12))/2 (<=457 deg); both scaled <280,000. |
| `src/w183_n.c` | p->a is signed16; conversion result <=5,965,233 in either update branch. |
| `src/w184_h.c` | p->h1e is signed16; rounded conversion result <=5,965,233. |
| `src/w186_c.c` | degrees is explicitly set to 0 or -180; result is within [-32768,0]. |
| `src/w2_k.c` | x,y are signed16; sqrt(x*x+y*y) <=46,341, safely within s32 before assignment/truncation to s16. |
| `src/wrapped_degree_phases.c` | Each function converts signed16 degrees; rounded result <=5,965,233. All three spans were verified. |
| `src/x10_a.c` | Signed-16 degree field; rounded result <=5,965,233. |
| `src/x11_e.c` | p->h1c is signed16; rounded result <=5,965,233. |
| `src/y0_k.c` | func_00417A40()%90 is in [-89,89] for signed remainder; rounded result <=16,203. |
| `src/y1_i.c` | Each first expression uses signed16 degrees (<=5,965,233); each second uses sine output scaled by 45 or 20 degrees (<=8,193). |
| `src/y4_d.c` | Signed-16 degrees multiplied by 3; rounded result <=17,895,698. |
| `src/z4_e.c` | Signed-16 degree field; rounded result <=5,965,233; converted to u32 then narrowed to low16 for sine lookup. |
| `src/z9_k.c` | D_00444A20 interpolation keys (0,0)->(11,45); signed16 frame capped above at10; lowest extrapolation gives about -134,050 degrees, scaled magnitude <24,401,000. |

Independent whole-function verification covers 54 catalogued spans.

The other 13,724 cached source/object pairs and all 37 headers are unchanged.
Full loaded-image linkage and packed retail ELF remain byte-exact with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 91 tests and catalog validation pass. Code remains 61.7602%; data 30.1510%.
