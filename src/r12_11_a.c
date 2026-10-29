/* AIFF header parser (CRI ADX AIFF support): walks the FORM/AIFF chunk list for COMM and SSND. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

static inline s32 rd16(u8 **pp)
{
    u8 *c = *pp;
    s32 v = c[0];
    v |= c[1] << 8;
    *pp = c + 2;
    return v;
}
static inline s32 rd32(u8 **pp)
{
    u8 *c = *pp;
    s32 v = c[0] | (c[1] << 8) | (c[2] << 16) | (c[3] << 24);
    *pp = c + 4;
    return v;
}
#define BS16(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))
#define BS16W(x) ((((u32)(x) >> 8) | ((x) << 8 & ~0xFF)) & 0xFFFF)
#define BS32B(x) ((((u32)(x) >> 24) | ((x) << 24)) | ((((x) << 8) & 0xff0000) | (((x) >> 8) & 0xff00)))
#define BS32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

u8 *func_003F6510(u8 *cur, u32 *rate, u32 *chan, u32 *bits, u32 *frames)
{
    u8 *end;
    u8 *res;
    s32 comm;
    s32 ssnd;
    s32 magic, size, type, v, e;
    magic = rd32(&cur);
    size = rd32(&cur); size = BS32(size);
    type = rd32(&cur);
    res = 0;
    comm = 0;
    ssnd = 0;
    if (magic != 0x4D524F46) return 0;
    if (type != 0x46464941) return 0;
    end = cur + size - 4;
    if (cur < end) {
        do {
            magic = cur[0] | (cur[1] << 8) | (cur[2] << 16) | (cur[3] << 24);
            cur += 4;
            size = rd32(&cur); size = BS32(size);
            switch (magic) {
            case 0x4D4D4F43:
                if (!comm) {
                    if (size < 0x12) return 0;
                    v = rd16(&cur);
                    comm = 1;
                    *chan = BS16(v);
                    v = rd32(&cur); v = BS32B(v);
                    *frames = v;
                    v = rd16(&cur);
                    *bits = BS16(v);
                    e = rd16(&cur);
                    v = rd16(&cur);
                    cur += 6;
                    /* 80-bit extended sample rate: mantissa >> (0x400E - exponent) */
                    *rate = (s32)BS16W(v) >> (0x400E - BS16W(e));
                    if (ssnd) return res;
                }
                break;
            case 0x444E5353:
                if (!ssnd) {
                    u32 o;
                    ssnd = 1;
                    o = cur[0] | (cur[1] << 8) | (cur[2] << 16) | (cur[3] << 24);
                    cur += 4;
                    o = BS32(o);
                    res = cur + o;
                    if (comm) return res;
                }
                break;
            default:
                cur += (size + 1) & -2;
                break;
            }
        } while (cur < end);
    }
    return res;
}
