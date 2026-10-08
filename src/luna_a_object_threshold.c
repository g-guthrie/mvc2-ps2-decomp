typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad0[5];
    u8 count;
    u8 pad1[0x1C - 0x06];
    s16 state;
    u8 pad2[0x13C - 0x1E];
    u8 active;
} Object;

extern void func_001C5110(Object *);

void func_001C4D60(Object *object) {
    if (object->state < 21)
        object->count++;
    if ((object->state & 3) == 0)
        goto inactive;
    object->active = 1;
    goto done;

inactive:
    object->active = 0;
done:
    func_001C5110(object);
}
