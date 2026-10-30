/*
 * The game's main (func_00170C30, src/z2_b.c) split for a host loop (Port J):
 * mvc2_boot() runs the init calls once, mvc2_frame() runs one iteration of
 * the endless 60 Hz loop (the body of main's for (;;)), so a host can drive
 * it from emscripten_set_main_loop / its own frame callback.
 *
 * The step names are kept in mvc2_host_step for crash reports.
 */
#include <stdio.h>
#include <stdlib.h>
#include "host.h"
#include "host_loop.h"

extern void func_0012F4C0(void);
extern void func_00170BF0(void);
extern void func_003D6B70(void);
extern s32 func_0012F460(void);
extern s32 func_0016ECC0(void);
extern void func_0012F3E0(u16 *);
extern void func_003D7630(void);
extern void func_0012F450(void);
extern void func_0016EE50(void);
extern void func_00417FB0(void);
extern void func_0012F440(void);
extern void func_001E42A0(void);
extern void func_003D6FF0(void);
extern void func_00170D30(void);
extern void func_003D7400(void);
extern void func_003D7640(void);
extern void func_0012DD90(void);
extern void func_00170D70(void);

const char *volatile mvc2_host_step = "start";
volatile long mvc2_host_frame = -1;
int mvc2_trace_state = 1;
int mvc2_unlock_all = 1;

/* "Unlock everything" (host option, default on; --no-unlock).  The Secret
 * Factor / save-data unlock state, as the shop (func_0014C... in
 * src/fb23_f.c) and the save loader (func_0038B8C0, src/r3_30_d.c) use it:
 *   g = D_004F4300 (D_004C2840): +0x30, +0x34  characters (bit = id; 0x20+ in +0x34)
 *                                +0x38, +0x3C  extra colours / costumes
 *   D_004F7FB4, D_004F7FB8      other shop items (func_001317F0: gallery, EX)
 *   D_004D179A                  shop level counter (0..7)
 * Applied every frame (OR), so the defaults written by func_003D6B70 and a
 * loaded save both end up fully unlocked; nothing is ever cleared. */
static void unlock_everything(void)
{
    u8 *g = (u8 *)EE_BSS_PTR(0x004F4300);
    static int parts = -1;
    if (parts < 0) {
        const char *e = getenv("MVC2_UNLOCK_PARTS");
        parts = e ? atoi(e) : 15;
    }
    if (parts & 1) {
        *(u32 *)(g + 0x30) = 0xFFFFFFFFu;
        *(u32 *)(g + 0x34) = 0xFFFFFFFFu;
    }
    if (parts & 2) {
        *(u32 *)(g + 0x38) = 0xFFFFFFFFu;
        *(u32 *)(g + 0x3C) = 0x07FFFFFFu; /* ids 0x20..0x3A */
    }
    if (parts & 4) {
        EE_BSS(u32, 0x004F7FB4) = 0xFFFFFFFFu;
        EE_BSS(u32, 0x004F7FB8) = 0xFFFFFFFFu;
    }
    if ((parts & 8) && EE_BSS(u8, 0x004D179A) < 7)
        EE_BSS(u8, 0x004D179A) = 7;
}

#define STEP(name, call) do { mvc2_host_step = name; call; } while (0)

int mvc2_boot(int run_platform_init)
{
    s32 r = 1;
    extern int host_fill_ee_holes(void);
    mvc2_host_frame = -1;
    host_fill_ee_holes();  /* EE data without C, from the disc's executable */
    {
        extern void arcade_init(void);
        arcade_init();     /* optional NAOMI tables (MVC2_ARCADE / MVC2_NAOMI) */
    }
    if (run_platform_init) {
        STEP("func_003EC160 platform init (640x480)", r = func_003EC160());
        if (r == 0)
            host_log("platform init returned 0 (the PS2 main retries forever); continuing");
    }
    STEP("func_0012F4C0 game init (heaps, resources, sound, fonts)", func_0012F4C0());
    STEP("func_00170BF0 file queue reset", func_00170BF0());
    STEP("func_003D6B70 state init", func_003D6B70());
    mvc2_host_frame = 0;
    return r;
}

static int last_state = -1;

void mvc2_frame(void)
{
    u8 *g = (u8 *)EE_BSS_PTR(0x004F4300);
    int st = g[0] << 16 | g[1] << 8 | g[2];
    if (mvc2_trace_state && st != last_state) {
        host_log("frame %ld: game state g[0..2] = %d %d %d", mvc2_host_frame, g[0], g[1], g[2]);
        last_state = st;
    }
    if (mvc2_unlock_all)
        unlock_everything();
    STEP("func_0012F460 frame counters / CRI tick / pad", func_0012F460());
    STEP("func_0016ECC0 network stubs", func_0016ECC0());
    STEP("func_0012F3E0 auto-repeat P1", func_0012F3E0((u16 *)EE_BSS_PTR(0x004F4480)));
    STEP("func_0012F3E0 auto-repeat P2", func_0012F3E0((u16 *)EE_BSS_PTR(0x004F4494)));
    STEP("func_003D7630 overlay counters", func_003D7630());
    STEP("func_0012F450", func_0012F450());
    if (EE_BSS(s32, 0x004C2870) == 1 && EE_BSS(u8, 0x004D17C2) != 1) {
        STEP("func_0016EE50 soft reset", func_0016EE50());
        STEP("func_00417FB0 flip", func_00417FB0());
        STEP("func_0012F440", func_0012F440());
        EE_BSS(s32, 0x004C2870) = 0;
    }
    STEP("func_001E42A0 sound tick", func_001E42A0());
    EE_BSS(s32, 0x004C2848) = 0;
    EE_BSS(s32, 0x004C284C) = 0;
    STEP("func_003D6FF0 game update", func_003D6FF0());
    STEP("func_00170D30 begin scene", func_00170D30());
    STEP("func_003D7400 render pass 1", func_003D7400());
    STEP("func_003D7640 render pass 2", func_003D7640());
    STEP("func_0012DD90 file loader tick", func_0012DD90());
    STEP("func_00170D70 end scene", func_00170D70());
    STEP("func_003ECD00 vsync/flip", func_003ECD00());
    mvc2_host_frame++;
}

int mvc2_game_state(void)
{
    u8 *g = (u8 *)EE_BSS_PTR(0x004F4300);
    return g[0] << 16 | g[1] << 8 | g[2];
}
