typedef void (*Mvc2Callback)(void);
extern void func_001CBEF0(void);
extern void func_001CC000(void);
extern void func_001CC0A0(void);
extern void func_001CC1B0(void);
extern void func_001CC280(void);
extern void func_001CC420(void);
extern void func_001CC610(void);
extern void func_001CC6D0(void);
extern void func_001CCB50(void);
extern void func_001CCB60(void);
extern void func_001CC440(unsigned char *);
typedef struct {
    Mvc2Callback earlier[12];
    void (*timed_jitter)(unsigned char *);
    Mvc2Callback later[2];
} TimedJitterPhaseTables;
const TimedJitterPhaseTables jtbl_0044DCF0 = {{
    func_001CBEF0,
    func_001CC000,
    func_001CCB50,
    func_001CCB60,
    func_001CC0A0,
    func_001CC1B0,
    func_001CCB50,
    func_001CCB60,
    func_001CC280,
    func_001CC420,
    func_001CCB50,
    func_001CCB60,
}, func_001CC440, {
    func_001CC610,
    func_001CC6D0,
}};
