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
    def test_repository_registry_and_callback_entries_are_current(self):
        root = MODULE.parents[1]
        functions = VERIFY.load_functions(root / "config/functions.csv")
        labels = VERIFY.load_labels(root / "config/data_labels.csv")
        VERIFY.validate_registry(functions, labels)
        with (root / "config/data_units.csv").open() as stream:
            sources = {row["name"]: root / row["source"] for row in csv.DictReader(stream)}
        consumers = {row["consumer"] for row in labels.values()} | {"gMvc2Dispatch_00445A20"}
        for consumer in sorted(consumers):
            with self.subTest(consumer=consumer):
                VERIFY.validate_table_source(
                    sources[consumer], functions,
                    {name: row for name, row in labels.items() if row["consumer"] == consumer},
                )

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

    def test_table_element_cast_is_accepted(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "")
            source.write_text("typedef void (*Target)(void);\nconst Target table[] = { (Target)lbl_00163F90, (Target)func_00163F40 };\n")
            VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))

    def test_table_element_cast_does_not_hide_data_pointer(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "")
            source.write_text("typedef void (*Target)(void);\nconst Target table[] = { (Target)D_00445A20 };\n")
            with self.assertRaisesRegex(ValueError, "data or unknown pointer"):
                VERIFY.validate_table_source(source, VERIFY.load_functions(functions), VERIFY.load_labels(labels))

    def test_raw_address_is_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            functions, labels, source = self.write_fixture(Path(temp), "0x00163F90")
            with self.assertRaisesRegex(ValueError, "unsupported table entry"):
                VERIFY.validate_table_source(source, VERIFY.load_functions(functions), {})

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
