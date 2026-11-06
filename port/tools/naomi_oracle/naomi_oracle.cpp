/*
 * naomi_oracle: runs the NAOMI arcade program (the user's own mvsc2.zip and
 * NAOMI BIOS naomi.zip, MAME sets) in the Flycast core, headless (no window,
 * no renderer: NO_REND, null audio, no frame limit), deterministic, with the
 * same state-driven input scripts as the port and the PS2 oracle (--script),
 * and dumps the gameplay state once per game frame (naomi_dump.h) for
 * naomi_compare.py.
 *
 * Frame boundary: a guest-PC hook (naomi_oracle.patch: the SH-4 dynarec's
 * block decoder calls oracle_call_hook() before the first instruction of a
 * block that starts at a hook PC, and splits blocks there) at 0x0C0283D6 in
 * the main loop 0x0C028394, right after the V-blank wait 0x0C1E9B20.
 *
 * Input: the script's PS2 pad bits are mapped to JVS buttons (square LP,
 * triangle HP, l1 A1, cross LK, circle HK, r1 A2, start, the d-pad; plus the
 * NAOMI-only "coin", "test", "service") and given to the emulated JVS I/O
 * board, so the game reads them through its own V-blank path.
 *
 * Usage (from the flycast binary): flycast --naomi-oracle --game mvsc2.zip
 *     --home DIR (holds naomi.zip; NVRAM/EEPROM files are written there:
 *     use a fresh copy per run) [--script FILE] [--frames N] [--dump FILE]
 *     [--dump-from N] [--resync STATE] [--press F:BTN[:LEN]] [--hook ADDR]
 *     [--trace ADDR] [--poke F:ADDR:SIZE:VALUE] [--region N] [--no-freeplay]
 *     [--interp] [--snap F:FILE] [--p1-team a,b,c] [--cpu-team a,b,c] [-v]
 */
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <string>
#include <vector>

#include "types.h"
#include "emulator.h"
#include "cfg/option.h"
#include "cfg/cfg.h"
#include "stdclass.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_if.h"
#include "hw/mem/addrspace.h"
#include "hw/maple/maple_devs.h"
#include "hw/pvr/Renderer_if.h"
#include "log/LogManager.h"
#include "oracle/oracle_hook.h"
#include "naomi_dump.h"

void common_linux_setup();

/* ---- RAM ------------------------------------------------------------------ */
static u8* ramp(u32 a) { return &mem_b[a & RAM_MASK]; }
static u32 rd32(u32 a) { u32 v; memcpy(&v, ramp(a), 4); return v; }
static u16 rd16(u32 a) { u16 v; memcpy(&v, ramp(a), 2); return v; }
static u8 rd8(u32 a) { return *ramp(a); }
static void wr32(u32 a, u32 v) { memcpy(ramp(a), &v, 4); }
static void wr16(u32 a, u16 v) { memcpy(ramp(a), &v, 2); }
static void wr8(u32 a, u8 v) { *ramp(a) = v; }

static int game_state()
{
	return rd8(NAOMI_G) << 16 | rd8(NAOMI_G + 1) << 8 | rd8(NAOMI_G + 2);
}

/* ---- script (port/host/fe/fe_main.c's language, as in the PS2 oracle) ---- */
static const struct { const char* n; u32 bit; } BTN[] = {
	{"start", 0x0008}, {"select", 0x0001}, {"cross", 0x4000}, {"circle", 0x2000},
	{"square", 0x8000}, {"triangle", 0x1000}, {"up", 0x0010}, {"down", 0x0040},
	{"left", 0x0080}, {"right", 0x0020}, {"l1", 0x0400}, {"r1", 0x0800}, {"l2", 0x0100},
	{"r2", 0x0200},
	/* NAOMI only (bits above the PS2 pad's 16) */
	{"coin", 0x10000}, {"test", 0x20000}, {"service", 0x40000},
};

/* PS2 pad bit -> JVS button (the PS2 game's default BUTTON CONFIG) */
static const struct { u32 ps2; u32 jvs; } JMAP[] = {
	{0x0008, NAOMI_START_KEY}, {0x0010, NAOMI_UP_KEY}, {0x0040, NAOMI_DOWN_KEY},
	{0x0080, NAOMI_LEFT_KEY}, {0x0020, NAOMI_RIGHT_KEY},
	{0x8000, NAOMI_BTN0_KEY}, /* square: light punch */
	{0x1000, NAOMI_BTN1_KEY}, /* triangle: heavy punch */
	{0x0400, NAOMI_BTN2_KEY}, /* l1: assist 1 */
	{0x4000, NAOMI_BTN3_KEY}, /* cross: light kick */
	{0x2000, NAOMI_BTN4_KEY}, /* circle: heavy kick */
	{0x0800, NAOMI_BTN5_KEY}, /* r1: assist 2 */
	{0x10000, NAOMI_COIN_KEY}, {0x20000, NAOMI_TEST_KEY}, {0x40000, NAOMI_SERVICE_KEY},
};

static struct
{
	std::vector<std::string> line;
	int pc = 0, timer = 0, count = 0;
} S;
static long g_frame = -1;
static bool g_quit = false;

static int state_match(const char* want)
{
	char cur[32];
	int st = game_state();
	/* five levels, as the port's (fe_main.c): g[3], g[4] are sub-states */
	snprintf(cur, sizeof cur, "%d/%d/%d/%d/%d", st >> 16, (st >> 8) & 0xFF, st & 0xFF, rd8(NAOMI_G + 3), rd8(NAOMI_G + 4));
	size_t n = strlen(want);
	return strncmp(cur, want, n) == 0 && (cur[n] == 0 || cur[n] == '/' || want[n - 1] == '/');
}

static void script_buttons(const char* spec, u32* b0, u32* b1)
{
	char buf[128], *t, *save = NULL;
	*b0 = *b1 = 0;
	snprintf(buf, sizeof buf, "%s", spec);
	for (t = strtok_r(buf, "+", &save); t; t = strtok_r(NULL, "+", &save))
	{
		int p2 = !strncmp(t, "p2:", 3);
		const char* nm = p2 ? t + 3 : t;
		for (const auto& k : BTN)
			if (!strcmp(nm, k.n)) *(p2 ? b1 : b0) |= k.bit;
	}
}

static void script_step(u32* b0, u32* b1)
{
	char cmd[32] = "", a1[160] = "", a2[64] = "", a3[32] = "";
	*b0 = *b1 = 0;
	while (S.pc < (int)S.line.size())
	{
		cmd[0] = a1[0] = a2[0] = a3[0] = 0;
		sscanf(S.line[S.pc].c_str(), "%31s %159s %63s %31s", cmd, a1, a2, a3);
		if (!strcmp(cmd, "state"))
		{
			int max = a2[0] ? atoi(a2) : 7200;
			if (state_match(a1)) { S.pc++; S.timer = 0; continue; }
			if (++S.timer > max)
			{
				fprintf(stderr, "[naomi] script: line %d: state %s not reached in %d frames (now %06X)\n", S.pc + 1, a1, max, game_state());
				S.pc++; S.timer = 0; continue;
			}
			return;
		}
		else if (!strcmp(cmd, "wait"))
		{
			if (S.timer++ < atoi(a1)) return;
			S.pc++; S.timer = 0; continue;
		}
		else if (!strcmp(cmd, "press"))
		{
			int len = a2[0] ? atoi(a2) : 6;
			if (S.timer < len) { script_buttons(a1, b0, b1); S.timer++; return; }
			if (S.timer++ < len + 6) return;
			S.pc++; S.timer = 0; continue;
		}
		else if (!strcmp(cmd, "hold"))
		{
			int len = a2[0] ? atoi(a2) : 1;
			if (S.timer < len) { script_buttons(a1, b0, b1); S.timer++; return; }
			S.pc++; S.timer = 0; continue;
		}
		else if (!strcmp(cmd, "until"))
		{
			int gap = a3[0] ? atoi(a3) : 30;
			if (S.timer == 0 && state_match(a1)) { S.pc++; S.count = 0; continue; }
			if (S.count > 200)
			{
				fprintf(stderr, "[naomi] script: line %d: state %s not reached after 200 presses (now %06X)\n", S.pc + 1, a1, game_state());
				S.pc++; S.count = 0; S.timer = 0; continue;
			}
			if (S.timer < 6) script_buttons(a2, b0, b1);
			if (++S.timer >= gap) { S.timer = 0; S.count++; }
			return;
		}
		else if (!strcmp(cmd, "shot"))
		{
			if (S.timer == 0) { S.timer = 1; return; }
			S.timer = 0;
			fprintf(stderr, "[naomi] shot %s at frame %ld state %06X\n", a1, g_frame, game_state());
			S.pc++; continue;
		}
		else if (!strcmp(cmd, "quit"))
		{
			fprintf(stderr, "[naomi] script: done at frame %ld\n", g_frame);
			g_quit = true;
			S.pc = (int)S.line.size();
			return;
		}
		else
		{
			/* commands the port knows and the oracle does not (e.g. "arcade")
			 * are skipped */
			fprintf(stderr, "[naomi] script: line %d: unknown command %s\n", S.pc + 1, cmd);
			S.pc++;
		}
	}
}

static int script_load(const char* path)
{
	FILE* f = fopen(path, "r");
	char ln[256];
	if (!f) return -1;
	while (fgets(ln, sizeof ln, f))
	{
		char* c = strchr(ln, '#');
		if (c) *c = 0;
		for (c = ln + strlen(ln); c > ln && (c[-1] == '\n' || c[-1] == ' ' || c[-1] == '\r' || c[-1] == '\t'); c--)
			c[-1] = 0;
		for (c = ln; *c == ' ' || *c == '\t'; c++)
			;
		if (*c) S.line.push_back(c);
	}
	fclose(f);
	return 0;
}

/* ---- options ---------------------------------------------------------------- */
struct Poke { long frame; u32 addr; int size; u32 value; std::string state; int done; };
struct Press { long frame; int len; u32 bits; };
static struct
{
	long frames = 0;
	FILE* dump = nullptr;
	long dump_from = 0;
	std::vector<Press> press;
	std::vector<Poke> poke;
	std::vector<std::pair<long, std::string>> snap;
	std::vector<u32> trace;
	long trace_from = 0, trace_to = 1L << 30;
	int verbose = 0;
	u32 hook = NAOMI_HOOK;
	const char* resync = nullptr;
	int resynced = 0;
	u32 last_pads = 0;
} O;

static u32 jvs_of(u32 ps2)
{
	u32 j = 0;
	for (const auto& m : JMAP)
		if (ps2 & m.ps2) j |= m.jvs;
	return j;
}

/* the same values as port/tools/oracle/dump_format.h oracle_resync(), at the
 * NAOMI addresses (g + 0x10 / 0x1C / 0x20 have the same offsets) */
static void naomi_resync()
{
	wr8(NAOMI_RNG_LO, 0x5A); /* PS2 D_004C26AC */
	wr8(NAOMI_RNG_HI, 0xA5); /* PS2 D_004C26B0 */
	wr32(NAOMI_G + 0x10, 10000);
	wr32(NAOMI_G + 0x1C, 10000);
	wr32(NAOMI_G + 0x20, 0);
}

static void dump_record(FILE* f, u32 frame, u32 pads)
{
	static u8 reg[NAOMI_REGION_HI - NAOMI_REGION_LO];
	u32 hdr[8];
	for (u32 a = NAOMI_REGION_LO; a < NAOMI_REGION_HI; a++)
		reg[a - NAOMI_REGION_LO] = rd8(a);
	hdr[0] = NAOMI_MAGIC;
	hdr[1] = frame;
	hdr[2] = (pads & 0xFFFF) | (pads >> 16 & 0xFFFF) << 16;
	hdr[3] = game_state();
	hdr[4] = rd8(NAOMI_RNG_LO) | (u32)rd8(NAOMI_RNG_HI) << 8;
	hdr[5] = (u32)g_frame;
	hdr[6] = 0;
	hdr[7] = 0;
	fwrite(hdr, 4, 8, f);
	fwrite(reg, 1, sizeof reg, f);
	fflush(f);
}

static void snap(const char* path)
{
	FILE* f = fopen(path, "wb");
	if (!f) return;
	/* NAOMI main RAM, 0x0C000000..0x0D000000 (16 MB) */
	for (u32 a = 0x0C000000; a < 0x0D000000; a += 0x10000)
		fwrite(ramp(a), 1, 0x10000, f);
	fclose(f);
	fprintf(stderr, "[naomi] snap %s at frame %ld\n", path, g_frame);
}

static void on_frame()
{
	g_frame++;
	if (O.verbose && (g_frame % 600) == 0)
		fprintf(stderr, "[naomi] frame %ld state %06X\n", g_frame, game_state());
	{
		static int last = -1;
		int st = game_state();
		if (st != last)
		{
			fprintf(stderr, "[naomi] frame %ld: game state g[0..2] = %d %d %d\n", g_frame, st >> 16, (st >> 8) & 0xFF, st & 0xFF);
			last = st;
		}
	}
	u32 b0 = 0, b1 = 0;
	for (const auto& p : O.press)
		if (g_frame >= p.frame && g_frame < p.frame + p.len) b0 |= p.bits;
	if (!S.line.empty())
	{
		u32 s0, s1;
		script_step(&s0, &s1);
		b0 |= s0;
		b1 |= s1;
	}
	oracle_jvs_buttons[0] = jvs_of(b0);
	oracle_jvs_buttons[1] = jvs_of(b1);
	for (auto& p : O.poke)
	{
		if (p.done) continue;
		if (p.state.empty() ? g_frame != p.frame : !state_match(p.state.c_str())) continue;
		if (p.size == 1) wr8(p.addr, (u8)p.value);
		else if (p.size == 2) wr16(p.addr, (u16)p.value);
		else wr32(p.addr, p.value);
		p.done = p.state.empty() ? 1 : 0;
		if (!p.state.empty()) p.done = 1;
		fprintf(stderr, "[naomi] poke %08X = %X (frame %ld)\n", p.addr, p.value, g_frame);
	}
	if (O.resync && !O.resynced && state_match(O.resync))
	{
		O.resynced = 1;
		naomi_resync();
		fprintf(stderr, "[naomi] resync at frame %ld (state %06X)\n", g_frame, game_state());
	}
	if (O.dump && g_frame >= O.dump_from)
		dump_record(O.dump, (u32)g_frame, b0 | b1 << 16);
	for (const auto& s : O.snap)
		if (s.first == g_frame) snap(s.second.c_str());
	if (O.frames > 0 && g_frame >= O.frames)
	{
		g_quit = true;
		emu.getSh4Executor()->Stop();
	}
}

/* --p1-team / --cpu-team a,b,c (ID or ID:T, T = assist type 0..2), as the
 * port's (port/host/arcade.c): side 0 / side 1 records (0, 2, 4 / 1, 3, 5)
 * get the character id (+0x52C, PS2 +0x540) when the
 * game loads a player's PAK (0x0C02764C, r4 = the player: the twin of PS2
 * func_0012EF50) and at the fight's load pass over all six (0x0C0230C6);
 * the assist type (+0x4C9, PS2 +0x4DD) when given */
#define HOOK_PAK 0x0C02764Cu
#define HOOK_LOADALL 0x0C0230C6u
static int team_id[2][3] = {{-1, -1, -1}, {-1, -1, -1}}, team_assist[2][3] = {{-1, -1, -1}, {-1, -1, -1}};
static int team_pal[2][3] = {{-1, -1, -1}, {-1, -1, -1}};
static int g_teams;
static void parse_team(const char* s, int side)
{
	for (int t = 0; t < 3 && s && *s; t++)
	{
		char* e;
		long id = strtol(s, &e, 0);
		if (e != s && id >= 0 && id <= 58)
		{
			team_id[side][t] = (int)id;
			if (*e == ':') team_assist[side][t] = (int)strtol(e + 1, &e, 0);
			/* ID:T:P, P = palette (+0x52D, PS2 +0x541): the menus pick with
			 * different buttons on the two sides; the port ignores ":P" */
			if (*e == ':') team_pal[side][t] = (int)strtol(e + 1, &e, 0);
		}
		s = strchr(s, ',');
		if (s) s++;
	}
	g_teams = 1;
}
static void force_player(int i)
{
	u32 p = NAOMI_PLAYERS + i * NAOMI_PSTRIDE;
	int side = i & 1, t = i / 2;
	if (team_id[side][t] < 0) return;
	if (rd8(p + 0x52C) != team_id[side][t])
		fprintf(stderr, "[naomi] %s pick %d: character %#x (forced) at frame %ld\n", side ? "CPU" : "P1", t, team_id[side][t], g_frame);
	wr8(p + 0x52C, (u8)team_id[side][t]);
	if (team_assist[side][t] >= 0) wr8(p + 0x4C9, (u8)team_assist[side][t]);
	if (team_pal[side][t] >= 0) wr8(p + 0x52D, (u8)team_pal[side][t]);
}

static void hook(u32 pc)
{
	if (g_quit) return;
	if (pc == (O.hook & 0x1FFFFFFF))
	{
		on_frame();
		return;
	}
	if (g_teams && pc == (HOOK_PAK & 0x1FFFFFFF))
	{
		u32 r4 = Sh4cntx.r[4] & 0x1FFFFFFF, base = NAOMI_PLAYERS & 0x1FFFFFFF;
		if (r4 >= base && r4 < base + 6 * NAOMI_PSTRIDE && (r4 - base) % NAOMI_PSTRIDE == 0)
			force_player((r4 - base) / NAOMI_PSTRIDE);
		return;
	}
	if (g_teams && pc == (HOOK_LOADALL & 0x1FFFFFFF))
	{
		for (int i = 0; i < 6; i++) force_player(i);
		return;
	}
	if (g_frame >= O.trace_from && g_frame <= O.trace_to)
		fprintf(stderr, "[trace] f%ld %08X(r4=%08X r5=%08X r6=%08X r7=%08X) pr=%08X\n", g_frame, pc | 0x0C000000,
		        Sh4cntx.r[4], Sh4cntx.r[5], Sh4cntx.r[6], Sh4cntx.r[7], Sh4cntx.pr);
}

static u32 parse_buttons(const char* s)
{
	u32 b0, b1;
	script_buttons(s, &b0, &b1);
	return b0;
}

int naomi_oracle_main(int argc, char** argv)
{
	const char* game = nullptr;
	std::string home = "naomi_home";
	int region = 1, freeplay = 1, interp = 0;
	for (int i = 1; i < argc; i++)
	{
		const char* a = argv[i];
		const char* n = i + 1 < argc ? argv[i + 1] : nullptr;
		if (!strcmp(a, "--game") && n) { game = n; i++; }
		else if (!strcmp(a, "--home") && n) { home = n; i++; }
		else if (!strcmp(a, "--script") && n) { if (script_load(n)) { fprintf(stderr, "cannot read %s\n", n); return 2; } i++; }
		else if (!strcmp(a, "--frames") && n) { O.frames = atol(n); i++; }
		else if (!strcmp(a, "--dump") && n) { O.dump = fopen(n, "wb"); i++; }
		else if (!strcmp(a, "--dump-from") && n) { O.dump_from = atol(n); i++; }
		else if (!strcmp(a, "--resync") && n) { O.resync = n; i++; }
		else if (!strcmp(a, "--hook") && n) { O.hook = strtoul(n, 0, 0); i++; }
		else if (!strcmp(a, "--trace") && n) { O.trace.push_back(strtoul(n, 0, 0)); i++; }
		else if (!strcmp(a, "--trace-from") && n) { O.trace_from = atol(n); i++; }
		else if (!strcmp(a, "--trace-to") && n) { O.trace_to = atol(n); i++; }
		else if (!strcmp(a, "--p1-team") && n) { parse_team(n, 0); i++; }
		else if (!strcmp(a, "--cpu-team") && n) { parse_team(n, 1); i++; }
		else if (!strcmp(a, "--region") && n) { region = atoi(n); i++; }
		else if (!strcmp(a, "--no-freeplay")) freeplay = 0;
		else if (!strcmp(a, "--interp")) interp = 1;
		else if (!strcmp(a, "-v")) O.verbose = 1;
		else if (!strcmp(a, "--snap") && n)
		{
			const char* c = strchr(n, ':');
			if (!c) return 2;
			O.snap.push_back({atol(n), std::string(c + 1)});
			i++;
		}
		else if (!strcmp(a, "--poke") && n)
		{
			/* F:ADDR:SIZE:VALUE or STATE@ADDR:SIZE:VALUE (first frame of STATE) */
			Poke p{0, 0, 4, 0, "", 0};
			const char* at = strchr(n, '@');
			if (at)
			{
				p.state.assign(n, at - n);
				if (sscanf(at + 1, "%x:%d:%x", &p.addr, &p.size, &p.value) != 3) return 2;
			}
			else if (sscanf(n, "%ld:%x:%d:%x", &p.frame, &p.addr, &p.size, &p.value) != 4) return 2;
			O.poke.push_back(p);
			i++;
		}
		else if (!strcmp(a, "--press") && n)
		{
			char btn[64] = "";
			long f = 0;
			int len = 6;
			sscanf(n, "%ld:%63[^:]:%d", &f, btn, &len);
			O.press.push_back({f, len, parse_buttons(btn)});
			i++;
		}
		else { fprintf(stderr, "unknown option %s\n", a); return 2; }
	}
	if (!game) { fprintf(stderr, "usage: flycast --naomi-oracle --game mvsc2.zip --home DIR [...]\n"); return 2; }

	LogManager::Init();
	set_user_config_dir(home + "/");
	set_user_data_dir(home + "/");
	add_system_data_dir(home + "/");
	common_linux_setup();
	if (!addrspace::reserve()) { fprintf(stderr, "cannot reserve the address space\n"); return 1; }
	{
		/* Flycast reloads its options from emu.cfg when a game starts, so
		 * the oracle's settings go into a fresh emu.cfg in --home */
		FILE* c = fopen((home + "/emu.cfg").c_str(), "w");
		if (!c) { fprintf(stderr, "cannot write %s/emu.cfg\n", home.c_str()); return 1; }
		fprintf(c, "[config]\nDynarec.Enabled = %s\nrend.ThreadedRendering = no\naica.DSPEnabled = no\n"
		           "ForceFreePlay = %s\nDreamcast.Region = %d\nDreamcast.AutoLoadState = no\n"
		           "Dreamcast.AutoSaveState = no\nSh4Clock = 200\n\n[audio]\nbackend = null\n\n"
		           "[network]\nEnable = no\nGGPO = no\n",
		        interp ? "no" : "yes", freeplay ? "yes" : "no", region);
		fclose(c);
	}
	cfgOpen();
	config::Settings::instance().reset();
	config::Settings::instance().load(false);
	settings.aica.muteAudio = true;

	oracle_hook_pcs[oracle_nhooks++] = O.hook & 0x1FFFFFFF;
	if (g_teams)
	{
		oracle_hook_pcs[oracle_nhooks++] = HOOK_PAK & 0x1FFFFFFF;
		oracle_hook_pcs[oracle_nhooks++] = HOOK_LOADALL & 0x1FFFFFFF;
	}
	for (u32 a : O.trace)
		if (oracle_nhooks < ORACLE_MAX_HOOKS) oracle_hook_pcs[oracle_nhooks++] = a & 0x1FFFFFFF;
	oracle_pc_hook = &hook;
	oracle_jvs_override = 1;

	auto t0 = std::chrono::steady_clock::now();
	try {
		emu.init();
		emu.loadGame(game);
		rend_init_renderer(); /* NO_REND: the null renderer */
		emu.start();
	} catch (const std::exception& e) {
		fprintf(stderr, "[naomi] cannot start %s: %s\n", game, e.what());
		return 1;
	}
	long last = -2;
	int idle = 0;
	while (!g_quit)
	{
		try {
			emu.render();
		} catch (const std::exception& e) {
			fprintf(stderr, "[naomi] emulation error at frame %ld: %s\n", g_frame, e.what());
			break;
		}
		if (g_frame == last)
		{
			if (++idle == 36000) { fprintf(stderr, "[naomi] no game frame in 36000 video frames (frame %ld)\n", g_frame); break; }
		}
		else idle = 0;
		last = g_frame;
	}
	double s = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
	fprintf(stderr, "[naomi] %ld frames in %.1f s, state %06X\n", g_frame + 1, s, game_state());
	if (O.dump) fclose(O.dump);
	fflush(stderr);
	_exit(0);
}
