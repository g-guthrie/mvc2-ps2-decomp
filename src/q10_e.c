typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct N_003DA650 { u8 pad[0xC]; struct N_003DA650 *next; } N_003DA650;
extern N_003DA650 *D_004D3690[];
extern N_003DA650 *D_004D3520[];
extern s16 D_004D3460[];
extern void func_003DAA40( void *);
void func_003DA650(u8 idx) {
    N_003DA650 *n = D_004D3690[idx];
    if (n != 0) do {
        func_003DAA40(n);
        n = n->next;
    } while (n != 0);
    D_004D3690[idx] = 0;
    D_004D3520[idx] = 0;
    D_004D3460[idx] = 0;
}
