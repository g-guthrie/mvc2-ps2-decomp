/*
 * Per-frame state dump of the NAOMI arcade program (mvsc2 Rev A) written by
 * naomi_oracle (port/tools/naomi_oracle/naomi_oracle.cpp, Flycast core) and
 * read by port/tools/naomi_oracle/naomi_compare.py, which translates it to
 * the PS2 layout and compares it with the port's MVC2_STATE_DUMP
 * (port/tools/oracle/dump_format.h).
 *
 * One record per game frame, taken at 0x0C0283D6 (main loop 0x0C028394,
 * right after the frame's V-blank wait 0x0C1E9B20 returns: the logic step
 * has not run yet; the same point as the PS2 oracle's func_0012F460 entry
 * and the port's mvc2_frame()).  Little endian:
 *   u32 magic 'MVN1', u32 frame, u16 pad1, u16 pad2 (script bits, PS2 pad
 *   layout), u32 game state g[0..2] (g = 0x0C2D6F88),
 *   u32 game RNG in the PS2 order: [0x0C283049] | [0x0C283048] << 8
 *     (= PS2 D_004C26AC | D_004C26B0 << 8),
 *   u32 sh4 frame counter (hook calls), u32 reserved,
 *   NAOMI_REGION bytes of main RAM [NAOMI_REGION_LO, NAOMI_REGION_HI):
 *     the input records 0x0C2D6F24 (2 x 20), the game block 0x0C2D6F88,
 *     the six player records 0x0C2D7088 (stride 0x5A4), the team / round
 *     block from 0x0C2D9260.
 */
#ifndef NAOMI_DUMP_H
#define NAOMI_DUMP_H
#define NAOMI_MAGIC 0x314E564Du /* "MVN1" */
#define NAOMI_REGION_LO 0x0C2D6F00u
#define NAOMI_REGION_HI 0x0C2D9700u
#define NAOMI_G 0x0C2D6F88u
#define NAOMI_PLAYERS 0x0C2D7088u
#define NAOMI_PSTRIDE 0x5A4u
#define NAOMI_RNG_HI 0x0C283048u /* PS2 D_004C26B0 */
#define NAOMI_RNG_LO 0x0C283049u /* PS2 D_004C26AC (returned) */
#define NAOMI_HOOK 0x0C0283D6u
#endif
