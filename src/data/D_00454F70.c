typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0027AD10(void);
extern void func_0027AF70(void);
extern void func_0027AF80(void);
extern void func_0027B4F0(void);
extern void func_0027B650(void);
extern void func_0027B670(void);
extern void func_0027B680(void);
extern void func_0027B690(void);
extern void func_0027B750(void);
extern void func_0027BD50(void);
extern void func_0027CD70(void);
extern void func_0027CF20(void);
extern void func_0027CF30(void);
extern void func_0027CF40(void);
extern void func_0027CF50(void);
extern void func_0027CF60(void);
extern void func_0027CF70(void);
extern void func_0027CF80(void);
extern void func_0027CF90(void);
extern void func_0027CFA0(void);
const Mvc2Callback D_00454F70[28] = {
    func_0027AF80,
    func_0027AD10,
    func_0027B4F0,
    func_0027B650,
    func_0027B670,
    func_0027B680,
    func_0027B690,
    func_0027B750,
    func_0027BD50,
    func_0027CF20,
    func_0027CF30,
    func_0027CF40,
    func_0027CF50,
    func_0027AF70,
    func_0027CD70,
    0,
    func_0027CF60,
    func_0027CF70,
    func_0027CF80,
    func_0027CF90,
    0,
    0,
    0,
    0,
    func_0027CFA0,
    0,
    0,
    0,
};
