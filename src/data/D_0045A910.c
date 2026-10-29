typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002D8F30(void);
extern void func_002D96F0(void);
extern void func_002D9850(void);
extern void func_002D9CF0(void);
extern void func_002D9E90(void);
extern void func_002D9EB0(void);
extern void func_002D9FC0(void);
extern void func_002DA1B0(void);
extern void func_002DA340(void);
extern void func_002DA5A0(void);
extern void func_002DA6A0(void);
extern void func_002DBB50(void);
extern void func_002DBD20(void);
extern void func_002DBDB0(void);
extern void func_002DBE80(void);
extern void func_002DC1D0(void);
extern void func_002DC1E0(void);
extern void func_002DC210(void);
extern void func_002DC240(void);
extern void func_002DC290(void);
extern void func_002DC070(void);
const Mvc2Callback D_0045A910[28] = {
    func_002D9850,
    func_002D8F30,
    func_002D9CF0,
    func_002D9E90,
    func_002D9FC0,
    func_002DA1B0,
    func_002DA340,
    func_002DA5A0,
    func_002DA6A0,
    func_002DBD20,
    func_002DBDB0,
    func_002DBE80,
    func_002DC1D0,
    func_002D96F0,
    func_002DBB50,
    func_002D9EB0,
    func_002DC1E0,
    func_002DC210,
    func_002DC240,
    func_002DC290,
    0,
    0,
    0,
    0,
    func_002DC070,
    0,
    0,
    0,
};
