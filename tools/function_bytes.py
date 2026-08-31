#!/usr/bin/env python3
"""Print each function's raw .text bytes from a MWCCPS2 relocatable ELF."""
import sys
from elftools.elf.elffile import ELFFile

for filename in sys.argv[1:]:
    with open(filename, "rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        print(filename)
        for symbol in symbols.iter_symbols():
            if symbol["st_info"]["type"] != "STT_FUNC" or not symbol.name:
                continue
            section = elf.get_section(symbol["st_shndx"])
            start = symbol["st_value"]
            size = symbol["st_size"] or section.data_size
            print(f"{symbol.name}\t{section.data()[start:start + size].hex()}")
