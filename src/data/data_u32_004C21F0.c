typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef void *Callback;
/* Initial values of the globals that share this block. Each field is named for the extern that
   the matching C source uses (u0_b.c, s0b.c, sdk1.c, sdk4c.c, k4.c, s5.c, ee96_register_callback_003FB108.c,
   u3_g.c, w3_c.c, w184_d.c, w0_u.c). Strings are char arrays of the length the readers imply.
   Words with no name in the C sources are typed u32 (leadXX, offset in hex) or pointers to
   other places in this block (ptr_XXXX), kept as the numeric address. */
typedef struct {
    u32 lead00;
    u32 lead04;
    u16 lead08[2];
    u16 lead0C[2];
    u16 lead10[4];
    u32 lead18;
    s32 D_004C220C;
    void (*D_004C2210)(void *);
    void (*D_004C2214)(void);
    char D_004C2218[8];
    char D_004C2220[8];
    char D_004C2228[8];
    char D_004C2230[8];
    s32 D_004C2238;
    u32 lead4C;
    char D_004C2240[8];
    u16 D_004C2248;
    u16 D_004C224A;
    u16 D_004C224C;
    u16 lead5E;
    char D_004C2250[8];
    char D_004C2258[8];
    u32 ptr_004C2258;
    u32 lead74;
    char D_004C2268[8];
    u32 ptr_004C2268;
    u32 lead84;
    char D_004C2278[8];
    char D_004C2280[8];
    s32 D_004C2288;
    u32 lead9C;
    char D_004C2290[8];
    s32 D_004C2298;
    u32 leadAC;
    Callback D_004C22A0;
    void *D_004C22A4;
    char D_004C22A8[4];
    volatile s32 D_004C22AC;
    volatile s32 D_004C22B0;
    s32 D_004C22B4;
    u32 lead_C8;
    s32 D_004C22BC;
    s32 D_004C22C0;
    volatile s32 D_004C22C4;
    volatile s32 D_004C22C8;
} data_u32_004C21F0_t;
typedef char data_u32_004C21F0_t_size_check[(sizeof(data_u32_004C21F0_t) == 220) ? 1 : -1];
data_u32_004C21F0_t data_u32_004C21F0 = {
    0x00000001u, 0x00000000u,
    { 0x0100u, 0xFFFFu }, { 0xFFFFu, 0x0000u }, { 0x0001u, 0x0001u, 0x0001u, 0x0000u },
    0x00000001u,
    0, 0, 0,
    { 'F', 'O', 'R', 'M', 0, 0, 0, 0 },
    { 'A', 'I', 'F', 'F', 0, 0, 0, 0 },
    { '.', 's', 'n', 'd', 0, 0, 0, 0 },
    { '.', 's', 'd', 0, 0, 0, 0, 0 },
    0,
    0x00000000u,
    { 'C', 'R', 'I', '-', 'M', 'W', 0, 0 },
    0, 0, 0,
    0x0000u,
    { 'S', 'P', 'S', 'D', 0, 0, 0, 0 },
    { 'f', 'm', 't', ' ', 0, 0, 0, 0 },
    0x004C2258u,
    0x00000000u,
    { 'd', 'a', 't', 'a', 0, 0, 0, 0 },
    0x004C2268u,
    0x00000000u,
    { 'R', 'I', 'F', 'F', 0, 0, 0, 0 },
    { 'W', 'A', 'V', 'E', 0, 0, 0, 0 },
    0,
    0x00000000u,
    { '(', 'c', ')', 'C', 'R', 'I', 0, 0 },
    0,
    0x00000000u,
    0, 0,
    { ' ', 0, 0, 0 },
    0,
    0x004BB5B0,
    0,
    0x00000000u,
    0,
    1,
    0,
    0x004BB5E8,
};
