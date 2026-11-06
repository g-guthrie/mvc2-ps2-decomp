#include "objects.h"
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c044846(struct Actor *);
extern unsigned char func_0c0464c4(struct Actor *),func_0c046030(struct Actor *);
extern int func_0c0439d8(struct Actor *,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044c60(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern signed char func_0c02a026(struct Actor *);
void func_0c03a810(struct Actor *a)
{
    if (func_0c043c66(a)) return;
    if (func_0c043a10(a)) return;
    if (func_0c044846(a)) return;
    if (a->b201==0) {
        if (func_0c0464c4(a)) return;
        if (func_0c046030(a)) return;
        if (func_0c0439d8(a,0)) return;
        if (func_0c043d3a(a)) return;
    }
    if (func_0c044c60(a)) return;
    if (((struct MaskObject *)a)->w340 & 0x1000) {
        func_0c0453c4(a,5);
        func_0c02a0c4(a,3,0);
        return;
    }
    if (func_0c02a026(a)>=0) return;
    func_0c0453c4(a,0);
}
