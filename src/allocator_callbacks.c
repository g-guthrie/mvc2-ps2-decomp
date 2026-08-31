/* Exact 92-byte callback allocation family. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct CallbackEntry {
    u8 prefix[16];
    u32 callback;
    u8 callback_padding[4];
    void *arg;
    u8 arg_padding[4];
    u8 mode;
    u8 mode_padding[5];
    u16 value;
} CallbackEntry;
extern CallbackEntry *func_003DA750(int, int, int);
extern void func_0019A0F0(void);
extern void func_0019B7B0(void);
extern void func_0019C220(void);
extern void func_0019C870(void);
extern void func_0019D2D0(void);
extern void func_001B6000(void);
extern void func_001B76C0(void);
extern void func_001CE500(void);
extern void func_001CEB40(void);
extern void func_001CEB40(void);
extern void func_001D0D90(void);
extern void func_00347FF0(void);
extern void func_0034B0D0(void);
extern void func_0034BCE0(void);
extern void func_0034CCC0(void);
extern void func_0034E290(void);
extern void func_0034FB40(void);
extern void func_003521D0(void);
extern void func_00364F20(void);
extern void func_00366090(void);
extern void func_0038F960(void);
extern void func_00390870(void);
extern void func_00391710(void);
extern void func_00392930(void);
extern void func_00399790(void);
void func_0019A010(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0019A0F0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x600;
    }
}
void func_0019B750(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0019B7B0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x800;
    }
}
void func_0019C1C0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0019C220;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x901;
    }
}
void func_0019C780(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0019C870;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x903;
    }
}
void func_0019D270(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0019D2D0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0xA00;
    }
}
void func_001B5FA0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001B6000;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1500;
    }
}
void func_001B7660(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001B76C0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1600;
    }
}
void func_001CE4A0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001CE500;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2400;
    }
}
void func_001CEA00(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001CEB40;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2600;
    }
}
void func_001CEAE0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 4, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001CEB40;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2600;
    }
}
void func_001D0D30(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 3, 0);
    if (entry != 0) {
        entry->callback = (u32)func_001D0D90;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2A00;
    }
}
void func_00347F90(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00347FF0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x206;
    }
}
void func_0034B070(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0034B0D0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x400;
    }
}
void func_0034BC80(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0034BCE0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x402;
    }
}
void func_0034CC60(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0034CCC0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x405;
    }
}
void func_0034E160(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0034E290;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x502;
    }
}
void func_0034FA80(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0034FB40;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x503;
    }
}
void func_00352170(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_003521D0;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x600;
    }
}
void func_00364EC0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00364F20;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1100;
    }
}
void func_00365F60(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00366090;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1101;
    }
}
void func_0038F440(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_0038F960;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1F00;
    }
}
void func_00390810(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00390870;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x1F02;
    }
}
void func_00391650(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00391710;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2000;
    }
}
void func_003928D0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00392930;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2000;
    }
}
void func_003996C0(void *arg, u8 mode) {
    CallbackEntry *entry = func_003DA750(0, 1, 0);
    if (entry != 0) {
        entry->callback = (u32)func_00399790;
        entry->arg = arg;
        entry->mode = mode;
        entry->value = 0x2600;
    }
}
