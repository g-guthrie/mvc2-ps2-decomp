typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x160]; s8 bytes[2]; } ByteContext;

extern int func_00175700(u8 *);
extern void func_00328E60(u8 *);
extern void func_0018FDB0(u8 *);
extern u8 *func_001BA5D0(u8 *, u8);
extern void func_0015B200(u8 *, f32 *, s32, s32);
extern void func_00162BA0(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_001843A0(u8 *);

void func_00277D40(u8 *p)
{
    u8 *actor = *(u8 **)(p + 0x220);
    u8 *callback;
    s8 *byteContext;
    s8 *byteField;
    s8 contextState;
    ByteContext *context;

    func_00175700(p);
    if ((*(s8 *)(p + 0x151) & 8) != 0) {
        *(s8 *)(p + 0x151) = 0;
        *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
        *(*(u8 **)(p + 0x1DC) + 0x1B5) = 0x24;
        actor[0x23E] = 3;
        actor[0x23C] = 3;
        func_00328E60(actor);
        func_0018FDB0(p);
    }
    if (*(s8 *)(p + 0x151) == 2) {
        V3 position;
        f32 offset;
        position = *(V3 *)(p + 0x34);
        if (*(s16 *)(p + 0x140) != 0)
            offset = 140.0f;
        else
            offset = -140.0f;
        position.x += offset;
        position.y += 204.0f;
        func_001BA5D0(p, 2);
        func_0015B200(p, &position.x, 1, 0x91);
        *(s8 *)(p + 0x151) = 0;
        func_00162BA0(*(u8 **)(p + 0x220));
    }
    context = (ByteContext *)p;
    byteContext = context->bytes;
    contextState = byteContext[1];
    byteField = byteContext + 1;
    if (contextState == 0x0F) {
        *byteField = 0;
        *(s8 *)(p + 0x151) = 0;
        func_001BA5D0(p, 0);
    }
    if (*(s8 *)(p + 0x151) == 4) {
        *(s8 *)(p + 0x151) = 0;
        func_001BA5D0(p, 3);
        func_001843A0(p);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        func_001266A0(p, 0, 0);
        *(s8 *)(p + 0x151) = 0;
        callback = *(u8 **)(p + 0x1DC);
        *(u8 **)(callback + 0x1C8) = p;
        callback[0x20A] = 1;
        callback[0x1B5] = 0x23;
    }
}
