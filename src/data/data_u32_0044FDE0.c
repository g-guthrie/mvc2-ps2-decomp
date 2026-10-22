typedef unsigned int u32;
/* 16 quadword entries of four u32 words. Entries 6-15 have the shape of GIF tag quadwords
 * (tag word first); entries 0-5 hold small values and zero pads. */
typedef struct {
    u32 w[4];
} data_u32_0044FDE0_quad_t;
typedef char data_u32_0044FDE0_size_check[(sizeof(data_u32_0044FDE0_quad_t) == 16) ? 1 : -1];

data_u32_0044FDE0_quad_t data_u32_0044FDE0[16] = {
    { 66u, 75u, 84u, 93u },
    { 102u, 111u, 0u, 0u },
    { 48u, 51u, 54u, 57u },
    { 60u, 63u, 0u, 0u },
    { 120u, 121u, 122u, 123u },
    { 124u, 125u, 0u, 0u },
    { 268435459u, 1u, 402657280u, 50333696u },
    { 536870915u, 1u, 402657280u, 50333696u },
    { 268435459u, 2u, 268437504u, 50337792u },
    { 536870915u, 2u, 268437504u, 50337792u },
    { 268435461u, 3u, 402655232u, 335548416u },
    { 50332672u, 0u, 0u, 0u },
    { 2432696323u, 7u, 402657280u, 50333696u },
    { 2432696323u, 9u, 268437504u, 50337792u },
    { 2164260867u, 6u, 402657280u, 6293504u },
    { 536870915u, 15u, 335548416u, 6292480u },
};
