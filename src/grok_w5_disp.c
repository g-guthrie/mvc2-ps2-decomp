typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);
typedef void (*DispatchFn2)(u8 *, void *);

extern DispatchFn jtbl_00443AD0[];
extern DispatchFn jtbl_00446300[];
extern DispatchFn jtbl_00449440[];
extern DispatchFn jtbl_0044A660[];
extern DispatchFn jtbl_0044B140[];
extern DispatchFn jtbl_0044BC10[];
extern DispatchFn jtbl_0044BC80[];
extern DispatchFn jtbl_0044BE10[];
extern DispatchFn jtbl_0044BED0[];
extern DispatchFn jtbl_0044C4E0[];
extern DispatchFn jtbl_0044CC10[];
extern DispatchFn jtbl_0044D930[];
extern DispatchFn jtbl_0044E7A0[];
extern DispatchFn jtbl_00450FE8[];
extern DispatchFn jtbl_00451070[];
extern DispatchFn jtbl_004510A8[];
extern DispatchFn jtbl_00451F50[];
extern DispatchFn jtbl_00452308[];
extern DispatchFn jtbl_004529F0[];
extern DispatchFn jtbl_00452A78[];
extern DispatchFn jtbl_00452C80[];
extern DispatchFn jtbl_004537F0[];
extern DispatchFn jtbl_00454678[];
extern DispatchFn jtbl_00454E60[];
extern DispatchFn jtbl_00454E90[];
extern DispatchFn jtbl_00455090[];
extern DispatchFn jtbl_00456868[];
extern DispatchFn jtbl_00456960[];
extern DispatchFn jtbl_004569C0[];
extern DispatchFn jtbl_00456A70[];
extern DispatchFn jtbl_00456AA0[];
extern DispatchFn jtbl_004576D0[];
extern DispatchFn jtbl_00457890[];
extern DispatchFn jtbl_004578F0[];
extern DispatchFn jtbl_004579A0[];
extern DispatchFn jtbl_004579D0[];
extern DispatchFn jtbl_004581E0[];
extern DispatchFn jtbl_004588A0[];
extern DispatchFn jtbl_00458D10[];
extern DispatchFn jtbl_004590C8[];
extern DispatchFn jtbl_00459410[];
extern DispatchFn jtbl_0045A7A0[];
extern DispatchFn jtbl_0045ACF8[];
extern DispatchFn jtbl_0045AD40[];
extern DispatchFn jtbl_0045AD80[];
extern DispatchFn jtbl_0045B270[];
extern DispatchFn jtbl_0045BF88[];
extern DispatchFn jtbl_0045D1D0[];
extern DispatchFn jtbl_0045D3C0[];
extern DispatchFn jtbl_0045DB78[];
extern DispatchFn jtbl_0045DC00[];
extern DispatchFn jtbl_0045DC38[];
extern DispatchFn jtbl_0045E140[];
extern DispatchFn jtbl_00462350[];
extern DispatchFn jtbl_00462D70[];
extern DispatchFn jtbl_00462DB0[];
extern DispatchFn jtbl_00463430[];
extern DispatchFn jtbl_00463440[];
extern DispatchFn jtbl_004634B0[];
extern DispatchFn jtbl_004634C0[];
extern DispatchFn jtbl_00463520[];
extern DispatchFn jtbl_00463F70[];
extern DispatchFn jtbl_004645D0[];
extern DispatchFn jtbl_004724F0[];
extern DispatchFn jtbl_00472640[];
extern DispatchFn jtbl_00472830[];
extern DispatchFn jtbl_00472DF0[];
extern DispatchFn jtbl_00472E20[];
extern DispatchFn jtbl_00472F20[];
extern DispatchFn jtbl_00473C40[];
extern DispatchFn jtbl_00473CA0[];
extern DispatchFn jtbl_00473D70[];
extern DispatchFn jtbl_00473DA0[];
extern DispatchFn jtbl_00473DC0[];
extern DispatchFn jtbl_00474310[];
extern DispatchFn jtbl_004744C0[];
extern DispatchFn jtbl_004BFA50[2];
extern DispatchFn jtbl_004BFD68[2];
extern DispatchFn jtbl_004BFE50[2];
extern DispatchFn jtbl_004BFF10[2];
extern DispatchFn jtbl_004BFF70[2];
extern DispatchFn jtbl_004BFFF8[2];
extern DispatchFn jtbl_004C0120[2];
extern DispatchFn jtbl_004C0278[2];
extern DispatchFn jtbl_004C02A0[2];
extern DispatchFn jtbl_004C0360[2];
extern DispatchFn jtbl_004C0410[2];
extern DispatchFn jtbl_004C0830[2];
extern DispatchFn jtbl_004C08F8[2];
extern DispatchFn jtbl_004C0A38[2];
extern DispatchFn jtbl_004C0BA8[2];
extern DispatchFn jtbl_004C0E78[2];
extern DispatchFn jtbl_004C1178[2];
extern DispatchFn jtbl_004C14B8[2];
extern DispatchFn jtbl_004C16E0[2];
extern DispatchFn jtbl_004C16E8[2];
extern DispatchFn jtbl_004C1780[2];
extern DispatchFn jtbl_004C1878[2];
extern DispatchFn jtbl_004C1880[2];
extern DispatchFn jtbl_004C18B8[2];
extern DispatchFn jtbl_004C1A00[2];
extern DispatchFn jtbl_004C1A50[2];
extern DispatchFn jtbl_004C1CE0[2];
extern DispatchFn2 jtbl_0044C080[];
extern DispatchFn2 jtbl_00471B20[];

void residual_001487B0(u8 *p) { jtbl_00443AD0[p[4]](p); }

void residual_0016C3D0(u8 *p) { jtbl_00446300[p[4]](p); }

void residual_00194460(u8 *p) { jtbl_00449440[p[4]](p); }

void residual_00198980(u8 *p) { jtbl_0044A660[p[5]](p); }

void residual_001A44E0(u8 *p) { jtbl_0044B140[p[4]](p); }

void residual_001AFD30(u8 *p) { jtbl_0044BC10[p[32]](p); }

void residual_001B1020(u8 *p) { jtbl_0044BC80[p[32]](p); }

void residual_001B6020(u8 *p) { jtbl_0044BE10[p[4]](p); }

void residual_001B7CF0(u8 *p) { jtbl_0044BED0[p[32]](p); }

void residual_001BB990(u8 *p) { jtbl_0044C080[p[4]](p, *(void **)(p + 24)); }

void residual_001BFEA0(u8 *p) { jtbl_0044C4E0[p[4]](p); }

void residual_001C4900(u8 *p) { jtbl_0044CC10[p[4]](p); }

void residual_001CA580(u8 *p) { jtbl_0044D930[p[33]](p); }

void residual_001CDF10(u8 *p) { jtbl_004BFA50[p[5]](p); }

void residual_001D8610(u8 *p) { jtbl_0044E7A0[p[4]](p); }

void residual_00201DD0(u8 *p) { jtbl_004BFD68[p[6]](p); }

void func_0020D2F0(u8 *a0, u8 *p) { jtbl_004BFE50[p[7]](a0); }

void residual_00218290(u8 *p) { jtbl_00450FE8[p[6]](p); }

void residual_00219D20(u8 *p) { jtbl_00451070[p[7]](p); }

void residual_0021A540(u8 *p) { jtbl_004510A8[p[7]](p); }

void residual_0021AA10(u8 *p) { jtbl_004BFF10[p[7]](p); }

void residual_0021F0F0(u8 *p) { jtbl_004BFF70[p[6]](p); }

void residual_00224740(u8 *p) { jtbl_004BFFF8[p[6]](p); }

void residual_0022EC70(u8 *p) { jtbl_004C0120[p[6]](p); }

void residual_00230320(u8 *p) { jtbl_00451F50[p[7]](p); }

void residual_002355D0(u8 *p) { jtbl_00452308[p[6]](p); }

void residual_0023C8A0(u8 *p) { jtbl_004C0278[p[6]](p); }

void residual_0023D390(u8 *p) { jtbl_004C02A0[p[6]](p); }

void residual_00240830(u8 *p) { jtbl_004529F0[p[6]](p); }

void residual_00242020(u8 *p) { jtbl_00452A78[p[7]](p); }

void residual_00245120(u8 *p) { jtbl_00452C80[p[6]](p); }

void residual_00245A60(u8 *p) { jtbl_004C0360[p[6]](p); }

void residual_0024B020(u8 *p) { jtbl_004C0410[p[6]](p); }

void residual_002591A0(u8 *p) { jtbl_004537F0[p[6]](p); }

void residual_0026CD20(u8 *p) { jtbl_00454678[p[6]](p); }

void residual_00279070(u8 *p) { jtbl_00454E60[p[7]](p); }

void residual_00279290(u8 *p) { jtbl_00454E90[p[6]](p); }

void residual_0027B7E0(u8 *p) { jtbl_004C0830[p[7]](p); }

void residual_0027BD70(u8 *p) { jtbl_00455090[p[6]](p); }

void residual_002833B0(u8 *p) { jtbl_004C08F8[p[6]](p); }

void residual_00289000(u8 *p) { jtbl_00456868[p[6]](p); }

void func_0028A770(u8 *a0, u8 *p) { jtbl_00456960[p[24]](a0); }

void func_0028AC20(u8 *a0, u8 *p) { jtbl_004569C0[p[24]](a0); }

void residual_0028BB80(u8 *p) { jtbl_00456A70[p[7]](p); }

void residual_0028BE90(u8 *p) { jtbl_00456AA0[p[7]](p); }

void residual_0028F850(u8 *p) { jtbl_004576D0[p[7]](p); }

void residual_00290A70(u8 *p) { jtbl_004C0A38[p[6]](p); }

void func_00291AE0(u8 *a0, u8 *p) { jtbl_00457890[p[24]](a0); }

void func_00291F90(u8 *a0, u8 *p) { jtbl_004578F0[p[24]](a0); }

void residual_00292EF0(u8 *p) { jtbl_004579A0[p[7]](p); }

void residual_00293200(u8 *p) { jtbl_004579D0[p[7]](p); }

void residual_0029D670(u8 *p) { jtbl_004581E0[p[6]](p); }

void residual_002A2CE0(u8 *p) { jtbl_004C0BA8[p[6]](p); }

void residual_002A8F70(u8 *p) { jtbl_004588A0[p[6]](p); }

void residual_002AE8D0(u8 *p) { jtbl_00458D10[p[6]](p); }

void residual_002B4CE0(u8 *p) { jtbl_004590C8[p[6]](p); }

void residual_002BA0D0(u8 *p) { jtbl_00459410[p[6]](p); }

void residual_002C7A70(u8 *p) { jtbl_004C0E78[p[6]](p); }

void residual_002D76E0(u8 *p) { jtbl_0045A7A0[p[6]](p); }

void residual_002DDE50(u8 *p) { jtbl_0045ACF8[p[6]](p); }

void residual_002DE940(u8 *p) { jtbl_0045AD40[p[7]](p); }

void residual_002DF390(u8 *p) { jtbl_0045AD80[p[7]](p); }

void residual_002E5EE0(u8 *p) { jtbl_0045B270[p[6]](p); }

void residual_002EA9F0(u8 *p) { jtbl_004C1178[p[6]](p); }

void residual_002FB0E0(u8 *p) { jtbl_0045BF88[p[6]](p); }

void residual_00302070(u8 *p) { jtbl_004C14B8[p[6]](p); }

void residual_0030DDD0(u8 *p) { jtbl_0045D1D0[p[6]](p); }

void residual_00311A70(u8 *p) { jtbl_0045D3C0[p[6]](p); }

void residual_00312620(u8 *p) { jtbl_004C16E0[p[6]](p); }

void residual_00313AC0(u8 *a0, u8 *p) { jtbl_004C16E8[p[13]](a0); }

void residual_0031D760(u8 *p) { jtbl_0045DB78[p[6]](p); }

void residual_0031F1B0(u8 *p) { jtbl_0045DC00[p[7]](p); }

void residual_0031F9F0(u8 *p) { jtbl_0045DC38[p[7]](p); }

void residual_0031FEC0(u8 *p) { jtbl_004C1780[p[7]](p); }

void residual_00327E00(u8 *p) { jtbl_0045E140[p[4]](p); }

void residual_00335A00(u8 *p) { jtbl_004C1878[p[5]](p); }

void residual_00335A80(u8 *p) { jtbl_004C1880[p[7]](p); }

void residual_00336600(u8 *p) { jtbl_004C18B8[p[5]](p); }

void residual_0034B9B0(u8 *p) { jtbl_004C1A00[p[5]](p); }

void residual_0034EAD0(u8 *p) { jtbl_00462350[p[5]](p); }

void residual_003506A0(u8 *p) { jtbl_004C1A50[p[5]](p); }

void residual_003572C0(u8 *p) { jtbl_00462D70[p[5]](p); }

void residual_00357C60(u8 *p) { jtbl_00462DB0[p[32]](p); }

void residual_0035FA80(u8 *p) { jtbl_00463430[p[4]](p); }

void residual_00360120(u8 *p) { jtbl_00463440[p[4]](p); }

void residual_003605D0(u8 *p) { jtbl_004634B0[p[4]](p); }

void residual_00360A20(u8 *p) { jtbl_004634C0[p[4]](p); }

void residual_003619E0(u8 *p) { jtbl_00463520[p[4]](p); }

void residual_00373DB0(u8 *p) { jtbl_004C1CE0[p[6]](p); }

void residual_00375EA0(u8 *p) { jtbl_00463F70[p[4]](p); }

void residual_00381FF0(u8 *p) { jtbl_004645D0[p[4]](p); }

void residual_00390D20(u8 *p) { jtbl_00471B20[p[4]](p, *(void **)(p + 24)); }

void residual_00397660(u8 *p) { jtbl_004724F0[p[5]](p); }

void residual_00399BF0(u8 *p) { jtbl_00472640[p[4]](p); }

void residual_0039EA90(u8 *p) { jtbl_00472830[p[4]](p); }

void residual_003A5EB0(u8 *p) { jtbl_00472DF0[p[4]](p); }

void residual_003A6830(u8 *p) { jtbl_00472E20[p[4]](p); }

void residual_003A7C40(u8 *p) { jtbl_00472F20[p[4]](p); }

void residual_003AFA90(u8 *p) { jtbl_00473C40[p[4]](p); }

void residual_003B0900(u8 *p) { jtbl_00473CA0[p[4]](p); }

void residual_003B2010(u8 *p) { jtbl_00473D70[p[4]](p); }

void residual_003B2900(u8 *p) { jtbl_00473DA0[p[4]](p); }

void residual_003B2FE0(u8 *p) { jtbl_00473DC0[p[4]](p); }

void residual_003B8760(u8 *p) { jtbl_00474310[p[5]](p); }

void residual_003B9C20(u8 *p) { jtbl_004744C0[p[5]](p); }
