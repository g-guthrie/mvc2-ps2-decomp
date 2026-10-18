import struct
import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from tools import generate_hybrid_relink, verify_data_object


class FakeSymbol(dict):
    def __init__(self, name, *, section, value=0, size=0):
        super().__init__(st_shndx=section, st_value=value, st_size=size)
        self.name = name


class FakeSymbolTable:
    def __init__(self, symbols):
        self.symbols = symbols

    def iter_symbols(self):
        return iter(self.symbols)

    def get_symbol(self, index):
        return self.symbols[index]


class FakeSection:
    def __init__(self, name, data=b""):
        self.name = name
        self._data = data
        self.data_size = len(data)
        self.header = SimpleNamespace(sh_type="SHT_PROGBITS", sh_info=0)

    def data(self):
        return self._data


class FakeRelocation(dict):
    def is_RELA(self):
        return False


class FakeRelocationSection:
    def __init__(self, section_index, relocations):
        self.header = SimpleNamespace(sh_type="SHT_REL", sh_info=section_index)
        self.relocations = relocations

    def iter_relocations(self):
        return iter(self.relocations)


class FakeELF:
    def __init__(self, symbols, sections, relocation_sections):
        self.symbol_table = FakeSymbolTable(symbols)
        self.sections = sections
        self.relocation_sections = relocation_sections

    def get_section_by_name(self, name):
        return self.symbol_table if name == ".symtab" else None

    def get_section(self, index):
        return self.sections[index]

    def iter_sections(self):
        return iter([*self.sections.values(), *self.relocation_sections])


class CompiledSwitchDataTest(unittest.TestCase):
    function_a = "func_00278850"
    function_b = "func_0027B1A0"
    table_a = "jtbl_004B73E0"
    table_b = "jtbl_004B7440"
    function_a_address = 0x00278850
    function_b_address = 0x0027B1A0
    table_a_address = 0x004B73E0
    table_b_address = 0x004B7440

    relocation_types = {
        name: number
        for number, name in generate_hybrid_relink.MIPS_RELOCATION_NAMES.items()
    }

    @staticmethod
    def _table(addends):
        return struct.pack("<12I", *addends)

    @classmethod
    def _relocations(cls, symbol_index, relocation_type, addends):
        return [
            FakeRelocation(
                r_offset=index * 4,
                r_info_sym=symbol_index,
                r_info_type=relocation_type,
            )
            for index, _ in enumerate(addends)
        ]

    @classmethod
    def _object(cls, *, extra_bytes_b=0, symbol_value_b=0, type_b=None):
        addends_a = [0x40 + index * 4 for index in range(12)]
        addends_b = [0x80 + index * 4 for index in range(12)]
        bytes_a = cls._table(addends_a)
        bytes_b = cls._table(addends_b) + bytes(extra_bytes_b)

        symbols = [
            FakeSymbol("", section="SHN_UNDEF"),
            FakeSymbol(cls.function_a, section=1, value=0, size=0x1A0),
            FakeSymbol(cls.function_b, section=1, value=0x1A0, size=0x1A0),
            FakeSymbol(cls.table_a, section=2, size=48),
            FakeSymbol(cls.table_b, section=3, value=symbol_value_b, size=48),
        ]
        sections = {
            1: FakeSection(".text", bytes(0x340)),
            2: FakeSection(".rodata", bytes_a),
            3: FakeSection(".rodata", bytes_b),
        }
        relocation_sections = [
            FakeRelocationSection(
                2,
                cls._relocations(
                    1,
                    cls.relocation_types["R_MIPS_32"],
                    addends_a,
                ),
            ),
            FakeRelocationSection(
                3,
                cls._relocations(
                    2,
                    type_b if type_b is not None else cls.relocation_types["R_MIPS_32"],
                    addends_b,
                ),
            ),
        ]
        return FakeELF(symbols, sections, relocation_sections), addends_a, addends_b

    @staticmethod
    def _unit(name, address, *, size=48, section=".rodata"):
        return generate_hybrid_relink.DataUnit(
            name=name,
            address=address,
            size=size,
            section=section,
            source="src/synthetic_switch_tables.c",
        )

    def _extract(self, elf, unit, addresses):
        with tempfile.TemporaryDirectory() as directory:
            object_path = Path(directory) / "switch_tables.o"
            object_path.write_bytes(b"synthetic ELF payload")
            with (
                patch.object(
                    generate_hybrid_relink, "ELFFile", return_value=elf
                ) as generator_elf,
                patch.object(
                    verify_data_object, "ELFFile", return_value=elf
                ) as data_verifier_elf,
            ):
                result = generate_hybrid_relink.extract_compiled_data_unit(
                    unit, object_path, addresses
                )
            generator_elf.assert_called_once()
            data_verifier_elf.assert_called_once()
            return result

    def test_same_named_sections_are_selected_by_symbol_and_relocated(self):
        elf, addends_a, addends_b = self._object()
        addresses = {
            self.function_a: self.function_a_address,
            self.function_b: self.function_b_address,
        }
        self.assertEqual(elf.sections[2].name, elf.sections[3].name)
        self.assertIsNot(elf.sections[2], elf.sections[3])
        self.assertEqual(elf.symbol_table.get_symbol(3)["st_value"], 0)
        self.assertEqual(elf.symbol_table.get_symbol(3)["st_size"], 48)
        self.assertEqual(elf.symbol_table.get_symbol(4)["st_value"], 0)
        self.assertEqual(elf.symbol_table.get_symbol(4)["st_size"], 48)

        result_a = self._extract(
            elf, self._unit(self.table_a, self.table_a_address), addresses
        )
        result_b = self._extract(
            elf, self._unit(self.table_b, self.table_b_address), addresses
        )

        self.assertEqual(
            result_a,
            self._table([self.function_a_address + addend for addend in addends_a]),
        )
        self.assertEqual(
            result_b,
            self._table([self.function_b_address + addend for addend in addends_b]),
        )
        self.assertNotEqual(result_a, result_b)

    def test_rejects_symbol_size_mismatch(self):
        elf, _, _ = self._object()
        with self.assertRaisesRegex(SystemExit, "compiled data size mismatch"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address, size=52),
                {self.function_a: self.function_a_address,
                 self.function_b: self.function_b_address},
            )

    def test_rejects_section_name_mismatch(self):
        elf, _, _ = self._object()
        with self.assertRaisesRegex(SystemExit, "compiled data section mismatch"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address, section=".data"),
                {self.function_a: self.function_a_address,
                 self.function_b: self.function_b_address},
            )

    def test_rejects_nonzero_table_symbol_offset(self):
        elf, _, _ = self._object(symbol_value_b=4)
        with self.assertRaisesRegex(SystemExit, "compiled data size mismatch"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address),
                {self.function_a: self.function_a_address,
                 self.function_b: self.function_b_address},
            )

    def test_rejects_extra_bytes_in_symbol_section(self):
        elf, _, _ = self._object(extra_bytes_b=4)
        with self.assertRaisesRegex(SystemExit, "compiled data section has extra bytes"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address),
                {self.function_a: self.function_a_address,
                 self.function_b: self.function_b_address},
            )

    def test_rejects_unmapped_function_relocation(self):
        elf, _, _ = self._object()
        with self.assertRaisesRegex(SystemExit, "unmapped data relocation target"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address),
                {self.function_a: self.function_a_address},
            )

    def test_rejects_non_word_data_relocation(self):
        elf, _, _ = self._object(type_b=self.relocation_types["R_MIPS_HI16"])
        with self.assertRaisesRegex(SystemExit, "unsupported data relocation R_MIPS_HI16"):
            self._extract(
                elf,
                self._unit(self.table_b, self.table_b_address),
                {self.function_a: self.function_a_address,
                 self.function_b: self.function_b_address},
            )


class CompiledSwitchBuildTest(unittest.TestCase):
    def _run_build(self, registered):
        repository = Path(__file__).resolve().parents[1]
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "tools").symlink_to(repository / "tools", target_is_directory=True)
            (root / "config").mkdir()
            (root / "src/data").mkdir(parents=True)
            (root / "src/data/dummy.c").write_text("const int data_u32_00424200 = 0;\n")
            (root / "config/data_units.csv").write_text(
                "name,address,size,section,source,kind\n"
                "jtbl_004B73E0,0x004B73E0,0x30,.rodata,src/owner.c,compiler_switch_table\n"
            )
            (root / "config/matches.csv").write_text(
                "source,status\n" + ("src/owner.c,complete\n" if registered else "")
            )
            return subprocess.run(
                ["sh", str(repository / "tools/compile_matching_data.sh")],
                cwd=root,
                env={**os.environ, "PYTHON": sys.executable, "WIBO": "/missing/wibo",
                     "MWCCPS2": "/missing/mwcc", "BUILD": "build/matching"},
                text=True, capture_output=True,
            )

    def test_rejects_table_without_registered_code_owner(self):
        result = self._run_build(False)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("compiler switch table has no registered C owner: jtbl_004B73E0", result.stderr)

    def test_requires_compiled_code_owner(self):
        result = self._run_build(True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("compile code owner before its switch table: src/owner.c", result.stderr)


if __name__ == "__main__":
    unittest.main()
