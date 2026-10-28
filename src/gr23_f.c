typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC: ./tryee.sh src/sa4_b.c sn */
typedef struct VT { u8 pad0[0x18]; s32 (*m18)(); s32 (*m1c)(); s32 (*m20)(); s32 (*m24)(); } VT;
typedef struct OB { VT *vt; } OB;
typedef struct EN { u8 pad[8]; OB *o; } EN;

typedef struct PX { u8 p0[8]; EN *e[8]; } PX;
extern s32 func_00408CE0(EN *);
extern void func_00408EC8(EN *);

void func_0040EAD0(u8 *p) {
    EN **a1;
    s32 cnt;
    s32 i;
    s32 buf[4];
    if (*(s8 *)(p + 0x48) == 1) {
        cnt = 0;
        for (i = 0; i < *(s8 *)(p + 0x26); i++) {
                if (func_00408CE0(((PX *)p)->e[i + 2]) != 1) {
                    OB *o = ((PX *)p)->e[i]->o;
                    if (o->vt->m24(o, 0) == *(s32 *)(p + 0x54)) {
                        cnt = cnt + 1;
                    }
                }
        }
        if (cnt == *(s8 *)(p + 0x26)) {
            i = 0;
            if (cnt > 0) {
                cnt = (s32)(p + 0x10);
                a1 = (EN **)((s32)p + 8);
                do {
                    OB *o;
                    o = a1[0]->o;
                    o->vt->m18(o, 0, 0x7FFFFFFF, buf);
                    { EN *e = a1[0]; e->o->vt->m20(e->o, 0, buf); }
                    o = a1[0]->o;
                    o->vt->m18(o, 0, 0x7FFFFFFF, buf);
                    if (buf[1] != *(s32 *)(p + 0x54)) {
                        for (;;) { __asm__ volatile("nop"); }
                    }
                    o = a1[0]->o;
                    a1++;
                    i++;
                    o->vt->m20(o, 0, buf);
                    *(u8 *)(p + 0x4B) = 0;
                    func_00408EC8(*(EN **)cnt);
                    cnt = cnt + 4;
                } while (i < *(s8 *)(p + 0x26));
            }
        }
    }
}
