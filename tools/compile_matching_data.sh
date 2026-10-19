#!/bin/sh
# Compile and private-verify each source-owned initialized-data unit.
# DATA_JOBS defaults to four workers; set it to 1 for serial operation.
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"

PYTHON=${PYTHON:-python3}
BUILD=${BUILD:-build/matching}
TARGET=${TARGET:-private/SLUS_204.86.rom}
DATA_JOBS=${DATA_JOBS:-4}
mkdir -p "$BUILD/data"

# Every compiled data unit must contribute its symbols, or relocation targets
# in units added later resolve to nothing and verification aborts.
"$PYTHON" -c "
from pathlib import Path
import subprocess, sys
sources = sorted(str(path) for path in Path('src/data').glob('*.c'))
subprocess.check_call(
    [sys.executable, 'tools/generate_data_symbol_addrs.py', *sources, 'config/data_symbol_addrs.txt']
)
"

"$PYTHON" - "$BUILD" "$TARGET" "$WIBO" "$MWCCPS2" "$PYTHON" "$DATA_JOBS" <<'PY'
from concurrent.futures import ThreadPoolExecutor, as_completed
import csv
import os
import subprocess
import sys
from pathlib import Path

build, target, wibo, mwcc, python, jobs_arg = sys.argv[1:]
try:
    jobs = int(jobs_arg)
except ValueError:
    raise SystemExit(f"DATA_JOBS must be a positive integer, got {jobs_arg!r}")
if jobs < 1:
    raise SystemExit(f"DATA_JOBS must be a positive integer, got {jobs_arg!r}")
includes = str(Path(mwcc).parent)
env = os.environ.copy()
env["MWCIncludes"] = includes
data_build = Path(build, "data")
data_build.mkdir(parents=True, exist_ok=True)

with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
    units = list(csv.DictReader(stream))

with Path("config/matches.csv").open(newline="", encoding="utf-8") as stream:
    code_sources = {
        row["source"] for row in csv.DictReader(stream)
        if row["status"] in {"matching", "complete"}
    }

def verify_switch_table(unit):
    source = Path(unit["source"])
    name = unit["name"]
    if unit["source"] not in code_sources:
        raise SystemExit(f"compiler switch table has no registered C owner: {name}")
    object_path = Path(build) / source.relative_to("src").with_suffix(".o")
    if not object_path.is_file():
        raise SystemExit(f"compile code owner before its switch table: {source}")
    subprocess.check_call([
        python, "tools/verify_data_object.py", str(object_path), target,
        "--name", name, "--symbols", "config/symbol_addrs.txt",
    ])


def compile_and_verify(unit):
    source = Path(unit["source"])
    name = unit["name"]
    # Use the data-unit name so each unit owns a unique object path even when
    # multiple units are declared in the same source file.
    object_path = data_build / (name + ".o")
    compile_result = subprocess.run(
        [
            wibo,
            mwcc,
            str(source),
            "-c",
            "-lang",
            "c",
            "-O3",
            "-sdatathreshold",
            "0",
            "-i",
            "src/data",
            "-o",
            str(object_path),
        ],
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    if compile_result.returncode:
        raise RuntimeError(
            f"compile failed for {name} from {source} "
            f"(exit {compile_result.returncode})\n{compile_result.stdout}"
        )
    verify_result = subprocess.run(
        [python, "tools/verify_data_object.py", str(object_path), target, "--name", name],
        env=env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    if verify_result.returncode:
        raise RuntimeError(
            f"verification failed for {name} from {source} "
            f"(exit {verify_result.returncode})\n{verify_result.stdout}"
        )
    return compile_result.stdout + verify_result.stdout


standalone_units = [unit for unit in units if unit["kind"] != "compiler_switch_table"]
switch_tables = [unit for unit in units if unit["kind"] == "compiler_switch_table"]
if jobs == 1:
    for unit in standalone_units:
        try:
            sys.stdout.write(compile_and_verify(unit))
        except Exception as error:
            print(error, file=sys.stderr)
            raise SystemExit(1)
else:
    executor = ThreadPoolExecutor(max_workers=jobs)
    futures = {executor.submit(compile_and_verify, unit): unit for unit in standalone_units}
    try:
        for future in as_completed(futures):
            unit = futures[future]
            try:
                sys.stdout.write(future.result())
            except Exception as error:
                cancelled = sum(
                    pending.cancel()
                    for pending in futures
                    if pending is not future and not pending.done()
                )
                print(
                    f"data-unit worker failed for {unit['name']}; "
                    f"cancelled {cancelled} not-yet-started jobs and waiting for active jobs:\n{error}",
                    file=sys.stderr,
                )
                executor.shutdown(wait=True, cancel_futures=True)
                for other, other_unit in futures.items():
                    if other is future or other.cancelled() or not other.done():
                        continue
                    other_error = other.exception()
                    if other_error is not None:
                        print(
                            f"additional worker failure for {other_unit['name']}: {other_error}",
                            file=sys.stderr,
                        )
                raise SystemExit(1)
    finally:
        executor.shutdown(wait=True, cancel_futures=True)

for unit in switch_tables:
    verify_switch_table(unit)
PY
