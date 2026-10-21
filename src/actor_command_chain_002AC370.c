typedef unsigned char u8;
typedef signed int s32; typedef unsigned int u32;
extern s32 func_00188690(u8 *); extern s32 func_00188ED0(u8 *); extern s32 func_00188C70(u8 *); extern s32 func_00189130(u8 *);
extern s32 func_002AC190(u8 *); extern s32 func_002AC030(u8 *); extern s32 func_002AC0E0(u8 *);
extern s32 func_002ABF80(u8 *); extern s32 func_002ABAC0(u8 *); extern s32 func_002ABB60(u8 *); extern s32 func_002ABC10(u8 *); extern s32 func_002ABCA0(u8 *); extern s32 func_002ABDA0(u8 *); extern s32 func_002ABEA0(u8 *); extern s32 func_002ABA50(u8 *); extern s32 func_002AB9F0(u8 *); extern void func_00187BB0(u8 *); extern int func_00188330(u8 *);
void func_002AC370(u8 *p)
{
    if(func_00188690(p)) return;
    if(func_00188ED0(p)) return;
    if(func_00188C70(p)) return;
    if(func_00189130(p)) return;
    if(*(u32 *)(p+0xD0)) {
        if(func_002AC190(p)) return;
        if(func_002AC030(p)) return;
        if(func_002AC0E0(p)) return;
        if(func_002ABF80(p)) return;
        if(func_002ABAC0(p)) return;
        if(func_002ABB60(p)) return;
        if(func_002ABC10(p)) return;
        if(func_002ABCA0(p)) return;
        if(func_002ABDA0(p)) return;
        if(func_002ABEA0(p)) return;
    } else {
        if(func_002ABF80(p)) return;
        if(func_002ABAC0(p)) return;
        if(func_002ABB60(p)) return;
        if(func_002ABC10(p)) return;
        if(func_002ABCA0(p)) return;
        if(func_002ABDA0(p)) return;
        if(func_002ABEA0(p)) return;
    }
    if(func_002ABA50(p)) return;
    if(func_002AB9F0(p)) return;
    func_00187BB0(p); func_00188330(p);
}
