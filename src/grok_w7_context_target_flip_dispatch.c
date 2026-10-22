typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef void (*ActorCallback)(u8 *);

extern void func_0018C6E0(void *);
extern const ActorCallback D_0045CF70[];

void func_0030BCA0(u8 *p)
{
    s16 state;

    func_0018C6E0(p);
    state = (s16)(p[0x1E6] ^ 1);
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = state;
    *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = (s8)state;
    D_0045CF70[p[0x20B] & 0x3F](p);
}
