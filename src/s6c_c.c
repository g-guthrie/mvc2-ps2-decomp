/* func_00173C80: MW 3.0.3 ./try.sh "-O3,p -sdatathreshold 8". Static copies of the real callees func_00173470/func_001734D0 tell MW the calls do not clobber $v0 (MW treats $v0 as live to the exit of a void function), so the else-branch temp takes $v1 as in retail. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x4C]; s8 b4C; } G_a;
typedef struct { u8 pad[0xC]; s8 c[3]; u8 pad2[9]; } T_a;
extern G_a *D_004C2840;
extern T_a D_004D1570[];
extern T_a D_004F7D30[];
extern T_a D_004D1370[];

static void func_00173470(u8 *p)
{
 --*(s16 *)(p+0x4da);
 if (*(s16 *)(p+0x4da)>0) return;
 *(s8 *)(p+0x4d3) ^= 1;
 if (*(s8 *)(p+0x4d2)==5) *(s16 *)(p+0x4da)=1;
 else if (*(s8 *)(p+0x4d3)!=0) *(s16 *)(p+0x4da)=40;
 else *(s16 *)(p+0x4da)=20;
}
typedef struct S1734D0 {
    char pad[1235];
    u8 f1235;
    char pad2[6];
    s16 f1242;
} S1734D0;
static void func_001734D0(S1734D0 *a0) {
    a0->f1242 = 40;
    a0->f1235 = 1;
}
void func_00173C80(u8 *p) {
    s8 i;
    s32 x;
    *(s16 *)(p + 0x4D4) -= 1;
    if (*(s16 *)(p + 0x4D4) == 0) {
        p[0x4D0] = 4;
        p[0x4D1] = 0;
        p[0x4D2] = 0;
        p[0x4D3] = 0;
        *(s16 *)(p + 0x4D4) = 0x3C;
        *(s16 *)(p + 0x4D6) = 0;
        *(s16 *)(p + 0x4D8) = 0;
        for (i = 0; i < 4; i++) {
            s8 *q = (s8 *)(p + i + 0x544);
            if (*q == 0x2D || *q == 0x2C) *q = 0x2A;
            x = p[0x551];
            if (x < 0x14) {
                if (D_004C2840->b4C != 7) {
                    D_004D1570[(u8)x].c[0] = *(s8 *)(p + 0x544);
                    D_004D1570[p[0x551]].c[1] = *(s8 *)(p + 0x545);
                    D_004D1570[p[0x551]].c[2] = *(s8 *)(p + 0x546);
                } else {
                    D_004F7D30[(u8)x].c[0] = *(s8 *)(p + 0x544);
                    D_004F7D30[p[0x551]].c[1] = *(s8 *)(p + 0x545);
                    D_004F7D30[p[0x551]].c[2] = *(s8 *)(p + 0x546);
                }
            }
            x = p[0x552];
            if (x < 0x14) {
                D_004D1370[(u8)x].c[0] = *(s8 *)(p + 0x544);
                D_004D1370[p[0x552]].c[1] = *(s8 *)(p + 0x545);
                D_004D1370[p[0x552]].c[2] = *(s8 *)(p + 0x546);
            }
        }
    } else {
        if (*(s16 *)(p + 0x4D6) != 0) *(s16 *)(p + 0x4D6) -= 1;
        if (*(s16 *)(p + 0x4D6) > 0) func_00173470(p);
        else func_001734D0((S1734D0 *)p);
    }
}
