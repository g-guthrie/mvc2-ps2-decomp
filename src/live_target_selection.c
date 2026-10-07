/* Select the opposing actor when the interaction request permits contact. */
typedef unsigned char u8;
extern u8 D_004D18A1, D_004D18A0;
extern int func_001E8110(u8 *,u8 *,int);
u8 *func_001E7FD0(u8 *p) {
    short request;
    if (D_004D18A1 & 8) return 0;
    request=*(short *)(*(u8 **)(p+0x1d4)+2);
    if (request >= 0) return 0;
    if (D_004D18A0 != 4) return 0;
    if (!*(signed char *)(p+0x24b)) {
        if (func_001E8110(p,*(u8 **)(p+0x220),request & 0x1fff))
            return *(u8 **)(p+0x220);
    }
    return 0;
}
