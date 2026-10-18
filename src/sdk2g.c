typedef struct Node { struct Node *prev; struct Node *next; int pad[4]; } Node;
extern Node *D_004C2AB4;
extern int D_004C2AB0;
extern void func_003F55B0(void *, int, int);


extern int D_004C2298;
extern void func_003FACE8(int, int, int, int, int, int, short, short, int, short, short);
extern void func_003FA910(int, int, int, int, int, int, short, short, int, short, short);
void func_003FB040(int a, int b, int c, int d, int e, int f, short g, short h, int i, short j, short k) {
    if (D_004C2298 == 0) func_003FACE8(a, b, c, d, e, f, g, h, i, j, k);
    else func_003FA910(a, b, c, d, e, f, g, h, i, j, k);
}
