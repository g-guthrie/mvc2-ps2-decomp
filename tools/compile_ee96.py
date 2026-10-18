#!/usr/bin/env python3
"""Compile preprocessed C with EE GCC 2.96 on Linux or the Mac probe VM."""
import argparse
import hashlib
import os
from pathlib import Path
import platform
import subprocess
import tempfile
import uuid


def compile_source(source, output, compiler, small_data_threshold=0, opt="O2"):
    flags = [f"-{opt}", f"-G{small_data_threshold}", "-ffunction-sections", "-quiet"]
    system = platform.system()
    if system == "Linux":
        with tempfile.TemporaryDirectory(prefix="mvc2-ee96-") as directory:
            assembly = Path(directory) / "unit.s"
            subprocess.run([str(compiler), str(source.resolve()), *flags, "-o", str(assembly)], check=True)
            body = assembly.read_bytes()
    elif system == "Darwin":
        binary = compiler.read_bytes()
        remote = "/tmp/mvc2-ee96-" + hashlib.sha256(binary).hexdigest()
        ssh = ["colima", "ssh", "--profile", "mvc2-probes", "--"]
        exists = subprocess.run([*ssh, "test", "-x", remote], capture_output=True)
        if exists.returncode:
            subprocess.run([*ssh, "sh", "-c", f"cat > {remote} && chmod 755 {remote}"], input=binary, check=True)
        job = "/tmp/mvc2-ee96-" + uuid.uuid4().hex
        source_remote, assembly_remote = job + ".i", job + ".s"
        try:
            subprocess.run([*ssh, "sh", "-c", f"cat > {source_remote}"], input=source.read_bytes(), check=True)
            subprocess.run([*ssh, remote, source_remote, *flags, "-o", assembly_remote], check=True)
            body = subprocess.run([*ssh, "cat", assembly_remote], stdout=subprocess.PIPE, check=True).stdout
        finally:
            subprocess.run([*ssh, "rm", "-f", "--", source_remote, assembly_remote], check=True)
    else:
        raise SystemExit(f"unsupported EE compiler host: {system}")
    if b"gcc2_compiled" not in body:
        raise SystemExit("EE compiler did not produce assembly")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(body)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--small-data-threshold", type=int, choices=(0, 8), default=0)
    parser.add_argument("--opt", choices=("O0", "O1", "O2", "O3"), default="O2")
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    compiler = Path(os.environ["EE96CC1"]).resolve()
    compile_source(args.source, args.output, compiler, args.small_data_threshold, args.opt)


if __name__ == "__main__":
    main()
