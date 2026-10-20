typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {
    u8 pad[0x7C];
    s16 count[];
} Counts;
typedef struct {
    u8 pad[0x1B7];
    u8 special;
    u8 gap[0x124];
    int countdown;
} Owner;

extern Counts *D_004C2794;

void func_00379A60(u8 *p)
{
    Owner *owner = *(Owner **)(p + 0x18);
    u8 *state = p + 0xD0;
    u8 animation;
    if (*(s8 *)(p + 0x1B2)) {
        *(s16 *)(state + 4) = 1;
        owner->countdown = 8;
    }
    if (!p[0x23] && owner->countdown)
        --owner->countdown;
    if (owner->countdown) {
        p[0x1B0] = 0;
        p[0x1B1] = 0;

        if (owner->special) {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x44 : 0x45);
        } else {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x30 : 0x38);
        }
        p[0x1B5] = animation;
        *(s8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        D_004C2794->count[p[2]]++;
    } else {
        if ((int)p[0x23] % 2 == 0) {
            p[0x1B0] = 0x42;
            p[0x1B1] = 0x42;
        } else {
            p[0x1B0] = 0;
            p[0x1B1] = 0;
        }

        if (owner->special) {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x44 : 0x45);
        } else {
            animation = (u8)(((int)p[0x23] / 2) % 2 == 1 ? 0x30 : 0x38);
        }
        p[0x1B5] = animation;
        *(s8 *)(p + 0x1B2) = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        D_004C2794->count[p[2]]++;
    }
}
