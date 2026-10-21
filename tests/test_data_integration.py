import csv
import tempfile
import unittest
from pathlib import Path

from tools.generate_data_symbol_addrs import extract_symbols
from tools.generate_hybrid_relink import DataUnit, check_non_overlapping_units, load_data_units
from tools.verify_data_object import Unit, load_unit
from tools.objdiff_report import DATA_SIZE, build_report, load_data_matches


ROOT = Path(__file__).resolve().parents[1]


class DataIntegrationTest(unittest.TestCase):
    def test_catalog_preserves_zero_units_and_dispatch(self):
        units = load_data_units(ROOT / "config/data_units.csv", 0x00100000, 0x3C2580)
        intervals = sorted((unit.address, unit.address + unit.size) for unit in units)
        with (ROOT / "config/zero_initialized_regions.csv").open() as stream:
            original_zeroes = list(csv.DictReader(stream))
        for row in original_zeroes:
            if row["compiler_placement"] == "assembly_byte_aligned":
                continue
            cursor = int(row["address"], 0)
            end = cursor + int(row["size"], 0)
            for start, stop in intervals:
                if stop <= cursor:
                    continue
                if start > cursor or cursor >= end:
                    break
                cursor = max(cursor, stop)
            self.assertGreaterEqual(cursor, end, row["name"])
        dispatch = [unit for unit in units if unit.name == "gMvc2Dispatch_00445A20"]
        self.assertEqual([(unit.address, unit.size, unit.section) for unit in dispatch], [(0x445A20, 0x400, ".rodata")])

    def test_catalog_does_not_include_assembly_only_zero_regions(self):
        with (ROOT / "config/zero_initialized_regions.csv").open() as stream:
            names = {
                row["name"]
                for row in csv.DictReader(stream)
                if row["compiler_placement"] == "assembly_byte_aligned"
            }
        with (ROOT / "config/data_units.csv").open() as stream:
            selected = {row["name"] for row in csv.DictReader(stream)}
        self.assertFalse(names & selected)

    def test_source_address_labels_become_symbolic_linker_entries(self):
        symbols = dict(extract_symbols(ROOT / "src/data/mvc2_dispatch_00445A20.c"))
        self.assertEqual(symbols["func_00163F90"], 0x00163F90)
        self.assertEqual(symbols["func_00168810"], 0x00168810)
        self.assertGreaterEqual(len(symbols), 112)
        jump_table_symbols = dict(extract_symbols(ROOT / "src/data/jtbl_004C2518.c"))
        self.assertEqual(jump_table_symbols["jtbl_004C2518"], 0x004C2518)
        global_symbols = dict(extract_symbols(ROOT / "src/data/data_ptr_004C250C.c"))
        self.assertEqual(global_symbols["gMvc2Scratchpad_70000000"], 0x70000000)

    def test_address_suffixed_global_data_label_becomes_linker_entry(self):
        symbols = dict(
            extract_symbols(ROOT / "src/data/gButtonConfigDebugLabel_004B8F38.c")
        )
        self.assertEqual(symbols["gButtonConfigDebugLabel_004B8F38"], 0x004B8F38)

    def test_replacements_reject_overlap(self):
        unit = DataUnit("data_a", 0x00100004, 8, ".data", "src/data_a.c")
        with self.assertRaisesRegex(SystemExit, "overlapping source replacements"):
            check_non_overlapping_units(
                [("func_a", 0x00100000, 8, "src/a.c")], [unit]
            )

    def test_unit_loader_returns_exact_catalog_metadata(self):
        units_path = ROOT / "config/data_units.csv"
        first_table_gap = load_unit(units_path, "data_raw_004A7940")
        second_table_candidate = load_unit(units_path, "data_raw_004A7F80")
        self.assertEqual(first_table_gap, Unit("data_raw_004A7940", 0x004A7940, 0x640, ".data"))
        self.assertEqual(second_table_candidate, Unit("data_raw_004A7F80", 0x004A7F80, 0x1000, ".data"))

    def test_report_counts_only_cataloged_complete_data(self):
        matches = load_data_matches(
            ROOT / "config/data_units.csv", ROOT / "config/data_matches.csv"
        )
        report = build_report([], {}, matches)
        # Compare the report against declarations, excluding linked raw placeholders.
        with (ROOT / "config/data_matches.csv").open() as stream:
            declarations = list(csv.DictReader(stream))
        reconstructed = [row for row in declarations if row["progress"] == "reconstructed"]
        expected_matched = sum(int(row["size"], 0) for row in reconstructed)
        expected_complete = sum(
            int(row["size"], 0) for row in reconstructed if row["status"] == "complete"
        )
        self.assertEqual(report["measures"]["matched_data"], str(expected_matched))
        self.assertEqual(report["measures"]["complete_data"], str(expected_complete))
        self.assertEqual(report["measures"]["total_data"], str(DATA_SIZE))
        self.assertGreater(sum(match["size"] for match in matches.values()), expected_matched)
        self.assertEqual(
            sum(int(unit["measures"].get("complete_data", 0)) for unit in report["units"]),
            expected_complete,
        )



if __name__ == "__main__":
    unittest.main()
