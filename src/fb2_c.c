typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern u8 D_0062BBA0[];

s32 func_003E06D0(u32 flags, s32 mode)
{
    extern u32 func_003DD160();
    extern void func_003DC2F0();
    u64 *q;
    u32 n;
    u64 s0;

    if (mode != 2) {
        q = (u64 *)func_003DD160(0x30, 0x10);
        n = 2;
    } else {
        q = (u64 *)func_003DD160(0x40, 0x10);
        n = 3;
    }
    q[0] = (u32)((n + 0x70000000) | 0x80000000);
    *(u32 *)((u8 *)q + 8) = 0x13000000;
    *(u32 *)((u8 *)q + 0xC) = n | 0x50000000;
    q[2] = (u32)(n - 1) | ((u64)0x10000000 << 32) | 0x8000;
    q[3] = 0xE;
    switch (flags & 0xF) {
    case 1:
        switch (flags & 0xF0) {
        case 0x10:
            switch (flags & 0xC00) {
            case 0:
                s0 = (u64)0x29 | ((u64)0x80 << 32);
                break;
            case 0x400:
                s0 = (u64)0xA4 | ((u64)0x80 << 32);
                break;
            case 0x800:
                break;
            }
            break;
        case 0:
            s0 = (u64)0xA8 | ((u64)0x80 << 32);
            break;
        case 0x20:
            s0 = 9;
            break;
        case 0x30:
            s0 = 6;
            break;
        case 0x40:
            s0 = 0x19;
            break;
        case 0x50:
            s0 = 0x16;
            break;
        default:
            return 0;
        }
        break;
    case 0:
        switch (flags & 0xF0) {
        case 0x10:
            s0 = (u64)0x6A | ((u64)0x80 << 32);
            break;
        case 0:
            s0 = (u64)0xAA | ((u64)0x80 << 32);
            break;
        case 0x20:
            s0 = 0x89;
            break;
        case 0x30:
            s0 = 0x46;
            break;
        case 0x40:
            s0 = 0x99;
            break;
        case 0x50:
            s0 = 0x56;
            break;
        default:
            return 0;
        }
        break;
    case 2:
        switch (flags & 0xF0) {
        case 0x10:
            s0 = 0x48;
            break;
        case 0:
            s0 = 0x88;
            break;
        case 0x30:
            s0 = 0x44;
            break;
        default:
            return 0;
        }
        break;
    case 3:
        switch (flags & 0xF0) {
        case 0:
            s0 = 2;
            break;
        case 0x20:
            s0 = 1;
            break;
        default:
            return 0;
        }
        break;
    case 4:
        switch (flags & 0xF0) {
        case 0x10:
            s0 = 0x58;
            break;
        case 0:
            s0 = 0x98;
            break;
        case 0x50:
            s0 = 0x54;
            break;
        default:
            return 0;
        }
        break;
    case 5:
        switch (flags & 0xF0) {
        case 0:
            s0 = 0x12;
            break;
        case 0x40:
            s0 = 0x11;
            break;
        default:
            return 0;
        }
        break;
    }
    switch (mode) {
    case 0:
        q[4] = s0;
        q[5] = 0x42;
        break;
    case 1:
        q[4] = s0;
        q[5] = 0x43;
        break;
    case 2:
        q[4] = s0;
        q[5] = 0x42;
        q[6] = s0;
        q[7] = 0x43;
        break;
    }
    func_003DC2F0((u32)q & 0xFFFFFFF, D_0062BBA0);
    return 1;
}
