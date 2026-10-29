# MvC2 PS2: the sound path, traced, and the port's audio layer

This covers the game-side sound API, the commands it sends to the IOP, what
the IOP driver does with them, and the host replacement in `port/audio/`.

Tags: **[verified]** means read in the decompiled C (`src/`), the EE asm, or
the IOP modules' code, and checked against the disc data. **[inferred]** means
deduced and not proven. All addresses are EE `func_XXXXXXXX` unless they are
marked IRX.

The IOP modules come from the user's disc (`/MODULES/*.IRX`). They were
disassembled only under `private/` and are not in git. `TSNDDRV.IRX` ships its
full symbol table and `.mdebug`, so `llvm-objdump -d -r` gives named
functions. `MODHSYN.IRX` is stripped.

## 1. Two systems

| | Music | Sound effects and voices |
|---|---|---|
| Data | AFS00: 23 CRI ADX streams | AFS01: 63 Sony HD/BD banks plus 2 Tamsoft blocks |
| EE code | CRI ADXT/ADXF (`0x3F5F88-0x411C10`) plus game wrappers `0x1E3F50-0x1E46E0` | game wrappers `0x1E2050-0x1E6B00`, Tamsoft client `0x422BE0-0x423E30` |
| IOP | `CRI_ADXI.IRX` (PS2RNA PCM output) | `TSNDDRV.IRX` over Sony `MODHSYN`/`MODMIDI`/`MODMSIN`/`LIBSD` |
| Port | `padx_*` in `audio.h` (ADX decode, 48 kHz) | `tsd_client.h`, the game's boundary, driving `tsd.c` + `synth.c` |

## 2. Music [verified]

### 2.1 Game wrappers

| Function | Role |
|---|---|
| `func_00418910` | Init: `ADXT_Create(2ch, work 0x301E4)` (`401150`), `ADXT_SetReloadSct(0x4B)` (`402208`), `func_00402458(adxt, 2)`, which writes `adxt+0x6D = 2`, the stall-recovery mode (section 6). It also calls `ADXERR_EntryErrFunc` (`402818` -> `3FB108`) with the empty callback `func_00418900`. |
| `func_001E3F50(bgm)` | **Prepare**: `ADXT_Stop`, `ADXT_Pause(adxt, 1)`, `ADXT_StartAfs(adxt, 0, D_004B6A70[bgm])`. Every track starts paused. |
| `func_001E3FE0()` | **Start**: `ADXT_Pause(adxt, 0)`. The output volume is 0.8 x max for AFS00 files 0-10 and max for the others (`ADXT_SetOutVol`). |
| `func_001E40E0` / `func_001E4150` | Stop. `40E0` sends the TSD `0x40` stop-all, then calls `ADXT_Stop` unless the stat is 0 or 5. `4150` calls `ADXT_Pause(1)`, then `ADXT_Stop`. |
| `func_003D3080(sw)` | Pause-menu `ADXT_Pause(sw)`, with the flag kept in `g+0x5C` |
| `func_001E41C0(v)` | Set the volume now: `ADXT_SetOutVol(200*log10(v/127))` in 0.1 dB (`func_001E1FF0`; 0 maps to -999, which is mute) |
| `func_001E4340(n)` / `func_001E46E0` | Fade over n frames, applied each frame (called from `func_001E42A0`) |
| `func_001E4260(stereo)` | `ADXT` mono = !stereo (`402BC0`), and TSD `0x42` |

The CRI names come from the `"E... ADXT_xxx: parameter error"` strings each
function references. `4026B0` is `ADXT_Pause`, not `SetLpFlg`. `ADXT_SetLpFlg`
(`4025F0`) has **no callers**, so the loop flag stays at the default of 1 set
by `ADXT_Create`.

### 2.2 Which track plays where
`D_004B6A70` (48 entries) maps a BGM id to an AFS00 file. A stage plays BGM id
= stage id: `func_00171700` does `func_001E3F50(D_004C27D0)`. It runs during the
stage load, and the round start (`func_001718D0`) calls `func_001E3FE0`.

| stages | 0, 9 | 1, 10 | 2 | 3, 12 | 4, 13 | 5, 14 | 6, 15 | 7, 16 | 8 | 11 |
|---|---|---|---|---|---|---|---|---|---|---|
| AFS00 file | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 11 |

### 2.3 Port: `padx_*` (`port/audio/audio.h`)
`padx_start_afs`, `padx_stop`, `padx_get_stat`, `padx_set_out_vol`,
`padx_pause`, `padx_set_lp_flg`, `padx_get_lp_cnt` and `padx_set_output_mono`
correspond one to one to the `ADXT_*` calls above, and `padx_get_stat` uses
CRI's stat values. The ADX decoder (`adx.c`) streams frame by frame through a
read callback, from memory or the disc. It is bit-identical to `adx.py`.

## 3. Bank format (AFS01) [verified on all 63 banks]

An entry holds `8 x {u32 ofs, u32 size}`:
- `[0]` HD
- `[1]` BD
- `[2]` **TQ**: the Tamsoft sound table (`"RDST" "qesT"` magic, `+0x0E u16 count`, `+0x10 u32 entry[count]` = `priority << 24 | offset`). It is sent to the IOP with the bank.
- `[3]` the **EE table**: 16-byte records, one per sound id.

`func_001E5710(entry, slot)` builds `D_004CC150[slot*512]` from the EE table.
That is 128 x 4 bytes `{1, rec[4], rec[0xE], rec[3]}`. `rec[4]` bit 7 means a
fixed pan of `rec[4] & 0x7F` (`0xC0` is centre), and `rec[3] != 0` means the
next id also sounds (layered). The function then queues command `0x4D(slot,
HD, BD, TQ)`.

The HD layouts are below. Sony's `sdhd.h` names fit the data: every sample has
`velLo 1`, `velHi 127`, `base 60`, `prio 10`, `vol 100`, and the same ADSR.

| Record | Fields used (offset) |
|---|---|
| Prog (`Prog` chunk) | `+0 u32 splitOfs`, `+4 nSplit`, `+5 splitSize (20)`, `+6 vol`, `+7 pan`, `+8 s8 transpose`, `+9 s8 detune`, `+0xA s8 keyFollowPan` |
| Split (20 bytes) | `+0 u16 sset`, `+2 lo`, `+4 hi`, `+6/+8 u16 bendLo/Hi` (semitones << 8), `+0x10 vol`, `+0x11 pan`, `+0x12 s8 transpose`, `+0x13 s8 detune` |
| Sset | `+1 velLo`, `+2 velHi`, `+3 n`, `+4 u16 smpl[n]` |
| Smpl (0x2A bytes) | `+0 u16 vag`, `+2 velLo`, `+4 velHi`, `+0xB baseNote`, `+0xC s8 detune`, `+0xD pan`, `+0xE group`, `+0xF prio`, `+0x10 vol`, `+0x12 u16 ADSR1`, `+0x14 u16 ADSR2` |
| Vagi | `+0 u32 bdOffset`, `+4 u16 rate`, `+6 loop` |

What is in the data:
- ADSR1/2 is `0x80FF / 0x5FC0` on all 1,683 samples: instant exponential attack, sustain at full level, release rate 0.
- The common SE are 8 kHz, with a few at 11/16 kHz. Character voices are labelled 24 kHz.
- 6 programs layer 2 or 3 splits (pans 0/64/127).

## 4. Sound effects and voices

### 4.1 Game-side API [verified]

```
character / effect code ─┬─ func_001E3710(actor, se)        common bank 6, pan from actor x
                         ├─ func_001E3430/3520/3630, 24E0   character bank (slot of the player)
                         ├─ func_001E3890/3CA0/3CC0/3CE0    (6|5|5|7, se, pan 8)
                         └─> func_001E3D20(slot, sound, panIdx, charId)   dispatcher
                               ├ slot 6, sound <=0x1A,0x25-26,0x48-4D -> func_001E4A10 (timed decay, state 4)
                               ├ slot 7, sound 1-5,0x3A-3B,0x40,0x42,0x4C-4D -> func_001E4C40 (timed stop, state 5)
                               └ else -> func_001E59E0 (plain play, handle 1)
fades / stops: func_001E5070 (state 3 fade to 2), func_001E4EB0 (state 2 fade+stop),
               func_001E47E0 / func_001E2420 (stop one), func_001E48B0 (stop all requests),
               func_001E5230 (per frame: runs the 36-entry ring D_004CBE80)
banks: func_001E2050 (boot: AFS01 #59 -> slot 6, #60 -> slot 7), func_001E2150 (stage:
       player i's character bank -> slot i, duplicates share), func_001E22C0/2330/23A0
       (#61/#62 -> slot 5, menus); all via func_001E5870 = func_001E5710 + wait
```

- **Sound id.** `id = (slot & 0x7F) << 16 | (sound & 0x7F) << 8 | handle`.
  Handle 1 is used for ordinary plays. The fading and timed requests use their
  ring index (`D_004C2720`) as the handle, so they can be addressed one by one.
- **Pan.** `panIdx = round(screenX / 40)`, clamped to 0..15. `D_0044F1C0` maps
  it to `0,12,24,36,44,52,58,64,64,70,76,84,92,104,116,127`. The EE table's
  fixed pan overrides it.
- **Volume.** `gain` is sent as an `s8`. Any value >= 128 is negative, so it
  is not sent and the IOP keeps 127. The fades send `(s32)FC`.
- **Priority / voice cutting on the EE (`func_001E59E0`).** Before a sound
  plays on a player slot (0-5), the function stops that slot's other voice
  lines (ids 0-5 and 10-0x1D) if TSD status fno 4 says they are playing. A
  per-character table lists ids that are exempt (`a3 = D_004CD170[slot].w4`).
  Ids >= 0x30 also stop themselves first.

### 4.2 The client boundary (EE -> IOP) [verified; serializer from asm]
The commands go into a 64 x 8-byte queue at `0x633E30` (`w0 < 0` means free).
`func_00423750` drains the queue through the serializer `func_00423E30` into a
512-byte stream terminated by `0xFF`. It then sends the stream with
`sceSifCallRpc(TSD\0 = 0x54534400, fno 0)`. Status queries go to `TSD\1` through
`func_00423990(fno, arg)`.

| EE function | Byte stream | Meaning (IRX handler) |
|---|---|---|
| `422EA0(id, vol, pan, pitch)` | `00-07, bank, sound, handle, [vol] [pan] [pitch hi lo]`. Bits 0/1/2 of the command byte mean vol/pan/pitch is present (the argument is >= 0). | **play**: `treq_TQ` -> `Tsnd_tqreq`. Defaults are vol 127, pan 64, pitch 0x2000. |
| `4230B0(id, vol, pan, pitch)` | `09-0F, bank, sound, handle, ...` (returns 1 if nothing is to be sent) | **change**: `Tsnd_tqchg` |
| `422FB0(id)` | `08 bank sound handle` | **stop**: `Tsnd_tqcancel`. Queued commands for the same id become `0x7F` (dropped). |
| `4231D0()` | `28` | stop all TQ slots (`Tsnd_tq_allstop`) |
| `423240(v)` | `29 hi lo` | master volume (`sceHSyn_SetVolume` on every port); set to `0xF5` at boot |
| `423650()` | `40` | stop all ports |
| `4236C0(on)` | `42 on` | output mode, 1 = stereo |
| `4235D0(slot)` | `48 slot` | release a bank |
| `423480(slot, hd, hdSz, bd, bdSz, tq, tqSz)` | `4D` + 2-byte slot + 3 x (u32 addr \| size >> 20, u16 size >> 4) | load a bank (the IOP DMAs it from EE memory) |
| `4232C0(...)` | `77 ...` | sent once at boot. The IRX's `tsndReqFunc` rejects 0x7x, and an error ends the packet. |
| `423990(4, id)` | TSD\1 fno 4 | 1 while a slot with (bank, sound, handle) is active (`Tsnd_tqchk`) |
| `423990(0x8000000C, 1)` | TSD\1 fno 0xC | number of bank DMAs still pending. `func_001E5870` waits for it to change and then reach 0. |

### 4.3 The IOP driver (TSNDDRV) [verified from the IRX]
- **Ports.** A loaded bank is a port. Each port has **16 request slots**
  (`tqreq_tbl`, 24 bytes each), and slot i plays on MIDI channel i of that
  port's hsyn instance. The driver is clocked by a hardware timer at
  **240 Hz** (`0x25800` IOP cycles; `ATick` -> `TsndTQ_ATick`).
- **Play (`Tsnd_tqreq`).**
  1. Look up `TQ[0x10 + 4*sound]` to get the priority and the byte-code offset.
  2. Take a free slot, searching from 15 down.
  3. If no slot is free, **steal**: take the slot with the largest age whose priority is strictly lower (`<= prio-1`). If there is none, the request is dropped.
  4. Bit 7 of the bank, sound or handle byte marks an exclusive class. An older slot flagged the same way (with the same handle or sound) is stopped. MvC2 never sets these bits.
- **Stop (`Tsnd_tqcancel`)** sets the slot's stop bit. On the next tick the
  slot sends CC120 (all sound off, a hard cut) and frees itself, unless the
  byte code is at a `FE 00` hold point. A stop releases a hold point.
- **Change** stores vol/pan/pitch and flags the slot. At the end of each tick
  `tsnd_tq_chgreq` sends `CC7 = seqVol*reqVol/127`, `CC10 = reqPan-64+seqPan`
  and `bend = seqPitch+reqPitch-0x2000`.
- **TQ byte code (`tsnd_tq`).** The table below lists every opcode. The shipped
  data uses only E0/E1/E2/E3, notes, delta times, FE and FF. Almost every sound
  is `E0 vol, E1 pan, E2 prog, note 60 (or 48) vel 127, wait, note off, FF`.

| byte | meaning |
|---|---|
| `00-7F n` | delta time. If `n & 0x80`, wait `(b+1)` 60 Hz frames (`n` is not consumed); otherwise wait `b + n*128 + 1` ticks. |
| `80-DF [x\|80] v` | note `(b & 0x7F) + 12`, velocity v (0 = key off), sent to hsyn as message `FD 10 ch note x v` |
| `E0 v` / `E1 v` / `E2 p` / `E3 lo hi` | volume / pan / program / pitch bend (combined with the request values as above) |
| `E4-EA` | CC11, CC123, CC120, CC1, CC2, CC64, CC84 |
| `EC-EE` | hsyn SE messages (not used by the data) |
| `F8 lo hi` | jump within the TQ |
| `F9` / `FA` / `FB` / `FD` | NRPN 2/3, CC91, set slot priority |
| `FE 00` | hold while the channel sounds; a stop request releases it (this is how looped sounds end) |
| `FE FE` / `FE xx` | end with CC123 / CC120 |
| `FF` | end once the channel is silent |

### 4.4 hsyn (MODHSYN) [verified for key-on and pitch; the rest is inferred]
- **Key-on (`0x658C`).** Every split of the channel's program whose
  `[lo, hi]` contains the note sounds, so layers play together. The note and
  velocity are then checked against the sset and sample ranges. A non-zero
  sample group stops the other voices of that group (`0x6F14`). Voice
  allocation uses the sample priority (`0x6408/0x6B0C/0x6BB0/0x6DB4`).
- **Pitch (`0x4404-0x4578`).** `pitch = sceSdNote2Pitch(baseNote, 0, note +
  prog.transpose + split.transpose, prog.detune + smpl.detune + split.detune
  [+ bend]) * (vagRate*65536/48000) >> 16`. The detune unit is 1/128 semitone.
  - The character banks play every voice at **note 48 against base 60**, or note 60 with a program transpose of -12. Their "24 kHz" VAGs therefore play at **12 kHz**. Their spectrum is band-limited at 6 kHz, so the source material was 12 kHz.
  - Common SE are 8 kHz.
  - That is the data behind the "muffled" gripe. The port keeps the pitch, because a different pitch would change the sound, but it removes the SPU2's 4-point Gaussian interpolation.
- [inferred] Volume is the product of sample, split, program, CC7 and CC11
  (all /127) times the master volume (`0x29`, read as 256 = unity). Pan adds
  the four pan fields to the channel pan and applies an equal-power law,
  normalised to 0 dB at the centre. Voice stealing takes the lowest priority,
  then released voices, then the oldest. The real hsyn allocator was not traced
  beyond its entry points.

### 4.5 Sound id -> tone, worked example
`func_001E3710(actor, 0x30)` plays hit sound 0x30 (`func_001E3A10` picks 0x30 or 0x31 by hit strength) for an actor at x = 320:
1. `func_001E3D20(6, 0x30, 8, charId)` -> `func_001E59E0`.
2. `D_004CC150[6*512 + 0x30*4]` gives the pan: `PAN_TAB[8] = 64`.
3. `422EA0(0x063001, -1, 64, -1)` queues the bytes `02 06 30 01 40`.
4. The IOP looks up AFS01 #59 `TQ[0x30]` = `{prio 10, ofs}`. Its byte code is `E0 6F E1 40 E2 30 B0 83 7F <wait> B0 83 00 FF`.
5. Request slot k (synth channel k) gets program 0x30, then note 60 vel 127. Prog 0x30 has 1 split (12..119), which leads to 1 sset and 1 sample (base 60), so the VAG plays at its 8000 Hz rate x 2^((60-60)/12). The note-off comes after the wait, by which time the one-shot VAG has ended. `FF` then frees the slot once the channel is silent.

## 5. The port's audio layer (`port/audio/`)

| File | Contents |
|---|---|
| `adx.c/h` | streaming ADX decoder; loop restore/carry (section 6) |
| `vag.c/h` | SPU2 ADPCM decoder; loop body decoded with carried history |
| `hdbank.c/h` | AFS01 bank parse (HD records, BD -> PCM, TQ, EE table) |
| `resample.c/h` | Kaiser-windowed sinc (16 taps per side, cutoff 0.95, β 9), polyphase fast path, streaming stereo converter |
| `synth.c/h` | hsyn replacement: 16 ports x 16 channels, 48 voices, SPU2-exact ADSR at 48 kHz, layering, pitch formula, priority stealing |
| `tsd.c/h` | TSNDDRV replacement: command stream parser, TQ slots and byte code at 240 Hz, status RPC |
| `tsd_client.c/h` | **the game's sound boundary**: same functions, signatures, 64-entry queue, cancel semantics and serializer as `0x422BE0-0x423E30`. The link step points `func_00422EA0` etc. at `tsdc_*` (the table is in the header). On 64-bit hosts, `tsdc_load_bank_ptr` passes real pointers as address tokens. |
| `audio.c/h` | engine: 48 kHz float mixer (TSD + BGM, master gain, clamp), SDL device (float32, 48 kHz; any other device rate goes through the sinc converter), lock, `padx_*`, web unlock, pause |
| `wav.c/h` | WAV I/O for tests |
| `port/apps/soundtest.c` | demo / test tool (section 7) |

### 5.1 Behaviour
- **Mixing.** The mixer renders at 48 kHz in the SDL callback and advances the
  driver 240 times a second (every 200 frames). API calls take the
  device lock.
- **Resampler.** VAG voices use the polyphase table. Steps above 1 widen the
  kernel. Measured from 48 kHz to 44.1 kHz: SNR 93 dB at 1 kHz and 96 dB at
  15 kHz; 20 kHz falls in the transition band.
- **Declick** (on by default, `Synth.declick`). The data's ADSR2 release rate
  0 is a 2-sample cut and CC120 is a hard stop. The port ramps both over 64
  samples (1.3 ms). This is the one intentional deviation from the SPU2.
- **Web.**
  - SDL2 opens a Web Audio context through a ScriptProcessorNode.
  - `audio_init` installs capture-phase `pointerdown`/`touchend`/`mousedown`/`keydown` listeners that call `audioContext.resume()` inside the gesture and start a 1-sample buffer (needed on iOS).
  - `audio_set_paused` (wire it to `PlatApp.on_pause`) pauses the SDL device and suspends or resumes the context.
  - Checked in headless Chromium (Playwright): an emulated locked context resumed on the first click, and hiding the page suspended it and showing it resumed it (`private/converted/audio_port/web_soundtest.png`). The device rate there was 44.1 kHz, so the converter ran. An AnalyserNode on SDL's output node read RMS 0.16 while track 1 played.

## 6. Music cut-out gripe ("one stage's music stops after the fight starts")

### 6.1 Every stage track loops correctly through the port's player
`soundtest --loop-check` writes `private/converted/audio_port/loopcheck.txt`.
- **Loops.** All 18 looping tracks:
  - have consistent loop points (loopStartByte = data + frame(loopStart)*36, and loopEnd <= total);
  - repeat pass 1 exactly on pass 2 (history restored);
  - stay `PLAYING` through 2+ loops in the ADXT shim at 48 kHz.
- **One-shots.** The 5 one-shots (12, 13, 14, 17, 18) end with `PLAYEND`.
- **Full-file loops.** Stage files 0 and 1 (stages 0/9 and 1/10) loop the whole file (loopStart 0).

**Finding: the PS2's loop seam glitches.**
- **Cause.** CRI's loop trap `adxt_trap_entry` (`0x403020`) only resets the
  ADXSJD position counters (`3FFED0/3FFF30-50`). It keeps the predictor
  history from loopEnd, and these v3 headers have no loop-start history.
- **Effect.** Decoding with that history leaves a transient after every jump.
  It is up to **25,645** (-2 dBFS) and lasts about 850 samples (18 ms) on
  track 7 (stages 7 and 16). It is over 8,000 on tracks 2, 4, 8, 10, 16, 19
  and 22.
- **Port.**
  - `ADX_LOOP_RESTORE` is the default: it restores the history saved at loopStart on pass 1, as vgmstream does and as v4 headers allow.
  - `padx_set_loop_carry(1)` reproduces the PS2 behaviour.

### 6.2 Code-side stop paths
- **Game code never stops BGM during a fight.**
  - The `ADXT_Stop` callers are scene exits: `0016BE80`, `0016BF10`, `0016EC30`, `00172A10`, `00176920`, `003D5360`, `0012FA40`, `00127520`, `001278F0` and so on, through `func_001E40E0` / `func_001E4150`.
  - No code calls `ADXT_SetLpFlg(0)`.
  - The only pause paths are the pause menu (`003D30A0`/`003D31A0`). `003D30A0` resumes only when `p->b0 == 0`.
- **Paused tracks are always resumed.** The stage track starts paused (`func_001E3F50`). Round start (`func_001718D0`) resumes it twice: through `func_001E3FE0`, which has early returns, and through `func_003D35C0` -> `ADXT_Pause(0)`, which is unconditional.
- **There is a stop path inside CRI, armed by the game's settings.**
  - **Detector.** The ADXT server check at `0x403E20` counts server calls in which a PLAYING, unpaused stream shows no progress in the decoder's sample counter (ADXSJD `+0x2C`, [inferred] meaning). Past `5 x svrFreq` = 300 calls it sets error -2 and calls **`ADXT_Stop`**. It does this in recovery modes 1 and 2 alike. The game's mode 2 only turns the *input-underrun* and *read-error* cases into a replay (`0x403D30`), and the stall check runs first.
  - **No recovery.** The error callback is empty, and no game code polls `ADXT_GetStat` during a fight. The track therefore stays silent until the next `func_001E3F50`.
  - **Fast trigger.** The ADX server is also called on every poll iteration of the synchronous file loader `func_0012DA40` (through `func_00418B10`), which reads AFS02 with ADXF from the same drive. A stall can therefore pass 300 calls in a fraction of a second.
  - **Cause.** A drive that stalls or retries reads of the AFS00 track after the round start would stop that stage's music for the rest of the round. Slow or worn discs fit the "some copies" wording.
  - **Fit.** The window opens exactly at round start, because the track is paused, and so exempt from the check, during the stage load.
  - **Conclusion.** The data is fine (6.1), so this stall-then-stop path is the explanation the code supports [inferred: not reproduced on hardware].
- **The port does not have this path.** Its ADX player reads from memory, never stalls, and stops only on `padx_stop` or a one-shot's end.

## 7. Demo and verification (`soundtest`)

```
build/port-native/soundtest --iso private/disc/mvc2.iso                 # interactive
  UP/DOWN track, LP (A/Square) play, LEFT/RIGHT sound, LK (Z/Cross) play,
  HP/HK bank +/-, START stop, M mono, L loop, H touch pad
soundtest --verify private/converted/audio_py       # vs adx.py / hdbd.py WAVs
soundtest --loop-check private/converted/audio_port/loopcheck.txt
soundtest --track 7 --bank 0 --sound 1 --render out.wav --seconds 10
soundtest --decode-adx 15 out.wav                   # first pass, native rate, smpl chunk
soundtest ... --frames 120                          # interactive smoke test, quits after 120 frames
```
On the web, `build/port-web/soundtest.html` uses the shared shell and its
file picker; the app exports `viewer_open_js`.

Results:
- **Verify.** All 23 AFS00 tracks are **sample-exact** against `adx.py` (48.8 M
  stereo frames), and so are all 176 VAGs of banks 0, 14, 59, 60, 61 and 62 against
  `hdbd.py`. The mixer passes ADX through bit-exactly at 0 dB, so a 48 kHz
  render of a track alone equals the decoder output.
- **Synth sanity.**
  - #59 sound 0 starts within one tick (380 frames: the first tick plus the attack) and lasts the VAG length at 8 kHz.
  - Ryu (#0) sound 1 lasts 2x its 24 kHz length, which is the traced 12 kHz playback.
  - #59 sound 58 is silent: its program has 0 splits in the HD.
- **Cost.** A 10-second stress test averaging 14 voices takes 0.29 s of CPU natively.

## 8. Open / not traced
- MODHSYN beyond key-on and pitch: the exact volume curve, the pan law, the
  allocator ties and the SE messages `0xEC-0xEE`. The data does not use the
  SE messages.
- `D_004CD170[slot]` volume fades (`func_001E4480`) are computed on the EE, but
  where they are applied was not traced.
- The PS2 output level of SE against BGM (the hsyn master `0xF5` against
  ADXT's 0 dB) has not been calibrated.
