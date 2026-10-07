#!/usr/bin/env python3
"""Install bundled build inputs and export a portable matching-build environment."""
import argparse
import hashlib
import os
from pathlib import Path
import platform
import shlex
import shutil
import subprocess
import tarfile
import tempfile

INPUT_ASSET = "mvc2-ps2-build-inputs.tar.gz"
EXPECTED_ARCHIVE_SHA256 = "585273a539688311c7c70833468527cd2ae82e5f1476c521233b3a361d611582"
ROOT = Path(__file__).resolve().parents[1]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def install(archive):
    if digest(archive) != EXPECTED_ARCHIVE_SHA256:
        raise SystemExit("private input archive SHA-256 mismatch")
    with tempfile.TemporaryDirectory(prefix="mvc2-inputs-") as directory:
        stage = Path(directory)
        with tarfile.open(archive, "r:gz") as bundle:
            # The archive itself is pinned above; also reject paths outside private/.
            for member in bundle.getmembers():
                parts = Path(member.name).parts
                if not parts or parts[0] != "private" or ".." in parts or member.name.startswith("/"):
                    raise SystemExit("invalid private input archive path")
                if not (member.isfile() or member.isdir()):
                    raise SystemExit("unexpected private input archive member")
            bundle.extractall(stage, filter="data")
        manifest = stage / "private/SHA256SUMS"
        files = []
        for line in manifest.read_text().splitlines():
            expected, relative = line.split("  ", 1)
            source = stage / relative
            if digest(source) != expected:
                raise SystemExit(f"input SHA-256 mismatch: {relative}")
            destination = ROOT / relative
            if destination.exists() and digest(destination) != expected:
                raise SystemExit(f"preserving different existing input: {relative}")
            files.append((source, destination))
        for source, destination in files:
            destination.parent.mkdir(parents=True, exist_ok=True)
            if not destination.exists():
                shutil.copy2(source, destination)
        shutil.copy2(manifest, ROOT / "private/SHA256SUMS")
        print(f"verified and installed {len(files)} private input files")


def configure():
    system, machine = platform.system(), platform.machine()
    if system == "Darwin":
        runner = "wibo-macos"
    elif system == "Linux" and machine in {"x86_64", "amd64"}:
        runner = "wibo-x86_64"
    else:
        raise SystemExit(f"unsupported wibo host: {system}/{machine}")
    toolchain = ROOT / "private/toolchain"
    values = {
        "WIBO": str(toolchain / runner),
        "MWCCPS2": str(toolchain / "compilers/mwcps2-3.0.3-020716/mwccps2.exe"),
        "MWCCPS2_30": str(toolchain / "compilers/mwcps2-3.0-011126/mwccps2.exe"),
        "PYTHON": str(ROOT / ".venv/bin/python"),
    }
    os.chmod(values["WIBO"], 0o755)
    with tempfile.TemporaryDirectory(prefix="mvc2-compiler-") as directory:
        source = Path(directory) / "smoke.c"
        source.write_text("int compiler_smoke(void) { return 42; }\n")
        for key in ("MWCCPS2", "MWCCPS2_30"):
            output = Path(directory) / (key + ".o")
            subprocess.run(
                [values["WIBO"], values[key], str(source), "-c", "-lang", "c", "-O3", "-o", str(output)],
                env={**os.environ, "MWCIncludes": str(Path(values[key]).parent)}, check=True,
            )
            if output.read_bytes()[:4] != b"\x7fELF":
                raise SystemExit(f"compiler smoke output is not ELF: {key}")
    environment = ROOT / "private/build.env"
    environment.write_text("".join(f"export {key}={shlex.quote(value)}\n" for key, value in values.items()))
    print("both Metrowerks compiler smoke tests passed")
    print("Run: . private/build.env")
    print("Then: make split hybrid test report PYTHON=\"$PYTHON\"")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--archive", type=Path, help="use a different local copy of the pinned bundle")
    args = parser.parse_args()
    if args.archive:
        install(args.archive.resolve())
    else:
        install(ROOT / "build-inputs" / INPUT_ASSET)
    configure()


if __name__ == "__main__":
    main()
