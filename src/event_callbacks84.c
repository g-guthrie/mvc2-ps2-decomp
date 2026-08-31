/* Exact 84-byte event callback allocation family. */
typedef unsigned char u8;
typedef struct Event { u8 pad00[16]; void *callback; u8 pad14[4]; void *arg; u8 pad1c[4]; u8 mode; } Event;
extern Event *func_003DA750(int, int, int);
extern void func_001A7990(void);
extern void func_001A8D50(void);
extern void func_001AC840(void);
extern void func_001AFD10(void);
extern void func_001B1000(void);
extern void func_001BC7A0(void);
extern void func_001BE020(void);
extern void func_001BE8F0(void);
extern void func_001C0A70(void);
extern void func_001C1450(void);
extern void func_001C5870(void);
extern void func_00362060(void);
extern void func_00363250(void);
extern void func_00363CB0(void);
extern void func_0036AB90(void);
extern void func_0036C120(void);
extern void func_0037E500(void);
extern void func_00380CC0(void);
extern void func_00385A80(void);
extern void func_00388910(void);
extern void func_00389350(void);
extern void func_003899B0(void);
extern void func_0038D3F0(void);
extern void func_0041A090(void);
void func_001A78D0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001A7990;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001A7930(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 4, 0);
    if (event != 0) {
        event->callback = func_001A7990;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001A8CF0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001A8D50;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001AC7E0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001AC840;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001AFCB0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001AFD10;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001B0F40(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001B1000;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001BC660(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001BC7A0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001BC6C0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 4, 0);
    if (event != 0) {
        event->callback = func_001BC7A0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001BDFC0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001BE020;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001BE890(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001BE8F0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001C09A0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001C0A70;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001C13F0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001C1450;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001C57B0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 3, 0);
    if (event != 0) {
        event->callback = func_001C5870;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_001C5810(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 4, 0);
    if (event != 0) {
        event->callback = func_001C5870;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00362000(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00362060;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_003631F0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00363250;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00363BD0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00363CB0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_0036A8D0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_0036AB90;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_0036BFF0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_0036C120;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_0037E4A0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_0037E500;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00380C60(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00380CC0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00385A20(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00385A80;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_003888B0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00388910;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_003892F0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_00389350;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00389950(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_003899B0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_0038D390(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_0038D3F0;
        event->arg = arg;
        event->mode = mode;
    }
}
void func_00419FE0(void *arg, u8 mode) {
    Event *event = func_003DA750(0, 1, 0);
    if (event != 0) {
        event->callback = func_0041A090;
        event->arg = arg;
        event->mode = mode;
    }
}
