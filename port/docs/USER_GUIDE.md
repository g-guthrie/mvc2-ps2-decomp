# Marvel vs. Capcom 2 port: player guide

This port runs the decompiled PS2 game (SLUS_204.86) natively, with no
emulator. It needs **your own disc image**: nothing from the game ships with
the port. It runs in a browser (desktop, phone, tablet) or as a desktop app
(SDL2). This guide covers starting the game, controls, every setting, and
where the settings are stored.

## Starting

**Browser.** Open `mvc2.html` from a web server, choose your disc image
(`.iso`) once, and the page keeps it on this device (IndexedDB) for later
visits. Nothing is uploaded. "Forget cached disc" (on the first screen, or
Settings > About) removes it.

- **Install as an app.** Over https (or `localhost`) the page is a
  Progressive Web App. Use the browser's Install button, or Settings > About >
  Install as an app. On iPhone or iPad use Share > Add to Home Screen. After
  the first load the app starts offline: the app shell is cached by the
  service worker, and the disc image is already on the device.
- **Personal single-file build** (`port/tools/pack_personal.py`): one `.html`
  with your disc inside. Double-click it to play offline. It needs no picker,
  no cache and no service worker. It is for your own use only: do not share it.

**Desktop app.**
`mvc2 [--iso DISC.iso] [--config FILE] [--set KEY=VALUE ...] [--fullscreen] [--no-unlock]`.
With no `--iso` it looks for `private/disc/mvc2.iso`.

The first click, tap or key press also turns the sound on: browsers keep audio
off until the page gets a gesture.

## Building the desktop app (Linux)

The game itself is built for a 32-bit target (the game's data keeps
pointers in 32-bit fields), so on Linux the app is an i386 binary. The
viewer and sound test tools are plain C and build for any pointer size.

Packages (Debian/Ubuntu): `clang`, `cmake`, `ninja-build`, `python3`, the
SDL2 headers (`libsdl2-dev`), and the 32-bit runtime libraries:

```sh
sudo dpkg --add-architecture i386 && sudo apt-get update
sudo apt-get install libsdl2-2.0-0:i386 libgl1-mesa-dri:i386 libegl1:i386 libgles2:i386
```

No 32-bit libc headers are needed: the build uses the x86-64 SDL2 headers
through a small shim it writes into the build directory.

```sh
# the game (from the repository root; the toolchain path must be absolute)
cmake -S port -B build/port-i386 -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo \
      -DCMAKE_TOOLCHAIN_FILE=$PWD/port/cmake/i386-clang.cmake
ninja -C build/port-i386 mvc2            # about 10 minutes the first time
./build/port-i386/mvc2 --iso /path/to/mvc2.iso

# the viewer and the sound test (native pointer size)
cd port/frontend && cmake --preset native && cmake --build --preset native
../../build/port-native/viewer --iso /path/to/mvc2.iso --stage 1
../../build/port-native/soundtest --iso /path/to/mvc2.iso --track 3
```

`-DMVC2_HOST_SIGS=FILE` reuses a signature table from an earlier build
(otherwise the configure step makes one, about 2 minutes). The arcade
toggles and every setting below work the same in the desktop app:
`--naomi mvsc2.zip --arcade abc`, `--set KEY=VALUE`, the F1 menu.

**Headless runs** (no window, for tests and CI): `SDL_VIDEODRIVER=offscreen`
(Mesa's software GL; `dummy` has no GL and does not work for the game or
the viewer) and `SDL_AUDIODRIVER=dummy`, plus `--hidden` (fixed 60 Hz steps,
no settings file):

```sh
SDL_VIDEODRIVER=offscreen SDL_AUDIODRIVER=dummy ./build/port-i386/mvc2 --hidden \
    --size 640x480 --shot-dir out --script port/tools/scripts/arcade_fight.txt mvc2.iso
```

`--shot F:file.png` and `--shot-every N --shot-dir D` save the game's
640x480 canvas (all 480 rows); `--wshot F:file.png` saves the window as the
player sees it.

## Default controls

The port maps your keys and buttons to a PS2 pad. The game's own **OPTION >
BUTTON CONFIG** then maps the PS2 pad buttons to attacks, so both layers
apply. With the game's default config:

| Action | Keyboard, player 1 | Keyboard, player 2 | Gamepad (position) | Xbox | PlayStation | Switch |
|---|---|---|---|---|---|---|
| Move | Arrow keys | Keypad 8 / 5 (or 2) / 4 / 6 | D-pad and left stick | | | |
| Light punch (SQUARE) | A | I | west | X | Square | Y |
| Heavy punch (TRIANGLE) | S | O | north | Y | Triangle | X |
| Light kick (CROSS) | Z | K | south | A | Cross | B |
| Heavy kick (CIRCLE) | X | L | east | B | Circle | A |
| Assist 1 (L1) | D | P | left bumper | LB | L1 | L |
| Assist 2 (R1) | C | ; | right bumper | RB | R1 | R |
| L2 / R2 (set in the game's BUTTON CONFIG) | Q / W | 9 / 0 | triggers | LT / RT | L2 / R2 | ZL / ZR |
| Start | Enter | Keypad Enter | start | Menu | Options | + |
| Select | Right Shift | Keypad + | back | View | Share | - |
| Macro 1 / Macro 2 | unbound | unbound | unbound | | | |

Gamepad buttons go by **position**, not by the letter printed on them. The
bottom face button is always light kick, so an Xbox, PlayStation and Switch
pad all play the same way. The menus show each pad's own labels.

**Two players.** The first gamepad plays as player 1 and the second as player
2 (swap them with Settings > Input > First gamepad plays). Keyboard set 1 is
always player 1 and keyboard set 2 is always player 2, so you can also play
pad against keyboard, or two people on one keyboard.

**Touch.** On a phone or tablet, touch the screen once and the on-screen pad
appears. It has a d-pad on the left, LP HP A1 / LK HK A2 on the right, and ST
(Start). In portrait the picture sits at the top with the pad below it. In
landscape the pad is laid over the sides of the picture. The pad's size and
opacity are under Settings > Input.

**Settings menu.**
- Browser: the gear button in the top-right corner, which fades while you
  play. Move the mouse or touch the screen to bring it back.
- In the game, on every platform: F1. On a gamepad: Back + Start together, or
  the Guide button. In the desktop app, Esc also works.
- Desktop app only: Alt+Enter or F11 toggles fullscreen.

The game pauses while either menu is open. Keys and buttons you press there
never reach the game.

## Settings

There are few options on purpose: everything that has one best choice just
uses it. The settings panel (and the in-game menu, F1) has only volumes,
touch controls, the gamepad-to-player choice and the button bindings.

### What the port always does
| | |
|---|---|
| Picture | The PS2's 640x448 picture, as large as fits, with sharp pixel scaling (crisp, even pixel widths); sprites sampled as the game asks; no CRT effect; v-sync on. |
| Speed | Game logic at a fixed 60 Hz. On a slow device some frames are not drawn, but no game step is skipped. |
| Input | Zero frames of delay: a press counts in the next game step (the retail PS2 adds 2 frames, the arcade about 1; ARCADE_DIFF.md 10.3). On top of that, **run-ahead** shows the frame the next step will produce, so a press appears on screen one frame sooner still (below). |
| Display | Desktop: the driver may not queue frames ahead of the screen (a GPU wait after each swap). Browser: a low-latency (desynchronized) canvas where the browser supports it, and the fast GPU on dual-GPU laptops. |
| Rules | The arcade's (NAOMI Rev A) wherever the arcade oracle confirmed a difference: the flying-screen edge, Servbot's hit-stop inputs, the super-freeze tick order, the arcade's sine/cosine and its float rounding. Characters' frames, boxes, damage and CPU AI are the same on both machines (ARCADE_DIFF.md sections 10-11). |
| Unlocks | Every character, stage and extra from the start. |
| Sound | The Dreamcast versions of the common effects when you add your Dreamcast disc (below). |

For testing, any of these can still be changed for one run with
`--set KEY=VALUE` (desktop) or `?KEY=VALUE` (browser), for example
`?video.fps=1` (frame rate and latency overlay), `video.crt=crt`,
`video.scale=integer`, `arcade.timing=ps2`, `arcade.fs_edge=0`,
`game.unlock_all=0` (or `--no-unlock`). Values saved by older versions are
ignored. `MVC2_PS2_EXACT=1` runs the PS2's rules; the PS2 oracle tools do
that automatically (a state-dump run without `--arcade`). The NAOMI ROM-file
tables (`--arcade abc --naomi mvsc2.zip`, desktop only) are not what the
arcade plays and stay a study tool (ARCADE_DIFF.md section 11).

**Frame pacing.** The game logic always runs at a fixed 60 Hz, sampled from
real time:
- 60 Hz display: one game step per refresh, with timing jitter snapped away.
- 120 or 144 Hz display: steps fall evenly across refreshes. The picture is
  only redrawn when a step ran.
- Slow device: up to 8 steps run per displayed frame (down to 7.5 fps on
  screen) and only the last one is drawn. Below that the game slows down
  rather than stutter.
- Hidden tab or minimised window: the game pauses, and the sound pauses with
  it.

### Audio
| Option | Key | Values | Default | |
|---|---|---|---|---|
| Master volume | `audio.volume` | 0-100 % | 100 | |
| Music volume | `audio.music` | 0-100 % | 100 | The game's ADX music. |
| Effects and voices | `audio.sfx` | 0-100 % | 100 | Sound effects and voices. |

**Dreamcast sound effects.** The PS2 disc stores most of the common sound
effects (hits, blocks, menu and round sounds) at 8 kHz, which cuts everything
above 4 kHz. The Dreamcast disc has the same recordings at 11-16 kHz. If you
have your own Dreamcast MvC2 disc, the port plays those versions instead,
with nothing else changed. There is no on/off option: they are used whenever
the disc is available.
- **Browser:** "Choose Dreamcast disc" on the start screen, or Settings >
  Audio. Choose the disc's data track (`track03.bin`, or an `.iso` of it).
  Only the 1 MB sound bank (`SE_COMN.BIN`) is kept on the device.
- **Desktop app:** `--dc-disc PATH` once (a `.gdi`, the data track as `.bin`
  or `.iso`, or `SE_COMN.BIN` itself); it is remembered as `audio.dc_disc`.
  `MVC2_DC_DISC=PATH` overrides it for one run.
- A `.chd` has to be converted first: `chdman extractcd -i mvc2.chd -o mvc2.gdi`.
- Only the USA disc's `SE_COMN.BIN` is known; another version is ignored and
  the PS2 effects stay. Voices and music are the same on both discs, so only
  the common effects change. Details: `port/docs/AUDIO.md` section 9.

In the browser, sound plays through an AudioWorklet at 48 kHz. Older browsers
fall back to a ScriptProcessorNode. Settings > About shows which one is in use
and counts any underruns.

### Input
| Option | Key | Values | Default | |
|---|---|---|---|---|
| First gamepad plays | `input.pad1_player` | Player 1 / Player 2 | Player 1 | The second gamepad plays the other player. |
| Touch controls | `touch.show` | Auto / Always / Never | Auto | Auto shows the pad after the first touch. |
| Touch control size | `touch.size` | 50-160 % | 100 % | |

The left stick also works as a d-pad. Bind a key or button to Macro 1
(LP+HP) or Macro 2 (LK+HK) under Controls.

### Controls (remapping)
Settings > Controls (in the in-game menu: Controls: player 1 / player 2)
lists every action with one keyboard and one gamepad binding for each player:
Up, Down, Left, Right, LP, HP, LK, HK, A1, A2, L2, R2, Start, Select, Macro 1
and Macro 2.

- To rebind, select a binding and press the new key or gamepad button. Esc
  cancels and Backspace (or Delete) clears the binding.
- If the new key or button already drives another action, the two actions
  swap, so nothing is left unbound.
- In the in-game menu: Left and Right choose the keyboard or gamepad column,
  and Delete or the north face button clears a binding.
- "Reset to defaults" restores one player's keyboard and gamepad bindings.

The settings file stores the bindings as `input.p1.kb.lp = A`,
`input.p2.pad.hk = east`. Each value is a comma list. The gamepad names are
south, east, west, north, lb, rb, lt, rt, back, start, ls, rs, up, down, left,
right, lx-, lx+, ly-, ly+, rx-, rx+, ry- and ry+. An empty value means
unbound. Removing the line restores the default.

## Input latency
The FPS overlay and Settings > About report the time from each key press,
touch or gamepad button to the 60 Hz game step that reads it:
- The port polls input immediately before every game step.
- A key tap shorter than one frame still counts, because presses are latched
  until the next step.
- On a 60 Hz display the time is below one frame (16.7 ms). It is typically
  half a frame, because a press waits for the next display refresh.

The arcade machine reads the controls one frame before its logic step
and the retail PS2 two frames before (ARCADE_DIFF.md 10.3), so the port
answers one frame sooner than the arcade and two sooner than the PS2.
For comparison, `--set arcade.timing=arcade` (or `ps2`) adds that delay
back for one run; the latency overlay does not include it.

**Run-ahead.** Each displayed frame the port runs the real game step
without drawing it, saves the game state (about 24 MB: the game's memory and
the host's per-frame state), runs one more step with the same input, draws
that one and restores the state. The game itself is never changed: with
deterministic input the full game state is bit-identical with run-ahead off,
1 frame and 2 frames (checked every 60 frames through boot, character select
and a 6,000-frame scripted fight). Sound and music requests from the
speculative step are dropped, so nothing plays twice, and textures or
palettes it uploaded are re-synced from the restored state.
- It runs only after 30 quiet steps, so not during loads, saves or bank
  changes, and it backs off when a speculative step does such work.
- It switches itself off on a device where it costs more than half a frame
  (8 ms per step, averaged).
- Testing: `--set video.runahead=0` (or 2), `?video.runahead=0`;
  `debug.state_hash=N` logs a hash of the whole state every N steps
  (with `MVC2_FIXED_CLOCK=1` and `MVC2_NO_AUDIO=1`, or `?env.NAME=1` in the
  browser, two runs of a script give the same hashes).

In headless Chromium with SwiftShader (a software GPU on a loaded machine)
the display ran at 5-9 fps and the measured latency was about 6 frames. That
number is the display rate in that test environment, not the port.

## Where settings are stored
- **Browser:** `localStorage["mvc2-settings"]` on this device, separately for
  each site or file. Clearing the site's data resets everything.
- **Desktop app:** a text file of `key = value` lines.

  | System | Path |
  |---|---|
  | Linux | `~/.local/share/mvc2-port/mvc2/settings.ini` |
  | Windows | `%APPDATA%\mvc2-port\mvc2\settings.ini` |
  | macOS | `~/Library/Application Support/mvc2-port/mvc2/settings.ini` |

  `--config FILE` uses another file. Headless runs (`--hidden`) never read or
  write it unless `--config` is given.
- **One run only:** `--set KEY=VALUE` (desktop app) or `?KEY=VALUE` in the
  page address (browser, for example `mvc2.html?video.crt=crt`) overrides an
  option for this run without saving it.

## Testing options (desktop app)
- `--wshot F:file.png` saves the window, including the scaling, filters, CRT
  effect and overlays, at display frame F.
- `--key F:KEYNAME[:LEN]` sends a real key event at display frame F, using
  SDL key names such as `F1`, `Return`, `Down` or `U`. This is how the menu
  and remapping are tested headless.
- `--press F:button[:LEN]` holds a PS2 button on pad 1 (unchanged).
- `--script FILE` runs a state-driven input script (`port/tools/scripts/`;
  in the browser `?script=` with `;` between lines).
- `--cpu-hp N` / `--p1-hp N` cap side 2's health and top up side 1's, so a
  script can play a whole ARCADE run to the ending.
- `--draw-every N` draws one game frame in N (fast headless runs).
- `--speed N` runs the game N times faster than real time (browser:
  `?args=--speed%204`).
- `?discmem` (browser): copy the whole disc image into memory, as older
  builds did, instead of reading it from the file on demand.
- Script command `hold B[+B..] [LEN]`: hold buttons LEN frames with no
  release after (motion inputs: `hold down 3`, `hold down+right 3`,
  `hold right+square 3`).
- Comparison with the retail game (port/tools/oracle, BOOT_NOTES "Oracle
  pass"): `MVC2_STATE_DUMP=FILE` (per-frame state), `MVC2_STATE_SNAP=F:FILE`
  (EE BSS + heap at frame F), `MVC2_RESYNC=STATE` (fixed RNG seeds and
  counters at STATE), `MVC2_PAD_DELAY=N` (the game reads the buttons N
  frames late), `MVC2_PS2FP_OFF=1` (with `-DMVC2_PS2_FLOAT=ON`: round to
  nearest again, for A/B).

## For developers: adding options (arcade-accuracy toggles)
Options are registered in C with the settings store in
`port/platform/settings.h`. Once registered, an option appears in the browser
panel and in the in-game menu, is saved per device, and can be set with
`--set` or `?key=value`. Neither UI needs any change.

```c
#include "settings.h"            /* port/platform */
static void on_frames(int v) { /* switch the tables */ }
static const SetDesc k_arcade_frames = {
    "arcade.frame_data", "NAOMI frame data", SET_SECTION_ARCADE, SET_BOOL,
    0, 0, 1, NULL, NULL, on_frames, SET_RESTART,
    "Use the arcade's frame and hitbox tables (needs your mvsc2.zip).", 0 };
/* at start-up (before or after settings_apply_all) */
settings_register(&k_arcade_frames);
/* anywhere */
int on = settings_get_int("arcade.frame_data");
```

How registration works:
- Types: `SET_BOOL`, `SET_ENUM` (labels in `choices`, stored values in
  `values`), `SET_INT` (`min`, `max`, `step`) and `SET_ACTION` (a button).
- Flags: `SET_RESTART` shows "next start". `SET_NATIVE_ONLY`, `SET_WEB_ONLY`
  and `SET_HIDDEN` limit where the option appears.
- The callback runs once at `settings_apply_all()`, or right away when the
  option is registered later, and again on every change.
- Use the `arcade.` key prefix for the arcade toggles. Rollback netcode
  (PORT_PLAN phase 5) needs both players to use the same toggles, so their
  values should be hashed into the handshake.
