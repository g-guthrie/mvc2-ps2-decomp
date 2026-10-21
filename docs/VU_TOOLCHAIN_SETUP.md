# DVP/VU tools for local recovery

The EE C compilers do not assemble VU microprograms. For that work, use
[PS2Dev's GNU binutils fork](https://github.com/ps2dev/binutils-gdb), pinned to
`3eb45ea37f0efd498d1de3cf9562de07197aefa8` (`dvp-v2.45.1`). The
[upstream build coordinator](https://github.com/ps2dev/ps2toolchain-dvp/tree/d8aa68a0295dcc480255826b1320857278ffdfc2)
is the reference for other hosts.

## Tested Apple Silicon setup

This build was tested on macOS 15.4 with Apple Clang 17, GNU make 4.4.1,
GMP 6.3.0 and MPFR 4.2.2. It installs into a private directory, without changing
system tools. GNU make, GMP and MPFR must already be available at the paths
below. The commands skip documentation generation because the tested host did
not have `makeinfo`.

Run from the repository root. `private/` is ignored by Git.

```sh
mkdir -p private/dvp-toolchain
cd private/dvp-toolchain
DVP_ROOT="$PWD"
git clone --branch dvp-v2.45.1 https://github.com/ps2dev/binutils-gdb.git src
git -C src checkout --detach 3eb45ea37f0efd498d1de3cf9562de07197aefa8
mkdir -p build
cd build
MAKEINFO=true CC=clang CXX=clang++ ../src/configure --quiet \
  --prefix="$DVP_ROOT/install/dvp" --target=dvp \
  --disable-nls --disable-build-warnings --with-system-zlib \
  --with-gmp=/opt/homebrew/opt/gmp --with-mpfr=/opt/homebrew/opt/mpfr
gmake -j8 MAKEINFO=true CFLAGS='-O2 -Wno-implicit-function-declaration' \
  all-gas all-binutils
gmake -j8 MAKEINFO=true install-gas install-binutils
export DVP_BIN="$DVP_ROOT/install/dvp/bin"
"$DVP_BIN/dvp-as" --version
```

The assembler reports GNU Binutils 2.45.1, configured for target `dvp`.
Linux/cloud users should follow the upstream coordinator's host dependency
instructions; the macOS Homebrew paths above are not portable. This project has
not yet tested a Linux build of this pinned toolchain.

## Assemble and inspect

Use an explicit VU architecture when disassembling. DVP ELF objects carry a
MIPS machine identifier, so relying on automatic architecture selection can
produce misleading output.

```sh
"$DVP_BIN/dvp-as" -o program.o program.vsm
"$DVP_BIN/dvp-objdump" -d -m dvp:vu program.o
"$DVP_BIN/dvp-readelf" -S -r program.o
# For a private raw VU instruction stream:
"$DVP_BIN/dvp-objdump" -D -b binary -m dvp:vu --endian=little program.bin
```

On the tested build, `dvp-objcopy` did not recognize the assembled DVP object
as an input target. Extract `.vutext` with the repository's pinned `pyelftools`
installation instead (set `PYTHON` to that environment's interpreter). For a standalone, fully resolved program starting at VU
address zero:

```sh
"$PYTHON" - program.o program.vutext.bin <<'PY'
import sys
from pathlib import Path
from elftools.elf.elffile import ELFFile

with open(sys.argv[1], "rb") as stream:
    elf = ELFFile(stream)
    sections = list(elf.iter_sections())
    code = [s for s in sections if s.name == ".vutext"]
    assert len(code) == 1, "Expected one .vutext section"
    assert code[0]["sh_addr"] == 0, "Expected a standalone program at VU address 0"
    assert not any(s["sh_type"] in ("SHT_REL", "SHT_RELA") for s in sections), \
        "Resolve relocations before comparing bytes"
    payload = code[0].data()
    assert payload and len(payload) % 8 == 0, "VU instruction pairs are 8 bytes"
Path(sys.argv[2]).write_bytes(payload)
PY
```

The local tool validation disassembled and reassembled a 462-instruction-pair
private program into the same 3,696 bytes, with no unresolved relocations.
That verifies the tools' roundtrip for this input. It does not establish recovered
algorithm semantics, source ownership, or matching progress. VIF/DMA packet
headers and payload extents require their own verification. Keep retail inputs,
derived disassemblies, tool binaries and generated objects private; this document
publishes only tool setup and usage.
