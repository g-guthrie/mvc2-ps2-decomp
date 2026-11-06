"""Small, dependency-free checks for the reference ROM and Hitachi output."""

import hashlib
import json
from pathlib import Path
import platform
import re
import struct
import subprocess
import sys
import zipfile
import zlib

ROOT = Path(__file__).resolve().parents[1]


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def load(path):
    return json.loads(Path(path).read_text())


def sha(data):
    return hashlib.sha256(data).hexdigest()


def verify_tools(root=ROOT):
    manifest = load(root / "toolchain/hitachi-shc-5.1r08.json")
    folder = root / "toolchain/hitachi-shc-5.1r08"
    expected = {item["name"] for item in manifest["files"]}
    if len(expected) != len(manifest["files"]) or expected != {p.name for p in folder.iterdir() if p.is_file()}:
        raise ValueError("Hitachi package is incomplete or contains unexpected files")
    for item in manifest["files"]:
        blob = (folder / item["name"]).read_bytes()
        if len(blob) != item["size"] or sha(blob) != item["sha256"]:
            raise ValueError("Hitachi checksum mismatch: " + item["name"])
    wibo = load(root / "toolchain/wibo.json")
    for item in wibo["assets"].values():
        if sha((root / item["path"]).read_bytes()) != item["sha256"]:
            raise ValueError("wibo checksum mismatch: " + item["path"])
    sdk = load(root / "toolchain/naomi-sdk.json")
    folder = root / "toolchain/naomi-sdk/lib"
    if {item["name"] for item in sdk["files"]} != {p.name for p in folder.iterdir() if p.is_file()}:
        raise ValueError("NAOMI SDK library folder is incomplete or contains unexpected files")
    for item in sdk["files"]:
        blob = (folder / item["name"]).read_bytes()
        if len(blob) != item["size"] or sha(blob) != item["sha256"]:
            raise ValueError("NAOMI SDK library checksum mismatch: " + item["name"])
    return {"compiler": manifest["version"], "compiler_files": len(expected), "wibo": wibo["version"],
            "sdk_libraries": len(sdk["files"])}


def runner(root=ROOT):
    system, machine = platform.system(), platform.machine().lower()
    key = "Darwin" if system == "Darwin" else "Linux-x86_64" if system == "Linux" and machine in {"x86_64", "amd64"} else None
    if key is None:
        raise ValueError("Use macOS with Intel-app support, or native Linux x86_64. "
                         "For this host, open GitHub > Actions > Hitachi build > Run workflow on your branch.")
    return [str(root / load(root / "toolchain/wibo.json")["assets"][key]["path"])]



def preflight():
    if sys.version_info < (3, 10):
        raise ValueError("Python 3.10+ is required. Run with a newer python3 interpreter.")
    runtime = runner()[0]
    if not Path(runtime).is_file():
        raise ValueError("Bundled wibo is missing. Use a complete git clone of this repository.")
    if platform.system() == "Darwin":
        try:
            result = subprocess.run(["/usr/bin/arch", "-x86_64", "/usr/bin/true"],
                                    capture_output=True, timeout=15)
        except (OSError, subprocess.SubprocessError) as error:
            raise ValueError("Cannot run Intel Mac tools. Use the GitHub Actions build for your branch.") from error
        if result.returncode:
            raise ValueError("This Mac cannot run Intel tools. On Apple Silicon, enable Rosetta/Intel-app support "
                             "using Apple's instructions: https://support.apple.com/102527 . "
                             "Then rerun the same command. Otherwise use GitHub > Actions > Hitachi build > Run workflow.")
    print(f"HOST {platform.system()} {platform.machine()} — bundled {Path(runtime).name}", flush=True)


def verify_rom(target, root=ROOT):
    expected = {item["name"]: item for item in target["roms"]}
    program = None
    with zipfile.ZipFile(root / target["archive"]) as archive:
        names = [item.filename for item in archive.infolist() if not item.is_dir()]
        if len(names) != len(set(names)) or set(names) != set(expected):
            raise ValueError("ROM archive has missing, duplicate, or unexpected members")
        for name, item in expected.items():
            blob = archive.read(name)
            if (len(blob), f"{zlib.crc32(blob):08x}", hashlib.sha1(blob).hexdigest()) != (
                    item["size"], item["crc32"], item["sha1"]):
                raise ValueError("Reference ROM mismatch: " + name)
            if name == target["program_rom"]:
                program = blob
    if program is None:
        raise ValueError("Program ROM is missing")
    for key in ("main", "test"):
        part = target[key]
        offset, address, size = (number(part[k]) for k in ("rom_offset", "address", "size"))
        if struct.unpack_from("<III", program, number(part["header_offset"])) != (offset, address, size):
            raise ValueError("Wrong boot descriptor: " + key)
        if sha(program[offset:offset + size]) != part["sha256"]:
            raise ValueError("Wrong executable hash: " + key)
    return program


def validate_units(units, target):
    names, intervals = set(), []
    base = number(target["main"]["address"])
    end = base + number(target["main"]["size"])
    for unit in units:
        if not re.fullmatch(r"[a-zA-Z_][a-zA-Z0-9_]*", unit["id"]) or unit["id"] in names:
            raise ValueError("Invalid or duplicate unit id")
        names.add(unit["id"])
        if unit["mode"] not in {"verified", "candidate"}:
            raise ValueError("Unknown unit mode")
        if "flags" in unit:
            raise ValueError("Units take their compiler options from config/compiler.json only: " + unit["id"])
        if unit.get("options", "game") not in load(ROOT / "config/compiler.json")["sets"]:
            raise ValueError("Unknown option set for unit " + unit["id"])
        if "library" in unit or "module" in unit:
            if "source" in unit or "options" in unit or not unit.get("module") or not unit.get("exports"):
                raise ValueError("A library unit names a library, a module and its exports, and nothing to compile: " + unit["id"])
            library = Path(unit["library"])
            if library.is_absolute() or ".." in library.parts or library.parts[:2] != ("toolchain", "naomi-sdk") or library.suffix != ".lib":
                raise ValueError("Unit library must be a .lib file below toolchain/naomi-sdk/")
            if not re.fullmatch(r"[A-Za-z_$][A-Za-z0-9_$]*", unit["module"]):
                raise ValueError("Invalid library module name: " + unit["id"])
        else:
            source = Path(unit["source"])
            if source.is_absolute() or ".." in source.parts or source.parts[0] != "src" or source.suffix != ".c":
                raise ValueError("Unit source must be a C file below src/")
        sections = set()
        for part in unit["sections"]:
            name = part["section"]
            if not re.fullmatch(r"[a-zA-Z_][a-zA-Z0-9_]*", name) or name in sections:
                raise ValueError("Invalid or duplicate section name")
            sections.add(name)
            address, size = number(part["address"]), number(part["size"])
            if size <= 0 or part["kind"] not in {"code", "data", "bss"}:
                raise ValueError("Invalid section size/kind")
            if part["kind"] != "bss":
                if address < base or address + size > end:
                    raise ValueError("Reference section outside the main image")
                intervals.append((address, address + size, unit["id"]))
        for symbol, value in {**unit.get("imports", {}), **unit.get("exports", {})}.items():
            if not re.fullmatch(r"[a-zA-Z_][a-zA-Z0-9_]*", symbol) or not 0 <= number(value) <= 0xFFFFFFFF:
                raise ValueError("Invalid symbol definition")
    intervals.sort()
    for left, right in zip(intervals, intervals[1:]):
        if left[1] > right[0]:
            raise ValueError(f"Overlapping reference ranges: {left[2]} and {right[2]}")


def elf_segments(blob):
    if len(blob) < 52 or blob[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("Expected little-endian ELF32")
    header = struct.unpack_from("<16sHHIIIIIHHHHHH", blob)
    if header[1:3] != (2, 42):
        raise ValueError("Expected a linked Hitachi SH executable, not a relocatable object")
    offset, stride, count = header[5], header[9], header[10]
    if stride != 32 or not count or offset + stride * count > len(blob):
        raise ValueError("Invalid ELF load table")
    segments = []
    for i in range(count):
        kind, file_offset, address, _, size, memory_size, flags, alignment = struct.unpack_from("<8I", blob, offset + i * stride)
        if kind != 1:
            continue
        if size > memory_size or file_offset + size > len(blob) or address + memory_size > 0x100000000:
            raise ValueError("Invalid ELF load segment")
        segments.append({"address": address, "size": size, "memory_size": memory_size,
                         "data": blob[file_offset:file_offset + size]})
    segments.sort(key=lambda part: part["address"])
    for a, b in zip(segments, segments[1:]):
        if a["address"] + a["memory_size"] > b["address"]:
            raise ValueError("Overlapping ELF load segments")
    return segments


def memory_bytes(segments, address, size):
    result = bytearray()
    cursor = address
    for part in segments:
        lo, hi = part["address"], part["address"] + part["size"]
        if lo <= cursor < hi:
            take = min(size - len(result), hi - cursor)
            result.extend(part["data"][cursor - lo:cursor - lo + take])
            cursor += take
            if len(result) == size:
                return bytes(result)
    raise ValueError(f"Linked ELF does not provide {size} bytes at 0x{address:08x}")


def link_map(text):
    sections, symbols, attribute = {}, {}, None
    for line in text.splitlines():
        match = re.search(r"ATTRIBUTE\s*:\s*(CODE|DATA|STACK|COMMON|DUMMY)", line)
        if match:
            attribute = match[1]
        match = re.fullmatch(r"\s*(\w+)\s+H'([0-9A-Fa-f]+)\s*-\s*H'([0-9A-Fa-f]+)\s+H'([0-9A-Fa-f]+)\s*", line)
        if match:
            start, end, size = (int(match[i], 16) for i in (2, 3, 4))
            if end - start + 1 != size or match[1] in sections:
                raise ValueError("Invalid or duplicate section in Hitachi link map")
            sections[match[1]] = {"address": start, "size": size, "attribute": attribute}
        match = re.fullmatch(r"\s*(\w+)\s+H'([0-9A-Fa-f]+)\s+(ENT|DAT)\s*", line)
        if match:
            symbols[match[1]] = int(match[2], 16)
    return sections, symbols


def compare(unit, elf, map_text, main, base):
    segments = elf_segments(elf)
    sections, symbols = link_map(map_text)
    checks, problems = [], []
    expected_names = {part["section"] for part in unit["sections"]}
    if set(sections) != expected_names:
        problems.append("Unexpected or missing linker sections")
    for symbol, address in unit.get("exports", {}).items():
        if symbols.get(symbol) != number(address):
            problems.append("Wrong exported symbol address: " + symbol)
    for part in unit["sections"]:
        address, size = number(part["address"]), number(part["size"])
        mapped = sections.get(part["section"], {})
        shape = mapped.get("address") == address and mapped.get("size") == size
        attribute = "CODE" if part["kind"] == "code" else "DATA"
        shape = shape and mapped.get("attribute") == attribute
        row = {**part, "address": address, "size": size, "linked_size": mapped.get("size"),
               "linked_address": mapped.get("address"), "equal_bytes": 0, "exact": False}
        if part["kind"] == "bss":
            row["exact"] = shape and any(p["address"] == address and p["size"] == 0 and p["memory_size"] == size for p in segments)
        else:
            reference = main[address - base:address - base + size]
            try:
                actual = memory_bytes(segments, address, size)
            except ValueError:
                actual = b""
            row["equal_bytes"] = sum(a == b for a, b in zip(actual, reference))
            row["exact"] = shape and len(reference) == size and actual == reference
        if not row["exact"]:
            problems.append("Not an exact section match: " + part["section"])
        checks.append(row)
    functions = function_rows(unit, sections, symbols, segments, main, base)
    pools = pool_rows(unit, sections, segments, main, base)
    expected_bytes = sum(number(p["size"]) for p in unit["sections"] if p["kind"] != "bss")
    if sum(p["size"] for p in segments) != expected_bytes:
        problems.append("Linked image contains extra or missing initialized bytes")
    if sum(p["memory_size"] for p in segments) != sum(number(p["size"]) for p in unit["sections"]):
        problems.append("Linked image contains extra or missing memory bytes")
    return {"exact": not problems, "sections": checks, "functions": functions, "pools": pools,
            "function_bytes": sum(f["size"] for f in functions if f["exact"]),
            "pool_bytes": sum(f["size"] for f in pools if f["exact"]), "problems": problems}, segments


def pool_rows(unit, sections, segments, main, base):
    """One row per declared interior data range, judged like a function: a
    candidate unit is credited for the pools that match once the section links."""
    rows = []
    for part in unit["sections"]:
        mapped = sections.get(part["section"], {})
        placed = mapped.get("address") == number(part["address"]) and mapped.get("size") == number(part["size"])
        for spare in part.get("interior", ()):
            address, size = number(spare["address"]), number(spare["size"])
            reference = main[address - base:address - base + size]
            try:
                actual = memory_bytes(segments, address, size)
            except ValueError:
                actual = b""
            rows.append({"address": address, "size": size, "kind": spare["kind"],
                         "equal_bytes": sum(a == b for a, b in zip(actual, reference)),
                         "exact": placed and actual == reference})
    return rows


def function_literals_match(address, code, part, segments, main, base):
    """PC-relative operands must resolve to retail data, not just identical loads."""
    for offset in range(0, len(code) - 1, 2):
        word = struct.unpack_from('<H', code, offset)[0]
        pc = address + offset
        if word >> 12 == 9:
            target, size = pc + 4 + (word & 255) * 2, 2
        elif word >> 12 == 13 or word >> 8 == 0xc7:
            target, size = ((pc + 4) & ~3) + (word & 255) * 4, 4
            if word >> 8 == 0xc7:
                # MOVA also addresses switch tables and other compound data.
                # Require the declared data region rather than assuming one word.
                for interior in part.get('interior', ()):
                    start, count = number(interior['address']), number(interior['size'])
                    if start <= target < start + count:
                        target, size = start, count
                        break
        else:
            continue
        if target < base or target + size > base + len(main):
            return False
        try:
            actual = memory_bytes(segments, target, size)
        except ValueError:
            return False
        if actual != main[target - base:target - base + size]:
            return False
    return True


def function_rows(unit, sections, symbols, segments, main, base):
    """One row per exported function: its retail bytes from the export address to
    the next export or section end, excluding declared interior data. A candidate unit is
    credited for exactly the functions whose rows match, once the section links
    at the declared address and size."""
    rows = []
    for part in unit["sections"]:
        if part["kind"] != "code":
            continue
        start, end = number(part["address"]), number(part["address"]) + number(part["size"])
        mapped = sections.get(part["section"], {})
        placed = mapped.get("address") == start and mapped.get("size") == end - start
        pools = sorted((number(spare["address"]), number(spare["address"]) + number(spare["size"]))
                       for spare in part.get("interior", ()))
        entries = sorted((number(address), symbol) for symbol, address in unit.get("exports", {}).items()
                         if start <= number(address) < end)
        for i, (address, symbol) in enumerate(entries):
            limit = entries[i + 1][0] if i + 1 < len(entries) else end
            fragments, cursor = [], address
            for lo, hi in pools:
                if hi <= cursor or lo >= limit:
                    continue
                if cursor < lo:
                    fragments.append((cursor, min(lo, limit)))
                cursor = max(cursor, min(hi, limit))
            if cursor < limit:
                fragments.append((cursor, limit))
            size, equal = 0, 0
            exact = placed and symbols.get(symbol) == address
            for lo, hi in fragments:
                reference = main[lo - base:hi - base]
                try:
                    actual = memory_bytes(segments, lo, hi - lo)
                except ValueError:
                    actual = b""
                size += hi - lo
                equal += sum(a == b for a, b in zip(actual, reference))
                exact = exact and actual == reference and function_literals_match(lo, actual, part, segments, main, base)
            rows.append({"symbol": symbol, "address": address, "size": size, "equal_bytes": equal,
                         "exact": bool(size) and exact})
    return rows


def input_fingerprint(root=ROOT):
    files = []
    for folder in ("src", "config", "tools", "tests", "toolchain"):
        files.extend(p for p in (root / folder).rglob("*") if p.is_file() and "__pycache__" not in p.parts and p.suffix != ".pyc")
    digest = hashlib.sha256()
    for path in sorted(files):
        digest.update(path.relative_to(root).as_posix().encode() + b"\0")
        digest.update(path.read_bytes())
    return digest.hexdigest()
