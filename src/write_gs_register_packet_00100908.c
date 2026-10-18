typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned long long u64;

struct RuntimeState {
    u8 pad[6];
    s16 version;
};

struct GsPacket {
    u64 word[5];
};

extern struct RuntimeState *func_00100468(void);

void func_00100908(const struct GsPacket *packet)
{
    struct RuntimeState *state = func_00100468();

    switch (state->version) {
    case 1:
        *(volatile u64 *)0x12000000 = packet->word[0];
        *(volatile u64 *)0x12000070 = packet->word[2];
        *(volatile u64 *)0x12000080 = packet->word[3];
        *(volatile u64 *)0x120000C0 = packet->word[4];
        break;
    default:
        *(volatile u64 *)0x12000000 = packet->word[0];
        *(volatile u64 *)0x12000020 = packet->word[1];
        *(volatile u64 *)0x12000090 = packet->word[2];
        *(volatile u64 *)0x120000A0 = packet->word[3];
        *(volatile u64 *)0x120000E0 = packet->word[4];
        break;
    }
}
