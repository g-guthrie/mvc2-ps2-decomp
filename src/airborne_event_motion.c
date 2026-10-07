/* Continue airborne motion until an event, owner state, or ground contact ends it. */
typedef unsigned char u8;
extern void func_00395890(u8 *);
extern void func_00395890(u8 *);
extern void func_00348440(u8 *);
extern void func_00175700(u8 *), func_001E7F60(u8 *);
extern void func_00348440(u8 *);
extern int func_00174470(u8 *);
void func_00348360(u8 *p) {
    float delta;
    if (*(signed char *)(p+0x1b3)) func_00348440(p);
    else if (!func_00174470(p)) func_00348440(p);
    else {
        p[0x24] = 0;
        if (*(float *)(p+0x38) <= *(float *)(*(u8 **)(p+0x18)+0x430)) func_00348440(p);
        else {
            func_00175700(p);
            delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
            delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
            delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
            delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
            func_001E7F60(p);
        }
    }
}
extern void func_00395160(u8 *);
extern int func_00174470(u8 *);
void func_00395040(u8 *p) {
    float delta;
    if (*(signed char *)(p+0x1b3)) func_00395160(p);
    else if (!func_00174470(p)) func_00395890(p);
    else {
        p[0x24] = 0;
        if (*(float *)(p+0x38) <= *(float *)(*(u8 **)(p+0x18)+0x430)) func_00395160(p);
        else {
            func_00175700(p);
            delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
            delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
            delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
            delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
            func_001E7F60(p);
        }
    }
}
extern void func_00395160(u8 *);
extern int func_00174470(u8 *);
void func_00395390(u8 *p) {
    float delta;
    if (*(signed char *)(p+0x1b3)) func_00395160(p);
    else if (!func_00174470(p)) func_00395890(p);
    else {
        p[0x24] = 0;
        if (*(float *)(p+0x38) <= *(float *)(*(u8 **)(p+0x18)+0x430)) func_00395160(p);
        else {
            func_00175700(p);
            delta=*(float *)(p+0x5c); *(float *)(p+0x34)+=delta;
            delta=*(float *)(p+0x68); *(float *)(p+0x5c)+=delta;
            delta=*(float *)(p+0x60); *(float *)(p+0x38)+=delta;
            delta=*(float *)(p+0x6c); *(float *)(p+0x60)+=delta;
            func_001E7F60(p);
        }
    }
}
