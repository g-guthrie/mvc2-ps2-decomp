/* 56 packed 32-bit colour words (top byte 0xFF). Reader func_0016D4B0 (0x0016D500, 0x0016D6D0..) loads D_00446460[lbu index] with lw (index scale 4) into the CB170/174/178/1CC colour slots. */
typedef unsigned int u32;
typedef struct { u32 argb; } Mvc2ColorEntry;

Mvc2ColorEntry data_rec_00446460[56] = {
    { 0xFFFFFFFFu }, /* 0x00446460 */
    { 0xFFFF0000u }, /* 0x00446464 */
    { 0xFF00FF00u }, /* 0x00446468 */
    { 0xFFFF9900u }, /* 0x0044646C */
    { 0xFFFFFF00u }, /* 0x00446470 */
    { 0xFF0000FFu }, /* 0x00446474 */
    { 0xFFFF00FFu }, /* 0x00446478 */
    { 0xFFFFA000u }, /* 0x0044647C */
    { 0xFFB000FFu }, /* 0x00446480 */
    { 0xFF00FFFFu }, /* 0x00446484 */
    { 0xFF6E6E6Eu }, /* 0x00446488 */
    { 0xFFFF93FCu }, /* 0x0044648C */
    { 0xFFFE09B2u }, /* 0x00446490 */
    { 0xFF909090u }, /* 0x00446494 */
    { 0xFF5A52FFu }, /* 0x00446498 */
    { 0xFF00FFD8u }, /* 0x0044649C */
    { 0xFFA0A0A0u }, /* 0x004464A0 */
    { 0xFFF77CF7u }, /* 0x004464A4 */
    { 0xFF00DEF7u }, /* 0x004464A8 */
    { 0xFFF3E817u }, /* 0x004464AC */
    { 0xFFE8F906u }, /* 0x004464B0 */
    { 0xFFEFB14Eu }, /* 0x004464B4 */
    { 0xFFECD629u }, /* 0x004464B8 */
    { 0xFFF56B94u }, /* 0x004464BC */
    { 0xFFD38B74u }, /* 0x004464C0 */
    { 0xFFFB2CD3u }, /* 0x004464C4 */
    { 0xFFF93CC3u }, /* 0x004464C8 */
    { 0xFF00FF15u }, /* 0x004464CC */
    { 0xFFFF0F50u }, /* 0x004464D0 */
    { 0xFF08F0FFu }, /* 0x004464D4 */
    { 0xFFFFE500u }, /* 0x004464D8 */
    { 0xFFFF6800u }, /* 0x004464DC */
    { 0xFFFF1000u }, /* 0x004464E0 */
    { 0xFFFF28FAu }, /* 0x004464E4 */
    { 0xFFD091FFu }, /* 0x004464E8 */
    { 0xFF98A0FFu }, /* 0x004464EC */
    { 0xFFC5FFAEu }, /* 0x004464F0 */
    { 0xFF74FFC1u }, /* 0x004464F4 */
    { 0xFFA0FFE1u }, /* 0x004464F8 */
    { 0xFF92E0FFu }, /* 0x004464FC */
    { 0xFF7CA9FFu }, /* 0x00446500 */
    { 0xFFBA82FFu }, /* 0x00446504 */
    { 0xFFEE40FFu }, /* 0x00446508 */
    { 0xFFFF40D2u }, /* 0x0044650C */
    { 0xFFFF40A6u }, /* 0x00446510 */
    { 0xFFFF4062u }, /* 0x00446514 */
    { 0xFFFFA200u }, /* 0x00446518 */
    { 0xFFFFE000u }, /* 0x0044651C */
    { 0xFFFFFC25u }, /* 0x00446520 */
    { 0xFFFF0F0Fu }, /* 0x00446524 */
    { 0xFFFF21F2u }, /* 0x00446528 */
    { 0xFF37CDFFu }, /* 0x0044652C */
    { 0xFFFFAE01u }, /* 0x00446530 */
    { 0xFF000000u }, /* 0x00446534 */
    { 0xFF000000u }, /* 0x00446538 */
    { 0xFF000000u }, /* 0x0044653C */
};
