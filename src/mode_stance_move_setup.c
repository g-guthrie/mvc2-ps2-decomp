/* Select a mode/stance move, reset its command, and consume one request nibble. */
typedef unsigned char u8;
extern u8 *D_004C2794;
extern void func_001757E0(u8 *,int,int), func_001E3710(u8 *,int);
extern u8 D_00458A00[], D_00458A20[];
void func_002AC830(u8 *p) {
    short offset = p[0x1fc]*4 + p[0x212]*12;
    unsigned int counter; u8 *move;
    if (!p[0x210]) move=D_00458A00+(short)offset;
    else move=D_00458A20+(short)offset;
    *(u8 **)(p+0x408)=move;
    p[0x1bb]=p[0x1fc];
    p[0x1b5]=*(signed char *)(p+0x1fc)+(*(signed char *)(p+0x212)*3+12);
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0;
    *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794; ++*(short *)(counter+0x7c);
    func_001757E0(p,(u8)(p[0x212]+11),p[0x1fc]);
    func_001E3710(p,(u8)(p[0x1fc]+20));
    if (!p[0x212]) {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&15) p[0x1ea]=requests-1;
    } else {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&240) p[0x1ea]=requests-16;
    }
}
extern u8 D_0045A600[], D_0045A620[];
void func_002D6820(u8 *p) {
    short offset = p[0x1fc]*4 + p[0x212]*12;
    unsigned int counter; u8 *move;
    if (!p[0x210]) move=D_0045A600+(short)offset;
    else move=D_0045A620+(short)offset;
    *(u8 **)(p+0x408)=move;
    p[0x1bb]=p[0x1fc];
    p[0x1b5]=*(signed char *)(p+0x1fc)+(*(signed char *)(p+0x212)*3+12);
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0;
    *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794; ++*(short *)(counter+0x7c);
    func_001757E0(p,(u8)(p[0x212]+11),p[0x1fc]);
    func_001E3710(p,(u8)(p[0x1fc]+20));
    if (!p[0x212]) {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&15) p[0x1ea]=requests-1;
    } else {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&240) p[0x1ea]=requests-16;
    }
}
extern u8 D_0045D660[], D_0045D6A0[];
void func_003175D0(u8 *p) {
    short offset = p[0x1fc]*4 + p[0x212]*12;
    unsigned int counter; u8 *move;
    if (!p[0x210]) move=D_0045D660+(short)offset;
    else move=D_0045D6A0+(short)offset;
    *(u8 **)(p+0x408)=move;
    p[0x1bb]=p[0x1fc];
    p[0x1b5]=*(signed char *)(p+0x1fc)+(*(signed char *)(p+0x212)*3+12);
    p[0x1b2]=*(unsigned short *)(p+0x1c0)=0;
    *(int *)(p+0x1d8)=0;
    counter=p[2]*2; counter+=(unsigned int)D_004C2794; ++*(short *)(counter+0x7c);
    func_001757E0(p,(u8)(p[0x212]+11),p[0x1fc]);
    func_001E3710(p,(u8)(p[0x1fc]+20));
    if (!p[0x212]) {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&15) p[0x1ea]=requests-1;
    } else {
        int requests=*(signed char *)(p+0x1ea);
        if (requests&240) p[0x1ea]=requests-16;
    }
}
