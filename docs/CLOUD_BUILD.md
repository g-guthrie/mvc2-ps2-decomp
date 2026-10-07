# Cloud matching-build setup

The source repository is public. Retail data and proprietary compiler binaries
are supplied through an authenticated release in the private companion repository
[g-guthrie/mvc2-ps2-build-inputs](https://github.com/g-guthrie/mvc2-ps2-build-inputs).
They remain outside the source repository's Git history.

## Inputs supplied

The pinned `build-inputs-v1` release contains:

- `private/SLUS_204.86.rom`: the exact 3,941,760-byte loaded image.
- `private/extracted/SLUS_204.86`: a deterministic reconstruction of the complete
  retail ELF, with SHA-256
  `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
- MWCCPS2 `mwcps2-3.0.3-020716` and `mwcps2-3.0-011126`, including their DLLs.
- Wibo 1.2.0 for Linux x86-64 and macOS, from the official
  [decompals/wibo release](https://github.com/decompals/wibo/releases/tag/1.2.0).
- A SHA-256 manifest for every supplied file.

The bootstrap pins the archive SHA-256, checks all file digests, preserves any
existing input whose content differs, and smoke-tests both compilers. It writes
absolute tool paths to the ignored `private/build.env` for the current checkout.
A Mac `wibo` executable cannot run in Linux; the bootstrap selects the Linux
binary on a Linux x86-64 executor.

## Linux x86-64 cloud executor

Use Python 3.11.8 or later and a GitHub identity authorized to read the private
companion repository. Cloud identities scoped only to the public source repo
must also be granted access to the private input repo. A download authorization
failure does not mean the inputs are absent locally.

On a Debian/Ubuntu executor, install the build dependencies if absent:

```sh
sudo apt-get update
sudo apt-get install -y python3-venv binutils-mipsel-linux-gnu libc6-i386 gh
```

From the source checkout:

```sh
git pull --ff-only
python3 -m venv .venv
.venv/bin/pip install -r requirements.txt
.venv/bin/python tools/bootstrap_private_inputs.py
. private/build.env
make split hybrid test report PYTHON="$PYTHON"
```

The bootstrap uses `gh release download` against the private release; it never
requires writing a token into the source tree or exposing one in a command.
If an authenticated bundle is already attached to the executor, import it with:

```sh
.venv/bin/python tools/bootstrap_private_inputs.py --archive /path/to/mvc2-ps2-private-inputs.tar.gz
. private/build.env
```

For a checkout at `/workspace/mvc2-ps2-decomp`, the generated values are:

```text
WIBO=/workspace/mvc2-ps2-decomp/private/toolchain/wibo-x86_64
MWCCPS2=/workspace/mvc2-ps2-decomp/private/toolchain/compilers/mwcps2-3.0.3-020716/mwccps2.exe
MWCCPS2_30=/workspace/mvc2-ps2-decomp/private/toolchain/compilers/mwcps2-3.0-011126/mwccps2.exe
PYTHON=/workspace/mvc2-ps2-decomp/.venv/bin/python
```

## Verification and continuation

`make hybrid` first compiles and checks every cataloged function/data replacement,
then verifies symbol placement and the full image/ELF hashes. `make test` and
catalog validation alone do not prove compiler matching or full-image linkage.
The hybrid image preserves unmatched retail bytes, so a byte-identical image
still does not establish 100% decompilation. Continue recovering real C and typed
data under [DECOMP.md](../DECOMP.md) and the progress catalog rules.

The source at this handoff credits 475,852 / 3,293,696 code bytes (14.4474%) and
4,200 / 648,064 reconstructed data bytes (0.6481%). Earlier cloud checkout
reports of 13.8286% refer to an older source checkpoint.
