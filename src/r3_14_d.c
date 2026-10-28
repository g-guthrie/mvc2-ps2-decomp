/* EE GCC 2.96 ./tryee.sh sn 0 O2: 20/105 words, only s4<->s5 swap (o vs n) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct O;
typedef struct OV {
    s32 pad[6];
    void (*f18)(struct O *, s32, s32, s32 *);
    void (*f1c)(struct O *, s32, s32 *);
    void (*f20)(struct O *, s32, s32 *);
} OV;
typedef struct O { OV *vt; } O;

extern void func_0011D8F8(s32, s32, s32);
extern void func_004104E0(s32 *, s32, s32 *, s32 *);

s32 func_00402A18(u8 *a, s32 b, s32 c)
{
    register O *o __asm__("$20") = *(O **)(a + 0x14);
    s32 buf[4];
    s32 aux[4];
    s32 blk, tot, done, n, t;

    if (o == 0) return 0;
    blk = b * 18;
    tot = (c / 32) * blk;
    o->vt->f18(o, 0, tot, buf);
    n = buf[1] / blk * blk;
    done = n;
    func_0011D8F8(buf[0], 0, done);
    func_004104E0(buf, done, buf, aux);
    o->vt->f20(o, 1, buf);
    o->vt->f1c(o, 0, aux);
    o->vt->f18(o, 0, tot - done, buf);
    n = buf[1] / blk * blk;
    func_0011D8F8(buf[0], 0, n);
    done += n;
    func_004104E0(buf, n, buf, aux);
    o->vt->f20(o, 1, buf);
    o->vt->f1c(o, 0, aux);
    return (done / blk) << 5;
}
