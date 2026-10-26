typedef void (*Mvc2Callback)(void);
extern void func_002462E0(unsigned char *,void *);
extern void func_002464C0(void);
typedef struct {
    void (*action_chain)(unsigned char *,void *);
    Mvc2Callback later;
} WorkChainRoots;
const WorkChainRoots jtbl_004C0388 = {
    func_002462E0,
    func_002464C0,
};
