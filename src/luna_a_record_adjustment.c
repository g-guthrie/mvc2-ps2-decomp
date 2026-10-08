typedef unsigned char u8;
typedef signed char s8;

typedef struct Record Record;

typedef struct {
    u8 pad[0x14];
    Record *source;
    u8 pad1[0x31 - 0x18];
    s8 state;
    u8 pad2[2];
    float first;
    float second;
} Object;

struct Record {
    u8 pad[0x34];
    float first;
    float second;
};

void func_0019EDD0(Object *object) {
    Record *source = object->source;
    object->state = -2;
    object->first = source->first;
    object->second = 51.42857f + source->second;
}
