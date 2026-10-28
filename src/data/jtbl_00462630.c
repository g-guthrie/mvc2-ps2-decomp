/* Phase handlers of the owner-paired actor, indexed by p[4] (0..12).
 * Every entry is a matched void (u8 *) handler; the lbl_ entry is the
 * phase-0 handler defined in src/owner_phase_pair_00351bf0.c. */
typedef void (*Mvc2PhaseHandler)(unsigned char *);
extern void func_00351E40(unsigned char *);
extern void func_00352140(unsigned char *);
extern void func_00352160(unsigned char *);
extern void func_00352300(unsigned char *);
extern void func_00352460(unsigned char *);
extern void func_00352540(unsigned char *);
extern void func_00352640(unsigned char *);
extern void func_00352660(unsigned char *);
extern void lbl_00351C30(unsigned char *);
extern void residual_003521F0(unsigned char *);
Mvc2PhaseHandler const jtbl_00462630[13] = {
    lbl_00351C30,
    func_00351E40,
    func_00352140,
    func_00352160,
    residual_003521F0,
    func_00352540,
    func_00352640,
    func_00352660,
    func_00352300,
    func_00352300,
    func_00352460,
    func_00352300,
    func_00352300,
};
