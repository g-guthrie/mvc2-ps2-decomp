typedef void (*Mvc2Callback)(void);
extern void func_003A5220(unsigned char *,unsigned char *);
extern void func_003A53A0(void);
extern void func_003A53E0(void);
extern void func_003A5460(void);
extern void func_003A58E0(void);
extern void func_003A5920(void);
extern void func_003A50E0(unsigned char *,unsigned char *);
typedef struct {
    void (*owner_action[2])(unsigned char *,unsigned char *);
    Mvc2Callback later[5];
} InheritedActionTables;
const InheritedActionTables jtbl_00472D60 = {{
    func_003A50E0,
    func_003A5220,
}, {
    func_003A58E0,
    func_003A5920,
    func_003A53A0,
    func_003A53E0,
    func_003A5460,
}};
