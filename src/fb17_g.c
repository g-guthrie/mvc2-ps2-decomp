typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

void func_003DBD80(u8 *pkt, s32 a1, u32 addr, u32 total, s16 p4, s16 p5, s16 p6, s16 p7, s16 p8, s16 p9, s16 p10)
{
    extern void func_003DBA00(u8 *, s32, s32, s32);
    extern void func_003DBA90(u8 *, u32, u32, s32, s32);
    u32 i;
    u32 n;
    s32 s1;
    u8 *q;
    s32 t;
    u32 cnt;
    n = total / 0x70000;
    if (total % 0x70000 != 0) {
        n++;
    }
    if (n == 1) {
        s1 = p10;
    } else {
        switch (p6) {
        case 0:
        case 1:
            s1 = (s16)(0x70000 / (p9 << 2));
            break;
        case 2:
            s1 = (s16)(0x70000 / (p9 << 1));
            break;
        case 0x13:
            s1 = (s16)(0x70000 / p9);
            break;
        case 0x14:
            s1 = (s16)(0x70000 / (p9 >> 1));
            break;
        default:
            break;
        }
    }
    if (p5 == 0) {
        p5 = 1;
    }
    q = pkt;
    i = 0;
    if (i < n) {
    cnt = total >> 4;
    do {
        func_003DBA00(q, 6, 0, 0);
        *(u32 *)(q + 8) = 0x13000000;
        *(u32 *)(q + 0xC) = 0x51000006;
        *(u64 *)(q + 0x10) = 0x1000000000000004ULL;
        *(u64 *)(q + 0x18) = 0xE;
        *(u64 *)(q + 0x20) = ((u64)p4 << 32) | ((s64)p5 << 48) | ((u64)p6 << 56);
        *(u64 *)(q + 0x28) = 0x50;
        *(u64 *)(q + 0x30) = ((u64)p7 << 32) | ((s64)p8 << 48);
        *(u64 *)(q + 0x38) = 0x51;
        *(u64 *)(q + 0x40) = (u64)(s16)p9 | ((u64)(s16)s1 << 32);
        *(u64 *)(q + 0x48) = 0x52;
        *(u64 *)(q + 0x50) = 0;
        *(u64 *)(q + 0x58) = 0x53;
        if (i >= n - 1) {
            *(u64 *)(q + 0x60) = 0x0800000000008000ULL | (u64)cnt;
            *(u64 *)(q + 0x68) = 0;
            func_003DBA90(q + 0x70, cnt, addr, a1, 0);
            *(u32 *)(q + 0x78) = 0;
            *(u32 *)(q + 0x7C) = cnt | 0x51000000;
        } else {
            *(u64 *)(q + 0x60) = 0x0800000000007000ULL;
            *(u64 *)(q + 0x68) = 0;
            func_003DBA90(q + 0x70, 0x7000, addr, 0, 0);
            *(u32 *)(q + 0x78) = 0;
            *(u32 *)(q + 0x7C) = 0x51007000;
            addr += 0x70000;
            q += 0x80;
            p8 = (s16)(p8 + s1);
            t = p8 + (s16)s1;
            if (t > p10) {
                s1 = (s16)(p10 - p8);
            }
            cnt -= 0x7000;
        }
    i++;
    } while (i < n);
    }
}
