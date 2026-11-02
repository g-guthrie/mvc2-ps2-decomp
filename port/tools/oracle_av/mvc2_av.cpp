/*
 * mvc2_av: mvc2_oracle (port/tools/oracle/mvc2_oracle.cpp, of which this is
 * a copy: same script language, hooks, --resync and state dump) plus what
 * the player sees and hears, for port/tools/oracle_av/:
 *   --gs-dir DIR [--gs-from F] [--gs-to F] [--gs-every N]
 *       Play!'s OpenGL GS (headless EGL/GLES, Mesa llvmpipe) renders; at each
 *       flip the DISPLAYED buffer (640x224, before Play!'s presentation
 *       filter) is written as DIR/fNNNNNN.png, NNNNNN = the game frame
 *       (func_0012F460 count) that was current when the flip ran.
 *   --wav FILE    the SPU2 output (44100 Hz stereo s16), and in --snd-log the
 *                 sample position at each game frame
 *   --snd-log FILE  per frame: game state changes (G), the TSD command
 *       stream sent to the IOP (T, func_00423750's sceSifCallRpc), TSD status
 *       queries (S, func_00423990), the ADXT calls (A ...), sample position (W)
 * Original header:
 *
 * mvc2_oracle: runs the RETAIL MvC2 executable (the user's own disc image)
 * in the Play! emulator core (HLE BIOS, no PS2 BIOS needed), headless and
 * deterministic, with the same state-driven input scripts as the port
 * (--script, port/tools/scripts/), and dumps the gameplay state once per game
 * frame for port/tools/oracle/compare.py.
 *
 * Frame boundary: a hook at the entry of func_0012F460 (the first call of
 * main's 60 Hz loop, src/z2_b.c), the same point at which the port's
 * mvc2_frame() starts (port/host/game_loop.c).  The hook is Play!'s
 * breakpoint prolog, patched (play.patch) to call us and continue.
 *
 * Usage: mvc2_oracle --iso DISC.iso [--script FILE] [--frames N]
 *          [--dump FILE] [--dump-from N] [--no-unlock] [--cpu-team a,b,c]
 *          [--p1-team id] [--press F:BUTTON[:LEN]] [--srand-sync]
 * The Play! data directory (memory cards, config) is $MVC2_ORACLE_HOME
 * (default ./oracle_home); delete it for a fresh card.
 */
#include <atomic>
#include <cstdarg>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <thread>
#include <vector>

#include "AppConfig.h"
#include "PS2VM.h"
#include "PS2VM_Preferences.h"
#include "PadHandler.h"
#include "PathUtils.h"
#include "gs/GSH_Null.h"
#include "gs/GSH_OpenGL/GSH_OpenGL.h"
#include "sound/SoundHandler.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <png.h>
#include <mutex>

fs::path CAppConfig::GetBasePath() const
{
	static const auto basePath = []() {
		const char* e = getenv("MVC2_ORACLE_HOME");
		fs::path p = e ? fs::path(e) : fs::path("oracle_home");
		Framework::PathUtils::EnsurePathExists(p);
		return fs::absolute(p);
	}();
	return basePath;
}

extern void (*g_oracleBreakHook)(CMIPS*);

#include "dump_format.h"

/* ---- pad --------------------------------------------------------------- */
static uint16 g_buttons[2]; /* libpad bits, 1 = pressed (port pad.h layout) */

static const struct
{
	uint16 bit;
	PS2::CControllerInfo::BUTTON b;
} k_map[] = {
    {0x0001, PS2::CControllerInfo::SELECT},
    {0x0002, PS2::CControllerInfo::L3},
    {0x0004, PS2::CControllerInfo::R3},
    {0x0008, PS2::CControllerInfo::START},
    {0x0010, PS2::CControllerInfo::DPAD_UP},
    {0x0020, PS2::CControllerInfo::DPAD_RIGHT},
    {0x0040, PS2::CControllerInfo::DPAD_DOWN},
    {0x0080, PS2::CControllerInfo::DPAD_LEFT},
    {0x0100, PS2::CControllerInfo::L2},
    {0x0200, PS2::CControllerInfo::R2},
    {0x0400, PS2::CControllerInfo::L1},
    {0x0800, PS2::CControllerInfo::R1},
    {0x1000, PS2::CControllerInfo::TRIANGLE},
    {0x2000, PS2::CControllerInfo::CIRCLE},
    {0x4000, PS2::CControllerInfo::CROSS},
    {0x8000, PS2::CControllerInfo::SQUARE},
};

class COraclePad : public CPadHandler
{
public:
	void Update(uint8* ram) override
	{
		Apply(ram);
	}
	void Apply(uint8* ram)
	{
		for(auto* itf : m_interfaces)
		{
			for(unsigned p = 0; p < 2; p++)
			{
				for(const auto& m : k_map)
					itf->SetButtonState(p, m.b, (g_buttons[p] & m.bit) != 0, ram);
				itf->SetAxisState(p, PS2::CControllerInfo::ANALOG_LEFT_X, 0x80, ram);
				itf->SetAxisState(p, PS2::CControllerInfo::ANALOG_LEFT_Y, 0x80, ram);
				itf->SetAxisState(p, PS2::CControllerInfo::ANALOG_RIGHT_X, 0x80, ram);
				itf->SetAxisState(p, PS2::CControllerInfo::ANALOG_RIGHT_Y, 0x80, ram);
			}
		}
	}
};
static COraclePad* g_pad;

/* ---- the game's state (EE RAM) ------------------------------------------ */
static CPS2VM* g_vm;
static uint8* ram() { return g_vm->m_ee->m_ram; }
static uint32 rd32(uint32 a) { uint32 v; memcpy(&v, ram() + (a & 0x1FFFFFF), 4); return v; }
static void wr32(uint32 a, uint32 v) { memcpy(ram() + (a & 0x1FFFFFF), &v, 4); }
static uint8 rd8(uint32 a) { return ram()[a & 0x1FFFFFF]; }
static void wr8(uint32 a, uint8 v) { ram()[a & 0x1FFFFFF] = v; }

static void ee_rd(uint32_t ee, void* dst, uint32_t n) { memcpy(dst, ram() + (ee & 0x1FFFFFF), n); }

static int game_state()
{
	return rd8(0x004F4300) << 16 | rd8(0x004F4301) << 8 | rd8(0x004F4302);
}

/* ---- script (same language as port/host/fe/fe_main.c) ------------------- */
static const struct
{
	const char* n;
	uint16 bit;
} BTN[] = {
    {"start", 0x0008}, {"select", 0x0001}, {"cross", 0x4000}, {"circle", 0x2000},
    {"square", 0x8000}, {"triangle", 0x1000}, {"up", 0x0010}, {"down", 0x0040},
    {"left", 0x0080}, {"right", 0x0020}, {"l1", 0x0400}, {"r1", 0x0800}, {"l2", 0x0100},
    {"r2", 0x0200},
};

static struct
{
	std::vector<std::string> line;
	int pc = 0, timer = 0, count = 0;
} S;
static long g_frame = -1;
static std::atomic<bool> g_quit(false);

/* ---- AV capture (see the header) ----------------------------------------- */
extern void (*g_oracleFlipHook)(unsigned, unsigned, unsigned, unsigned);
static struct
{
	std::string gs_dir;
	long gs_from = 0, gs_to = 1L << 30, gs_every = 1;
	FILE* snd = nullptr;
	FILE* wav = nullptr;
	uint64 wav_samples = 0; /* stereo frames written */
	std::mutex snd_mu;
	std::atomic<long> gs_tag{-1};
	long gs_last_saved = -1;
	long flips = 0;
	int last_state = -1;
} AV;

static void snd_log(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void snd_log(const char* fmt, ...)
{
	if(!AV.snd) return;
	std::lock_guard<std::mutex> l(AV.snd_mu);
	va_list ap;
	va_start(ap, fmt);
	vfprintf(AV.snd, fmt, ap);
	va_end(ap);
}

static void png_save(const char* path, const uint8* rgba, unsigned w, unsigned h)
{
	FILE* f = fopen(path, "wb");
	if(!f) return;
	png_structp p = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
	png_infop i = png_create_info_struct(p);
	if(setjmp(png_jmpbuf(p)))
	{
		png_destroy_write_struct(&p, &i);
		fclose(f);
		return;
	}
	png_init_io(p, f);
	png_set_compression_level(p, 3);
	png_set_IHDR(p, i, w, h, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(p, i);
	std::vector<uint8> row(w * 3);
	for(unsigned y = 0; y < h; y++)
	{
		for(unsigned x = 0; x < w; x++)
			memcpy(&row[x * 3], rgba + (y * w + x) * 4, 3);
		png_write_row(p, row.data());
	}
	png_write_end(p, i);
	png_destroy_write_struct(&p, &i);
	fclose(f);
}

/* GS thread: the displayed framebuffer at a flip */
static void av_flip(unsigned fbo, unsigned w, unsigned h, unsigned scale)
{
	long tag = AV.gs_tag.load();
	AV.flips++;
	if(AV.gs_dir.empty() || tag < AV.gs_from || tag > AV.gs_to || (tag - AV.gs_from) % AV.gs_every) return;
	if(w == 0 || h == 0) { w = 640; h = 224; }
	w *= scale;
	h *= scale;
	std::vector<uint8> px(w * h * 4, 0);
	if(fbo)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, px.data());
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	char path[1024];
	snprintf(path, sizeof path, "%s/f%06ld.png", AV.gs_dir.c_str(), tag);
	png_save(path, px.data(), w, h); /* a later flip in the same game frame overwrites */
	AV.gs_last_saved = tag;
}

class CGSH_AvGL : public CGSH_OpenGL
{
public:
	CGSH_AvGL()
	    : CGSH_OpenGL(true)
	{
	}
	static FactoryFunction GetFactoryFunction()
	{
		return []() { return new CGSH_AvGL(); };
	}
	void InitializeImpl() override
	{
		auto gpd = (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
		m_dpy = gpd ? gpd(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, nullptr) : eglGetDisplay(EGL_DEFAULT_DISPLAY);
		EGLint ma, mi, n = 0;
		if(!eglInitialize(m_dpy, &ma, &mi)) { fprintf(stderr, "[av] eglInitialize failed\n"); abort(); }
		eglBindAPI(EGL_OPENGL_ES_API);
		EGLint ca[] = {EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_PBUFFER_BIT, EGL_NONE};
		EGLConfig cfg = nullptr;
		eglChooseConfig(m_dpy, ca, &cfg, 1, &n);
		EGLint xa[] = {EGL_CONTEXT_MAJOR_VERSION, 3, EGL_CONTEXT_MINOR_VERSION, 2, EGL_NONE};
		m_ctx = eglCreateContext(m_dpy, n ? cfg : EGL_NO_CONFIG_KHR, EGL_NO_CONTEXT, xa);
		if(!eglMakeCurrent(m_dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, m_ctx)) { fprintf(stderr, "[av] eglMakeCurrent failed\n"); abort(); }
		fprintf(stderr, "[av] GS: %s, %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
		/* the presentation target (unused: av_flip reads the buffer itself) */
		glGenRenderbuffers(1, &m_rb);
		glBindRenderbuffer(GL_RENDERBUFFER, m_rb);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, 640, 448);
		glGenFramebuffers(1, &m_presentFramebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_presentFramebuffer);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_rb);
		PRESENTATION_PARAMS pp;
		pp.windowWidth = 640;
		pp.windowHeight = 448;
		pp.mode = PRESENTATION_MODE_FILL;
		m_presentationParams = pp;
		CGSH_OpenGL::InitializeImpl();
	}
	void ReleaseImpl() override
	{
		CGSH_OpenGL::ReleaseImpl();
		eglMakeCurrent(m_dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		eglDestroyContext(m_dpy, m_ctx);
	}
	void PresentBackbuffer() override
	{
	}

private:
	EGLDisplay m_dpy = EGL_NO_DISPLAY;
	EGLContext m_ctx = EGL_NO_CONTEXT;
	GLuint m_rb = 0;
};

/* SPU2 output -> WAV (44100 Hz stereo s16) */
class CAvSound : public CSoundHandler
{
public:
	void Reset() override {}
	void Write(int16* s, unsigned int n, unsigned int rate) override
	{
		(void)rate;
		if(AV.wav) fwrite(s, 2, n, AV.wav);
		AV.wav_samples += n / 2;
	}
	bool HasFreeBuffers() override { return true; }
	void RecycleBuffers() override {}
};

static void wav_header(FILE* f, uint32 frames)
{
	uint32 data = frames * 4, v;
	fseek(f, 0, SEEK_SET);
	fwrite("RIFF", 1, 4, f);
	v = 36 + data; fwrite(&v, 4, 1, f);
	fwrite("WAVEfmt ", 1, 8, f);
	v = 16; fwrite(&v, 4, 1, f);
	uint16 h = 1; fwrite(&h, 2, 1, f);
	h = 2; fwrite(&h, 2, 1, f);
	v = 44100; fwrite(&v, 4, 1, f);
	v = 44100 * 4; fwrite(&v, 4, 1, f);
	h = 4; fwrite(&h, 2, 1, f);
	h = 16; fwrite(&h, 2, 1, f);
	fwrite("data", 1, 4, f);
	fwrite(&data, 4, 1, f);
	fseek(f, 0, SEEK_END);
}

/* sound command hooks (function entries / a return site = block starts) */
#define TSD_RPC_RET 0x00423844 /* after func_00423750's sceSifCallRpc: D_00634100[D_00633E18] */
static const uint32 k_snd_hooks[] = {TSD_RPC_RET, 0x00423990, 0x00402C20, 0x00401868, 0x004020D8, 0x004026B0, 0x00402BC0};
static int snd_hook(CMIPS* ctx)
{
	if(!AV.snd) return 0;
	uint32 pc = ctx->m_State.nPC;
	auto& r = ctx->m_State.nGPR;
	switch(pc)
	{
	case TSD_RPC_RET:
	{
		uint32 n = rd32(0x00633E18);
		std::string hex;
		char b[4];
		for(uint32 i = 0; i < n && i < 0x200; i++)
		{
			snprintf(b, sizeof b, "%02X", rd8(0x00634100 + i));
			hex += b;
		}
		snd_log("%ld T %s\n", g_frame, hex.c_str());
		return 1;
	}
	case 0x00423990: snd_log("%ld S %X %X\n", g_frame, r[CMIPS::A0].nV0, r[CMIPS::A1].nV0); return 1;
	case 0x00402C20: snd_log("%ld A start %d %d\n", g_frame, (int)r[CMIPS::A1].nV0, (int)r[CMIPS::A2].nV0); return 1;
	case 0x00401868:
		/* ADXT_StartAfs calls ADXT_Stop itself (0x00402C60): not a game call */
		if(r[CMIPS::RA].nV0 < 0x00402C20 || r[CMIPS::RA].nV0 >= 0x00402D00) snd_log("%ld A stop\n", g_frame);
		return 1;
	case 0x004020D8: snd_log("%ld A vol %d\n", g_frame, (int)r[CMIPS::A1].nV0); return 1;
	case 0x004026B0: snd_log("%ld A pause %d\n", g_frame, (int)r[CMIPS::A1].nV0); return 1;
	case 0x00402BC0: snd_log("%ld A mono %d\n", g_frame, (int)r[CMIPS::A0].nV0); return 1;
	}
	return 0;
}

/* per game frame (EE thread) */
static void av_frame()
{
	int st = rd8(0x004F4300) << 16 | rd8(0x004F4301) << 8 | rd8(0x004F4302);
	if(st != AV.last_state)
	{
		snd_log("%ld G %06X\n", g_frame, st);
		AV.last_state = st;
	}
	if(AV.wav) snd_log("%ld W %llu\n", g_frame, (unsigned long long)AV.wav_samples);
	if(!AV.gs_dir.empty())
	{
		long f = g_frame;
		g_vm->m_ee->m_gs->SendGSCall([f]() { AV.gs_tag = f; });
	}
}

static int state_match(const char* want)
{
	char cur[32];
	int st = game_state();
	snprintf(cur, sizeof cur, "%d/%d/%d", st >> 16, (st >> 8) & 0xFF, st & 0xFF);
	size_t n = strlen(want);
	return strncmp(cur, want, n) == 0 && (cur[n] == 0 || cur[n] == '/' || want[n - 1] == '/');
}

static void script_buttons(const char* spec, uint16* b0, uint16* b1)
{
	char buf[128], *t, *save = NULL;
	*b0 = *b1 = 0;
	snprintf(buf, sizeof buf, "%s", spec);
	for(t = strtok_r(buf, "+", &save); t; t = strtok_r(NULL, "+", &save))
	{
		int p2 = !strncmp(t, "p2:", 3);
		const char* nm = p2 ? t + 3 : t;
		for(const auto& k : BTN)
			if(!strcmp(nm, k.n)) *(p2 ? b1 : b0) |= k.bit;
	}
}

static void script_step(uint16* b0, uint16* b1)
{
	char cmd[32] = "", a1[160] = "", a2[64] = "", a3[32] = "";
	*b0 = *b1 = 0;
	while(S.pc < (int)S.line.size())
	{
		cmd[0] = a1[0] = a2[0] = a3[0] = 0;
		sscanf(S.line[S.pc].c_str(), "%31s %159s %63s %31s", cmd, a1, a2, a3);
		if(!strcmp(cmd, "state"))
		{
			int max = a2[0] ? atoi(a2) : 7200;
			if(state_match(a1)) { S.pc++; S.timer = 0; continue; }
			if(++S.timer > max)
			{
				fprintf(stderr, "[oracle] script: line %d: state %s not reached in %d frames (now %06X)\n", S.pc + 1, a1, max, game_state());
				S.pc++; S.timer = 0; continue;
			}
			return;
		}
		else if(!strcmp(cmd, "wait"))
		{
			if(S.timer++ < atoi(a1)) return;
			S.pc++; S.timer = 0; continue;
		}
		else if(!strcmp(cmd, "press"))
		{
			int len = a2[0] ? atoi(a2) : 6;
			if(S.timer < len) { script_buttons(a1, b0, b1); S.timer++; return; }
			if(S.timer++ < len + 6) return;
			S.pc++; S.timer = 0; continue;
		}
		else if(!strcmp(cmd, "hold"))
		{
			int len = a2[0] ? atoi(a2) : 1;
			if(S.timer < len) { script_buttons(a1, b0, b1); S.timer++; return; }
			S.pc++; S.timer = 0; continue;
		}
		else if(!strcmp(cmd, "until"))
		{
			int gap = a3[0] ? atoi(a3) : 30;
			if(S.timer == 0 && state_match(a1)) { S.pc++; S.count = 0; continue; }
			if(S.count > 200)
			{
				fprintf(stderr, "[oracle] script: line %d: state %s not reached after 200 presses (now %06X)\n", S.pc + 1, a1, game_state());
				S.pc++; S.count = 0; S.timer = 0; continue;
			}
			if(S.timer < 6) script_buttons(a2, b0, b1);
			if(++S.timer >= gap) { S.timer = 0; S.count++; }
			return;
		}
		else if(!strcmp(cmd, "shot"))
		{
			/* the port takes two steps for a shot (draw, then write) */
			if(S.timer == 0) { S.timer = 1; return; }
			S.timer = 0;
			fprintf(stderr, "[oracle] shot %s at frame %ld state %06X\n", a1, g_frame, game_state());
			S.pc++; continue;
		}
		else if(!strcmp(cmd, "quit"))
		{
			fprintf(stderr, "[oracle] script: done at frame %ld\n", g_frame);
			g_quit = true;
			S.pc = (int)S.line.size();
			return;
		}
		else
		{
			fprintf(stderr, "[oracle] script: line %d: unknown command %s\n", S.pc + 1, cmd);
			S.pc++;
		}
	}
}

static int script_load(const char* path)
{
	FILE* f = fopen(path, "r");
	char ln[256];
	if(!f) return -1;
	while(fgets(ln, sizeof ln, f))
	{
		char* c = strchr(ln, '#');
		if(c) *c = 0;
		for(c = ln + strlen(ln); c > ln && (c[-1] == '\n' || c[-1] == ' ' || c[-1] == '\r' || c[-1] == '\t'); c--)
			c[-1] = 0;
		for(c = ln; *c == ' ' || *c == '\t'; c++)
			;
		if(*c) S.line.push_back(c);
	}
	fclose(f);
	return 0;
}

/* ---- options ------------------------------------------------------------- */
static struct
{
	long frames = 0;
	int unlock = 1;
	FILE* dump = nullptr;
	long dump_from = 0;
	int cpu_team[3] = {-1, -1, -1};
	int p1_team = -1;
	int cpu_hp = -1, p1_hp = -1;
	struct
	{
		long frame;
		int len;
		uint16 bits;
	} press[256];
	int npress = 0;
	int verbose = 0;
	uint32 hook = 0x0012F460;
	struct
	{
		long frame;
		std::string path;
	} snap[64];
	int nsnap = 0;
	const char* resync = nullptr;
	int resynced = 0;
} O;

static void ee_wr(uint32_t ee, uint32_t v) { wr32(ee, v); }
static void ee_wr8(uint32_t ee, uint8_t v) { wr8(ee, v); }

static void pad_inject(uint32 p);

/* port/host/game_loop.c unlock_everything(), the same writes at the same point */
static void unlock_everything()
{
	const uint32 g = 0x004F4300;
	wr32(g + 0x30, 0xF8FFFFFFu);
	wr32(g + 0x34, 0x07FFFFFFu);
	wr32(g + 0x38, 0xF8FFFFFFu);
	wr32(g + 0x3C, 0x07FFFFFFu);
	wr32(0x004F7FB4, 0xFFFFFFFFu);
	wr32(0x004F7FB8, 0xFFFFFFFFu);
	if(rd8(0x004D179A) < 7) wr8(0x004D179A, 7);
}

static void on_frame(CMIPS* ctx)
{
	if(ctx->m_State.nPC != O.hook)
	{
		static int warned;
		if(warned++ < 5) fprintf(stderr, "[oracle] hook block at %08X (want %08X)\n", ctx->m_State.nPC, O.hook);
		return;
	}
	g_frame++;
	av_frame();
	if(O.verbose && (g_frame % 600) == 0)
		fprintf(stderr, "[oracle] frame %ld state %06X\n", g_frame, game_state());
	{
		static int last = -1;
		int st = game_state();
		if(st != last)
		{
			fprintf(stderr, "[oracle] frame %ld: game state g[0..2] = %d %d %d\n", g_frame, st >> 16, (st >> 8) & 0xFF, st & 0xFF);
			last = st;
		}
	}
	if(O.unlock) unlock_everything();
	/* --cpu-hp N / --p1-hp N: port/host/game_loop.c cpu_hp_cap() (the port
	 * applies it later in the frame, after code that does not touch health) */
	for(int i = 0; O.p1_hp > 0 && i < 6; i += 2)
	{
		uint32 a = 0x004F20B0 + i * 0x5B8 + 0x434;
		int16 hp = (int16)(rd8(a) | rd8(a + 1) << 8);
		if(hp > 0 && hp < O.p1_hp) { wr8(a, (uint8)O.p1_hp); wr8(a + 1, (uint8)(O.p1_hp >> 8)); }
	}
	for(int i = 1; O.cpu_hp >= 0 && i < 6; i += 2)
	{
		uint32 a = 0x004F20B0 + i * 0x5B8 + 0x434;
		int16 hp = (int16)(rd8(a) | rd8(a + 1) << 8);
		if(hp > O.cpu_hp) { wr8(a, (uint8)O.cpu_hp); wr8(a + 1, (uint8)(O.cpu_hp >> 8)); }
	}
	uint16 b0 = 0, b1 = 0;
	for(int i = 0; i < O.npress; i++)
		if(g_frame >= O.press[i].frame && g_frame < O.press[i].frame + O.press[i].len) b0 |= O.press[i].bits;
	if(!S.line.empty())
	{
		uint16 s0, s1;
		script_step(&s0, &s1);
		b0 |= s0;
		b1 |= s1;
	}
	g_buttons[0] = b0;
	g_buttons[1] = b1;
	g_pad->Apply(ram());
	pad_inject(0);
	pad_inject(1);

	if(O.resync && !O.resynced && state_match(O.resync))
	{
		uint32 r = rd32(0x0043B6F8);
		O.resynced = 1;
		oracle_resync(&ee_wr, &ee_wr8);
		wr32(r + 0xA8, (uint32)ORACLE_RESYNC_SEED);
		wr32(r + 0xAC, (uint32)(ORACLE_RESYNC_SEED >> 32));
		fprintf(stderr, "[oracle] resync at frame %ld (state %06X)\n", g_frame, game_state());
	}
	if(O.dump && g_frame >= O.dump_from)
	{
		uint32 r = rd32(0x0043B6F8);
		uint64 seed = (uint64)rd32(r + 0xA8) | (uint64)rd32(r + 0xAC) << 32;
		oracle_dump_record(O.dump, (uint32)g_frame, b0, b1, &ee_rd, nullptr, seed);
	}
	for(int i = 0; i < O.nsnap; i++)
		if(O.snap[i].frame == g_frame) oracle_snap(O.snap[i].path.c_str(), &ee_rd, nullptr);
	if(O.frames > 0 && g_frame >= O.frames) g_quit = true;
}

/* --trace ADDR (several allowed): print the argument registers each time a
 * block starts at ADDR (a function entry) in frames [--trace-from, --trace-to] */
static std::vector<uint32> g_trace;
static long g_trace_from = 0, g_trace_to = 1L << 30;
/* --mem-trace ADDR:EEADDR:N: at each block start ADDR (in the --trace-from/to
 * frames) print N floats at EEADDR and $a0 */
struct MemTrace
{
	uint32 addr, ee, n;
};
static std::vector<MemTrace> g_memtrace;
static void trace(CMIPS* ctx);
static void mem_trace(CMIPS* ctx, const MemTrace& m);
static void trace(CMIPS* ctx)
{
	auto& r = ctx->m_State.nGPR;
	if(g_frame < g_trace_from || g_frame > g_trace_to) return;
	fprintf(stderr, "[trace] f%ld %08X(a0=%08X a1=%08X a2=%08X a3=%08X t0=%08X) ra=%08X f12=%08X f13=%08X f14=%08X\n",
	        g_frame, ctx->m_State.nPC, r[CMIPS::A0].nV0, r[CMIPS::A1].nV0, r[CMIPS::A2].nV0, r[CMIPS::A3].nV0,
	        r[CMIPS::T0].nV0, r[CMIPS::RA].nV0, ctx->m_State.nCOP1[12], ctx->m_State.nCOP1[13], ctx->m_State.nCOP1[14]);
}

static void mem_trace(CMIPS* ctx, const MemTrace& m)
{
	if(g_frame < g_trace_from || g_frame > g_trace_to) return;
	fprintf(stderr, "[mem] f%ld %08X a0=%08X", g_frame, m.addr, ctx->m_State.nGPR[CMIPS::A0].nV0);
	for(uint32 i = 0; i < m.n; i++)
	{
		uint32 w = rd32(m.ee + 4 * i);
		float f;
		memcpy(&f, &w, 4);
		fprintf(stderr, " %.9g", f);
	}
	fprintf(stderr, "\n");
}

/* --snap-at ADDR:FRAME:FILE: snapshot when a block starts at ADDR in FRAME */
struct SnapAt
{
	uint32 addr;
	long frame;
	std::string path;
	int done;
};
static std::vector<SnapAt> g_snapat;

/* scePadRead (func_0010D910) entry: the frame's buttons go straight into
 * libpad's two EE receive buffers (D_004C83D0[port][0].buffer, 2 x 0x80
 * bytes, buttons active low at +2/+3) just before the game copies them, so
 * it reads them in the frame they were set, as the port reads
 * host_pad_set()'s buttons.  (Through the IOP pad module alone they arrive
 * one or two frames later, depending on when its DMA lands.) */
#define SCE_PAD_READ 0x0010D910
/* the return site of func_003EDA60's scePadRead call: the copy the game made
 * is overwritten with the frame's buttons there too, because the IOP's SIF
 * DMA can land in libpad's buffer between the entry hook and the copy (Play!
 * interleaves the EE and the IOP in time slices) */
#define SCE_PAD_READ_RET 0x003EDE5C
static uint32 g_pad_dst[2], g_pad_last = 0;
static void pad_inject(uint32 p)
{
	uint32 buf = rd32(0x004C83D0 + p * 0x70);
	uint16 inv = (uint16)~g_buttons[p];
	if(!buf) return;
	for(uint32 h = 0; h < 0x100; h += 0x80)
	{
		uint8 st = rd8(buf + h + 112);
		wr8(buf + h + 0, 0); /* status ok */
		/* the mode id the fl pad layer last saw (D_0062C094[i * 12],
		 * func_003EDA60): a change makes it drop the frame's buttons and
		 * re-query the pad, which Play!'s pad module triggers now and then */
		if(rd8(0x0062C094 + p * 12)) wr8(buf + h + 1, rd8(0x0062C094 + p * 12));
		wr8(buf + h + 2, (uint8)inv);
		wr8(buf + h + 3, (uint8)(inv >> 8));
		/* a pad that is up reads as stable (6) every frame, as the port's
		 * libpad does: Play!'s pad module passes through other states for
		 * a frame when its DMA is late, and the game then keeps the old
		 * buttons */
		if(st >= 1 && st <= 6) wr8(buf + h + 112, 6);
	}
}

static void pad_read_hook(CMIPS* ctx)
{
	uint32 p = ctx->m_State.nGPR[CMIPS::A0].nV0 & 1;
	g_pad_dst[p] = ctx->m_State.nGPR[CMIPS::A2].nV0;
	g_pad_last = p;
	if(g_frame >= g_trace_from && g_frame <= g_trace_to && getenv("MVC2_ORACLE_PADDBG"))
	{
		uint32 b = rd32(0x004C83D0 + p * 0x70);
		fprintf(stderr, "[pad] f%ld port %u dst %08X buf %08X: %08X fr %d | %08X fr %d  want %04X\n", g_frame, p,
		        ctx->m_State.nGPR[CMIPS::A2].nV0, b, rd32(b), (int)rd32(b + 0x58), rd32(b + 0x80), (int)rd32(b + 0xD8), g_buttons[p]);
	}
	uint32 buf = rd32(0x004C83D0 + p * 0x70);
	uint16 inv = (uint16)~g_buttons[p];
	if(!buf) return;
	for(uint32 h = 0; h < 0x100; h += 0x80)
	{
		wr8(buf + h + 2, (uint8)inv);
		wr8(buf + h + 3, (uint8)(inv >> 8));
	}
}

/* --cpu-team a,b,c / --p1-team a,b,c: as the port's (port/host/arcade.c):
 * the game's own CPU pick (func_0032DF90) runs, then the ids replace its
 * choices at its two return sites; side 0's picks are forced as the game
 * queues their PAKs (func_0012EF50 / func_0012EF80 entry). */
static int g_cpu_team[3] = {-1, -1, -1}, g_p1_team[3] = {-1, -1, -1};
static int g_pick_side;
#define CPU_PICK 0x0032DF90
static const uint32 k_cpu_pick_ret[] = {0x0032A298, 0x0032CBD0};
static void force_rec(uint32 rec, int id, const char* who, int t, int set_assist)
{
	wr8(rec + 0x540, (uint8)id);
	wr8(rec + 1, (uint8)id);
	if(set_assist) wr8(rec + 0x4DD, rd8(0x004405A0 + id));
	fprintf(stderr, "[oracle] %s pick %d: character %#x (forced)\n", who, t, id);
}
static int team_hook(CMIPS* ctx)
{
	uint32 pc = ctx->m_State.nPC;
	if(pc == CPU_PICK)
	{
		g_pick_side = (int8)ctx->m_State.nGPR[CMIPS::A0].nV0;
		return 1;
	}
	for(uint32 r : k_cpu_pick_ret)
		if(pc == r)
		{
			uint32 g = rd32(0x004C2840);
			if((int8)rd8(g + 0x85) == 7) return 1;
			for(int t = 0; t < 3; t++)
				if(g_cpu_team[t] >= 0) force_rec(0x004F20B0 + (g_pick_side + t * 2) * 0x5B8, g_cpu_team[t], "CPU", t, 1);
			return 1;
		}
	if(pc == 0x0012EF50 || pc == 0x0012EF80)
	{
		uint32 p = ctx->m_State.nGPR[CMIPS::A0].nV0;
		if(p >= 0x004F20B0 && p < 0x004F20B0 + 6 * 0x5B8 && (p - 0x004F20B0) % 0x5B8 == 0)
		{
			int i = (p - 0x004F20B0) / 0x5B8;
			if(!(i & 1) && g_p1_team[i / 2] >= 0 && (int8)rd8(p + 0x540) != g_p1_team[i / 2])
				force_rec(p, g_p1_team[i / 2], "P1", i / 2, 0);
		}
		return 1;
	}
	return 0;
}
static void parse_team(const char* s, int* t)
{
	for(int k = 0; k < 3 && s && *s; k++)
	{
		char* e;
		long v = strtol(s, &e, 0);
		if(e != s) t[k] = (int)v;
		s = strchr(s, ',');
		if(s) s++;
	}
}

static void hook(CMIPS* ctx)
{
	if(g_quit) return;
	if(snd_hook(ctx)) return;
	if(team_hook(ctx)) return;
	if(ctx->m_State.nPC == SCE_PAD_READ_RET)
	{
		uint32 p = g_pad_last, d = g_pad_dst[p];
		uint16 inv = (uint16)~g_buttons[p];
		if(d && rd8(d) != 0xFF)
		{
			wr8(d + 2, (uint8)inv);
			wr8(d + 3, (uint8)(inv >> 8));
		}
		for(uint32 a : g_trace)
			if(a == ctx->m_State.nPC) trace(ctx);
		return;
	}
	if(ctx->m_State.nPC == SCE_PAD_READ)
	{
		pad_read_hook(ctx);
		for(uint32 a : g_trace)
			if(a == ctx->m_State.nPC) trace(ctx);
		return;
	}
	if(ctx->m_State.nPC != O.hook)
	{
		for(auto& m : g_memtrace)
			if(m.addr == ctx->m_State.nPC) mem_trace(ctx, m);
		for(auto& s : g_snapat)
			if(s.addr == ctx->m_State.nPC && s.frame == g_frame && !s.done)
			{
				s.done = 1;
				oracle_snap(s.path.c_str(), &ee_rd, nullptr);
				fprintf(stderr, "[oracle] snap %s at %08X frame %ld\n", s.path.c_str(), s.addr, g_frame);
			}
		for(uint32 a : g_trace)
			if(a == ctx->m_State.nPC) { trace(ctx); return; }
		return;
	}
	on_frame(ctx);
}

static uint16 parse_buttons(const char* s)
{
	uint16 b0, b1;
	script_buttons(s, &b0, &b1);
	return b0;
}

int main(int argc, char** argv)
{
	const char* iso = nullptr;
	for(int i = 1; i < argc; i++)
	{
		const char* a = argv[i];
		const char* n = i + 1 < argc ? argv[i + 1] : nullptr;
		if(!strcmp(a, "--iso") && n) { iso = n; i++; }
		else if(!strcmp(a, "--script") && n) { if(script_load(n)) { fprintf(stderr, "cannot read %s\n", n); return 2; } i++; }
		else if(!strcmp(a, "--frames") && n) { O.frames = atol(n); i++; }
		else if(!strcmp(a, "--dump") && n) { O.dump = fopen(n, "wb"); i++; }
		else if(!strcmp(a, "--dump-from") && n) { O.dump_from = atol(n); i++; }
		else if(!strcmp(a, "--no-unlock")) O.unlock = 0;
		else if(!strcmp(a, "--resync") && n) { O.resync = n; i++; }
		else if(!strcmp(a, "--cpu-hp") && n) { O.cpu_hp = atoi(n); i++; }
		else if(!strcmp(a, "--p1-hp") && n) { O.p1_hp = atoi(n); i++; }
		else if(!strcmp(a, "--cpu-team") && n) { parse_team(n, g_cpu_team); i++; }
		else if(!strcmp(a, "--p1-team") && n) { parse_team(n, g_p1_team); i++; }
		else if(!strcmp(a, "--snap-at") && n)
		{
			SnapAt sa;
			char path[512];
			if(sscanf(n, "%x:%ld:%511s", &sa.addr, &sa.frame, path) != 3) return 2;
			sa.path = path;
			sa.done = 0;
			g_snapat.push_back(sa);
			i++;
		}
		else if(!strcmp(a, "--mem-trace") && n)
		{
			MemTrace m;
			if(sscanf(n, "%x:%x:%u", &m.addr, &m.ee, &m.n) != 3) return 2;
			g_memtrace.push_back(m);
			i++;
		}
		else if(!strcmp(a, "--trace") && n) { g_trace.push_back(strtoul(n, 0, 0)); i++; }
		else if(!strcmp(a, "--trace-from") && n) { g_trace_from = atol(n); i++; }
		else if(!strcmp(a, "--trace-to") && n) { g_trace_to = atol(n); i++; }
		else if(!strcmp(a, "-v")) O.verbose = 1;
		else if(!strcmp(a, "--snap") && n)
		{
			/* --snap F:FILE: the raw EE BSS at frame F */
			const char* c = strchr(n, ':');
			if(!c) return 2;
			O.snap[O.nsnap].frame = atol(n);
			O.snap[O.nsnap].path = c + 1;
			O.nsnap++;
			i++;
		}
		else if(!strcmp(a, "--hook") && n) { O.hook = strtoul(n, 0, 0); i++; }
		else if(!strcmp(a, "--press") && n)
		{
			char btn[64] = "";
			long f = 0;
			int len = 6;
			sscanf(n, "%ld:%63[^:]:%d", &f, btn, &len);
			O.press[O.npress].frame = f;
			O.press[O.npress].len = len;
			O.press[O.npress].bits = parse_buttons(btn);
			O.npress++;
			i++;
		}
		else if(!strcmp(a, "--gs-dir") && n) { AV.gs_dir = n; i++; }
		else if(!strcmp(a, "--gs-from") && n) { AV.gs_from = atol(n); i++; }
		else if(!strcmp(a, "--gs-to") && n) { AV.gs_to = atol(n); i++; }
		else if(!strcmp(a, "--gs-every") && n) { AV.gs_every = atol(n) > 0 ? atol(n) : 1; i++; }
		else if(!strcmp(a, "--wav") && n) { AV.wav = fopen(n, "wb+"); if(AV.wav) wav_header(AV.wav, 0); i++; }
		else if(!strcmp(a, "--snd-log") && n) { AV.snd = fopen(n, "w"); i++; }
		else { fprintf(stderr, "unknown option %s\n", a); return 2; }
	}
	if(!iso) { fprintf(stderr, "usage: mvc2_oracle --iso DISC.iso [...]\n"); return 2; }

	CPS2VM vm;
	g_vm = &vm;
	CAppConfig::GetInstance().SetPreferencePath(PREF_PS2_CDROM0_PATH, fs::absolute(iso));
	CAppConfig::GetInstance().SetPreferenceBoolean(PREF_PS2_LIMIT_FRAMERATE, false);
	vm.Initialize();
	vm.ReloadFrameRateLimit();
	if(!AV.gs_dir.empty())
	{
		g_oracleFlipHook = &av_flip;
		vm.CreateGSHandler(CGSH_AvGL::GetFactoryFunction());
	}
	else
		vm.CreateGSHandler(CGSH_Null::GetFactoryFunction());
	if(AV.wav) vm.CreateSoundHandler([]() -> CSoundHandler* { return new CAvSound(); });
	vm.CreatePadHandler([]() -> CPadHandler* { g_pad = new COraclePad(); return g_pad; });
	vm.Reset();
	vm.m_ee->m_os->BootFromCDROM();
	vm.m_ee->m_EE.m_breakpoints.insert(O.hook);
	vm.m_ee->m_EE.m_breakpoints.insert(SCE_PAD_READ);
	vm.m_ee->m_EE.m_breakpoints.insert(SCE_PAD_READ_RET);
	if(g_cpu_team[0] >= 0 || g_cpu_team[1] >= 0 || g_cpu_team[2] >= 0)
	{
		vm.m_ee->m_EE.m_breakpoints.insert(CPU_PICK);
		for(uint32 r : k_cpu_pick_ret) vm.m_ee->m_EE.m_breakpoints.insert(r);
	}
	if(g_p1_team[0] >= 0 || g_p1_team[1] >= 0 || g_p1_team[2] >= 0)
	{
		vm.m_ee->m_EE.m_breakpoints.insert(0x0012EF50);
		vm.m_ee->m_EE.m_breakpoints.insert(0x0012EF80);
	}
	for(uint32 a : g_trace) vm.m_ee->m_EE.m_breakpoints.insert(a);
	if(AV.snd)
		for(uint32 a : k_snd_hooks) vm.m_ee->m_EE.m_breakpoints.insert(a);
	for(auto& sa : g_snapat) vm.m_ee->m_EE.m_breakpoints.insert(sa.addr);
	for(auto& m : g_memtrace) vm.m_ee->m_EE.m_breakpoints.insert(m.addr);
	g_oracleBreakHook = &hook;
	auto t0 = std::chrono::steady_clock::now();
	vm.Resume();
	long last = -2;
	int idle = 0;
	while(!g_quit)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if(g_frame == last)
		{
			if(++idle == 300) fprintf(stderr, "[oracle] no game frame for 60 s (frame %ld)\n", g_frame);
		}
		else idle = 0;
		last = g_frame;
		if(idle > 600) break;
	}
	vm.Pause();
	double s = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
	fprintf(stderr, "[oracle] %ld frames in %.1f s, state %06X\n", g_frame + 1, s, game_state());
	if(O.dump) fclose(O.dump);
	if(AV.snd) fclose(AV.snd);
	if(AV.wav) { wav_header(AV.wav, (uint32)AV.wav_samples); fclose(AV.wav); }
	fprintf(stderr, "[av] %ld flips, %llu sample frames\n", AV.flips, (unsigned long long)AV.wav_samples);
	vm.DestroyPadHandler();
	vm.DestroyGSHandler();
	vm.Destroy();
	_exit(0);
}
