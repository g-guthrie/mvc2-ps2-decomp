/* Remaining unmatched func_003DA750 event-allocator wrappers. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

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
    int field_d0;
} Event;

extern Event *func_003DA750(int, int, int);

extern void func_00329100(void);
extern void func_00329750(void);
extern void func_00387380(void);
extern void func_00387C90(void);
extern void func_003A8B70(void);
extern void func_001C8B70(void);
extern void func_00329810(void);
extern void func_003289F0(void);
extern void func_00328C70(void);
extern void func_00328EC0(void);
extern void func_00329510(void);
extern void func_001E0AC0(void);
extern void func_0019BAD0(void);
extern void func_001BF460(void);
extern void func_0019B170(void);
extern void func_003A08F0(void);
extern void func_003A12E0(void);
extern void func_00194170(void);
extern void func_001CAF00(void);
extern void func_00346820(void);
extern void func_00346AC0(void);
extern void func_00390D00(void);
extern void func_003B6AA0(void);

void func_003290B0(void *arg) {
    Event *event = func_003DA750(0, 12, 1);
    if (event != 0) {
        event->value = 5;
        event->callback = func_00329100;
        event->arg = arg;
    }
}
void func_00329700(void *arg) {
    Event *event = func_003DA750(0, 12, 1);
    if (event != 0) {
        event->value = 9;
        event->callback = func_00329750;
        event->arg = arg;
    }
}

void func_00387330(int pool, u8 mode) {
    Event *event = func_003DA750(pool, 1, 2);
    if (event != 0) {
        event->callback = func_00387380;
        event->arg = (void *)pool;
        event->field20 = mode;
    }
}
void func_00387C40(int pool, u8 mode) {
    Event *event = func_003DA750(pool, 1, 2);
    if (event != 0) {
        event->callback = func_00387C90;
        event->arg = (void *)pool;
        event->field20 = mode;
    }
}

void func_003A8B10(u8 *arg) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003A8B70;
        event->arg = arg;
        event->value = 0x2f01;
        event->field_d0 = *(u16 *)(arg + 0x168);
    }
}

void func_001C8B10(s8 *arg) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001C8B70;
        event->arg = arg;
        event->value = 0x1e02;
        event->field20 = arg[0x161];
    }
}

void func_003297B0(u8 *arg) {
    Event *event = func_003DA750(0, 12, 0);
    if (event != 0) {
        event->callback = func_00329810;
        event->arg = arg;
        event->field1 = arg[1];
        event->value = 0xa;
    }
}

void func_00328990(s8 *arg) {
    Event *event = func_003DA750(0, 12, 0);
    if (event != 0) {
        event->callback = func_003289F0;
        event->arg = arg;
        event->value = 0x200;
        arg[0x23d]++;
    }
}
void func_00328C10(s8 *arg) {
    Event *event = func_003DA750(0, 12, 0);
    if (event != 0) {
        event->callback = func_00328C70;
        event->arg = arg;
        event->value = 0x300;
        arg[0x23d]++;
    }
}
void func_00328E60(s8 *arg) {
    Event *event = func_003DA750(0, 12, 0);
    if (event != 0) {
        event->callback = func_00328EC0;
        event->arg = arg;
        event->value = 0x400;
        arg[0x23d]++;
    }
}
void func_003294B0(s8 *arg) {
    Event *event = func_003DA750(0, 12, 0);
    if (event != 0) {
        event->callback = func_00329510;
        event->arg = arg;
        event->value = 0x700;
        arg[0x23d]++;
    }
}

void func_001E0A60(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 1);
    if (event != 0) {
        event->callback = func_001E0AC0;
        event->arg = arg;
        event->value = 0x3a00;
        event->field20 = mode;
    }
}

void func_0019BA70(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_0019BAD0;
        event->field20 = mode;
        event->arg = arg;
        event->value = 0x801;
    }
}
void func_001BF350(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001BF460;
        event->field20 = mode;
        event->arg = arg;
        event->value = 0x1901;
    }
}

void func_0019B110(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 1);
    if (event != 0) {
        event->value = 0x700;
        event->field20 = mode;
        event->callback = func_0019B170;
        event->arg = arg;
    }
}
void func_003A0890(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 1);
    if (event != 0) {
        event->value = 0x2b00;
        event->field20 = mode;
        event->callback = func_003A08F0;
        event->arg = arg;
    }
}
void func_003A1280(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 1);
    if (event != 0) {
        event->value = 0x2b02;
        event->field20 = mode;
        event->callback = func_003A12E0;
        event->arg = arg;
    }
}

void func_001940A0(u8 *arg) {
    Event *event = func_003DA750(0, 3, 1);
    if (event != 0) {
        event->callback = func_00194170;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = 0;
        event->field21 = 0;
        event->value = 0x301;
    }
}
void func_001CAEA0(u8 *arg) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001CAF00;
        event->field20 = 0;
        event->field21 = 0;
        event->arg = arg;
        event->field1 = arg[1];
        event->value = 0x1f02;
    }
}
void func_003467C0(u8 *arg) {
    Event *event = func_003DA750(0, 1, 1);
    if (event != 0) {
        event->callback = func_00346820;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = 0;
        event->field21 = 0;
        event->value = 0x100;
    }
}
void func_00346A60(u8 *arg) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00346AC0;
        event->arg = arg;
        event->field1 = arg[1];
        event->field20 = 0;
        event->field21 = 0;
        event->value = 0x101;
    }
}

void func_00390BE0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00390D00;
        event->arg = arg;
        event->field20 = mode;
        event->field21 = 0;
        event->value = 0x1f03;
    }
}
void func_003B69D0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003B6AA0;
        event->arg = arg;
        event->field20 = mode;
        event->field21 = 0;
        event->value = 0x3403;
    }
}


