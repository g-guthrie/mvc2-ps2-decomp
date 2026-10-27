/* Provisional: state bounds, callback table ownership and owner lifetime remain open. */
typedef unsigned char u8;
typedef void (*ActorCallback)(u8 *);
extern const ActorCallback jtbl_00474320[3];
void func_003B8980(u8 *p) {
    u8 *owner;
    if (p[5] != 2) {
        owner = *(u8 **)(p + 0x14);
        if (owner[5] != 0 || owner[0x1fd] != 1 || owner[0x1e4] != 29) {
            p[5] = 2;
            *(float *)(p + 0x60) = -4.285714149475098f;
            *(float *)(p + 0x6c) = 0.5357142686843872f;
            *(float *)(p + 0x5c) = 0.0f;
            *(float *)(p + 0x68) = 0.0f;
        }
    }
    jtbl_00474320[p[5]](p);
}
