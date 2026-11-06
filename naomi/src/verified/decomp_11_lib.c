/* Hitachi SHC 5.0R31 reconstructed leaf functions. */

#pragma section n1d7070
int func_0c1f8070(unsigned char *p) { int count = 0; if (*(int*)(p+4) >= 2) count++; if (*(int*)(p+8) >= 2) count++; if (count != 0) { *(int*)p = 0; *(int*)(p+4) = 1; *(int*)(p+8) = 0; *(int*)(p+12) = 1; } return count; }

struct S_0c2006a8 { int a; int b; unsigned char *c; unsigned char *d; };
#pragma section n1df6a8
int func_0c2006a8(struct S_0c2006a8 *p) { unsigned int v; v = *p->d; p->d++; p->a--; p->c++; p->b--; while (*p->c != 0) { p->c++; p->b--; } return v; }

struct Node_0c224cb8 { unsigned char pad[4]; struct Node_0c224cb8 *next; int f8; };
