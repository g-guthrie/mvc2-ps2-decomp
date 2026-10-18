typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
typedef struct { u8 pad[0xC]; s8 c; } H;
extern H *D_004C2A00;
extern G *D_004C2794;
extern u8 D_004C078C[4], D_004C0790[4], D_004C0794[4];
extern s16 D_004C27A4;

void func_0039B0B0(u8 *p) {
    extern void func_001757E0(); extern void func_001E7F60();
    s16 v;
    if (D_004C2A00->c != 0) {
        v = *(s16*)(p+0x1C) - 1;
        *(s16*)(p+0x1C) = v;
        if (v == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            *(f32*)(p+0x5C) = 0; 
            *(f32*)(p+0x60) = 0; 
            *(f32*)(p+0x68) = 0; 
            *(f32*)(p+0x6C) = 0; 
            p[0x1B5] = 0x3F;
            p[0x1B2] = *(u16*)(p+0x1C0) = 0;
            *(s32*)(p+0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            func_001757E0(p, 0x15, 0x12);
        }
        func_001E7F60(p);
    }
}

void func_002401F0(u8 *p) {
    extern s8 func_00175700(); extern void func_00184540();
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16*)(p+0x1C0) = 0;
            *(s32*)(p+0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
        break;
    }
}

void func_00274150(u8 *p) {
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0; p[0x1B5] = 9; *(u8**)(p+0x408) = D_004C078C; p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1; p[0x1B5] = 0xA; *(u8**)(p+0x408) = D_004C0790; p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2; p[0x1B5] = 0xB; *(u8**)(p+0x408) = D_004C0794; p[0x1BB] = 2;
        break;
    default:
        break;
    }
    *(volatile u8*)(p+0x1B5) = p[0x1B5];
    p[0x1B2] = *(u16*)(p+0x1C0) = 0;
    *(s32*)(p+0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 10, p[0x168]);
}

s32 func_001A1330(u8 *p, s32 n, u8 x) {
    extern u8 *func_003DA750(); extern void func_001A1400();
    u8 *head, *o;
    s32 i;
    if (D_004C27A4 <= n) return 0;
    if (n > 12) n = 12;
    i = 0;
    if (0 < n) do {
        o = func_003DA750(0, 3, 1);
        if (o != 0) {
            *(s16*)(o+0x26) = 0xC04;
            o[0x23] = i;
            o[0x20] = x;
            *(s16*)(o+0x1E) = n;
            *(void**)(o+0x10) = (void*)func_001A1400;
            *(u8**)(o+0x18) = p;
            if (i == 0) head = o;
        }
        i++;
    } while (i < n);
    *(u8**)(head+0x14) = o;
    return i;
}
