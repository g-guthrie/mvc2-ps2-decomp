"""Host compile flags shared by probe_host_build.py; port/CMakeLists.txt
mirrors them (keep the two in sync)."""
import os

TARGETS = {
    # -malign-double: EE ABI aligns long long/double to 8 inside structs
    # (measured with MWCC: sizeof(struct{char;long long;}) == 16); i386 SysV
    # would use 4 and shift every struct offset after such a member.
    "i386": ["--target=i386-linux-gnu", "-m32", "-malign-double"],
    "wasm32": ["--target=wasm32-unknown-unknown"],
    # PRIMARY target: the Emscripten toolchain's own clang (what emcc runs per
    # TU; calling it directly skips emcc's ~0.3 s python start-up per file).
    "emscripten": ["--target=wasm32-unknown-emscripten"],
}

EMSDK = os.environ.get("EMSDK", "/home/user/emsdk")
COMPILERS = {"emscripten": os.path.join(EMSDK, "upstream/bin/clang")}


def compiler(target):
    return COMPILERS.get(target, "clang")


def common_flags(root):
    return [
        "-std=gnu99", "-O0", "-ffreestanding", "-nostdlibinc", "-fno-builtin",
        "-fno-common", "-fsigned-char",
        "-w",  # decomp C is full of K&R / implicit decls; report errors only
        "-Wno-error=implicit-function-declaration", "-Wno-error=int-conversion",
        "-Wno-error=incompatible-pointer-types", "-Wno-error=implicit-int",
        "-Wno-error=return-type", "-Wno-error=incompatible-function-pointer-types",
        "-ferror-limit=50",
        "-include", str(root / "port/include/ps2_compat.h"),
        "-I", str(root / "src"), "-I", str(root / "src/data"),
    ]
