/* Remaining func_003DA750 event-allocator wrappers. */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Event {
    u8 field0;
    u8 field1;
    u8 pad02[14];
    void *callback;
    u8 pad14[4];
    void *arg;
    u8 pad1c[4];
    u8 field20;
    u8 field21;
    u8 pad22[4];
    u16 value;
    u8 pad28[0xa8];
    u16 field_d0;
} Event;

extern Event *func_003DA750(int, int, int);

extern void func_001AD260(void);
extern void func_001B7CD0(void);
extern void func_001B8260(void);
extern void func_001B8840(void);
extern void func_001C8D40(void);
extern void func_001CBE90(void);
extern void func_001D1000(void);
extern void func_001A3250(void);
extern void func_001D56F0(void);
extern void func_001D8B30(void);
extern void func_001D9260(void);
extern void func_001D9E00(void);
extern void func_001DD9A0(void);
extern void func_001E07C0(void);
extern void func_00347280(void);
extern void func_00368000(void);
extern void func_00378D30(void);
extern void func_00383C90(void);
extern void func_00390D00(void);
extern void func_003947F0(void);
extern void func_00395A00(void);
extern void func_003605B0(void);
extern void func_00360A00(void);
extern void func_00361180(void);
extern void func_003619C0(void);
extern void func_003A6E40(void);
extern void func_003B3970(void);

void func_001B7C70(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001B7CD0;
        event->arg = arg;
        event->value = 0x1601;
        event->field20 = mode;
    }
}
void func_001B8200(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001B8260;
        event->arg = arg;
        event->value = 0x1602;
        event->field20 = mode;
    }
}
void func_001B87E0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001B8840;
        event->arg = arg;
        event->value = 0x1603;
        event->field20 = mode;
    }
}
void func_001C8CE0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001C8D40;
        event->arg = arg;
        event->value = 0x1e03;
        event->field20 = mode;
    }
}
void func_001E0760(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001E07C0;
        event->arg = arg;
        event->value = 0x3a00;
        event->field20 = mode;
    }
}
void func_003471C0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00347280;
        event->arg = arg;
        event->value = 0x201;
        event->field20 = mode;
    }
}
void func_00378CD0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00378D30;
        event->arg = arg;
        event->value = 0x1602;
        event->field20 = mode;
    }
}

void func_001AD170(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001AD260;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x1100;
    }
}
void func_001CBDA0(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001CBE90;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x2000;
    }
}
void func_001D0F90(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001D1000;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x2a01;
    }
}
void func_00367F90(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00368000;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x1102;
    }
}
void func_00383B80(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00383C90;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x1b00;
    }
}
void func_00390C40(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00390D00;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x1f03;
    }
}
void func_00394780(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003947F0;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x2100;
    }
}
void func_00395920(void *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00395A00;
        event->arg = arg;
        event->field20 = first;
        event->field21 = second;
        event->value = 0x2200;
    }
}

void func_001A31D0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001A3250;
        event->value = 0xd00;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001D5670(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001D56F0;
        event->value = 0x2e00;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001D8A30(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001D8B30;
        event->value = 0x3100;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001D8AB0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 4, 0);
    if (event != 0) {
        event->callback = func_001D8B30;
        event->value = 0x3100;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001D91E0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001D9260;
        event->value = 0x3200;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001D9D80(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001D9E00;
        event->value = 0x3300;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001DD8A0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001DD9A0;
        event->value = 0x3700;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_001DD920(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 4, 0);
    if (event != 0) {
        event->callback = func_001DD9A0;
        event->value = 0x3700;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_00360530(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003605B0;
        event->value = 0xf01;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_00360980(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00360A00;
        event->value = 0xf00;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_00361070(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00361180;
        event->value = 0xf04;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_00361940(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003619C0;
        event->value = 0xf01;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_003A6DC0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003A6E40;
        event->value = 0x2e05;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
void func_003B38F0(u8 *arg, u8 first, u8 second) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003B3970;
        event->value = 0x2e05;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = first;
        event->field21 = second;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}
