typedef unsigned int u32;
typedef const char *CStrPtr;
typedef struct { CStrPtr formatArgument; CStrPtr sourcePath; u32 word08; } ArchiveEntry;
typedef char ArchiveEntry_size_check[(sizeof(ArchiveEntry) == 12) ? 1 : -1];
/* func_004189A0 walks rows 0..3 at stride 0xC (addiu $s1, 0xC; slti 4).
 * word0 is the %s argument for D_004BEE18/D_004BEE20; word1 is passed to
 * func_003FBE88. word08 is not read by that loop; it is typed as u32 to match
 * the s32 third member of the Ro record in src/w20b0_o.c. */
extern const char gArchiveName_004BEDD8[];
extern const char gArchiveName_004BEDE8[];
extern const char gArchiveName_004BEDF8[];
extern const char gArchiveName_004BEE08[];
extern char gArchivePath_006334D0[];
extern char gArchivePath_006332A0[];
extern char gArchivePath_006329D0[];
extern char gArchivePath_006328B0[];
ArchiveEntry data_archive_entries_004A6A60[4] = {
    { gArchiveName_004BEDD8, gArchivePath_006334D0, 0x28u },
    { gArchiveName_004BEDE8, gArchivePath_006332A0, 0x8Cu },
    { gArchiveName_004BEDF8, gArchivePath_006329D0, 0x3D7u },
    { gArchiveName_004BEE08, gArchivePath_006328B0, 0x1u },
};
