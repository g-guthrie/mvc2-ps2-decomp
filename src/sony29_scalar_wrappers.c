#include "sony29_fileio_path_requests.h"
extern int func_00105540(int);
extern void func_00107A68(void);
extern int func_00103E20(int);
extern int D_00438304;

void func_00105628(int character)
{
    if (character == 10) {
        func_00105540(13);
        func_00105540(10);
    } else {
        func_00105540(character);
    }
}

int func_00107AB8(int operation)
{
    func_00107A68();
    func_00103E20(D_00438304);
    return 0;
}
