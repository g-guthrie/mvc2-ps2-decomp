# naomi_oracle: the arcade program as a frame-by-frame oracle

Runs the NAOMI arcade program (the user's own MAME `mvsc2.zip`, Rev A
`epr-23085a`, and NAOMI BIOS `naomi.zip`) headless in the Flycast core and
dumps the gameplay state once per game frame, so the port's arcade mode can be
compared with the real arcade program the way `port/tools/oracle/` compares
the port with the retail PS2 executable.  No ROM or BIOS bytes are in this
directory or in anything it writes to git.

| File | What |
|---|---|
| `build.sh` | clones Flycast v2.5 (pinned commit), applies `flycast.patch`, links the driver; `WORKDIR/build/flycast` |
| `flycast.patch` | guest-PC hooks (the SH-4 dynarec's block decoder calls `oracle_call_hook()` before a block that starts at a hook PC and splits blocks there; the interpreter checks every PC), a JVS button override, no audio throttle, the null renderer, symbols kept, the `--naomi-oracle` entry |
| `naomi_oracle.cpp`, `oracle_hook.*`, `naomi_dump.h` | the driver (copied into `core/oracle/` by `build.sh`) |
| `naomi_compare.py` | translates a NAOMI dump to the PS2 layout and compares it with the port's `MVC2_STATE_DUMP` |
| `run_pair.sh` | one scenario on both sides + the comparison |
| `scripts/` | `menu_naomi.txt` / `menu_port.txt` (the two menus) + `body_fight.txt` (the fight, from `oracle/scripts/fight_mix.txt`); `mk.sh` writes `naomi_fight.txt` / `port_fight.txt` |

## Build and run

```sh
port/tools/naomi_oracle/build.sh                 # ~12 min, ~250 MB in /tmp/naomi_oracle_src
export NAOMI_ZIP=/path/to/mvsc2.zip NAOMI_BIOS=/path/to/naomi.zip
TEAMS="--p1-team 0:0:1,0x17:0:0,0x2c:0:2 --cpu-team 6:0:0,0x2a:0:0,0x34:0:0" \
NAOMI_ARGS="--poke 2/1/2/0@0C2D703A:1:7" ARCADE=de \
port/tools/naomi_oracle/run_pair.sh OUT 7000 2/1/2/3 \
    port/tools/naomi_oracle/scripts/naomi_fight.txt port/tools/naomi_oracle/scripts/port_fight.txt
```

The oracle alone: `flycast --naomi-oracle --game mvsc2.zip --home DIR
[--script F] [--frames N] [--dump F] [--resync STATE] [--p1-team a,b,c]
[--cpu-team a,b,c] [--poke STATE@ADDR:SIZE:VALUE | F:ADDR:SIZE:VALUE]
[--snap F:FILE] [--trace ADDR] [--interp] [--region N] [--no-freeplay]`.
`DIR` holds `naomi.zip` (a link); the EEPROM / NVRAM files written there make
later runs differ, so `run_pair.sh` uses a fresh one per run.  About 80 game
frames/s on one core; the same inputs give byte-identical dumps.

## How it lines up with the port

- **Frame point:** 0x0C0283D6 in the main loop 0x0C028394, right after the
  V-blank wait 0x0C1E9B20 returns (the logic step has not run): the same
  point as the PS2 oracle's `func_0012F460` entry and the port's
  `mvc2_frame()`.
- **State names:** `g = 0x0C2D6F88` on the NAOMI (`0x004F4300` on the PS2);
  scripts and `--resync` take up to five levels, `g[0..4]`
  (`2/1/2/3` = the first frame of a fight; the port's script matcher and
  `MVC2_RESYNC` take five levels too).  The attract states match the PS2's
  (1/1 logo, 1/2, 1/3, 1/4 demo set-up, 1/5 demo, 1/6), the fight is 2/1/2
  on both; the menus differ (the arcade goes from its attract to the
  character select with START, free play).
- **Input:** script names are the PS2 pad's; square LP, triangle HP, l1 A1,
  cross LK, circle HK, r1 A2 map to JVS buttons 0..5 (the PS2 default
  BUTTON CONFIG), plus `coin`, `test`, `service`.  Buttons set at frame N
  reach the game's input record at frame N+2 (the JVS request, then the
  V-blank parse), so the port runs with `MVC2_ARCADE_DELAY=2`
  (`run_pair.sh` `PAD_DELAY`).
- **Teams:** `--p1-team` / `--cpu-team` `ID[:T[:P]]` as the port's (T assist
  type, P palette, which the port ignores): the id goes to +0x52C when the
  game loads that player's PAK (0x0C02764C, the twin of PS2 `func_0012EF50`)
  and at the fight's load pass (0x0C0230C6).
- **Resync:** at the first frame of STATE the game RNG (0x0C283049/48 = PS2
  `D_004C26AC/B0`) and g+0x10/0x1C/0x20 get the PS2 oracle's values.
- **Layout:** players at 0x0C2D7088, stride 0x5A4 (PS2 0x004F20B0, 0x5B8);
  PS2 offset = NAOMI + 0 below 0x84, + 0x10 for 0xEC..0x183, + 0x14 from
  0x19C (found with `naomi_compare.py --align`); the PS2 inserts 16 bytes of
  render state in 0x84..0xEB and has more PAK section pointers in
  0x184..0x19B (neither compared).  Fields that differ by design are listed
  with their reason in `naomi_compare.py` (`BY_DESIGN`, `G_BY_DESIGN`).

## Results

See `port/docs/BOOT_NOTES.md` "Arcade oracle" for the scenarios, match
lengths and findings.
