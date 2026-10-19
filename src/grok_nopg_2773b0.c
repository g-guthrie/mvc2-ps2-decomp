/* Metrowerks 3.0: ./try.sh src/grok_nopg_2773b0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00275A80(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_002774C0(u8 *);

void func_002773B0(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 5);
    p[437] = 55;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    if (p[525] == 2) {
        func_00185490(p);
        func_00175C00(p, 0);
        p[360] = 1;
        *(f32 *)(p + 92) = *(f32 *)(p + 92) / 16.0f;
        *(f32 *)(p + 96) = *(f32 *)(p + 96) / 8.0f;
        *(f32 *)(p + 108) = *(f32 *)(p + 108) / 64.0f;
        *(u32 *)(p + 104) = 0;
    } else {
        p[360] = 0;
        func_00275A80(p);
    }
    func_001757E0(p, 21, p[360]);
    func_001E3210(p, 5);
    func_002774C0(p);
}
