typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00281210(void);
extern void func_002817D0(void);
extern void func_00281950(void);
extern void func_00281960(void);
extern void func_002822D0(void);
extern void func_00282C20(void);
extern void func_00282D40(void);
extern void func_00282FB0(void);
extern void func_00283130(void);
extern void func_002831B0(void);
extern void func_00283390(void);
extern void func_002858E0(void);
extern void func_00285AC0(void);
extern void func_00285C00(void);
extern void func_00285E20(void);
extern void func_00285FF0(void);
extern void func_00286030(void);
extern void func_00286090(void);
extern void func_002860F0(void);
extern void func_00286160(void);
const Mvc2Callback D_00455960[28] = {
    func_00281950,
    func_00281210,
    func_00281960,
    func_002822D0,
    func_00282D40,
    func_00282FB0,
    func_00283130,
    func_002831B0,
    func_00283390,
    func_00285AC0,
    func_00285C00,
    func_00285E20,
    func_00285FF0,
    func_002817D0,
    func_002858E0,
    func_00282C20,
    func_00286030,
    func_00286090,
    func_002860F0,
    func_00286160,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
