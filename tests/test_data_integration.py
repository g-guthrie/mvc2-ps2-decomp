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
    def test_catalog_contains_only_the_eight_c_zero_units_and_dispatch(self):
        units = load_data_units(ROOT / "config/data_units.csv", 0x00100000, 0x3C2580)
        zeroes = [unit for unit in units if unit.name.startswith("data_zero_")]
        self.assertEqual(len(zeroes), 8)
        self.assertEqual(sum(unit.size for unit in zeroes), 0x15958)
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
        self.assertEqual(symbols["lbl_00163F90"], 0x00163F90)
        self.assertEqual(symbols["func_00168810"], 0x00168810)
        self.assertGreaterEqual(len(symbols), 112)

    def test_replacements_reject_overlap(self):
        unit = DataUnit("data_a", 0x00100004, 8, ".data", "src/data_a.c")
        with self.assertRaisesRegex(SystemExit, "overlapping source replacements"):
            check_non_overlapping_units(
                [("func_a", 0x00100000, 8, "src/a.c")], [unit]
            )

    def test_unit_loader_returns_exact_catalog_metadata(self):
        unit = load_unit(ROOT / "config/data_units.csv", "data_zero_004A7950")
        self.assertEqual(unit, Unit("data_zero_004A7950", 0x004A7950, 0x1630, ".data"))

    def test_report_counts_only_cataloged_complete_data(self):
        matches = load_data_matches(
            ROOT / "config/data_units.csv", ROOT / "config/data_matches.csv"
        )
        report = build_report([], {}, matches)
        self.assertEqual(report["measures"]["matched_data"], str(0x15D58))
        self.assertEqual(report["measures"]["complete_data"], str(0x15D58))
        self.assertEqual(
            report["units"][-1]["sections"][0]["fuzzy_match_percent"],
            0x15D58 * 100.0 / DATA_SIZE,
        )


if __name__ == "__main__":
    unittest.main()
