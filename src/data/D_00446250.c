typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Installed as D_004C2674 by func_0016B3F0 (src/w182_l.c). The stepper at
 * 0x0016B868..B8FC reads 4-byte steps: delay (lbu +0, 0xFF ends the
 * script), flag (lbu +1, then lb as a signed value), id (lbu +2, plus
 * 0x910) and arg (lbu +3), then advances D_004C2674 by 4. */
typedef struct { u8 delay; s8 flag; u8 id; u8 arg; } ScriptStep;
typedef char ScriptStep_size_check[(sizeof(ScriptStep) == 4) ? 1 : -1];
ScriptStep D_00446250[15] = {
    { 0x0Au, 0, 0x00u, 0x01u },
    { 0x06u, 1, 0x01u, 0x02u },
    { 0x06u, 2, 0x00u, 0x04u },
    { 0x06u, 3, 0x01u, 0x05u },
    { 0x06u, 4, 0x00u, 0x02u },
    { 0x06u, 5, 0x01u, 0x03u },
    { 0x06u, 6, 0x00u, 0x02u },
    { 0x06u, 7, 0x01u, 0x03u },
    { 0x06u, 8, 0x00u, 0x02u },
    { 0x06u, 9, 0x01u, 0x03u },
    { 0x06u, 10, 0x00u, 0x02u },
    { 0x06u, 11, 0x01u, 0x05u },
    { 0x06u, 12, 0x00u, 0x02u },
    { 0x1Eu, 13, 0x01u, 0x00u },
    { 0xFFu, -1, 0xFFu, 0xFFu }
};
