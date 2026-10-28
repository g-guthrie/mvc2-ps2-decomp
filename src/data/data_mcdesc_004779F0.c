typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Microcode descriptors. func_003E0F60 (src/fb69_d.c) selects one by format
 * (tbl = D_004779F0 + 0x30 * t, t = 0..48) and stores it at state+0x40. Readers:
 *   func_003F0500: lw +0x0 (masked to 28 bits and DMA'd by func_003DC2F0), lw +0x4/+0x8/+0xC
 *     ((end - base) >> 3 -> D_0062BFC8, (entry - base) >> 3 passed on), lw +0x10 and jalr it
 *     with (state, (entry - base) >> 3), lw +0x14 as an index into D_00478DF0;
 *   func_003EE9A0 / func_003EEC30: lw +0x14, +0x18 (index into D_00478E10), +0x1C (index
 *     into D_00478E60), +0x20, +0x24;
 *   every setup callback (func_003E1B20 ...): lwc1 +0x28.
 * Word +0x2C is never read (always zero). */
typedef s32 (*Mvc2MicrocodeSetup)(void *, u32);
typedef struct {
    const u8 *microcode;
    u32 entry;
    u32 base;
    u32 end;
    Mvc2MicrocodeSetup setup;
    u32 idx_478DF0; /* +0x14 */
    u32 idx_478E10; /* +0x18 */
    u32 idx_478E60; /* +0x1C */
    u32 w20;
    u32 w24;
    f32 scale;
    u32 unk_2C;
} Mvc2MicrocodeDesc;
typedef char Mvc2MicrocodeDesc_size_check[(sizeof(Mvc2MicrocodeDesc) == 0x30) ? 1 : -1];
extern const u8 D_00424200[];
extern const u8 D_004250C0[];
extern const u8 D_00425470[];
extern const u8 D_004259F0[];
extern const u8 D_00425D60[];
extern const u8 D_00426580[];
extern const u8 D_00427760[];
extern const u8 D_00428510[];
extern const u8 D_00428E60[];
extern const u8 D_004291D0[];
extern const u8 D_00429510[];
extern const u8 D_0042A460[];
extern const u8 D_0042B210[];
extern const u8 D_0042B4D0[];
extern const u8 D_0042B780[];
extern const u8 D_0042BA90[];
extern const u8 D_0042BD80[];
extern const u8 D_0042C040[];
extern const u8 D_0042C2E0[];
extern const u8 D_0042C630[];
extern const u8 D_0042C950[];
extern const u8 D_0042DAF0[];
extern const u8 D_0042DEB0[];
extern const u8 D_0042E290[];
extern const u8 D_0042E660[];
extern const u8 D_0042E990[];
extern const u8 D_0042ED10[];
extern const u8 D_0042F0D0[];
extern const u8 D_0042F410[];
extern const u8 D_0042F7C0[];
extern const u8 D_0042FB60[];
extern const u8 D_0042FF40[];
extern const u8 D_004302C0[];
extern const u8 D_00430640[];
extern const u8 D_00430970[];
extern const u8 D_00430CC0[];
extern const u8 D_00430FA0[];
extern const u8 D_00431290[];
extern const u8 D_00431670[];
extern const u8 D_00431A80[];
extern const u8 D_00431E60[];
extern const u8 D_00432230[];
extern const u8 D_004325D0[];
extern const u8 D_004329B0[];
extern const u8 D_00434410[];
extern const u8 D_00434770[];
extern const u8 D_00435850[];
extern const u8 D_004369A0[];
extern const u8 D_00437C90[];
extern s32 func_003E1B20(void *, u32);
extern s32 func_003E1FD0(void *, u32);
extern s32 func_003E24B0(void *, u32);
extern s32 func_003E2B70(void *, u32);
extern s32 func_003E31D0(void *, u32);
extern s32 func_003E33F0(void *, u32);
extern s32 func_003E38D0(void *, u32);
extern s32 func_003E3B20(void *, u32);
extern s32 func_003E4050(void *, u32);
extern s32 func_003E42F0(void *, u32);
extern s32 func_003E4850(void *, u32);
extern s32 func_003E4B20(void *, u32);
extern s32 func_003E4D50(void *, u32);
extern s32 func_003E5090(void *, u32);
extern s32 func_003E5680(void *, u32);
extern s32 func_003E59E0(void *, u32);
extern s32 func_003E5FF0(void *, u32);
extern s32 func_003E6370(void *, u32);
extern s32 func_003E69D0(void *, u32);
extern s32 func_003E6DA0(void *, u32);
extern s32 func_003E7430(void *, u32);
extern s32 func_003E7830(void *, u32);
extern s32 func_003E7BC0(void *, u32);
extern s32 func_003E7FD0(void *, u32);
extern s32 func_003E8490(void *, u32);
Mvc2MicrocodeDesc data_mcdesc_004779F0[49] = {
    /*  0 */ { D_004250C0, 0x0u, 0x0u, 0x390u, func_003E1B20, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /*  1 */ { D_00425470, 0x0u, 0x0u, 0x560u, func_003E1FD0, 0u, 8u, 0u, 4080u, 0x10u, 128.0f, 0u },
    /*  2 */ { D_004259F0, 0x0u, 0x0u, 0x358u, func_003E1B20, 1u, 2u, 1u, 3968u, 0x0u, 255.0f, 0u },
    /*  3 */ { D_00425D60, 0x0u, 0x0u, 0x388u, func_003E5090, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /*  4 */ { D_00426580, 0x0u, 0x0u, 0x3B0u, func_003E5090, 1u, 2u, 1u, 3968u, 0x0u, 255.0f, 0u },
    /*  5 */ { D_00427760, 0x0u, 0x0u, 0xD30u, func_003E2B70, 2u, 0u, 0u, 2048u, 0x0u, 128.0f, 0u },
    /*  6 */ { D_00428510, 0x0u, 0x0u, 0x8D0u, func_003E24B0, 2u, 8u, 0u, 1600u, 0x16u, 128.0f, 0u },
    /*  7 */ { D_00428E60, 0x0u, 0x0u, 0x350u, func_003E1B20, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /*  8 */ { D_004291D0, 0x0u, 0x0u, 0x320u, func_003E1B20, 4u, 3u, 1u, 4080u, 0x0u, 255.0f, 0u },
    /*  9 */ { D_00429510, 0x0u, 0x0u, 0x3A0u, func_003E5090, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /* 10 */ { D_0042A460, 0x0u, 0x0u, 0x348u, func_003E5090, 4u, 3u, 1u, 4080u, 0x0u, 255.0f, 0u },
    /* 11 */ { D_0042B210, 0x0u, 0x0u, 0x2A8u, func_003E31D0, 3u, 5u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 12 */ { D_0042B4D0, 0x0u, 0x0u, 0x290u, func_003E31D0, 4u, 7u, 1u, 3968u, 0x0u, 255.0f, 0u },
    /* 13 */ { D_0042B780, 0x0u, 0x0u, 0x2F8u, func_003E31D0, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 14 */ { D_0042BA90, 0x0u, 0x0u, 0x2D8u, func_003E31D0, 1u, 6u, 1u, 2560u, 0x0u, 255.0f, 0u },
    /* 15 */ { D_0042BD80, 0x0u, 0x0u, 0x2A8u, func_003E5680, 3u, 5u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 16 */ { D_0042C040, 0x0u, 0x0u, 0x288u, func_003E5680, 4u, 7u, 1u, 3968u, 0x0u, 255.0f, 0u },
    /* 17 */ { D_0042C2E0, 0x0u, 0x0u, 0x330u, func_003E5680, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 18 */ { D_0042C630, 0x0u, 0x0u, 0x308u, func_003E5680, 1u, 6u, 1u, 2560u, 0x0u, 255.0f, 0u },
    /* 19 */ { D_0042C950, 0x0u, 0x0u, 0x1158u, func_003E7FD0, 0u, 0u, 0u, 2880u, 0x0u, 128.0f, 0u },
    /* 20 */ { D_0042DAF0, 0x0u, 0x0u, 0x3A0u, func_003E33F0, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 21 */ { D_0042DEB0, 0x0u, 0x0u, 0x3C0u, func_003E59E0, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 22 */ { D_0042E290, 0x0u, 0x0u, 0x3B0u, func_003E33F0, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /* 23 */ { D_0042E660, 0x0u, 0x0u, 0x318u, func_003E38D0, 3u, 5u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 24 */ { D_0042E990, 0x0u, 0x0u, 0x360u, func_003E38D0, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 25 */ { D_0042ED10, 0x0u, 0x0u, 0x3A8u, func_003E59E0, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /* 26 */ { D_0042F0D0, 0x0u, 0x0u, 0x320u, func_003E5FF0, 3u, 5u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 27 */ { D_0042F410, 0x0u, 0x0u, 0x390u, func_003E5FF0, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 28 */ { D_0042F7C0, 0x0u, 0x0u, 0x388u, func_003E3B20, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 29 */ { D_0042FB60, 0x0u, 0x0u, 0x3C0u, func_003E6370, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 30 */ { D_0042FF40, 0x0u, 0x0u, 0x360u, func_003E3B20, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /* 31 */ { D_004302C0, 0x0u, 0x0u, 0x368u, func_003E6370, 3u, 1u, 0u, 4080u, 0x0u, 128.0f, 0u },
    /* 32 */ { D_00430640, 0x0u, 0x0u, 0x310u, func_003E4050, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 33 */ { D_00430970, 0x0u, 0x0u, 0x330u, func_003E69D0, 0u, 4u, 0u, 3040u, 0x0u, 128.0f, 0u },
    /* 34 */ { D_00430CC0, 0x0u, 0x0u, 0x2C0u, func_003E4050, 3u, 5u, 0u, 4000u, 0x0u, 128.0f, 0u },
    /* 35 */ { D_00430FA0, 0x0u, 0x0u, 0x2D0u, func_003E69D0, 3u, 5u, 0u, 3840u, 0x0u, 128.0f, 0u },
    /* 36 */ { D_00431290, 0x0u, 0x0u, 0x3C8u, func_003E42F0, 0u, 0u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 37 */ { D_00431670, 0x0u, 0x0u, 0x3F8u, func_003E6DA0, 0u, 0u, 0u, 3840u, 0x0u, 128.0f, 0u },
    /* 38 */ { D_00431A80, 0x0u, 0x0u, 0x3C0u, func_003E42F0, 3u, 1u, 0u, 4000u, 0x0u, 128.0f, 0u },
    /* 39 */ { D_00431E60, 0x0u, 0x0u, 0x3B0u, func_003E6DA0, 3u, 1u, 0u, 3840u, 0x0u, 128.0f, 0u },
    /* 40 */ { D_00432230, 0x0u, 0x0u, 0x380u, func_003E4850, 0u, 4u, 0u, 3200u, 0x0u, 128.0f, 0u },
    /* 41 */ { D_004325D0, 0x0u, 0x0u, 0x3C0u, func_003E7430, 0u, 4u, 0u, 3040u, 0x0u, 128.0f, 0u },
    /* 42 */ { D_004329B0, 0x0u, 0x0u, 0x330u, func_003E4850, 3u, 5u, 0u, 3968u, 0x0u, 128.0f, 0u },
    /* 43 */ { D_00434410, 0x0u, 0x0u, 0x340u, func_003E7430, 3u, 5u, 0u, 3840u, 0x0u, 128.0f, 0u },
    /* 44 */ { D_00434770, 0x0u, 0x0u, 0x1098u, func_003E7830, 3u, 5u, 0u, 2880u, 0x0u, 128.0f, 0u },
    /* 45 */ { D_00435850, 0x0u, 0x0u, 0x1108u, func_003E7BC0, 3u, 5u, 0u, 2880u, 0x0u, 128.0f, 0u },
    /* 46 */ { D_004369A0, 0x0u, 0x0u, 0x12B0u, func_003E8490, 3u, 1u, 0u, 2720u, 0x0u, 128.0f, 0u },
    /* 47 */ { D_00437C90, 0x0u, 0x0u, 0x4B0u, func_003E4B20, 0u, 2u, 0u, 1600u, 0x0u, 128.0f, 0u },
    /* 48 */ { D_00424200, 0x0u, 0x0u, 0xE70u, func_003E4D50, 5u, 9u, 0u, 2560u, 0xEu, 128.0f, 0u },
};
