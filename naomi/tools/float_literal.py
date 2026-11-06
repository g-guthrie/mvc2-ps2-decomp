#!/usr/bin/env python3
"""Print a decimal spelling that SHC parses to exactly the given float bits.

    python3 tools/float_literal.py 0x41092492 0xbf2b6db6

SHC truncates a decimal float literal toward zero instead of rounding it to
nearest, so the shortest spelling of a value is usually one ulp low. The
spelling that lands is one nudged away from zero, still inside the same float.
This compiles a table of candidates and reports the first that the compiler
really turns into the requested bits.
"""
import math
import os
import re
import shutil
import struct
import subprocess
import sys

from core import ROOT, load, runner


def candidates(bits):
    """Spellings inside the float, ordered shortest first. Because SHC truncates
    toward zero, every nudge goes away from zero and stays under the next float."""
    value = struct.unpack('<f', struct.pack('<I', bits))[0]
    ulp = math.ulp(value)
    seen = []
    for digits in range(6, 17):
        for step in range(0, 8):
            text = format(value + math.copysign(step * ulp / 8, value or 1.0), f'.{digits}g')
            if not any(c in text for c in '.eE'):
                text += '.0'          # "1f" is not a C float literal; "1.0f" is
            if text not in seen and struct.unpack('<I', struct.pack('<f', float(text)))[0] in (bits, bits + 1):
                seen.append(text)
    return seen


def main():
    targets = [int(arg, 16) for arg in sys.argv[1:]]
    if not targets:
        sys.exit(__doc__)
    table = {bits: candidates(bits) for bits in dict.fromkeys(targets)}
    work = ROOT / 'build' / f'work-float-{os.getpid()}'
    shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work)
    try:
        # One array per target, so a target the compiler will not take whole
        # cannot hide the answer for the others.
        source = ''.join(f'const float t{i}[] = {{ {", ".join(t + "f" for t in texts)} }};\n'
                         for i, (bits, texts) in enumerate(table.items()) if texts)
        (work / 'f.c').write_text(source)
        flags = load(ROOT / 'config/compiler.json')['sets']['game']
        env = {**os.environ, 'SHC_LIB': '.', 'SHC_TMP': '.'}
        result = subprocess.run(runner() + [str(work / 'shc.exe'), 'f.c', *flags, '-code=asmcode', '-object=f.src'],
                                cwd=work, env=env, capture_output=True, timeout=300)
        if result.returncode:
            sys.exit(result.stdout.decode('utf-8', errors='replace'))
        assembly = (work / 'f.src').read_text(errors='replace')
    finally:
        shutil.rmtree(work, ignore_errors=True)
    emitted, current = {}, None
    for line in assembly.splitlines():
        label = re.match(r'^_t(\d+):', line)
        if label:
            current = int(label.group(1))
            emitted[current] = []
        elif current is not None and '.DATA.L' in line:
            emitted[current] += [int(h, 16) for h in re.findall(r"H'([0-9A-F]+)", line)]
        elif current is not None and line.strip() and not line.startswith(' '):
            current = None
    found = {}
    for i, (bits, texts) in enumerate(t for t in table.items() if t[1]):
        for text, got in zip(texts, emitted.get(i, [])):
            if got == bits:
                found[bits] = text
                break
    for bits in targets:
        print(f'0x{bits:08x} {found[bits] + "f" if bits in found else "no spelling found"}')


if __name__ == '__main__':
    main()
