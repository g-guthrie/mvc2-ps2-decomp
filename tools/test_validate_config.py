import tempfile
import unittest
from pathlib import Path

from tools.validate_config import DATA_START, TEXT_END, TEXT_START, validate

FUNCTION_FIELDS = "name,address,size,end,classification,confidence"
GAP_FIELDS = "start,end,size"
MATCH_FIELDS = "name,address,size,source,status"
UNIT_FIELDS = "name,address,size,section,source,kind"
LABEL_FIELDS = (
    "name,address,kind,containing_function,containing_start,containing_end,"
    "offset,consumer,occurrences,provenance"
)
REGION_FIELDS = "name,address,size,kind,compiler_placement,confidence"


def csv_text(header: str, rows: list[str]) -> str:
    return "\n".join([header, *rows]) + "\n"


class ValidateConfigTest(unittest.TestCase):
    def setUp(self):
        self._temp = tempfile.TemporaryDirectory()
        self.root = Path(self._temp.name)
        self.config = self.root / "config"
        self.config.mkdir()
        (self.root / "src").mkdir()
        (self.root / "src" / "main.c").write_text("void f(void) {}\n", encoding="utf-8")
        (self.root / "src" / "data.c").write_text("int g;\n", encoding="utf-8")
        self.files = {
            "functions.csv": (FUNCTION_FIELDS, [
                f"func_a,{TEXT_START:#010x},0x10,{TEXT_START + 0x10:#010x},code,baseline",
                f"func_b,{TEXT_START + 0x20:#010x},0x10,{TEXT_START + 0x30:#010x},code,baseline",
            ]),
            "gaps.csv": (GAP_FIELDS, [
                f"{TEXT_START + 0x10:#010x},{TEXT_START + 0x20:#010x},0x10",
                f"{TEXT_START + 0x30:#010x},{TEXT_END:#010x},{TEXT_END - TEXT_START - 0x30:#x}",
            ]),
            "matches.csv": (MATCH_FIELDS, [
                f"func_a,{TEXT_START:#010x},0x10,src/main.c,complete",
            ]),
            "data_units.csv": (UNIT_FIELDS, [
                f"gTable,{DATA_START:#010x},0x40,.rodata,src/data.c,dispatch_table",
            ]),
            "data_matches.csv": (MATCH_FIELDS, [
                f"gTable,{DATA_START:#010x},0x40,src/data.c,complete",
            ]),
            "data_labels.csv": (LABEL_FIELDS, [
                f"lbl_x,{TEXT_START + 0x4:#010x},code_interior,func_a,{TEXT_START:#010x},"
                f"{TEXT_START + 0x10:#010x},0x4,gTable,1,test",
            ]),
            "zero_initialized_regions.csv": (REGION_FIELDS, []),
        }

    def tearDown(self):
        self._temp.cleanup()

    def write(self, **overrides):
        for name, (header, rows) in self.files.items():
            rows = overrides.get(name.removesuffix(".csv"), rows)
            (self.config / name).write_text(csv_text(header, rows), encoding="utf-8")
        return validate(self.config, self.root)

    def assertProblem(self, report, fragment):
        self.assertFalse(report.ok)
        self.assertTrue(
            any(fragment in problem for problem in report.problems),
            f"{fragment!r} not in {report.problems}",
        )

    def test_clean_inventory_passes(self):
        report = self.write()
        self.assertTrue(report.ok, report.problems)
        self.assertTrue(report.notes)

    def test_end_must_equal_address_plus_size(self):
        report = self.write(functions=[
            f"func_a,{TEXT_START:#010x},0x10,{TEXT_START + 0x14:#010x},code,baseline",
            f"func_b,{TEXT_START + 0x20:#010x},0x10,{TEXT_START + 0x30:#010x},code,baseline",
        ])
        self.assertProblem(report, "address+size != end")

    def test_zero_size_row_is_reported(self):
        report = self.write(functions=[
            f"func_a,{TEXT_START:#010x},0x0,{TEXT_START:#010x},code,baseline",
            f"func_b,{TEXT_START + 0x20:#010x},0x10,{TEXT_START + 0x30:#010x},code,baseline",
        ])
        self.assertProblem(report, "non-positive size")

    def test_overlapping_functions_are_reported(self):
        report = self.write(
            functions=[
                f"func_a,{TEXT_START:#010x},0x30,{TEXT_START + 0x30:#010x},code,baseline",
                f"func_b,{TEXT_START + 0x20:#010x},0x10,{TEXT_START + 0x30:#010x},code,baseline",
            ],
            matches=[],
            data_labels=[],
        )
        self.assertProblem(report, "overlaps")

    def test_unsorted_functions_are_reported(self):
        report = self.write(
            functions=[
                f"func_b,{TEXT_START + 0x20:#010x},0x10,{TEXT_START + 0x30:#010x},code,baseline",
                f"func_a,{TEXT_START:#010x},0x10,{TEXT_START + 0x10:#010x},code,baseline",
            ],
            matches=[],
            data_labels=[],
        )
        self.assertProblem(report, "not strictly after")

    def test_misaligned_function_is_reported(self):
        report = self.write(
            functions=[
                f"func_a,{TEXT_START + 0x2:#010x},0x10,{TEXT_START + 0x12:#010x},code,baseline",
            ],
            matches=[],
            data_labels=[],
            gaps=[],
        )
        self.assertProblem(report, "not 4-byte aligned")

    def test_gap_overlapping_a_function_is_double_coverage(self):
        report = self.write(gaps=[
            f"{TEXT_START + 0x8:#010x},{TEXT_START + 0x20:#010x},0x18",
            f"{TEXT_START + 0x30:#010x},{TEXT_END:#010x},{TEXT_END - TEXT_START - 0x30:#x}",
        ])
        self.assertProblem(report, "double coverage")

    def test_uncovered_hole_is_reported(self):
        report = self.write(gaps=[
            f"{TEXT_START + 0x30:#010x},{TEXT_END:#010x},{TEXT_END - TEXT_START - 0x30:#x}",
        ])
        self.assertProblem(report, "unexplained hole")

    def test_incomplete_tiling_is_reported(self):
        report = self.write(gaps=[
            f"{TEXT_START + 0x10:#010x},{TEXT_START + 0x20:#010x},0x10",
        ])
        self.assertProblem(report, "text span not fully tiled")

    def test_match_size_mismatch_is_reported(self):
        report = self.write(matches=[
            f"func_a,{TEXT_START:#010x},0x8,src/main.c,complete",
        ])
        self.assertProblem(report, "!= inventory")

    def test_match_without_inventory_entry_is_reported(self):
        report = self.write(matches=[
            f"func_zz,{TEXT_START:#010x},0x10,src/main.c,complete",
        ])
        self.assertProblem(report, "no inventory entry")

    def test_missing_source_file_is_reported(self):
        report = self.write(matches=[
            f"func_a,{TEXT_START:#010x},0x10,src/absent.c,complete",
        ])
        self.assertProblem(report, "missing source file")

    def test_data_unit_outside_data_span_is_reported(self):
        report = self.write(
            data_units=[f"gTable,{TEXT_START:#010x},0x40,.rodata,src/data.c,dispatch_table"],
            data_matches=[],
        )
        self.assertProblem(report, "outside the initialized-data span")

    def test_data_match_size_mismatch_is_reported(self):
        report = self.write(data_matches=[
            f"gTable,{DATA_START:#010x},0x80,src/data.c,complete",
        ])
        self.assertProblem(report, "!= inventory")

    def test_label_offset_mismatch_is_reported(self):
        report = self.write(data_labels=[
            f"lbl_x,{TEXT_START + 0x4:#010x},code_interior,func_a,{TEXT_START:#010x},"
            f"{TEXT_START + 0x10:#010x},0x8,gTable,1,test",
        ])
        self.assertProblem(report, "offset")

    def test_label_outside_container_is_reported(self):
        report = self.write(data_labels=[
            f"lbl_x,{TEXT_START + 0x40:#010x},code_interior,func_a,{TEXT_START:#010x},"
            f"{TEXT_START + 0x10:#010x},0x40,gTable,1,test",
        ])
        self.assertProblem(report, "is not inside")

    def test_label_container_must_match_functions_csv(self):
        report = self.write(data_labels=[
            f"lbl_x,{TEXT_START + 0x4:#010x},code_interior,func_other,{TEXT_START:#010x},"
            f"{TEXT_START + 0x10:#010x},0x4,gTable,1,test",
        ])
        self.assertProblem(report, "containing_function")


if __name__ == "__main__":
    unittest.main()
