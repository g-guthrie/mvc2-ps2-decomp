typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
typedef struct { u8 p0[2]; u8 b2; u8 p1[0x31]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0xCC]; u8 b13C; u8 p5[0x103]; u8 b140[1];} X_00395ED0;
extern G *D_004C2794;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; } A_002D3B50;
extern u8 D_004B75B0[];
extern void (*D_0045A500[])(A_002D3B50 *);

void func_00395ED0(u8 *a, u8 *b)
{
    extern void func_001757E0(u8 *, s32, s32);
    f32 c;
    a[0x1B0] = 0x40;
    a[0x1B1] = 0;
    a[0x1B5] = 0x43;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    a[0x13C] = 1;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(s32 *)(a + 0x5C) = 0;
    *(s32 *)(a + 0x60) = 0;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x6C) = 0;
    *(f32 *)(a + 0x38) += 201.42855834960938f;
    *(u32 *)(a + 0x60) = 0x414DB6DB;
    *(u32 *)(a + 0x6C) = 0xBF092492;
    if (*(s16 *)(b + 0x140) != 0) *(f32 *)(a + 0x34) += 118.33332824707031f;
    else *(f32 *)(a + 0x34) += -118.33332824707031f;
    *(f32 *)(a + 0x5C) = (*(f32 *)(*(u8 **)(b + 0x220) + 0x34) - *(f32 *)(b + 0x34)) / 64.0f;
    func_001757E0(a, 0x13, 6);
}

void func_002D3B50(A_002D3B50 *p)
{
    extern void func_002D3D10(A_002D3B50 *);
    extern s8 func_00175700(A_002D3B50 *);
    extern void func_001843A0(A_002D3B50 *);
    u8 *a = (u8 *)p;
    f32 z;
    f32 *v1, *a0;
    func_002D3D10(p);
    if (func_00175700(p) < 0) {
        *(s32 *)&p->f5c = 0;
        *(s32 *)&p->f60 = 0;
        *(s32 *)&p->f68 = 0;
        *(s32 *)&p->f6c = 0;
        func_001843A0(p);
        return;
    }
    if (a[0x15B] != 0) {
        a[0x1B5] = D_004B75B0[a[0x15B]];
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        a[0x15B] = 0;
    }
    D_0045A500[*(s8 *)(a + 0x151)](p);
    z = 0.0f;
    v1 = &p->f5c;
    a0 = &p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f5c * p->f68 > z) {
        *v1 = z;
        *a0 = z;
    }
}
