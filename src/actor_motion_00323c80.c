typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
extern int func_00175700(u8 *);extern void func_001830D0(void *,void *,s32);
typedef struct { u8 pad0[0x6]; u8 f6; u8 pad7[0x15]; s16 f1C; u8 pad1E[0x133]; s8 f151; u8 pad152[0x117]; u8 f269; u8 pad26A[0xd2]; u8 f33C; u8 pad33D[0xc7]; u8 f404; u8 f405; u8 pad406[0x6]; u8 f40C; } P323;
void func_00323C80(P323 *p) {
    u32 v[3];
    u32 t;
    p->f40C = 2;
    p->f33C = 5;
    p->f405 = (p->f269 == 6) ? 2 : 0;
    func_00175700((u8 *)p);
    if (p->f151 != 0) {
        p->f404 = 0;
        p->f405 = 0;
        t = p->f6; p->f6 = t + 1; p->f151 = 0; p->f1C = 0xF0; v[1] = 0x425EDB6D; v[0] = 0;
        func_001830D0(p, v, 1);
    }
}
