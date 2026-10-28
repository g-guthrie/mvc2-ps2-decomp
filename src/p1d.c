/* MWCC 3.0.3 -O3 -Op -sdatathreshold 0 (try.sh src/p1d.c "-O3 -Op -sdatathreshold 0"). */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

/* Variable-length entry: mask word, unused word, byte size of the entry. */
typedef struct {
    u32 mask;
    u32 pad;
    s32 size;
} E;

/* Static copy of the real leaf at 0x003F1F00 (src/gp_small_accessors.c):
 * it returns the file header, whose words are { mask, entry count }. */
static u32 *func_003F1F00(void *file) { return file; }

E *func_003F1F10(E *e, u32 m) {
    u32 *h = func_003F1F00(e);
    u32 i;
    if (h[0] & m) {
        e = (E *)((u8 *)e + 12);
        for (i = 0; i < h[1]; i++) {
            if (e->mask & m) return e;
            e = (E *)((u8 *)e + e->size);
        }
    }
    return 0;
}
