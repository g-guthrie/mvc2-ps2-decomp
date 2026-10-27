typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_00282610(u8 *);
extern void func_00282680(u8 *);
extern void func_002825A0(u8 *);
extern void func_002823F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0030F650(u8 *);
extern u8 *D_004C2794 __attribute__((section(".sdata")));

extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D90(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001863F0();
extern void func_001EA110();
extern void func_001EA240();
extern void func_001EA280();
extern void func_001EA4D0();
extern void func_001EF450();
extern void func_001EF620();
extern void func_001EF690();
extern void func_001EF7A0();
extern void func_001FD3F0();
extern void func_001FD430();
extern void func_001FD6B0();
extern void func_001FD7A0();
extern void func_00209690();
extern void func_00209780();
extern void func_002097F0();
extern void func_002098E0();
extern void func_00211640();
extern void func_002116C0();
extern void func_00211740();
extern void func_00211860();
extern void func_0021E010();
extern void func_0021E0B0();
extern void func_0021E150();
extern void func_0021E460();
extern void func_00223B30();
extern void func_00223C10();
extern void func_00223CA0();
extern void func_00223D50();
extern void func_0022DA10();
extern void func_0022DA50();
extern void func_0022DA90();
extern void func_0022DBE0();
extern void func_0023AE90();
extern void func_0023AF00();
extern void func_0023AFE0();
extern void func_0023B070();
extern void func_002448B0();
extern void func_00244950();
extern void func_002449F0();
extern void func_00244AD0();
extern void func_00249280();
extern void func_002493F0();
extern void func_002495D0();
extern void func_002498D0();
extern void func_0024EB50();
extern void func_0024EBC0();
extern void func_0024ECB0();
extern void func_0024ED20();
extern void func_0025D550();
extern void func_0025D5C0();
extern void func_0025D650();
extern void func_0025D6D0();
extern void func_002636E0();
extern void func_00263850();
extern void func_00263970();
extern void func_00263B20();
extern void func_0026C020();
extern void func_0026C0F0();
extern void func_0026C190();
extern void func_0026C1D0();
extern void func_0026FEB0(u8 *);
extern void func_0026FFF0(u8 *);
extern void func_00270030(u8 *);
extern void func_00270070(u8 *);
extern void func_00274650();
extern void func_00274920();
extern void func_002749C0();
extern void func_00274B90();
extern void func_002875E0();
extern void func_002876B0();
extern void func_00287780();
extern void func_00287880();
extern void func_0028EED0();
extern void func_0028EFA0();
extern void func_0028EFE0();
extern void func_0028F050();
extern void func_00296390();
extern void func_002964C0();
extern void func_00296500();
extern void func_00296750();
extern void func_0029C520();
extern void func_0029C720();
extern void func_0029C840();
extern void func_0029C9A0();
extern void func_002A1E20();
extern void func_002A1FA0();
extern void func_002A2010();
extern void func_002A20F0();
extern void func_002A8270();
extern void func_002A82E0();
extern void func_002A8350();
extern void func_002A85A0();
extern void func_002B3A40();
extern void func_002B3AB0();
extern void func_002B3B20();
extern void func_002B3C00();
extern void func_002B94D0();
extern void func_002B9540();
extern void func_002B95B0();
extern void func_002B9620();
extern void func_002C1390();
extern void func_002C13D0();
extern void func_002C1410();
extern void func_002C1450();
extern void func_002C6740();
extern void func_002C6820();
extern void func_002C6950();
extern void func_002C6A70();
extern void func_002CCE00();
extern void func_002CCE70();
extern void func_002CCEB0();
extern void func_002CD020();
extern void func_002D24A0();
extern void func_002D2560();
extern void func_002D25A0();
extern void func_002D25E0();
extern void func_002E9F00();
extern void func_002EA080();
extern void func_002EA2C0();
extern void func_002EA3E0();
extern void func_002F3130();
extern void func_002F3170();
extern void func_002F3240();
extern void func_002F3280();
extern void func_002F7F30();
extern void func_002F8070();
extern void func_002F8100();
extern void func_002F8170();
extern void func_002FD1D0();
extern void func_002FD2D0();
extern void func_002FD340();
extern void func_002FD3B0();
extern void func_003016C0();
extern void func_00301840();
extern void func_00301940();
extern void func_00301A60();
extern void func_00305DE0();
extern void func_00305FE0();
extern void func_003061E0(u8 *);
extern void func_00306280();
extern void func_00310950();
extern void func_00310AE0();
extern void func_00310B50();
extern void func_00310F60();

void func_001EA040(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_001EA4D0(p); else func_001EA280(p); } else { if (p[525] == 1) func_001EA240(p); else func_001EA110(p); } }

void func_001EF810(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_001EF7A0(p); else func_001EF690(p); } else { if (p[525] == 1) func_001EF620(p); else func_001EF450(p); } }

void func_001FD7E0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_001FD7A0(p); else func_001FD6B0(p); } else { if (p[525] == 1) func_001FD430(p); else func_001FD3F0(p); } }

void func_00282320(u8 *p)
{
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    func_001863F0(p);
    if (p[530] == 1) {
        if (p[525] == 0)
            func_00282610(p);
        else
            func_00282680(p);
    } else {
        if (p[525] == 1)
            func_002825A0(p);
        else
            func_002823F0(p);
    }
}

void func_002095C0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002098E0(p); else func_002097F0(p); } else { if (p[525] == 1) func_00209780(p); else func_00209690(p); } }

void func_00211570(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00211860(p); else func_00211740(p); } else { if (p[525] == 1) func_002116C0(p); else func_00211640(p); } }

void func_0021DF40(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0021E460(p); else func_0021E150(p); } else { if (p[525] == 1) func_0021E0B0(p); else func_0021E010(p); } }

void func_00223A60(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00223D50(p); else func_00223CA0(p); } else { if (p[525] == 1) func_00223C10(p); else func_00223B30(p); } }

void func_0022DC20(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0022DBE0(p); else func_0022DA90(p); } else { if (p[525] == 1) func_0022DA50(p); else func_0022DA10(p); } }

void func_0023ADC0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0023B070(p); else func_0023AFE0(p); } else { if (p[525] == 1) func_0023AF00(p); else func_0023AE90(p); } }

void func_002447E0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00244AD0(p); else func_002449F0(p); } else { if (p[525] == 1) func_00244950(p); else func_002448B0(p); } }

void func_002491B0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002498D0(p); else func_002495D0(p); } else { if (p[525] == 1) func_002493F0(p); else func_00249280(p); } }

void func_0024EA80(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0024ED20(p); else func_0024ECB0(p); } else { if (p[525] == 1) func_0024EBC0(p); else func_0024EB50(p); } }

void func_0025D480(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0025D6D0(p); else func_0025D650(p); } else { if (p[525] == 1) func_0025D5C0(p); else func_0025D550(p); } }

void func_00263610(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00263B20(p); else func_00263970(p); } else { if (p[525] == 1) func_00263850(p); else func_002636E0(p); } }

void func_0026BF50(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0026C1D0(p); else func_0026C190(p); } else { if (p[525] == 1) func_0026C0F0(p); else func_0026C020(p); } }

void func_0026FDE0(u8 *p)
{
    if (p[530] == 1) {
        if (p[525] == 1)
            func_00270070(p);
        else
            func_00270030(p);
    } else if (p[525] == 1) {
        func_0026FFF0(p);
    } else {
        func_0026FEB0(p);
    }
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    func_001863F0(p);
}

void func_00274580(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00274B90(p); else func_002749C0(p); } else { if (p[525] == 1) func_00274920(p); else func_00274650(p); } }

void func_00287510(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00287880(p); else func_00287780(p); } else { if (p[525] == 1) func_002876B0(p); else func_002875E0(p); } }

void func_0028EE00(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0028F050(p); else func_0028EFE0(p); } else { if (p[525] == 1) func_0028EFA0(p); else func_0028EED0(p); } }

void func_002962C0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00296750(p); else func_00296500(p); } else { if (p[525] == 1) func_002964C0(p); else func_00296390(p); } }

void func_0029C450(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_0029C9A0(p); else func_0029C840(p); } else { if (p[525] == 1) func_0029C720(p); else func_0029C520(p); } }

void func_002A1D50(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002A20F0(p); else func_002A2010(p); } else { if (p[525] == 1) func_002A1FA0(p); else func_002A1E20(p); } }

void func_002A81A0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002A85A0(p); else func_002A8350(p); } else { if (p[525] == 1) func_002A82E0(p); else func_002A8270(p); } }

void func_002B3970(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002B3C00(p); else func_002B3B20(p); } else { if (p[525] == 1) func_002B3AB0(p); else func_002B3A40(p); } }

void func_002B9400(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002B9620(p); else func_002B95B0(p); } else { if (p[525] == 1) func_002B9540(p); else func_002B94D0(p); } }

void func_002C12C0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002C1450(p); else func_002C1410(p); } else { if (p[525] == 1) func_002C13D0(p); else func_002C1390(p); } }

void func_002C6670(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002C6A70(p); else func_002C6950(p); } else { if (p[525] == 1) func_002C6820(p); else func_002C6740(p); } }

void func_002CCD30(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002CD020(p); else func_002CCEB0(p); } else { if (p[525] == 1) func_002CCE70(p); else func_002CCE00(p); } }

void func_002D23D0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002D25E0(p); else func_002D25A0(p); } else { if (p[525] == 1) func_002D2560(p); else func_002D24A0(p); } }

void func_002E9E30(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002EA3E0(p); else func_002EA2C0(p); } else { if (p[525] == 1) func_002EA080(p); else func_002E9F00(p); } }

void func_002F3060(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002F3280(p); else func_002F3240(p); } else { if (p[525] == 1) func_002F3170(p); else func_002F3130(p); } }

void func_002F7E60(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002F8170(p); else func_002F8100(p); } else { if (p[525] == 1) func_002F8070(p); else func_002F7F30(p); } }

void func_002FD100(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_002FD3B0(p); else func_002FD340(p); } else { if (p[525] == 1) func_002FD2D0(p); else func_002FD1D0(p); } }

void func_003015F0(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00301A60(p); else func_00301940(p); } else { if (p[525] == 1) func_00301840(p); else func_003016C0(p); } }

void func_00305D10(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00306280(p); else func_003061E0(p); } else { if (p[525] == 1) func_00305FE0(p); else func_00305DE0(p); } }

void func_003061E0(u8 *p)
{
    u8 *owner = p + 0x2B8;
    u8 state = p[0x1FC];

    switch (state) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        break;
    case 2:
        owner[0x10] = 8;
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        break;
    }
}

void func_0030D640(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_0030F650(p);
        return;
    }
    if ((s8)p[0x151] != 0) {
        *(u8 **)(p + 0x334) = 0;
        p[0x1B5] = 25;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    }
}

void func_00310880(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00310F60(p); else func_00310B50(p); } else { if (p[525] == 1) func_00310AE0(p); else func_00310950(p); } }

extern void func_00309F00(u8 *), func_00309E80(u8 *), func_00309DB0(u8 *), func_00309CF0(u8 *);

void func_00309C20(u8 *p) { *(float *)(p+52) += *(float *)(p+92); *(float *)(p+92) += *(float *)(p+104); *(float *)(p+56) += *(float *)(p+96); *(float *)(p+96) += *(float *)(p+108); func_001863F0(p); if (p[530] == 1) { if (p[525] == 1) func_00309F00(p); else func_00309E80(p); } else { if (p[525] == 1) func_00309DB0(p); else func_00309CF0(p); } }

void func_00306480(u8 *p)
{
    u8 *q = p + 0x2B8;

    p[0x2C8] = 8;
    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        func_0018C4B0(p, 5);
        if (p[0x212] == 1) {
            p[0x1B5] = 0x35;
            p[0x20D] = 0;
            func_001757E0(p, 0x14, 0);
            p[0x1B5] = (s8)p[0x1B5];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
            *(u16 *)(q + 0x12) = *(u16 *)(p + 0x168);
        }
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_001863F0(p);
    if (p[0x15B]) {
        func_001E3710(p, 0x16);
        p[0x15B] = 0;
    }
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
