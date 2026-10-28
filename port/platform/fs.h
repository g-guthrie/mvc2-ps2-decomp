/* File layer: AFS entries by (partition, index) read straight from the disc
 * image (C ports of port/tools/convert/iso.py and afs.py).
 *
 * The image is accessed through a FsSource (read_at callback), so the backing
 * store can be a stdio file (native), a MEMFS/IDBFS file (Emscripten), or an
 * in-memory buffer. Nothing here is 32-bit specific (64-bit offsets).
 *
 * Partitions as mounted by func_004189A0: ptid 0..3 = /PS2/AFS00..AFS03.AFS.
 */
#ifndef PORT_FS_H
#define PORT_FS_H
#include <stddef.h>
#include <stdint.h>

typedef struct FsSource {
    void *ctx;
    /* Read n bytes at absolute offset off into dst. Returns bytes read. */
    size_t (*read_at)(void *ctx, uint64_t off, void *dst, size_t n);
    void (*close)(void *ctx);
    uint64_t size;
} FsSource;

int fs_source_open_file(FsSource *src, const char *path); /* 0 = ok */
void fs_source_memory(FsSource *src, const void *data, size_t size);
void fs_source_close(FsSource *src);

/* ---- ISO9660 ---- */
typedef struct IsoFile {
    char path[96];      /* upper case, '/'-separated, ";1" stripped */
    uint32_t lba;
    uint32_t size;
} IsoFile;

typedef struct Iso {
    FsSource src;
    IsoFile *files;
    int n_files, cap_files;
} Iso;

int iso_open(Iso *iso, FsSource src);           /* takes ownership of src */
void iso_close(Iso *iso);
const IsoFile *iso_find(const Iso *iso, const char *path); /* case-insensitive */
/* Read [off, off+n) of a file. Returns bytes read. */
size_t iso_read(const Iso *iso, const IsoFile *f, uint64_t off, void *dst, size_t n);
/* Whole file into a malloc'd buffer (caller frees). */
uint8_t *iso_load(const Iso *iso, const char *path, size_t *size_out);

/* ---- AFS ---- */
typedef struct AfsEntry {
    uint32_t offset, size;
    char name[33];
} AfsEntry;

typedef struct Afs {
    const Iso *iso;
    IsoFile file;
    int ptid;
    int count;
    AfsEntry *entries;
} Afs;

int afs_open(Afs *afs, const Iso *iso, int ptid); /* 0 = ok */
void afs_close(Afs *afs);
int afs_find(const Afs *afs, const char *name);   /* -1 if absent */
/* malloc'd copy of entry `index` (caller frees), NULL on error. */
uint8_t *afs_load(const Afs *afs, int index, size_t *size_out);

/* Convenience: the four partitions mounted together. */
typedef struct GameDisc {
    Iso iso;
    Afs afs[4];
    int afs_ok[4];
} GameDisc;

int disc_open(GameDisc *d, const char *iso_path); /* 0 = ok */
int disc_open_source(GameDisc *d, FsSource src);
void disc_close(GameDisc *d);
uint8_t *disc_load(GameDisc *d, int ptid, int index, size_t *size_out);

#endif
