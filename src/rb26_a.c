typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 D_004C26CC;
static s32 func_001919B0(s32 n) {
    s32 r = 0;
    s32 sh = 0;
    do {
        r += (n % 10) << sh;
        n /= 10;
        sh += 4;
    } while (n != 0);
    return r;
}

static u16 func_00191920(u8 a, u8 b) {
    u16 lo = (b & 0xF) + ((D_004C26CC & 1) + (a & 0xF));
    u16 sum;
    if (lo > 9) {
        lo -= 10;
        lo |= 0x10;
    }
    sum = (b & 0xF0) + ((s16)lo + (a & 0xF0));
    {
        u16 r = sum;
        if (r > 0x99) {
            r = (u8)(r - 0xA0);
            D_004C26CC = 1;
        } else {
            D_004C26CC = 0;
        }
        return r;
    }
}

typedef struct { s16 pad[0x434 / 2]; s16 f434; } E_a;
typedef struct { u8 pad[0x18]; E_a *e[3]; } Ent_a;
typedef struct { u32 w[3]; } Row_a;
typedef struct { Row_a ent[1]; } G_a;
extern G_a *D_004C2794;

void func_00191A00(u32 *a, u32 *b)
{
    s32 val;
    Ent_a *en;
    u8 *q;
    s32 i;
    s32 idx;
    s32 off;
    s32 raw;

    *a = 0;
    *b = 0;
    raw = ((u8 *)D_004C2794)[0x3E];
    if (raw >= 0) {
        idx = (u8)raw;
        off = idx * 12;
        en = (Ent_a *)(off + (s32)D_004C2794);
        val = en->e[0]->f434;
        val += en->e[1]->f434;
        val += en->e[2]->f434;
        val = ((u32)val * 200) / 144;
        *b = func_001919B0(val);
        val = 0x300;
        for (i = 0; i < 3; i++) {
            if (((Ent_a *)(off + (s32)D_004C2794))->e[i]->f434 == 0x90) {
                D_004C26CC = 0;
                q = (u8 *)&val;
                ((u8 *)b)[0] = func_00191920(((u8 *)b)[0], q[0]);
                *(u8 *)((s32)b + 1) = func_00191920(((u8 *)b)[1], q[1]);
                *(u8 *)((s32)b + 2) = func_00191920(((u8 *)b)[2], q[2]);
                *(u8 *)((s32)b + 3) = func_00191920(((u8 *)b)[3], q[3]);
            }
        }
        *a = *b >> 12;
        *b = *b << 20;
    }
}
