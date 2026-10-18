/* MWCC 3.0.3 -O3 -Op -sdatathreshold 0 (try.sh src/p1d.c "-O3 -Op -sdatathreshold 0"). */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 mask;
    u32 count;
} H;
typedef struct {
    u32 mask;
    u32 pad;
    s32 size;
} E;

/* Recipe 2: static leaf so $a0/$a1 survive the call without a saved register. */
static H *func_003F1F00(void) { return (H *)0x1000; }

E *func_003F1F10(E *e, u32 m) {
    H *h = func_003F1F00();
    u32 i;
    if (h->mask & m) {
        e = (E *)((u8 *)e + 12);
        for (i = 0; i < h->count; i++) {
            if (e->mask & m) return e;
            e = (E *)((u8 *)e + e->size);
        }
    }
    return 0;
}
