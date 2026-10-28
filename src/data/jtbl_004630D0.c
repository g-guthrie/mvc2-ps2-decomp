/* State tables reached with (object, work): 00358DD0 dispatches the
 * first with work = object+0x88, and 003593F0 forwards the work pointer
 * it receives from 00359410 to the second. */
typedef unsigned char u8;
typedef void (*EventPhase)(u8 *, u8 *);
extern void lbl_00358E30(u8 *, u8 *);
extern void func_00358F30(u8 *, u8 *);
extern void func_0035AE40(u8 *, u8 *);
extern void func_0035AE60(u8 *, u8 *);
extern void func_00359240(u8 *, u8 *);
extern void func_00359330(u8 *, u8 *);
extern void func_003593D0(u8 *, u8 *);

typedef struct {
    EventPhase phase[4];
    EventPhase child[3];
} EventPhaseTables;
const EventPhaseTables jtbl_004630D0 = {{
    lbl_00358E30,
    func_00358F30,
    func_0035AE40,
    func_0035AE60,
}, {
    func_00359240,
    func_00359330,
    func_003593D0,
}};
