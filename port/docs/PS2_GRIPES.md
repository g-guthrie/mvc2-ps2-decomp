# PS2 version gripes and how the port addresses them

Community complaints about the PS2 release compared with the Dreamcast and
NAOMI arcade versions (forum reports, not measured tests; each will be checked
against the PS2 code/data and the NAOMI decomp before acting on it).

| Gripe | Likely cause on PS2 | Port plan |
|---|---|---|
| Downsampled, muffled audio; one stage's music cuts out after the fight starts (some copies) | Lower-quality audio storage; SPU2/IOP playback | Clean ADX/VAG decode and resampling through SDL; fix the music-stop bug in code; optional override that loads the player's own Dreamcast/NAOMI audio. |
| Muddy / blurry / pixelated visuals | 640x224 field rendering, interlaced NTSC output, bilinear sprites | Progressive output at native resolution, nearest/integer sprite scaling, optional CRT/pixel filters. **Done:** Settings > Video (scaling, upscaling filter, sprite filtering, scanlines / CRT). |
| Slowdown | PS2 performance limits | Fixed 60 Hz logic step on modern hardware; "arcade slowdown" not done: not a code feature (ARCADE_DIFF.md §8). **Done (logic):** fixed step, refresh snapping, and frame skip that drops draws, not logic. |

| Downsampled, muffled audio; one stage's music cuts out after the fight starts (some copies) | Lower-quality audio storage; SPU2/IOP playback | Clean ADX/VAG decode and resampling through SDL; fix the music-stop bug in code (checked 2026-10-30: not reproduced on any VS stage; the port's in-memory ADX player cannot starve like the IOP stream, BOOT_NOTES "Fidelity pass"); optional override that loads the player's own Dreamcast/NAOMI audio. |
| Muddy / blurry / pixelated visuals | 640x224 field rendering, interlaced NTSC output, bilinear sprites | Progressive output at native resolution, nearest/integer sprite scaling, optional CRT/pixel filters. |
| Slowdown | PS2 performance limits | Fixed 60 Hz logic step on modern hardware; optional "arcade slowdown" toggle. |
| Longer loading | CD streaming | AFS entries read from local files; near-instant. |
| Missing animation frames, altered hitboxes, anti-air assists not invincible on startup, counter glitch hitting both characters | Data/code changes in the PS2 build | **Done:** "Arcade accuracy" settings (`arcade.frame_data`, `arcade.damage`, `arcade.cpu_ai`) restore the NAOMI tables from the user's own `mvsc2.zip`. The assist and counter code is the same as the arcade's; the differences are in data (ARCADE_DIFF.md §5-7). |
| Input lag, button layouts | Interlaced pipeline, buffering | Poll input immediately before the update, minimal buffering, full 6-button remapping for pads/sticks/keyboards. **Done:** polled per step, latency measured in the FPS overlay, keyboard and gamepad remapping for 2 players, macros, touch pad. |
| No online play outside Japan | Modem/network mode was Japan-only | Deterministic logic makes rollback netcode feasible later. |
| Shop unlocks | Secret characters bought with points | Optional "unlock everything" setting. **Done:** `game.unlock_all` (default on). |

Sources: racketboy (viewtopic.php?f=44&t=42024), CheapAssGamer ("which version
is better?"), GameFAQs MvC2 boards, Shoryuken forum archive (MvC2 version
differences), Gematsu (2009 developer note on PS2/Xbox issues), StrategyWiki.

Player-facing description of every option: USER_GUIDE.md.
