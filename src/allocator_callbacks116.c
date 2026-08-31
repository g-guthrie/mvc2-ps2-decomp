/* Exact 116-byte callback allocation family. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Entry {
    u8 field0; u8 field1; u8 pad2[14];
    void (*callback)(void); u8 pad20[4]; void *arg; u8 pad28[4];
    u8 field32; u8 field33; u8 pad34[4]; u16 value;
} Entry;
extern Entry *func_003DA750(int, int, int);
extern void func_001A7130(void);
void func_001A70B0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = func_001A7130;
        entry->value = 0xF00;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_0035C830(void);
void func_0035C7B0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_0035C830;
        entry->value = 0xD00;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_0035D470(void);
void func_0035D370(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_0035D470;
        entry->value = 0xD01;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_0035FA60(void);
void func_0035F9E0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_0035FA60;
        entry->value = 0xF00;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_00360100(void);
void func_00360080(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_00360100;
        entry->value = 0xF01;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003A5090(void);
void func_003A4F80(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003A5090;
        entry->value = 0x2E00;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003A5A80(void);
void func_003A5A00(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003A5A80;
        entry->value = 0x2E01;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003A5E90(void);
void func_003A5D90(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003A5E90;
        entry->value = 0x2E02;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003A6810(void);
void func_003A6790(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 2, 0);
    if (entry != 0) {
        entry->callback = func_003A6810;
        entry->value = 0x2E03;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003A7C20(void);
void func_003A7B20(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003A7C20;
        entry->value = 0x2E06;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003AFA70(void);
void func_003AF9F0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003AFA70;
        entry->value = 0x3100;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B08E0(void);
void func_003B0860(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B08E0;
        entry->value = 0x3101;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B11C0(void);
void func_003B10B0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B11C0;
        entry->value = 0x3300;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B1BF0(void);
void func_003B1B70(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B1BF0;
        entry->value = 0x3301;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B1FF0(void);
void func_003B1EF0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B1FF0;
        entry->value = 0x3302;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B28E0(void);
void func_003B2860(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 2, 0);
    if (entry != 0) {
        entry->callback = func_003B28E0;
        entry->value = 0x3303;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003B2FC0(void);
void func_003B2E90(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003B2FC0;
        entry->value = 0x3304;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003C0C60(void);
void func_003C0BE0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003C0C60;
        entry->value = 0x3700;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003C1350(void);
void func_003C11D0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003C1350;
        entry->value = 0x3701;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003C3AE0(void);
void func_003C3A60(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003C3AE0;
        entry->value = 0x3702;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
extern Entry *func_003DA750(int, int, int);
extern void func_003C4350(void);
void func_003C42D0(u8 *arg, u8 first, u8 second) {
    Entry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = func_003C4350;
        entry->value = 0x3703;
        entry->arg = arg;
        entry->field1 = arg[1];
        entry->field32 = first;
        entry->field33 = second;
    }
}
