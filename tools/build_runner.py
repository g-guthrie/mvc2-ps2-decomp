"""Shared machinery for the parallel matching build.

Three things make the serial build slow, and this module addresses each:

* Every verify ran in a fresh interpreter that re-read the 4 MB retail image,
  the whole symbol map and the whole match table. `install_verifier_memo`
  memoizes those loaders inside a worker process, keyed by each file's
  path, size and mtime, so a long-lived worker sees edits but reads an
  unchanged file once. The verifiers' own checks are untouched.
* Independent units ran one at a time. Callers fan work out over a process
  pool; `worker_count` picks the width.
* Unchanged units were recompiled. `CompileCache` stores a command's outputs
  under a digest of everything it reads: its command text, the values of
  the environment variables it names, and the content of every repository
  file it names together with the headers those files include, recursively.
  Only compiles are cached. Verification always reruns on the restored
  object, so a stale cache entry can only cost a mismatch, never hide one.
"""

from __future__ import annotations

import csv
import hashlib
import os
import re
import shutil
import sys
import tempfile
from pathlib import Path

CACHE_VERSION = "1"
INCLUDE_RE = re.compile(
    rb'^[ \t]*(?:#[ \t]*include[ \t]*[<"]([^>"\n]+)[>"]|\.include[ \t]+"([^"\n]+)")', re.M
)
DEFAULT_INCLUDE_DIRS = (Path("src"), Path("src/data"), Path("include"))


def worker_count() -> int:
    value = os.environ.get("MATCH_JOBS") or os.environ.get("DATA_JOBS")
    if value and value != "auto":
        jobs = int(value)
        if jobs < 1:
            raise SystemExit(f"MATCH_JOBS must be a positive integer, got {value!r}")
        return jobs
    return os.cpu_count() or 1


def _stat_key(path) -> tuple[str, int, int]:
    stat = os.stat(path)
    return (os.fspath(path), stat.st_mtime_ns, stat.st_size)


_file_info: dict[tuple, tuple[bytes, tuple[str, ...]]] = {}


def file_digest(path: Path, include_dirs=()) -> bytes:
    """Digest a file together with every header it includes, recursively."""
    dirs = tuple(include_dirs) + DEFAULT_INCLUDE_DIRS
    return _digest(path, dirs, ())


def _info(path: Path) -> tuple[bytes, tuple[str, ...]]:
    # Memoized per file by its own stat; the include tree is re-walked on
    # every call, so editing a header is seen even when the includer is not.
    key = _stat_key(path)
    info = _file_info.get(key)
    if info is None:
        data = path.read_bytes()
        names = tuple(
            (match.group(1) or match.group(2)).decode("utf-8", "replace")
            for match in INCLUDE_RE.finditer(data)
        )
        info = (hashlib.sha256(data).digest(), names)
        _file_info[key] = info
    return info


def _digest(path: Path, dirs: tuple, stack: tuple) -> bytes:
    content, names = _info(path)
    digest = hashlib.sha256(content)
    for name in names:
        candidates = [path.parent / name, *(d / name for d in dirs)]
        found = next((c for c in candidates if c.is_file()), None)
        digest.update(b"\0include\0" + name.encode())
        if found is not None and found.resolve() not in stack:
            digest.update(_digest(found, dirs, stack + (path.resolve(),)))
    return digest.digest()


class CompileCache:
    """Content-addressed store of a command's output files."""

    def __init__(self, root: Path, enabled: bool = True):
        self.root = root
        self.enabled = enabled

    def restore(self, key: str, outputs: list[Path]) -> str | None:
        if not self.enabled:
            return None
        entry = self.root / key[:2] / key
        if not (entry / "log").is_file():
            return None
        for output in outputs:
            stored = entry / "files" / output.name
            if stored.is_file():
                output.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(stored, output)
            elif output.exists():
                output.unlink()
        return (entry / "log").read_text(encoding="utf-8", errors="replace")

    def store(self, key: str, outputs: list[Path], log: str) -> None:
        if not self.enabled:
            return
        if len({output.name for output in outputs}) != len(outputs):
            return  # same basename twice; not worth a nested layout
        entry = self.root / key[:2] / key
        if entry.exists():
            return
        entry.parent.mkdir(parents=True, exist_ok=True)
        staging = Path(tempfile.mkdtemp(prefix=".stage-", dir=entry.parent))
        (staging / "files").mkdir()
        for output in outputs:
            if output.is_file():
                shutil.copyfile(output, staging / "files" / output.name)
        (staging / "log").write_text(log, encoding="utf-8")
        try:
            os.rename(staging, entry)
        except OSError:
            shutil.rmtree(staging, ignore_errors=True)  # another worker won


def install_verifier_memo() -> None:
    """Memoize the verifiers' file loaders for this process."""
    tools = str(Path(__file__).resolve().parent)
    if tools not in sys.path:
        sys.path.insert(0, tools)
    import verify_data_object
    import verify_object

    def by_stat(function):
        cache = {}

        def wrapper(path=None, *args):
            if path is None:
                return function()
            key = (_stat_key(path), args)
            if key not in cache:
                cache[key] = function(path, *args)
            return cache[key]

        return wrapper

    verify_object.load_addresses = by_stat(verify_object.load_addresses)
    verify_object.load_readonly_sections = by_stat(verify_object.load_readonly_sections)
    verify_data_object.load_symbols = by_stat(verify_data_object.load_symbols)

    original_load_matches = verify_object.load_matches
    # Load every valid row once, then select by source: the same rows the
    # original returns for a given source, without rereading the table.
    all_matches = by_stat(lambda path: _group_by_source(original_load_matches(path, None)))

    def load_matches(path, source=None):
        rows, by_source = all_matches(path)
        return list(rows if source is None else by_source.get(source, ()))

    verify_object.load_matches = load_matches

    def index_units(path):
        # Same fields and first-row-wins lookup as verify_data_object.load_unit.
        units = {}
        with Path(path).open(newline="", encoding="utf-8") as stream:
            for row in csv.DictReader(stream):
                units.setdefault(row["name"], verify_data_object.Unit(
                    row["name"],
                    int(row["address"], 0),
                    int(row["size"], 0),
                    row["section"],
                    row.get("source", ""),
                    row.get("kind", ""),
                ))
        return units

    units = by_stat(index_units)

    def load_unit(path, name):
        unit = units(path).get(name)
        if unit is None:
            raise SystemExit(f"unknown data unit: {name}")
        return unit

    verify_data_object.load_unit = load_unit

    original_read_bytes = Path.read_bytes
    images = {}

    def read_bytes(self):
        if self.suffix != ".rom":
            return original_read_bytes(self)
        key = _stat_key(self)
        if key not in images:
            images[key] = original_read_bytes(self)
        return images[key]

    Path.read_bytes = read_bytes


def _group_by_source(rows):
    by_source: dict[str, list] = {}
    for row in rows:
        by_source.setdefault(row["source"], []).append(row)
    return rows, by_source


def run_tool_main(module_name: str, argv: list[str]) -> tuple[bool, str]:
    """Run a verifier's main() in this process; return (ok, output)."""
    import contextlib
    import importlib
    import io

    module = importlib.import_module(module_name)
    output = io.StringIO()
    saved = sys.argv
    sys.argv = [module_name, *argv]
    try:
        with contextlib.redirect_stdout(output), contextlib.redirect_stderr(output):
            module.main()
        return True, output.getvalue()
    except SystemExit as error:
        if error.code in (None, 0):
            return True, output.getvalue()
        message = error.code if isinstance(error.code, str) else f"exit {error.code}"
        return False, output.getvalue() + f"{message}\n"
    except Exception as error:  # a verifier bug must fail the unit, not the pool
        return False, output.getvalue() + f"{type(error).__name__}: {error}\n"
    finally:
        sys.argv = saved
