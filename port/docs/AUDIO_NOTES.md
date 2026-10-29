# Audio layer: progress notes (Port I)

Append-only log so a restart can resume. Newest last.

## 1. Trace (done)
- BGM: ADXT wrappers 1E3F50 (Stop, Pause(1), StartAfs = "prepare paused"),
  1E3FE0 (Pause(0) + volume = "start"), 1E40E0 / 1E4150 (stop), 3D3080
  (pause menu). CRI names recovered from the "E... ADXT_xxx: parameter error"
  strings (scratch script names.py): 4026B0 = ADXT_Pause (not SetLpFlg),
  402458 writes adxt+0x6D = auto-recovery mode 2 (replay), 402818 =
  ADXERR_EntryErrFunc(empty 418900).
- TSD client: 64 x 8-byte EE queue at 0x633E30, serializer 423E30 (asm only)
  -> 512-byte byte stream -> sceSifCallRpc(TSD\0, fno 0). Status RPC TSD\1
  (423990(fno, arg)): fno 4 = Tsnd_tqchk (is (bank,sound,handle) active).
- IOP: TSNDDRV.IRX has a full symbol table (llvm-objdump works on it).
  treq_TQ / Tsnd_tqreq / tsnd_tq traced: 16 request slots per bank port,
  slot i = MIDI channel i of an hsyn port; TQ byte code interpreted at 240 Hz.
  MODHSYN (stripped) traced only for key-on and pitch: note used as sent,
  pitch = sceSdNote2Pitch(baseNote, 0, note+transposes, fine) * rate/48000.
- Character voices: TQ note = base-12 (or prog transpose -12) => effective
  12 kHz playback of "24 kHz" VAGs; their spectrum is band-limited at 6 kHz,
  i.e. 12 kHz material. This is the data, not a bug.

## 2. Implementation
(see below)
- port/audio/ written: adx, vag, hdbank, resample (Kaiser sinc, 8 taps/side),
  synth (hsyn-like), tsd (TSNDDRV), tsd_client (EE queue + serializer),
  audio (SDL device, ADXT-shaped BGM, mixer), wav. Targets port_audio and
  soundtest in port/cmake/frontend.cmake. Native build clean.
- `soundtest --verify private/converted/audio_py`: all 23 ADX tracks and
  176 VAGs (banks 0, 14, 59-62) sample-exact vs adx.py / hdbd.py.
- `--loop-check`: all 18 loops valid and keep PLAYING through 2+ loops; 5
  one-shots end. Found: CRI's v3 loop (adxt_trap_entry 0x403020) carries the
  predictor history into loopStart -> transient up to 25645 for ~850 samples
  (track 7 = stages 7/16). Port default restores the loop-start history
  (pass 2 == pass 1 exactly); padx_set_loop_carry(1) gives the PS2 behaviour.
- Fixed: tsd.c byte macro evaluated p++ twice (skipped operands). Kernel
  widened to 16 taps/side + polyphase fast path (48k->44.1k: 93-96 dB SNR to
  15 kHz; 14-voice stress 0.29 s CPU per 10 s).
- Mixer passthrough verified: 8 s render of track 15 == adx.py bytes; looped
  render repeats pass 1 exactly after loopEnd.
- Web: builds (soundtest.html, shared shell, exports viewer_open_js).
  Playwright: locked context resumes on first click; hide/show suspends and
  resumes; AnalyserNode RMS 0.16 while a track plays (44.1 kHz device).
- Docs: port/docs/AUDIO.md written (trace, protocol, IOP semantics, port
  layer, loop check, cut-out analysis). Status: done; integration = point
  func_00422BE0..00423E30 at tsdc_* and the ADXT calls at padx_*.
