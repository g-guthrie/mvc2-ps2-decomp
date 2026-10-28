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

/* Provisional: this static duplicate must be replaced by the shared helper;
 * the format buffer extent and entry sizes are also unproved. */
static H *func_003F1F00(void *file) { return (H *)file; }

E *func_003F1F10(E *e, u32 m) {
    H *h = func_003F1F00(e);
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
