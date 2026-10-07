/* Restore the selected stance flags before the common state transition. */
typedef unsigned char u8;
extern void func_00186A60(u8 *,int);
void func_00215B30(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(signed char *)(p+0x4dd)) {
    case 0: p[0x1fd]=0; p[0x1b7]=0; break;
    case 1: p[0x1fd]=3; p[0x1b7]=1; break;
    case 2: p[0x1fd]=7; p[0x1b7]=1; break;
    }
    func_00186A60(p,21);
}
void func_00215BA0(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(signed char *)(p+0x4dd)) {
    case 0: p[0x1fd]=0; p[0x1b7]=0; break;
    case 1: p[0x1fd]=3; p[0x1b7]=1; break;
    case 2: p[0x1fd]=7; p[0x1b7]=1; break;
    }
    func_00186A60(p,21);
}
void func_002D8DA0(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(signed char *)(p+0x4dd)) {
    case 0: p[0x1fd]=0; p[0x1b7]=0; break;
    case 1: p[0x1fd]=3; p[0x1b7]=1; break;
    case 2: p[0x1fd]=7; p[0x1b7]=1; break;
    }
    func_00186A60(p,21);
}
