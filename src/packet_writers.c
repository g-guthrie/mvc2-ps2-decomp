/* Native packet writers sharing truthful helper codegen/clobber information. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef struct {
    u8 pad0[4];
    u8 *currentPacket;
    s32 usedWords;
    u8 pad0C[4];
    u8 *buffer;
    s32 capacityWords;
    u8 pad18[2];
    s16 lastN;
    s16 packetCount;
} PacketWriter;

static s32 func_00420A00(s32 *p)
{
    s32 x = p[2];
    return (s32)((u8 *)p[4] + (x << 3) + 16);
}

static s32 func_00420A20(s32 *p, s32 a1)
{
    s32 v = p[2] + a1;
    if (p[5] < v)
        return 0;
    p[2] = v;
    return 1;
}

s32 func_00420AB0(PacketWriter *writer, s64 first, s64 second)
{
    u64 *packet = (u64 *)func_00420A00((s32 *)writer);

    if (func_00420A20((s32 *)writer, 2) == 0)
        return 0;
    packet[0] = (u64)second;
    packet[1] = (u64)first;
    writer->packetCount++;
    return 1;
}

s32 func_00420B30(PacketWriter *writer, u64 value, s32 n)
{
    u64 *packet = (u64 *)func_00420A00((s32 *)writer);

    if (func_00420A20((s32 *)writer, 2) == 0)
        return 0;
    writer->currentPacket = (u8 *)packet;
    packet[0] = 0x0400000000008000ULL | ((u64)(s64)n << 60);
    packet[1] = value;
    writer->lastN = (s16)n;
    return 1;
}
