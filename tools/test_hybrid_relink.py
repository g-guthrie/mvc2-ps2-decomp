import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from tools.generate_hybrid_relink import (
    MIPS_RELOCATION_NAMES,
    extract_compiled_functions,
    load_compiled_objects,
)
from tools.verify_hybrid_symbols import verify_placements


class FakeSymbol(dict):
    def __init__(self, name, **values):
        super().__init__(values)
        self.name = name


class FakeSymbolTable:
    def __init__(self, symbols):
        self.symbols = symbols

    def iter_symbols(self):
        return iter(self.symbols)

    def get_symbol(self, index):
        return self.symbols[index]


class FakeSection:
    def __init__(self, data=b"", **header):
        self._data = data
        self.header = SimpleNamespace(**header)

    def data(self):
        return self._data


class FakeRelocation(dict):
    def is_RELA(self):
        return False


class FakeRelocationSection(FakeSection):
    def __init__(self, relocations, section_index):
        super().__init__(sh_type="SHT_REL", sh_info=section_index)
        self.relocations = relocations

    def iter_relocations(self):
        return iter(self.relocations)


class FakeElf:
    def __init__(self, symbol_table, code_section, relocation_section):
        self.symbol_table = symbol_table
        self.code_section = code_section
        self.relocation_section = relocation_section

    def get_section_by_name(self, name):
        return self.symbol_table if name == ".symtab" else None

    def iter_sections(self):
        return iter([self.relocation_section])

    def get_section(self, index):
        if index != 5:
            raise AssertionError(index)
        return self.code_section


class HybridRelinkTest(unittest.TestCase):
    def test_common_ps2_relocation_types_are_named_for_externalization(self):
        expected = {
            1: "R_MIPS_16",
            2: "R_MIPS_32",
            3: "R_MIPS_REL32",
            4: "R_MIPS_26",
            5: "R_MIPS_HI16",
            6: "R_MIPS_LO16",
            7: "R_MIPS_GPREL16",
            10: "R_MIPS_PC16",
            12: "R_MIPS_GPREL32",
            18: "R_MIPS_64",
            28: "R_MIPS_HIGHER",
            29: "R_MIPS_HIGHEST",
        }
        self.assertEqual(
            {number: MIPS_RELOCATION_NAMES[number] for number in expected}, expected
        )

    def test_function_extraction_does_not_pull_internal_callee(self):
        symbols = [
            FakeSymbol("", st_shndx="SHN_UNDEF", st_value=0, st_size=0),
            FakeSymbol("func_a", st_shndx=5, st_value=0, st_size=8),
            FakeSymbol("func_b", st_shndx=5, st_value=8, st_size=8),
        ]
        relocation = FakeRelocation(r_offset=0, r_info_sym=2, r_info_type=4)
        elf = FakeElf(
            FakeSymbolTable(symbols),
            FakeSection(bytes.fromhex("0000000c000000000800e00300000000")),
            FakeRelocationSection([relocation], 5),
        )
        with tempfile.TemporaryDirectory() as directory:
            object_path = Path(directory) / "batch.o"
            object_path.touch()
            with patch("tools.generate_hybrid_relink.ELFFile", return_value=elf):
                functions, synthetic = extract_compiled_functions(
                    [("func_a", 0x00100000, 8, "src/batch.c")],
                    {"src/batch.c": object_path},
                    {"func_a": 0x00100000, "func_b": 0x00100008},
                )
        self.assertEqual(set(functions), {"func_a"})
        self.assertEqual(len(functions["func_a"].body), 8)
        self.assertEqual(functions["func_a"].relocations[0].type_name, "R_MIPS_26")
        self.assertEqual(functions["func_a"].relocations[0].symbol_name, "func_b")
        self.assertEqual(synthetic, {})

    def test_compiled_objects_are_discovered_from_sources(self):
        with tempfile.TemporaryDirectory() as directory:
            compiled_dir = Path(directory)
            expected = compiled_dir / "engine" / "batch.o"
            expected.parent.mkdir()
            expected.touch()
            result = load_compiled_objects(
                [],
                [("func_a", 0x00100000, 8, "src/engine/batch.c")],
                compiled_dir,
            )
        self.assertEqual(result, {"src/engine/batch.c": expected})

    def test_placement_validation_rejects_shifted_function(self):
        matches = [{"name": "func_a", "address": "0x00100000", "size": "0x8"}]
        symbols = {"func_a": {"st_value": 0x00100004, "st_size": 8}}
        with self.assertRaisesRegex(SystemExit, "placement mismatch"):
            verify_placements(matches, symbols)

    def test_placement_validation_accepts_exact_function(self):
        matches = [{"name": "func_a", "address": "0x00100000", "size": "0x8"}]
        symbols = {"func_a": {"st_value": 0x00100000, "st_size": 8}}
        self.assertEqual(len(verify_placements(matches, symbols)), 1)


if __name__ == "__main__":
    unittest.main()
