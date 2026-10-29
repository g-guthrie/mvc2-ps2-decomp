/* func_0040E008: EE GCC 2.96, ./tryee.sh src/r13_11_a.c sn 0 O2. Events are written as evs[n].x
 * (not through a separate ev pointer), so loop strength reduction creates the ev giv
 * and its init copy lands last in the preheader, as in retail. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s8 b0;
    u8 pad1[0x20 - 0x01];
    void *w20;
    s8 b24;
    s8 b25;
    s8 b26;
    s8 b27;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    s32 w38[2];
    s32 w40[2];
    u8 pad48[0x4A - 0x48];
    s8 b4A;
    s8 b4B;
    u8 pad4C[0x58 - 0x4C];
} PadEnt;

typedef struct {
    s16 type;
    void *id;
    s32 a;
    s32 b;
} PadEv;

typedef struct {
    s32 n;
    u8 pad4[0xC];
    PadEv ev[0x80];
} PadQ;

extern PadEnt D_0048FD38[8];
extern s32 D_0048DB98[];

void func_0040E008(s32 unused, PadQ *q)
{
    PadEnt *e;
    PadEv *ev;
    PadEv *evs;
    s32 n;
    s32 i;
    s32 k;
    s32 v;

    n = 0;
    evs = q->ev;
    i = 0;
    do {
        e = &D_0048FD38[i];
        if (e->b0 != 1) goto next;
        if (n == 0x80) break;
        if (e->b4B != e->b4A) {
            evs[n].type = 8;
            evs[n].id = e->w20;
            evs[n].a = e->b4B;
            n++;
            e->b4A = e->b4B;
        }
        if (n == 0x80) break;
        if (*(u16 *)&e->b24 == 0x100) {
            evs[n].type = 2;
            evs[n].id = e->w20;
            evs[n].a = e->b24;
            n++;
            e->b25 = e->b24;
        }
        if (n == 0x80) break;
        if (e->b26 != e->b27) {
            evs[n].type = 3;
            evs[n].id = e->w20;
            evs[n].a = e->b26;
            n++;
            e->b27 = e->b26;
        }
        if (n == 0x80) break;
        if (e->w28 != e->w2C) {
            evs[n].type = 4;
            evs[n].a = e->w28;
            e->w2C = e->w28;
            evs[n].id = e->w20;
            n++;
        }
        if (n == 0x80) break;
        v = e->w30;
        if (v != e->w34) {
            evs[n].b = D_0048DB98[-v];
            evs[n].a = 0;
            e->w34 = e->w30;
            evs[n].type = 5;
            evs[n].id = e->w20;
            n++;
        }
        if (n == 0x80) break;
        if (n == 0x7F) break;
        for (k = 0; k < e->b26; k++) {
            if (e->w38[k] != e->w40[k]) {
                evs[n].type = 9;
                evs[n].a = k;
                evs[n].b = e->w38[k];
                evs[n].id = e->w20;
                    n++;
                e->w40[k] = e->w38[k];
            }
        }
        if (n == 0x80) break;
        if (*(u16 *)&e->b24 == 1) {
            evs[n].type = 2;
            evs[n].id = e->w20;
            evs[n].a = e->b24;
            n++;
            e->b25 = e->b24;
        }
        if (n == 0x80) break;
    next:
        i++;
    } while (i < 8);
    q->n = n;
}
