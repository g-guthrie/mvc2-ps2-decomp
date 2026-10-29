/* Adapted from the ICO decompilation (github.com/nathanialf/ico,
 * sce/libcdvd/cdvd000.c), Copyright (c) 2026 the ico decompilation
 * contributors, MIT License (see LICENSES/MIT-ico-decomp.txt). */
/* func_0010F3C8: libcdvd sceCdInit(mode).
   Sony EE GCC 2.9-991111 cc1 + GNU as 2.10-ee-001003-1:
     ./trysony29x.sh src/r15_07_a.c EE29CC1 EEAS210 0 O2
   (also exact with the SN assembler, and with the 991111-01 cc1).
   Spelling follows the libcdvd decompilation in the ICO decomp
   (sce/libcdvd/cdvd000.c); this game's older libcdvd has nop busy-waits.
   Storing init_bind (D_004399CC) before init_sdata in the serve block
   shortens hi(D_004399CC)'s live range so global-alloc gives it $s4. */
typedef struct {
    char pad[0x24];
    int serve;
} RpcCd;

extern int D_00439990; /* SCE_CD_debug */
extern int D_004399A0; /* cb_semid */
extern int D_004399A4; /* poff_busy */
extern int D_004399A8; /* _sceCd_ncmd_semid */
extern int D_004399AC; /* _sceCd_scmd_semid */
extern volatile int D_004399B4; /* _sceCd_ee_read_mode */
extern int D_004399B8; /* ncmd_bind */
extern int D_004399BC; /* poff_bind */
extern int D_004399C0; /* search_bind */
extern int D_004399C4; /* diskready_bind */
extern int D_004399C8; /* scmd_bind */
extern int D_004399CC; /* init_bind */
extern int D_004399D0; /* init_count */
extern int D_004C8650; /* cd_thread_id */
extern RpcCd D_004C8868; /* init_cd */
extern int D_004C88C0; /* init_sdata */
extern int D_0043AB80[]; /* _sceCd_scmdrdata */

extern char D_004AB4F8[]; /* msg_bind */
extern char D_004AB518[]; /* msg_exit */
extern int func_0010F1E8(int); /* sceCdSyncS */
extern void func_00106628(int); /* sceSifInitRpc */
extern int func_00103CD0(void); /* GetThreadId */
extern int func_00106C98(RpcCd *, unsigned int, int); /* sceSifBindRpc */
extern int func_00105E80(const char *, ...); /* scePrintf */
extern void func_00106578(void *, int); /* sceSifWriteBackDCache */
extern int func_00106E68(RpcCd *, int, int, void *, int, void *, int, void *, void *); /* sceSifCallRpc */
extern void func_0010EA40(void); /* cdvd_exit */
extern void func_0010E9A8(void); /* cmd_sem_init */
extern int func_0010EB90(void); /* PowerOffCB */

int func_0010F3C8(int mode)
{
    int *p;
    int ver;
    int r;
    int w;
    int type;
    int v1;
    int v2;

    if (func_0010F1E8(1) != 0) {
        return 0;
    }
    func_00106628(0);
    D_004C8650 = func_00103CD0();
    *(volatile int *)&D_004399A4 = 1;
    D_004399C0 = -1;
    D_004399B8 = -1;
    D_004399C8 = -1;
    D_004399C4 = -1;
    D_004399CC = -1;
    D_004399BC = -1;
    D_004399B4 = 0;
    D_004399D0++;
    while (1) {
        r = func_00106C98(&D_004C8868, 0x80000592, 0);
        if (r < 0) {
            if (D_00439990 > 0) {
                func_00105E80(D_004AB4F8, r, D_004399D0);
            }
            w = 0x100000;
            do { w--; __asm__ volatile ("nop"); } while (w != -1);
            continue;
        }
        if (D_004C8868.serve != 0) {
            D_004399CC = 0;
            D_004C88C0 = mode;
            func_00106578(&D_004C88C0, 4);
            p = D_0043AB80;
            if (func_00106E68(&D_004C8868, 0, 0, &D_004C88C0, 4, p, 16, 0, 0) < 0) {
                *(volatile int *)&D_004399A4 = 0;
                return 0;
            }
            break;
        }
        w = 0x100000;
        do { w--; __asm__ volatile ("nop"); } while (w != -1);
    }
    v1 = *(int *)((int)(p + 1) | 0x20000000);
    v2 = *(int *)((int)(p + 2) | 0x20000000);
    type = *(int *)((int)(p + 3) | 0x20000000);
    ver = 1;
    if (type == 0xFF) {
    } else if (type == 0xFE) {
        D_00439990 = 1;
    } else if (v1 / 256 < 2 || v2 / 256 < 2) {
        ver = 2;
    }
    *(volatile int *)&D_004399A4 = 0;
    switch (mode) {
    case 5:
        if (D_00439990 > 0) {
            func_00105E80(D_004AB518);
        }
        func_0010EA40();
        *(volatile int *)&D_004399A8 = -1;
        *(volatile int *)&D_004399AC = -1;
        *(volatile int *)&D_004399A0 = -1;
        break;
    case 0:
    case 1:
    default:
        func_0010E9A8();
        func_0010EB90();
        break;
    }
    return ver;
}
