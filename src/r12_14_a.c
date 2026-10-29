typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_004239D0(u32, s32, s32, s32);
extern s32 func_00423AA0(const u32 *);
extern s32 func_00423B70(s32, s32, s32, s32, s32, s32);
extern s32 func_00423D00(u32, s32);
extern s32 func_00423DA0(u32, s32, s32);

s32 func_00423E30(u32 *p)
{
    s32 c;
    s32 w;
    s32 r;

    w = p[0];
    c = w >> 24;

    if (c == 0x7F) return 0;
    r = -1;
    if (c == -1) return 0;
    switch (c & 0xF0) {
    case 0x00:
        return func_004239D0(w, ((u8 *)p)[4], ((u8 *)p)[5], *(u16 *)((u8 *)p + 6));
    case 0x20:
        if (c & 8) {
            r = (c == 0x29) ? func_00423D00(w, 3) : func_00423D00(w, 1);
        } else if (c == 0x22 || c == 0x20 || c == 0x24 || c == 0x23) {
            r = func_00423D00(w, 3);
        } else {
            r = func_00423D00(w, 2);
        }
        break;
    case 0x30:
    case 0x70:
        if (c == 0x38 || c == 0x30 || c == 0x31 || c == 0x71 || c == 0x73) {
            r = func_00423D00(w, 2);
        } else if (c == 0x37 || c == 0x39 || c == 0x3A || c == 0x3B || c == 0x3D || c == 0x72 || c == 0x75) {
            r = func_00423D00(w, 3);
        } else if (c == 0x36 || c == 0x74) {
            r = func_00423D00(w, 4);
        } else if (c == 0x77 || c == 0x3C || c == 0x3E) {
            r = func_00423B70(w, 5, ((u8 *)p)[4], 0, 0, 0);
        } else if (c == 0x3F) {
            r = func_00423B70(w, 7, ((u8 *)p)[4], ((u8 *)p)[5], ((u8 *)p)[6], 0);
        } else {
            r = (c == 0x35) ? func_00423AA0(p) : func_00423D00(w, 1);
        }
        break;
    case 0x40:
        if (c == 0x47 || c == 0x48 || c == 0x49 || c == 0x4A || c == 0x41 || c == 0x42) {
            r = func_00423D00(w, 2);
        } else if (c == 0x4B) {
            r = func_00423D00(w, 3);
        } else if (c == 0x45 || c == 0x4C) {
            r = func_00423D00(w, 4);
        } else if (c == 0x44) {
            r = func_00423B70(w, 6, ((u8 *)p)[4], ((u8 *)p)[5], 0, 0);
        } else if (c == 0x4D || c == 0x4E) {
            r = func_00423DA0(w, 3, 0x15);
        } else {
            r = (c == 0x4F) ? func_00423B70(p[1], 6, (u8)(w >> 8), (u8)w, 0, 0) : func_00423D00(w, 1);
        }
        break;
    case 0x60:
    case 0x50:
        r = func_00423D00(w, 2);
        break;
    }
    return r;
}
