typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern s8 func_00175670(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern void func_0028D8B0(u8 *);
extern void func_001C3EC0(u8 *, int);
extern void func_00290E30(u8 *);
extern void func_00294BC0(u8 *);
extern void func_001C09A0(u8 *, int);
extern void func_00386510(u8 *);
extern void func_003872E0(u8 *);
extern void func_00387BE0(u8 *);
extern void func_00186A20(u8 *);
extern void func_00255620(u8 *);
extern void func_00126400(void);
extern void func_0011D8F8(void *, int, int);
extern void func_00179150(u8 *, u8 *);
extern void func_003B5530(u8 *);
extern void func_001CCB50(u8 *);
extern void func_00199460(u8 *);
extern void func_003DAA40(u8 *);
extern void func_0034B040(u8 *);
extern void func_00123090(void);
extern void func_00151A20(int);
extern void func_001520E0(int);
extern void func_0016B0C0(u8 *, u8 *, int);
extern void func_00185490(u8 *);
extern void func_0034FA60(u8 *);

void func_0028C130(u8 *p) {
    u8 *q = p + 696;
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        q[9] = 1;
    }
}
void func_002934A0(u8 *p) {
    u8 *q = p + 696;
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        q[9] = 1;
    }
}

void func_0028AE60(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
    }
    func_0028D8B0(p);
}
void func_0028B770(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
    }
    func_0028D8B0(p);
}

void func_0028CEC0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_001C3EC0(p, p[722]);
    }
}
void func_00294210(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_001C3EC0(p, p[722]);
    }
}

void func_0028FA60(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        p[6] = 0;
        *(f32 *)(p + 52) = *(f32 *)(p + 100);
    }
}
void func_0028FDE0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        p[6] = 0;
        *(f32 *)(p + 52) = *(f32 *)(p + 100);
    }
}

void func_002FEA00(u8 *p) {
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0)
        func_001843A0(p);
}
void func_00307420(u8 *p) {
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0)
        func_001843A0(p);
}

void func_002921D0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
    }
    func_00294BC0(p);
}
void func_00292AE0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
    }
    func_00294BC0(p);
}

void func_002C1FD0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0;
    }
}
void func_002C2190(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0;
    }
}

void func_003137D0(u8 *p) {
    if ((s8)p[337] != 0)
        p[337] = 0;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
void func_00313A50(u8 *p) {
    if ((s8)p[337] != 0)
        p[337] = 0;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_001C3290(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        func_001C09A0(p, 51);
    }
}
void func_001C33E0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        func_001C09A0(p, 51);
    }
}

void func_001F3E00(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[537] = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}
void func_001F5690(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[537] = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

void func_00288B60(u8 *p) {
    if (*(s16 *)(p + 28) == 0) {
        p[7]++;
        func_001757E0(p, 19, 6);
    }
    func_00175700(p);
}
void func_00290450(u8 *p) {
    if (*(s16 *)(p + 28) == 0) {
        p[7]++;
        func_001757E0(p, 19, 6);
    }
    func_00175700(p);
}

void func_0028BC70(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_00386510(p);
    }
}
void func_00292FE0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_00386510(p);
    }
}

void func_0028BDE0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_003872E0(p);
    }
}
void func_00293150(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_003872E0(p);
    }
}

void func_0028BFC0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_00387BE0(p);
    }
}
void func_00293330(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        p[337] = 0;
        func_00387BE0(p);
    }
}



void func_001A8140(u8 *p) {
    if ((*(u8 **)(p + 8))[4] >= 2) {
        p[4]++;
        p[316] = 0;
    } else {
        func_00175670(p);
    }
}
void func_001A87F0(u8 *p) {
    if ((*(u8 **)(p + 8))[4] >= 2) {
        p[4]++;
        p[316] = 0;
    } else {
        func_00175670(p);
    }
}

void func_00216570(u8 *p) {
    u8 *q = p + 696;
    if (p[532] != 0)
        p[537] = 24;
    else
        p[537] = 0;
    if (q[0] != 0 && p[525] != 2)
        q[0] = 0;
}
void func_0031B960(u8 *p) {
    u8 *q = p + 696;
    if (p[532] != 0)
        p[537] = 24;
    else
        p[537] = 0;
    if (q[0] != 0 && p[525] != 2)
        q[0] = 0;
}

void func_0021C590(u8 *p, u8 *q) {
    func_001266A0(p, 1, 1);
    func_00178F20(p, q);
}
void func_00321E40(u8 *p, u8 *q) {
    func_001266A0(p, 1, 1);
    func_00178F20(p, q);
}

void func_0021BED0(u8 *p, u8 *q) {
    func_001266A0(p, 5, 5);
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00178F20(p, q);
}
void func_00321780(u8 *p, u8 *q) {
    func_001266A0(p, 5, 5);
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00178F20(p, q);
}

void func_00228300(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[6]++;
        func_00186A20(p);
    }
}
void func_002D3E90(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[6]++;
        func_00186A20(p);
    }
}

void func_00240620(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 104) = 0;
        func_001843A0(p);
    }
}
void func_0026D2D0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 104) = 0;
        func_001843A0(p);
    }
}



void func_002891A0(u8 *p) {
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
void func_00289340(u8 *p) {
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_002A5850(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00126400();
        func_001843A0(p);
    }
}
void func_002F4210(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00126400();
        func_001843A0(p);
    }
}



void func_002BF810(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (q[347] != 0)
        func_00179150(q, p);
    else
        func_00178F20(q, p);
}
void func_002D5EF0(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (q[347] != 0)
        func_00179150(q, p);
    else
        func_00178F20(q, p);
}





void func_001F15E0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[537] = 0;
        func_001843A0(p);
    }
}
void func_001F1DD0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[537] = 0;
        func_001843A0(p);
    }
}



void func_00260CF0(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    {
        s16 t = *(s16 *)(p + 28);
        *(s16 *)(p + 28) = t - 1;
        if (t == 0) {
            p[6]++;
            *(s16 *)(p + 28) = 10;
        }
    }
    func_00175700(p);
}
void func_00260D30(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    {
        s16 t = *(s16 *)(p + 28);
        *(s16 *)(p + 28) = t - 1;
        if (t == 0) {
            p[6]++;
            *(s16 *)(p + 28) = 10;
        }
    }
    func_00175700(p);
}

int func_0028D9B0(u8 *p) {
    u8 *q = p + 696;
    if (p[704] != 0) {
        q[8] = 0;
        q[13]++;
        p[436] = (s8)p[436] + 6;
        return 1;
    }
    return 0;
}
int func_00294CC0(u8 *p) {
    u8 *q = p + 696;
    if (p[704] != 0) {
        q[8] = 0;
        q[13]++;
        p[436] = (s8)p[436] + 6;
        return 1;
    }
    return 0;
}

void func_0020AB20(u8 *p) {
    p[316] = 0;
    func_00199460(p);
    func_001757E0(p, 19, 3);
}
void func_0020AB60(u8 *p) {
    p[316] = 0;
    func_00199460(p);
    func_001757E0(p, 19, 3);
}

void func_0021C900(u8 *p) {
    if (p[523] == 1 && *(s16 *)(p + 28) != 0)
        func_00175700(p);
}
void func_003221B0(u8 *p) {
    if (p[523] == 1 && *(s16 *)(p + 28) != 0)
        func_00175700(p);
}

void func_0028ACE0(u8 *p, u8 *q) {
    if (--*(s16 *)(p + 28) == 0) {
        q[24]++;
        *(s16 *)(p + 28) = 24;
    }
}
void func_00292050(u8 *p, u8 *q) {
    if (--*(s16 *)(p + 28) == 0) {
        q[24]++;
        *(s16 *)(p + 28) = 24;
    }
}

void func_001D3480(u8 *p) {
    if (p[5] == 0)
        p[5]++;
    else
        func_003DAA40(p);
}
void func_003A0E40(u8 *p) {
    if (p[5] == 0)
        p[5]++;
    else
        func_003DAA40(p);
}

void func_0034AC90(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) {
        p[4]++;
        p[316] = 0;
    }
}
void func_003B8940(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_0019F920(u8 *p) {
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
}
void func_00350C90(u8 *p) {
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
}

void func_001F7060(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if ((s8)q[353] != 0)
        func_00178F20(q, p);
}
void func_001F7090(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if ((s8)q[353] != 0)
        func_00178F20(q, p);
}

void func_0021BC00(u8 *p, u8 *q) {
    p[337] = 6;
    *(u8 **)(q + 456) = p;
    q[522] = 1;
    q[486] = p[486];
    q[437] = 32;
    q[525] = 2;
    func_00126400();
}
void func_003214B0(u8 *p, u8 *q) {
    p[337] = 6;
    *(u8 **)(q + 456) = p;
    q[522] = 1;
    q[486] = p[486];
    q[437] = 32;
    q[525] = 2;
    func_00126400();
}

void func_0034A9C0(u8 *p) {
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
    func_0034B040(p);
}
void func_0034AD60(u8 *p) {
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
    func_0034B040(p);
}

void func_0036FCC0(u8 *p) {
    if ((*(u8 **)(p + 24))[6] == 8)
        func_00175700(p);
}
void func_0036FF30(u8 *p) {
    if ((*(u8 **)(p + 24))[6] == 8)
        func_00175700(p);
}

void func_001B2C90(u8 *p) {
    if ((*(u8 **)(p + 24))[484] != 22)
        p[4]++;
    else if ((s8)p[339] >= 0)
        func_00175670(p);
}
void func_001B2F40(u8 *p) {
    if ((*(u8 **)(p + 24))[484] != 22)
        p[4]++;
    else if ((s8)p[339] >= 0)
        func_00175670(p);
}

void func_00152790(void) {
    func_00123090();
    func_00151A20(13);
    func_001520E0(13);
}
void func_00152930(void) {
    func_00123090();
    func_00151A20(13);
    func_001520E0(13);
}

void func_001F36C0(u8 *p) {
    u8 *q = p + 696;
    if ((s8)p[337] != 0) {
        p[7]++;
        q[2] = 0;
    }
    func_00175700(p);
}
void func_001F4FA0(u8 *p) {
    u8 *q = p + 696;
    if ((s8)p[337] != 0) {
        p[7]++;
        q[2] = 0;
    }
    func_00175700(p);
}

void func_00389170(u8 *p, u8 *q) {
    if ((s8)q[337] == 0) {
        p[4]++;
        p[316] = 0;
    }
}
void func_003898C0(u8 *p, u8 *q) {
    if ((s8)q[337] == 0) {
        p[4]++;
        p[316] = 0;
    }
}

int func_00166D60(u8 *p, u8 *q) {
    func_0016B0C0(p, q, 0);
    return 1;
}
int func_00166EA0(u8 *p, u8 *q) {
    func_0016B0C0(p, q, 0);
    return 1;
}

void func_00191ED0(u8 *p) {
    p[533] = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DBu;
    func_00184540(p);
}
void func_002E2F10(u8 *p) {
    p[533] = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DBu;
    func_00184540(p);
}

void func_0022C700(u8 *p) {
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00185490(p);
}
void func_002D3230(u8 *p) {
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00185490(p);
}

void func_0028B2B0(u8 *p) {
    u8 *q = p + 696;
    if (--p[723] == 0) {
        u8 *r = *(u8 **)(q + 20);
        p[7] = r[0];
        q[27] = r[2];
        *(u8 **)(q + 20) = r + 4;
        q[24] = 0;
    }
}
void func_00292620(u8 *p) {
    u8 *q = p + 696;
    if (--p[723] == 0) {
        u8 *r = *(u8 **)(q + 20);
        p[7] = r[0];
        q[27] = r[2];
        *(u8 **)(q + 20) = r + 4;
        q[24] = 0;
    }
}

void func_0028B2F0(u8 *p) {
    u8 *q = p + 696;
    if (p[7] != 2) {
        p[7] = 2;
        q[24] = 0;
    }
}
void func_00292660(u8 *p) {
    u8 *q = p + 696;
    if (p[7] != 2) {
        p[7] = 2;
        q[24] = 0;
    }
}


