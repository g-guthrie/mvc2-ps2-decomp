/* Advance and deactivate when the parent exits; otherwise run its handler. */
typedef unsigned char u8;
extern void (*D_004642A0[])(u8 *,u8 *);
extern void (*D_00464380[])(u8 *,u8 *);
extern void (*D_00464C10[])(u8 *,u8 *);
extern void (*D_00471A00[])(u8 *,u8 *);
extern void (*D_004A6CE0[])(u8 *,u8 *);

#define PARENT_DISPATCH(name,handlers,index_offset) \
void name(u8 *p) { \
 u8 *parent=*(u8 **)(p+0x18); \
 if (parent[4]>=2) { ++p[4]; p[0x13c]=0; } \
 else handlers[p[index_offset]](p,parent); \
}

PARENT_DISPATCH(func_0037ECD0, D_004642A0, 0x20)
PARENT_DISPATCH(func_003804B0, D_00464380, 0x5)
PARENT_DISPATCH(func_00389C20, D_00464C10, 0x20)
PARENT_DISPATCH(func_0038D660, D_00471A00, 0x20)
PARENT_DISPATCH(func_0041A170, D_004A6CE0, 0x20)
