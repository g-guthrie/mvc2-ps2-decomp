typedef const char * CStrPtr;
typedef struct { CStrPtr formatArgument; CStrPtr sourcePath; } CStrPointerPair;
/* func_004189A0 selects rows 0..3. word0 supplies the %s argument to D_004BEE18/D_004BEE20; word1 is copied as a string by func_00406688 through func_00400468. */
extern const char gArchiveName_004BEDD8[];
extern char gArchivePath_006334D0[];
CStrPointerPair data_cstr_pointer_pair_004A6A60[1] = {
    { gArchiveName_004BEDD8, gArchivePath_006334D0 },
};
