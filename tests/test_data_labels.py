import csv
import importlib.util
import tempfile
import unittest
from pathlib import Path

MODULE = Path(__file__).parents[1] / "tools" / "verify_data_labels.py"
SPEC = importlib.util.spec_from_file_location("verify_data_labels", MODULE)
VERIFY = importlib.util.module_from_spec(SPEC)
assert SPEC.loader is not None
SPEC.loader.exec_module(VERIFY)


class DataLabelTest(unittest.TestCase):
    def write_fixture(self, root: Path, table: str) -> tuple[Path, Path, Path]:
        functions = root / "functions.csv"
        labels = root / "data_labels.csv"
        source = root / "table.c"
        functions.write_text(
            "name,address,size,end,classification,source\n"
            "func_00163F40,0x00163F40,0x70,0x00163FB0,code,test\n"
            "D_00445A20,0x00445A20,0x400,0x00445E20,data,test\n",
            encoding="utf-8",
        )
        labels.write_text(
            "name,address,kind,containing_function,containing_start,containing_end,offset,consumer,occurrences,provenance\n"
            "lbl_00163F90,0x00163F90,code_interior,func_00163F40,0x00163F40,0x00163FB0,0x50,test,1,test\n",
            encoding="utf-8",
        )
        source.write_text("const void *table[] = { " + table + " };\n", encoding="utf-8")
        return functions, labels, source

    def test_registered_interior_label_is_accepted(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "lbl_00163F90, func_00163F40")
            VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))

    def test_unknown_interior_label_is_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "lbl_00163F94")
            with self.assertRaisesRegex(ValueError, "unknown interior pointer"):
                VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))

    def test_data_pointer_is_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "D_00445A20")
            with self.assertRaisesRegex(ValueError, "data or unknown pointer"):
                VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))

    def test_function_interior_masquerading_as_start_is_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "func_00163F90")
            with self.assertRaisesRegex(ValueError, "unknown/non-start function pointer"):
                VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))


if __name__ == "__main__":
    unittest.main()
