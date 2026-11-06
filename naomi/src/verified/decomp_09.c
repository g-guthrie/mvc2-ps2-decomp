#include "objects.h"

#pragma section n1df790
int func_0c200790(struct ByteCursor *p) { int ch = *p->cur; p->cur++; p->cnt0--; p->cnt8++; p->cnt4--; if (ch != 2) { while (*p->cur != 0) { p->cur = p->cur + 1; p->cnt0 -= 1; } } return ch; }

#pragma section n1df8aa
int func_0c2008aa(struct ByteCursor *p) { int ch = *p->cur; p->cur++; p->cnt0--; p->cnt8++; p->cnt4--; p->cnt8++; p->cnt4--; if (ch != 2) { int i = 4; do { p->cur = p->cur + 1; i = i - 1; } while (i != 0); p->cnt0 -= 4; } return ch; }

#pragma section n1df8f0
int func_0c2008f0(struct ByteCursor *p) { int ch = *p->cur; p->cur++; p->cnt0--; p->cnt8++; p->cnt4--; p->cnt8++; p->cnt4--; if (ch != 2) { int i = 4; do { p->cur = p->cur + 1; i = i - 1; } while (i != 0); p->cnt0 -= 4; } return ch; }
