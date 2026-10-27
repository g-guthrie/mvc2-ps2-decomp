typedef signed int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_00107A68(void);
extern void func_00103E20(s32 v);
extern s32 D_00438304;
extern s32 func_00103CD0(void);
extern void func_00103B60(u32 a, void *b, s32 c);
extern s32 func_00103D00();
extern void func_00110748(void);
extern s32 func_00104990(s32 v);
extern void func_0040AE10(char *path);
extern char D_00488328[];
extern void func_003F88E0(void *p);
extern s16 D_004791F8[];
typedef struct { s8 flag; char pad[0x47]; } Slot;
extern Slot D_00488390[40];

Slot *func_00409C90(void) {
    Slot *r = 0;
    s32 i;
    for (i = 39; i >= 0; i--)
        if (D_00488390[39 - i].flag == 0) r = &D_00488390[39 - i];
    return r;
}
extern volatile s32 D_00488310[];
char *func_00409870(void) { s32 x = D_00488310[0]; func_0040AE10(0); return D_00488328; }
void func_003F8978(void) {
    s32 i;
    char *p = (char *)D_004791F8;
    for (i = 15; i >= 0; i--, p += 0xB0)
        if (*(s16 *)p == 1) func_003F88E0(p);
}
