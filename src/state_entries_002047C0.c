typedef unsigned char u8;

extern void func_001863F0();
extern void func_00204990();
extern void func_00204950();
extern void func_002048D0();
extern void func_00204890();
extern void func_00309F00();
extern void func_00309E80();
extern void func_00309DB0();
extern void func_00309CF0();

void func_002047C0(u8 *p) {
    *(float *)(p+52) += *(float *)(p+92);
    *(float *)(p+92) += *(float *)(p+104);
    *(float *)(p+56) += *(float *)(p+96);
    *(float *)(p+96) += *(float *)(p+108);
    func_001863F0(p);
    if (p[530] == 1) {
        if (p[525] == 1) func_00204990(p);
        else func_00204950(p);
    } else {
        if (p[525] == 1) func_002048D0(p);
        else func_00204890(p);
    }
}

