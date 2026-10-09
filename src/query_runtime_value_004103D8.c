typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

struct RuntimeNode;
struct RuntimeNodeValue
{
    u32 first;
    s32 value;
};

struct RuntimeNode
{
    struct RuntimeNode *next;
    u32 unknown;
    struct RuntimeNodeValue value;
};

typedef void (*RuntimeFallback)(void *argument, s32 error);

struct RuntimeQueryContext
{
    u8 unknown0[5];
    s8 mode;
    u8 unknown6[18];
    struct RuntimeNode *entries[4];
    RuntimeFallback fallback;
    void *fallbackArgument;
};

s32 func_004103D8(struct RuntimeQueryContext *context, s32 index,
                  s32 expected, s32 *actual)
{
    struct RuntimeNode *node;
    struct RuntimeNodeValue value;

    *actual = 0;
    if ((u32)index >= 4)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
        return 0;
    }

    node = context->entries[index];
    if (node == 0)
        return 0;

    value = node->value;
    *actual = value.value;
    if (context->mode == 1)
    {
        if (value.value < expected)
            return 0;
        return 1;
    }
    return value.value == expected;
}
