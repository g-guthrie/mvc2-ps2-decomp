/* SN GCC 2.95.2 runtime leaves, compiled with -O2 -G0. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Runtime { unsigned char pad[0xA8]; u64 value; } Runtime;
extern Runtime *D_0043B6F8;

Runtime *func_0011B370(void) { return D_0043B6F8; }
int func_00119D88(int value) { return value < 0 ? -value : value; }
void func_0011F5C0(u32 value) { D_0043B6F8->value = value; }
