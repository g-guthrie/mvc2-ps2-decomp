# Build inputs

Three things the NAOMI build needs are not ours to redistribute, so they are
not in the repository. Supply them from material you own, at these paths under
`naomi/`:

    orig/mvsc2.zip                  Marvel vs. Capcom 2 NAOMI ROM set (Export/Korea Rev A)
    toolchain/hitachi-shc-5.1r08/   Hitachi SH C/C++ compiler 5.1 Release 8
    toolchain/naomi-sdk/lib/        Sega's prebuilt NAOMI SDK libraries

All three paths are gitignored. The manifests that pin them are committed, so
the wrong build of any input is reported, not silently used:

    config/target.json                  ROM set and member hashes
    toolchain/hitachi-shc-5.1r08.json   per-file compiler hashes
    toolchain/naomi-sdk.json            per-file SDK hashes and their source

`toolchain/wibo/` (MIT) runs the Windows compiler and is committed.

## Host

Linux x86_64, or macOS with Intel application support (Rosetta on Apple
Silicon). Python 3.10 or newer; the build uses only the standard library.
Linux ARM64 cannot run the bundled x86_64 runtime. If a copy stripped the
executable bits: `chmod +x toolchain/wibo/wibo-x86_64 toolchain/wibo/wibo-macos`.

## Check

```sh
cd naomi
python3 tools/build.py check --clean --jobs 2
```

Wait for `PASS full main ... and program ROM ... match` and a zero exit
status. A quicker integrity check of the inputs alone:

```sh
python3 - <<'PY'
import sys
sys.path.insert(0, 'tools')
from core import ROOT, load, sha, verify_rom, verify_tools
print(verify_tools())
target = load(ROOT / 'config/target.json')
assert sha((ROOT / target['archive']).read_bytes()) == target['archive_sha256']
print(f"PASS: {len(target['roms'])} ROM members, {len(verify_rom(target))} program bytes")
PY
```

## CI

`.github/workflows/naomi-build.yml` checks for the inputs and skips the build
and evidence steps when they are absent, which is the normal state for a fresh
clone. To run the real build in CI, supply the inputs to the runner from
somewhere private.
