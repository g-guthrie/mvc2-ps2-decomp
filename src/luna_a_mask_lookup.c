typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object {
    u8 pad[5];
    u8 disabled;
    u8 pad2[0x1E4 - 0x06];
    u8 type;
} Object;

extern volatile u16 D_004461C0[];

u32 func_0016A210(Object *object, int index) {
    if (object->disabled)
        return 0;
    return D_004461C0[object->type] & (1u << index);
}
