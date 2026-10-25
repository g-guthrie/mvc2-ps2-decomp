typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);
extern u8 D_004D18E6;
typedef struct CallbackEntry CallbackEntry;
extern CallbackEntry *func_001CE4A0(void *, u8);
extern void func_002B9E60(u8 *);

void func_002B9F60(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1E) = 0;
    if ((*(u8 **)(p + 0x220))[1] == 0x26) {
        func_00185490(p);
        func_001757E0(p, 19, 4);
    } else if (D_004D18E6 && func_001CE4A0(p, 1)) {
        p[6] = 2;
        func_002B9E60(p);
    } else
        func_001757E0(p, 19, 0);
}
