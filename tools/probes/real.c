typedef unsigned int u32;
typedef unsigned char u8;

u32 probe_102520(u32 value) {
    if ((value >> 28) == 7) {
        value = (value & 0x0fffffff) | 0x80000000;
    }
    return value;
}

void probe_102548(u8 *dst, u32 count) {
    while (count != 0) {
        *dst++ = 0;
        count--;
    }
}

extern int probe_table[10];

int probe_102580(u32 index) {
    if (index < 10) {
        return probe_table[index];
    }
    return 0;
}

u32 probe_102898(u32 value) {
    volatile u32 *reg = (volatile u32 *)0x1000e060;
    u32 old = *reg;
    *reg = value;
    return old;
}

u32 probe_102c58(volatile u32 *p, u32 value) {
    u32 old = *p;
    *p = value;
    return (old >> 8) & 1;
}
