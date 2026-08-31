/* Exact 76-byte allocator/callback-registration family. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct EventEntry { u8 pad_00[16]; void *callback; u8 pad_14[4]; void *arg; u8 pad_1c[10]; u16 event_id; } EventEntry;
extern EventEntry *func_003DA750(int, int, int);
extern void func_0019C4F0(void);
extern void func_001B8B40(void);
extern void func_001B8E10(void);
extern void func_001B9000(void);
extern void func_001B9450(void);
extern void func_001B9740(void);
extern void func_001C86A0(void);
extern void func_001CF8D0(void);
extern void func_001D6E60(void);
extern void func_001D7570(void);
extern void func_001DAD30(void);
extern void func_00377E60(void);
extern void func_00379470(void);
extern void func_0037B760(void);
extern void func_00383950(void);
extern void func_003985C0(void);
extern void func_00398D80(void);
extern void func_003B7200(void);
void func_0019C4A0(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_0019C4F0;
        entry->arg = arg;
        entry->event_id = 0x902;
    }
}
void func_001B8AF0(void *arg) {
    EventEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = func_001B8B40;
        entry->arg = arg;
        entry->event_id = 0x1604;
    }
}
void func_001B8DC0(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001B8E10;
        entry->arg = arg;
        entry->event_id = 0x1605;
    }
}
void func_001B8FB0(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001B9000;
        entry->arg = arg;
        entry->event_id = 0x1601;
    }
}
void func_001B9400(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001B9450;
        entry->arg = arg;
        entry->event_id = 0x1607;
    }
}
void func_001B96F0(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001B9740;
        entry->arg = arg;
        entry->event_id = 0x1608;
    }
}
void func_001C85D0(void *arg) {
    EventEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = func_001C86A0;
        entry->arg = arg;
        entry->event_id = 0x1E00;
    }
}
void func_001CF800(void *arg) {
    EventEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = func_001CF8D0;
        entry->arg = arg;
        entry->event_id = 0x2700;
    }
}
void func_001D6E10(void *arg) {
    EventEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = func_001D6E60;
        entry->arg = arg;
        entry->event_id = 0x2F01;
    }
}
void func_001D7520(void *arg) {
    EventEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = func_001D7570;
        entry->arg = arg;
        entry->event_id = 0x2F03;
    }
}
void func_001DACE0(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001DAD30;
        entry->arg = arg;
        entry->event_id = 0x3401;
    }
}
void func_00377E10(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_00377E60;
        entry->arg = arg;
        entry->event_id = 0x1600;
    }
}
void func_00379420(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_00379470;
        entry->arg = arg;
        entry->event_id = 0x1603;
    }
}
void func_0037B710(void *arg) {
    EventEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_0037B760;
        entry->arg = arg;
        entry->event_id = 0x1701;
    }
}
void func_00383900(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_00383950;
        entry->arg = arg;
        entry->event_id = 0x1A01;
    }
}
void func_00398570(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003985C0;
        entry->arg = arg;
        entry->event_id = 0x2501;
    }
}
void func_00398D30(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_00398D80;
        entry->arg = arg;
        entry->event_id = 0x2503;
    }
}
void func_003B71B0(void *arg) {
    EventEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B7200;
        entry->arg = arg;
        entry->event_id = 0x3404;
    }
}
