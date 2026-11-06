/* Hitachi const data 0x0c227e50-0x0c2286b2: unowned pieces of the game
   loading/notice/JAMMA text tables and records, completing the rest2_* fragments
   around them (record layouts named per object). */

#pragma section n206e50
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c227e50 = {
    { 0x04u, 0x11u, 0x01u },
    "prohibited."
};

#pragma section n206e90
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c227e90 = {
    { 0x04u, 0x13u, 0x01u },
    "Violators are subject to severe penalties"
};

#pragma section n206ed0
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c227ed0 = {
    { 0x04u, 0x15u, 0x01u },
    "and will be prosecuted to the full extent"
};

#pragma section n206f10
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c227f10 = {
    { 0x04u, 0x17u, 0x01u },
    "of the law."
};

#pragma section n206f50
const unsigned char dat_0c227f50[] = {
    0xffu, 0x00u,
};

#pragma section n206f92
const struct {
    unsigned char head[1];
    char text[7];
} dat_0c227f92 = {
    { 0x05u },
    "WARNING"
};

#pragma section n206fd0
const struct {
    unsigned char head[3];
    char text[37];
} dat_0c227fd0 = {
    { 0x04u, 0x07u, 0x05u },
    "This game is for use in the European "
};

#pragma section n207010
const struct {
    unsigned char head[3];
    char text[15];
} dat_0c228010 = {
    { 0x04u, 0x09u, 0x05u },
    "countries only."
};

#pragma section n207050
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228050 = {
    { 0x04u, 0x0bu, 0x05u },
    "Sales, export or operation outside these"
};

#pragma section n207090
const struct {
    unsigned char head[3];
    char text[43];
} dat_0c228090 = {
    { 0x04u, 0x0du, 0x05u },
    "countries may be construed as copyright and"
};

#pragma section n2070d0
const struct {
    unsigned char head[3];
    char text[37];
} dat_0c2280d0 = {
    { 0x04u, 0x0fu, 0x05u },
    "trademark infringement and is strictl"
};

#pragma section n207110
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c228110 = {
    { 0x04u, 0x11u, 0x05u },
    "prohibited."
};

#pragma section n207150
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228150 = {
    { 0x04u, 0x13u, 0x05u },
    "Violators are subject to severe penalties"
};

#pragma section n207190
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228190 = {
    { 0x04u, 0x15u, 0x05u },
    "and will be prosecuted to the full extent"
};

#pragma section n2071d0
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c2281d0 = {
    { 0x04u, 0x17u, 0x05u },
    "of the law."
};

#pragma section n207210
const unsigned char dat_0c228210[] = {
    0xffu, 0x00u,
};

#pragma section n207252
const struct {
    unsigned char head[1];
    char text[7];
} dat_0c228252 = {
    { 0x04u },
    "WARNING"
};

#pragma section n207290
const struct {
    unsigned char head[3];
    char text[43];
} dat_0c228290 = {
    { 0x04u, 0x07u, 0x04u },
    "This game is for use in the South-East Asia"
};

#pragma section n2072d0
const struct {
    unsigned char head[3];
    char text[17];
} dat_0c2282d0 = {
    { 0x04u, 0x09u, 0x04u },
    " countries only."
};

#pragma section n207310
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228310 = {
    { 0x04u, 0x0bu, 0x04u },
    "Sales, export or operation outside these"
};

#pragma section n207350
const struct {
    unsigned char head[3];
    char text[43];
} dat_0c228350 = {
    { 0x04u, 0x0du, 0x04u },
    "countries may be construed as copyright and"
};

#pragma section n207390
const struct {
    unsigned char head[3];
    char text[37];
} dat_0c228390 = {
    { 0x04u, 0x0fu, 0x04u },
    "trademark infringement and is strictl"
};

#pragma section n2073d0
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c2283d0 = {
    { 0x04u, 0x11u, 0x04u },
    "prohibited."
};

#pragma section n207410
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228410 = {
    { 0x04u, 0x13u, 0x04u },
    "Violators are subject to severe penalties"
};

#pragma section n207450
const struct {
    unsigned char head[3];
    char text[41];
} dat_0c228450 = {
    { 0x04u, 0x15u, 0x04u },
    "and will be prosecuted to the full extent"
};

#pragma section n207490
const struct {
    unsigned char head[3];
    char text[11];
} dat_0c228490 = {
    { 0x04u, 0x17u, 0x04u },
    "of the law."
};

#pragma section n2074d0
const unsigned char dat_0c2284d0[] = {
    0xffu, 0x00u,
};

#pragma section n207510
const char dat_0c228510[6] = "ERROR.";

#pragma section n20751a
const char dat_0c22851a[18] = "MMA I/O BOARD NOT ";

#pragma section n207530
const char dat_0c228530[2] = "D.";

#pragma section n207536
const char dat_0c228536[28] = "MMA I/O BOARD(S) DON'T HAVE\n";

#pragma section n207556
const char dat_0c228556[8] = "OUGH SWI";

#pragma section n207564
const char dat_0c228564[16] = "OR FUNCTIONS.";

#pragma section n207574
const char dat_0c228574[20] = " JAMMA I/O BOARD(S)\n";

#pragma section n20758e
const char dat_0c22858e[6] = "D CONN";

#pragma section n207598
const char dat_0c228598[12] = "ON ERROR.";

#pragma section n2075a4
const char dat_0c2285a4[12] = "CREDIT(S) ";

#pragma section n2075b0
const char dat_0c2285b0[8] = "%1d/%1d";

#pragma section n2075b8
const char dat_0c2285b8[6] = "0/%1d";

#pragma section n2075c4
const char dat_0c2285c4[4] = "%1d ";

#pragma section n2075cc
const char dat_0c2285cc[2] = ";S";

#pragma section n2075ce
const char dat_0c2285ce[4] = "\000\027/G";

#pragma section n2075d8
const unsigned short dat_0c2285d8[] = {
    0xe780u, 0x0000u, 0xe780u, 0x0080u, 0x2040u,
};

#pragma section n2075e6
const unsigned short dat_0c2285e6[] = {
    0x0082u,
};

#pragma section n2075ec
const unsigned short dat_0c2285ec[] = {
    0x1460u, 0x0082u, 0x64c0u, 0x0000u, 0x7920u, 0x0082u, 0x6b60u, 0x0000u,
    0xe480u, 0x0082u, 0x65a0u, 0x0000u, 0x4a20u, 0x0083u, 0x6a20u, 0x0000u,
    0xb440u, 0x0083u, 0x6780u, 0x0000u, 0x1bc0u, 0x0084u, 0x65c0u, 0x0000u,
    0x8180u, 0x0084u, 0x67a0u, 0x0000u, 0xe920u, 0x0084u, 0x62a0u,
};

#pragma section n20762e
const unsigned short dat_0c22862e[] = {
    0x0085u, 0x6a20u, 0x0000u, 0xb5e0u, 0x0085u, 0x6ba0u, 0x0000u, 0x2180u,
    0x0086u, 0x68c0u,
};

#pragma section n207646
const unsigned short dat_0c228646[] = {
    0x0086u, 0x67c0u, 0x0000u, 0xf200u, 0x0086u, 0x6960u, 0x0000u, 0x5b60u,
    0x0087u, 0x6540u, 0x0000u, 0xc0a0u, 0x0087u, 0x6900u, 0x0000u, 0x29a0u,
    0x0088u, 0x6980u, 0x0000u, 0x9320u, 0x0088u, 0x71a0u,
};

#pragma section n207678
const unsigned short dat_0c228678[] = {
    0x68c0u, 0x0000u, 0x6d80u, 0x0089u, 0x67a0u, 0x0000u, 0xd520u, 0x0089u,
    0x6be0u, 0x0000u, 0x4100u, 0x008au, 0x66c0u, 0x0000u, 0xa7c0u, 0x008au,
    0x6960u, 0x0000u, 0x1120u, 0x008bu, 0x6780u, 0x0000u, 0x78a0u, 0x008bu,
    0x6980u, 0x0000u, 0xe220u, 0x008bu, 0x64a0u,
};
