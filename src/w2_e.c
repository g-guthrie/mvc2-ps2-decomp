typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u32 func_003E0CB0(u32 c, s32 m)
{
    u8 v[4];
    s32 i;
    u8 t;
    v[0] = c >> 16;
    v[1] = c >> 8;
    v[2] = c;
    v[3] = c >> 24;
    if (m == 0) {
        i = 0;
        do {
            t = v[i];
            if (t == 0xFF) {
                v[i] = 0x80;
            } else if (t != 0) {
                v[i] = (u32)t >> 1;
                if (v[i] == 0) {
                    v[i] = 1;
                }
            }
            i++;
        } while (i < 4);
    } else {
        t = v[3];
        if (t == 0xFF) {
            v[3] = 0x80;
        } else if (t != 0) {
            v[3] = (u32)t >> 1;
            if (v[3] == 0) {
                v[3] = 1;
            }
        }
    }
    return (v[3] << 24) | (v[0] << 16) | (v[1] << 8) | v[2];
}
