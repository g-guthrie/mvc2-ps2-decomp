typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00270B10(u8 *);
extern void func_00183D10(u8 *);
extern void func_001B7C70(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_00275A80(u8 *);
extern void func_002761A0(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0028D810(u8 *, u8 *);
extern void func_0028D8B0(u8 *);
extern void func_00288E80(u8 *);
extern u8 D_00455D20[];
extern void func_001861B0(u8 *);
extern void func_00249DC0(u8 *);
extern void func_001B8AF0(u8 *);
extern void func_002705C0(u8 *);

typedef struct { u8 prefix[0x1B5]; u8 action; } ActorActionView;
typedef char ActorActionOffsetCheck[
    ((u32)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];

void func_00272690(u8 *p)
{
    p[6]++;
    func_00270B10(p);
    func_00183D10(p);
    p[437] = 73;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 9);
    func_001B7C70(p, 2);
}

void func_00276110(u8 *p)
{
    p[6] = 1;
    func_00275A80(p);
    p[437] = 50;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_001757E0(p, 21, 21);
    func_002761A0(p);
}

void residual_00288DF0(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_0028D810(p, D_00455D20);
    func_0028D8B0(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    func_001757E0(p, 19, 5);
    func_00288E80(p);
}

void func_00271E00(u8 *p)
{
    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    p[6]++;
    p[437] = 67;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00270B10(p);
    func_001B8AF0(p);
    func_001757E0(p, 22, 2);
}

void func_00270520(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[6]++;
        *(u32 *)(p + 0x5C) = 0x41A00000;
        *(u32 *)(p + 0x68) = 0xBF200000;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (p[0x1E6]) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_002705C0(p);
    }
}

void func_00249D20(u8 *p)
{
    u32 t;
    p[6]++;
    func_001861B0(p);
    p[437] = 22;
    p[525] = 1;
    func_001757E0(p, 20, 3);
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00249DC0(p);
}
