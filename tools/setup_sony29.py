#!/usr/bin/env python3
"""Install the pinned Sony EE GCC 2.9 compiler without changing existing tools."""
import argparse
import hashlib
import os
from pathlib import Path
import shlex
import shutil
import subprocess
import tarfile
import tempfile
import urllib.request

URL = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111.tar.gz"
SHA256 = "9ebbb042eb1e5d33d772293c5e9286a54dbec29865a3d7fbb398c97436f33583"
ROOT = Path(__file__).resolve().parents[1]


def install(archive, destination):
    if hashlib.sha256(archive.read_bytes()).hexdigest() != SHA256:
        raise ValueError("Sony compiler archive SHA-256 mismatch")
    with tempfile.TemporaryDirectory(prefix="mvc2-sony29-") as temporary:
        stage = Path(temporary)
        with tarfile.open(archive, "r:gz") as bundle:
            bundle.extractall(stage, filter="data")
        compiler = Path("lib/gcc-lib/ee/2.9-ee-991111/cc1.exe")
        if not (stage / compiler).is_file():
            raise ValueError("compiler archive has no expected cc1.exe")
        files = [p for p in stage.rglob("*") if p.is_file()]
        for source in files:
            target = destination / source.relative_to(stage)
            if target.exists() and target.read_bytes() != source.read_bytes():
                raise ValueError(f"preserving different existing tool: {target}")
        for source in files:
            target = destination / source.relative_to(stage)
            target.parent.mkdir(parents=True, exist_ok=True)
            if not target.exists():
                shutil.copy2(source, target)
    return (destination / compiler).resolve()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--archive", type=Path, help="use a local copy of the pinned archive")
    args = parser.parse_args()
    runner = os.environ.get("WIBO")
    if not runner:
        parser.error("source private/build.env first (WIBO is required for the smoke test)")
    destination = ROOT / "private/toolchain/compilers/ee-gcc-2.9-991111"
    with tempfile.TemporaryDirectory(prefix="mvc2-sony29-download-") as temporary:
        archive = args.archive
        if archive is None:
            archive = Path(temporary) / "compiler.tar.gz"
            urllib.request.urlretrieve(URL, archive)
        compiler = install(archive, destination)
        source, output = Path(temporary) / "smoke.i", Path(temporary) / "smoke.s"
        source.write_text("extern int f(int); int probe(int x,int y) { int a=f(x); int b=f(y); return f(a)+b; }\n")
        subprocess.run([runner, str(compiler), str(source), "-O2", "-G0", "-quiet", "-o", str(output)], check=True)
        assembly = output.read_text()
        if "gcc2_compiled" not in assembly or not all(instruction in assembly for instruction in ("sd\t$16,0($sp)", "sd\t$17,16($sp)", "sd\t$31,32($sp)")):
            raise ValueError("Sony compiler spill-layout smoke test failed")
    environment = ROOT / "private/sony29.env"
    environment.write_text(f"export EE29CC1={shlex.quote(str(compiler))}\n")
    print(f"Verified Sony EE GCC 2.9 archive and native SD/LD spill layout. Run: . {environment}")


if __name__ == "__main__":
    main()
