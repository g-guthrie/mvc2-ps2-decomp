import csv
import subprocess
import sys
import struct
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from tools import generate_hybrid_relink, verify_data_object, verify_object


class FakeSymbol(dict):
    def __init__(self, name, *, section, value=0, size=0, symbol_type="STT_NOTYPE"):
        super().__init__(
            st_shndx=section,
            st_value=value,
            st_size=size,
            st_info={"type": symbol_type},
        )
        self.name = name


class FakeSymbolTable:
    def __init__(self, symbols):
        self.symbols = symbols

    def iter_symbols(self):
        return iter(self.symbols)

    def get_symbol(self, index):
        return self.symbols[index]


class FakeSection(dict):
    def __init__(self, name, data=b"", *, flags=0, sh_type="SHT_PROGBITS", sh_info=0):
        super().__init__(sh_flags=flags, sh_type=sh_type)
        self.name = name
        self._data = data
        self.data_size = len(data)
        self.header = SimpleNamespace(sh_type=sh_type, sh_info=sh_info)

    def data(self):
        return self._data


class FakeRelocation(dict):
    def __init__(self, offset, symbol_index, kind=verify_object.R_MIPS_32):
        super().__init__(r_offset=offset, r_info_sym=symbol_index, r_info_type=kind)

    def is_RELA(self):
        return False


class FakeRelocationSection(dict):
    def __init__(self, name, section_index, relocations):
        super().__init__(sh_type="SHT_REL", sh_info=section_index)
        self.name = name
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
        return iter([*self.sections, *self.relocation_sections])


class EmbeddedCompilerSwitchTest(unittest.TestCase):
    base = verify_object.BASE_ADDRESS
    function_address = base + 0x20
    readonly_address = base + 0x40
    function_size = 0x20
    readonly_size = 0x10
    source = "src/owner.c"
    table = "jtbl_00400044"

    def _fake_elf(self, *, table_addends=(4, 8), prefix=b"PRE!", include_function=True,
                  function_bytes=None,
                  table_relocations=True,
                  table_symbol=None, table_symbol_value=0, table_section_size=None):
        text_body = function_bytes if function_bytes is not None else bytes(self.function_size)
        if include_function:
            symbols = [
                FakeSymbol("", section="SHN_UNDEF"),
                FakeSymbol("func_owner", section=1, size=self.function_size,
                           symbol_type="STT_FUNC"),
            ]
            text = FakeSection(".text.func_owner", text_body, flags=4)
        else:
            symbols = [FakeSymbol("", section="SHN_UNDEF")]
            text = FakeSection(".text.other", text_body, flags=4)

        rodata = bytearray(prefix + struct.pack("<II", *table_addends) + b"TAIL")
        if len(rodata) != self.readonly_size:
            raise AssertionError("bad synthetic readonly extent")
        sections = [FakeSection("", b""), text, FakeSection(".rodata", bytes(rodata), flags=2)]
        relocs = [FakeRelocationSection(
            ".rel.rodata", 2,
            [FakeRelocation(4, 1), FakeRelocation(8, 1)],
        )] if include_function and table_relocations else []
        if table_symbol:
            symbols.append(FakeSymbol(table_symbol, section=2, value=table_symbol_value,
                                      size=8))
            if table_section_size is not None and table_section_size != len(rodata):
                sections[2] = FakeSection(".rodata", bytes(rodata[:table_section_size]), flags=2)
        return FakeELF(symbols, sections, relocs)

    def _write_inputs(self, root, *, unit_address=None, unit_size=8, source=None,
                      section=".rodata", kind="compiler_switch_table", owner_status="complete",
                      include_anchor=True):
        root.mkdir(parents=True, exist_ok=True)
        source = source or self.source
        owner_address = self.readonly_address
        units = root / "data_units.csv"
        with units.open("w", newline="") as stream:
            writer = csv.writer(stream)
            writer.writerow(["name", "address", "size", "section", "source", "kind"])
            writer.writerow([self.table, hex(unit_address if unit_address is not None else owner_address + 4),
                             hex(unit_size), section, source, kind])
        matches = root / "matches.csv"
        with matches.open("w", newline="") as stream:
            writer = csv.writer(stream)
            writer.writerow(["name", "address", "size", "source", "status"])
            if owner_status:
                writer.writerow(["func_owner", hex(self.function_address), hex(self.function_size),
                                 self.source, owner_status])
        code_symbols = root / "symbol_addrs.txt"
        code_symbols.write_text(
            f"_gp = {hex(self.base + 0x1000)};\nfunc_owner = {hex(self.function_address)};\n"
        )
        data_symbols = root / "data_symbol_addrs.txt"
        data_symbols.write_text("")
        readonly = root / "readonly_sections.csv"
        with readonly.open("w", newline="") as stream:
            writer = csv.writer(stream)
            writer.writerow(["source", "section", "address", "size"])
            if include_anchor:
                writer.writerow([self.source, ".rodata", hex(owner_address), hex(self.readonly_size)])
        target = root / "retail.rom"
        image = bytearray(0x80)
        function_offset = self.function_address - self.base
        image[function_offset:function_offset + self.function_size] = bytes(self.function_size)
        rodata_offset = owner_address - self.base
        resolved_rodata = bytearray(b"PRE!" + struct.pack(
            "<II", self.function_address + 4, self.function_address + 8
        ) + b"TAIL")
        image[rodata_offset:rodata_offset + self.readonly_size] = resolved_rodata
        target.write_bytes(image)
        object_path = root / "owner.o"
        object_path.write_bytes(b"fake ELF")
        return units, matches, code_symbols, data_symbols, readonly, target, object_path

    def _verify(self, *, addends=(4, 8), prefix=b"PRE!", include_function=True,
                function_bytes=None,
                source=None, section=".rodata", kind="compiler_switch_table",
                unit_address=None, unit_size=8, owner_status="complete", include_anchor=True):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(
                Path(directory), unit_address=unit_address, unit_size=unit_size,
                source=source, section=section, kind=kind, owner_status=owner_status,
                include_anchor=include_anchor,
            )
            units, matches, code_symbols, data_symbols, readonly, target, object_path = paths
            fake_elf = self._fake_elf(
                table_addends=addends, prefix=prefix, include_function=include_function,
                function_bytes=function_bytes,
            )
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                unit = verify_data_object.load_unit(units, self.table)
                return verify_data_object.embedded_switch_table_data(
                    unit, object_path, target, matches_path=matches,
                    code_symbols_path=code_symbols, readonly_sections_path=readonly,
                )

    def test_extracts_only_declared_embedded_slice_after_full_owner_verification(self):
        body = self._verify()
        self.assertEqual(body, struct.pack("<II", self.function_address + 4,
                                          self.function_address + 8))

    def test_hybrid_relink_extracts_embedded_switch_table_slice(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(Path(directory))
            units, matches, code_symbols, _, readonly, target, object_path = paths
            fake_elf = self._fake_elf()
            unit = generate_hybrid_relink.DataUnit(
                self.table, self.readonly_address + 4, 8, ".rodata", self.source,
                "compiler_switch_table",
            )
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                result = generate_hybrid_relink.extract_compiled_data_unit(
                    unit,
                    object_path,
                    verify_object.load_addresses(code_symbols),
                    target_path=target,
                    matches_path=matches,
                    code_symbols_path=code_symbols,
                    readonly_sections_path=readonly,
                )
            self.assertEqual(
                result,
                struct.pack("<II", self.function_address + 4, self.function_address + 8),
            )


    def test_hybrid_relink_rejects_embedded_table_outside_owner(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(Path(directory))
            _, matches, code_symbols, _, readonly, target, object_path = paths
            fake_elf = self._fake_elf()
            unit = generate_hybrid_relink.DataUnit(
                self.table, self.readonly_address + 0xC, 8, ".rodata", self.source,
                "compiler_switch_table",
            )
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                with self.assertRaisesRegex(SystemExit, "outside readonly owner"):
                    generate_hybrid_relink.extract_compiled_data_unit(
                        unit,
                        object_path,
                        verify_object.load_addresses(code_symbols),
                        target_path=target,
                        matches_path=matches,
                        code_symbols_path=code_symbols,
                        readonly_sections_path=readonly,
                    )


    def test_hybrid_relink_direct_cli_imports_new_data_helper(self):
        script = Path(generate_hybrid_relink.__file__).resolve()
        result = subprocess.run(
            [sys.executable, str(script), "--help"],
            cwd=script.parents[1],
            text=True,
            capture_output=True,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("--readonly-sections", result.stdout)


    def test_rejects_table_slice_corruption(self):
        with self.assertRaisesRegex(SystemExit, "readonly section differs from retail"):
            self._verify(addends=(8, 8))

    def test_rejects_neighbor_corruption_even_when_table_is_unchanged(self):
        with self.assertRaisesRegex(SystemExit, "readonly section differs from retail"):
            self._verify(prefix=b"BAD!")

    def test_rejects_wrong_owner_source(self):
        with self.assertRaisesRegex(SystemExit, "owner is not registered"):
            self._verify(source="src/not_owner.c")

    def test_rejects_wrong_section(self):
        with self.assertRaisesRegex(SystemExit, "owner section mismatch"):
            self._verify(section=".data")

    def test_rejects_embedded_table_outside_owner(self):
        with self.assertRaisesRegex(SystemExit, "outside readonly owner"):
            self._verify(unit_address=self.readonly_address + 0xC, unit_size=8)
        with self.assertRaisesRegex(SystemExit, "outside readonly owner"):
            self._verify(unit_address=self.readonly_address - 4, unit_size=8)

    def test_rejects_unregistered_or_uncredited_owner(self):
        with self.assertRaisesRegex(SystemExit, "owner is not registered"):
            self._verify(owner_status=None)
        with self.assertRaisesRegex(SystemExit, "owner is not fully credited"):
            self._verify(owner_status="placeholder")

    def test_rejects_wrong_object_without_complete_owner_function(self):
        with self.assertRaisesRegex(SystemExit, "compiled function missing"):
            self._verify(include_function=False)

    def test_rejects_corrupt_owner_function(self):
        with self.assertRaisesRegex(SystemExit, "func_owner mismatch"):
            self._verify(function_bytes=b"X" * self.function_size)

    def test_does_not_treat_arbitrary_raw_subrange_as_embedded_table(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(Path(directory), kind="initialized_byte_array")
            units, matches, code_symbols, data_symbols, readonly, target, object_path = paths
            fake_elf = self._fake_elf()
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                unit = verify_data_object.load_unit(units, self.table)
                self.assertIsNone(verify_data_object.embedded_switch_table_data(
                    unit, object_path, target, matches_path=matches,
                    code_symbols_path=code_symbols, readonly_sections_path=readonly,
                ))
            with patch.object(verify_data_object, "ELFFile", return_value=fake_elf):
                with self.assertRaisesRegex(SystemExit, "missing data symbol"):
                    verify_data_object.resolved_data(unit, object_path,
                                                     verify_data_object.load_symbols(data_symbols))

    def test_rejects_declared_switch_subrange_without_pointer_relocations(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(Path(directory))
            units, matches, code_symbols, data_symbols, readonly, target, object_path = paths
            image = bytearray(target.read_bytes())
            raw_table = struct.pack("<II", 4, 8)
            start = self.readonly_address - self.base + 4
            image[start:start + 8] = raw_table
            target.write_bytes(image)
            fake_elf = self._fake_elf(table_relocations=False)
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                unit = verify_data_object.load_unit(units, self.table)
                with self.assertRaisesRegex(SystemExit, "lacks complete word relocations"):
                    verify_data_object.embedded_switch_table_data(
                        unit, object_path, target, matches_path=matches,
                        code_symbols_path=code_symbols, readonly_sections_path=readonly,
                    )

    def test_standalone_switch_helper_keeps_zero_offset_whole_section_rule(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            units, matches, code_symbols, data_symbols, readonly, target, object_path = self._write_inputs(
                root, include_anchor=False,
            )
            unit = verify_data_object.load_unit(units, self.table)
            fake_elf = self._fake_elf(table_symbol=self.table, table_symbol_value=4,
                                      table_section_size=12)
            with patch.object(verify_object, "ELFFile", return_value=fake_elf):
                self.assertIsNone(verify_data_object.embedded_switch_table_data(
                    unit, object_path, target, matches_path=matches,
                    code_symbols_path=code_symbols, readonly_sections_path=readonly,
                ))
            with patch.object(verify_data_object, "ELFFile", return_value=fake_elf):
                with self.assertRaisesRegex(SystemExit, "unexpected data placement"):
                    verify_data_object.resolved_data(unit, object_path,
                                                     verify_data_object.load_symbols(data_symbols))


    def test_named_standalone_table_works_without_a_readonly_map(self):
        with tempfile.TemporaryDirectory() as directory:
            paths = self._write_inputs(Path(directory), include_anchor=False)
            units, matches, code_symbols, data_symbols, readonly, target, object_path = paths
            readonly.unlink()
            unit = verify_data_object.load_unit(units, self.table)
            self.assertIsNone(verify_data_object.embedded_switch_table_data(
                unit, object_path, target, matches_path=matches,
                code_symbols_path=code_symbols, readonly_sections_path=readonly,
            ))
            fake_elf = self._fake_elf(table_symbol=self.table)
            fake_elf.sections[2] = FakeSection(
                ".rodata", struct.pack("<II", 4, 8), flags=2,
            )
            fake_elf.relocation_sections[0].relocations = [
                FakeRelocation(0, 1), FakeRelocation(4, 1),
            ]
            with patch.object(verify_data_object, "ELFFile", return_value=fake_elf):
                body = verify_data_object.resolved_data(
                    unit, object_path, verify_data_object.load_symbols(code_symbols),
                )
            start = unit.address - self.base
            self.assertEqual(body, target.read_bytes()[start:start + unit.size])


if __name__ == "__main__":
    unittest.main()
