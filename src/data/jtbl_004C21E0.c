/* 003D90A0 selects these two getters. All eight direct native callers
 * pass selector 0 or 1; both targets return a zero-extended status byte. */
typedef int (*SelectorHandler)(int);
extern int func_003D90C0(int);
extern int func_003D90D0(int);
const SelectorHandler jtbl_004C21E0[2] = {
    func_003D90C0,
    func_003D90D0,
};
typedef char SelectorTableSizeCheck[(sizeof(jtbl_004C21E0) == 8) ? 1 : -1];
