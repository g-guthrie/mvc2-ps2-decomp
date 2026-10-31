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

Every option is in the browser's settings panel and in the in-game menu. Both
menus are built from the same option list. Changes apply immediately unless
marked "next start".

### Video
| Option | Key | Values | Default | What it does |
|---|---|---|---|---|
| Fullscreen | `video.fullscreen` (desktop app) | Off / On | Off | Desktop fullscreen. In the browser use the fullscreen button or the menu's "Toggle fullscreen" (browsers only allow it after a click or key press). |
| Scaling | `video.scale` | Fit / Integer / Stretch | Fit | Fit is the largest 4:3 picture. Integer uses only whole multiples of 640x480, so every pixel is the same size, and falls back to Fit when the window is smaller. Stretch fills the window. |
| Upscaling filter | `video.filter` | Nearest / Sharp / Smooth | Sharp | Nearest gives hard pixels, which can have uneven widths at non-integer sizes. Sharp gives crisp pixels with even widths (sharp bilinear). Smooth is bilinear. |
| Sprite filtering | `video.sprite_filter` | As the game / Nearest / Smooth | As the game | How 2D sprites are sampled: as the game asks, always nearest (crisp), or always smooth (the PS2's soft look). |
| CRT effect | `video.crt` | Off / Scanlines / CRT | Off | Scanlines draws 240 lines, like the 15 kHz picture the game was made for. CRT adds a shadow mask, slight curvature and a vignette. Both fade out on small windows, where they would cause moiré. |
| CRT strength | `video.crt_strength` | 0-100 % | 60 % | Strength of the scanlines and the mask. |
| V-sync | `video.vsync` (desktop app) | Off / On | On | Waits for the display refresh. In the browser the page always follows the display. |
| Drop frames when slow | `video.frame_skip` | Off / On | On | On a slow device the game keeps full speed by skipping the drawing of some frames, never the game logic. |
| Show FPS and latency | `video.fps` | Off / On | Off | Shows, in the corner: display frames per second, game-logic rate and the cost of one step, display refresh, and input latency (average and worst, in ms and frames). |

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
| Audio buffer | `audio.latency` (browser) | Auto / Low / Normal / High | Auto | How far ahead sound is mixed: Low 40 ms, Normal 80 ms, High 150 ms. Auto uses 2.5 display frames, at least 50 ms. Raise it if you hear crackles. |

In the browser, sound plays through an AudioWorklet at 48 kHz. Older browsers
fall back to a ScriptProcessorNode. Settings > About shows which one is in use
and counts any underruns.

### Input
| Option | Key | Values | Default | |
|---|---|---|---|---|
| First gamepad plays | `input.pad1_player` | Player 1 / Player 2 | Player 1 | The second gamepad plays the other player. |
| Left stick moves | `input.stick_dpad` | Off / On | On | The left stick also works as a d-pad. |
| Stick dead zone | `input.deadzone` | 20-90 % | 50 % | How far the stick must be pushed to count as a direction. |
| Macro 1 presses / Macro 2 presses | `input.macro1` / `input.macro2` | LP+HP, LK+HK, LP+LK, HP+HK, A1+A2, LP+HP+LK+HK, LP+HP+HK | LP+HP / LK+HK | Buttons pressed together by the Macro 1 and Macro 2 bindings. Bind a key or button to the macro under Controls. |
| Touch controls | `touch.show` | Auto / Always / Never | Auto | Auto shows the pad after the first touch. |
| Touch control size | `touch.size` | 50-160 % | 100 % | |
| Touch control opacity | `touch.opacity` | 10-100 % | 60 % | |

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

### Game
| Option | Key | Default | |
|---|---|---|---|
| Unlock everything | `game.unlock_all` | On | Every character, stage and extra is available from the start. Turning it back off takes effect on the next start, because unlocked items stay unlocked until you restart. In the browser, `?nounlock` starts once with the game's own unlock state without changing the setting. |

### Arcade accuracy
Optional, all off by default. Each toggle swaps one group of the PS2 game's
per-character tables for the arcade's (NAOMI `mvsc2`, Export/Korea Rev A),
read from **your own** MAME `mvsc2.zip` when the game starts. Nothing from
the arcade ROM is in the port. Changes take effect on the next start.

| Option | Key | Default | |
|---|---|---|---|
| NAOMI frame data + hitboxes | `arcade.frame_data` | Off | Animation timing (for example Cyclops' 09/02 is 17 frames / 51 ticks instead of 12 / 37) and hit, hurt and body boxes, including the startup invulnerability that comes from them. |
| NAOMI damage + hit data | `arcade.damage` | Off | Base damage and the other hit properties (Ryu's attack 0x30: 28 instead of 14). |
| NAOMI CPU AI | `arcade.cpu_ai` | Off | The CPU opponents' decision tables. |

Where the zip comes from:
- **Browser:** when a toggle is on, the page asks for `mvsc2.zip` before the
  disc boots and keeps it in IndexedDB (a "Forget" button removes it). For one
  run, `?arcade=abc` (a = frames, b = damage, c = AI) or `?arcade.damage=1`.
- **Personal single-file build:** `pack_personal.py ... --naomi mvsc2.zip`
  embeds the two ROM members the port reads (about 6 MB). Keep it private.
- **Desktop app:** `--naomi PATH` (or the raw setting `arcade.naomi = PATH` in
  settings.ini), with `--arcade abc` or the settings above.

The set is checked by CRC-32 (every member present must match Rev A). If it
is missing or wrong, the log says so and the PS2 tables are used. Both
netplay peers will need the same toggles; the log prints a session hash of
the loaded tables for that. Details: ARCADE_DIFF.md section 5.

## Input latency
The FPS overlay and Settings > About report the time from each key press,
touch or gamepad button to the 60 Hz game step that reads it:
- The port polls input immediately before every game step.
- A key tap shorter than one frame still counts, because presses are latched
  until the next step.
- On a 60 Hz display the time is below one frame (16.7 ms). It is typically
  half a frame, because a press waits for the next display refresh.

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
