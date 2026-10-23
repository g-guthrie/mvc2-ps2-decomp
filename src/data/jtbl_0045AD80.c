#include "capture_state_bank.h"

extern void func_002DF3B0(unsigned char *);
extern void func_002DF470(unsigned char *);
extern void func_002DF510(unsigned char *);
extern void func_002DF540(unsigned char *);
extern void func_002DF5E0(unsigned char *, unsigned char *);
extern void func_002DF8C0(unsigned char *, unsigned char *);
extern void func_002DFA20(unsigned char *, unsigned char *);
extern void func_002DFAE0(unsigned char *, unsigned char *);
extern void func_002E0060(unsigned char *, unsigned char *);
extern void func_002E00D0(unsigned char *, unsigned char *);
extern void func_002E0130(unsigned char *, unsigned char *);

const CaptureStateBank jtbl_0045AD80 = {
    {
        func_002DF3B0,
        func_002DF470,
        func_002DF510,
        func_002DF540,
    },
    {
        func_002DF5E0,
        func_002DF8C0,
        func_002DFA20,
        func_002DFAE0,
        func_002E0060,
        func_002E00D0,
        func_002E0130,
    },
};
