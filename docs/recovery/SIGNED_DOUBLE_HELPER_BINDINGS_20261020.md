# Correct signed and unsigned double helper bindings

The code address map now binds `dptoli` to the actual signed implementation
at 00119BC0 and `dptoul` to the actual unsigned implementation at 00119CE8.
The two reconstructed functions are in `fp_bit_integer_conversions.c`.
Previously, both compiler names selected the signed helper; this allowed an
unsigned C cast to pass byte comparison while expressing the wrong behavior
for a negative value.

All 52 affected native calls in 39 source files have now been reviewed and
normalized. The earlier checkpoint changed 37 calls in 29 files; this followup
completes 15 calls in ten files. Ten conversions have bounded producer/data
proof and use signed conversion before unsigned wrapping. Five conversions
with unbounded float inputs explicitly call the real signed helper using its
actual `s32 (double)` interface. That helper truncates toward zero, returns
zero for NaNs and subunit magnitudes, and saturates infinities and values
outside signed 32-bit range. These calls preserve those full-domain semantics
rather than introducing an unbounded floating-to-integer C cast.

The three actual unsigned calls in `w1911_k.c` remain unsigned. Its complete
280-byte routine was recompiled from source without symbol renaming and
verified exactly using the corrected `dptoul` binding. The build script's
special objcopy operation has been removed.

An independent audit of all credited code objects and their corresponding
native instructions finds 72 `dptoli` calls, all targeting 00119BC0, and three
`dptoul` calls, all targeting 00119CE8. No caller depends on the former shared
alias. Every registered function in each changed compilation unit was
independently recompiled with its production compiler and flags and checked
in full. This is a source-semantics correction; it adds no catalog code bytes.

## Additional bounded producer evidence

- `src/grok_bt_335830.c`: Native caller residual 003356F0 sets +0x60 from D_004B7F68[p[5]], toggles p[5]&1, then sets +0x54=(next-current)/200. ROM at D_004B7F68 contains {20,-20}. Thus |f60|<=20, |f54|<=0.2; full s16 h1C gives |f54*h1C|<=6553.6 degrees and scaled value <1.2M.
- `src/m8k.c`: Native producer 003340A0 selects one of three records at D_004B7D70, sets p[0x21] to record header (6/4/5) and p[5]=1, then calls 00334240. The latter accepts p5<count, computes table indexes from the duration/index records, and reads f6c from D_004B7D58. Valid groups 0..2 and steps 1..count-1 use only indices 0..2; values are {-120,0,100}. Scaled magnitude <=21,846. Table/state group range is implicit but directly established by the producer record set.
- `src/q13_d.c`: Native predecessor 00332D30 selects D_004B7B40 record group and reads p+0x50 from D_004B7B30 using record indexes. The six groups and valid frame slots select indices 0..2; raw float table is {0,-1,+1,0}. Scaled magnitude <=183.
- `src/z1_k.c`: Native caller residual 00335400 sets +0x60 from D_004B7F68[p[5]], toggles p[5]&1, then sets +0x54=(next-current)/200. ROM at D_004B7F68 contains {20,-20}. Thus |f60|<=20, |f54|<=0.2; full s16 h1C gives scaled product <1.2M.
- `src/t7_e.c`: Exact source caller func_00332270 sets +0x54=(D_004B78C8[to]-D_004B78C8[from])/duration before native 00332420 calls func_00332580 (JAL at 0x00332548); native 00332420 does not change +0x54. D_004B78C8 values {50,19}; D_004B78D0 records use valid indexes 0/1 and durations >=300. For f54 max31/300 and full s16 h1C, scaled value <617k. Other two entries: h5e calls func_003333C0 after exact scale interpolation from {-50,-19}; m99f calls func_00333950 after exact interpolation from {-60,-20,20,0}. Maximum table delta/duration is 80/300; full s16 h1C gives scaled value <1.6M.
- `src/z13_g.c`: `func_00147580` loops i=0..3 and calls exact constructor `func_00146CD0(0,(s8)i)`. `func_00146CD0` sets new actor +0x20 from its second argument. `func_001473C0` dispatches by +0x23 to the complete five-entry table; all state handlers read +0x20 and none overwrite it. Native `func_00146D80` copies +0x20 into a newly allocated child and does not mutate the parent. The complete matching data tables have 4 V3 entries and V4 angles {-90,0,180,90}; scaled magnitude <=32,769.

The selector bounds also follow allocator and state initialization: the object
pool clears each new object; q13 starts in group zero and wraps its group
modulo six, while m8k starts in group zero and advances modulo three. Their
step counters are checked against the selected record header before sampling.
For z13, the caller loops over 0..3 and stores that selector in the new object;
the remaining constructor call passes zero. Child creation copies the same
selector, and callback handlers leave it unchanged. For the third t7 entry,
00332270 sets the bounded scale increment and 00332420 forwards it unchanged
to 00332580. These producer chains close the earlier pending range proofs.

The followup independently verifies 35 complete catalogued spans across ten
changed source files plus the unsigned conversion object. The other 13,742
cached source/object pairs and all 37 headers are unchanged. Full linkage
preserves the 3,941,760-byte loaded image with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and the 3,942,320-byte packed ELF with SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 91 tests, build coverage and catalog validation pass. Code remains
2,034,192 / 3,293,696 bytes (61.7602%); data remains 195,398 / 648,064 (30.1510%).
