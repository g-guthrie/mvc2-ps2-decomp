import unittest

from tools.progress_catalog import (
    DATA_BEGIN,
    DATA_SIZE,
    TEXT_SIZE,
    code_progress,
    data_progress,
    first_overlap,
    unique_covered_bytes,
    validate_code_catalog,
    validate_data_catalog,
)


class ProgressCatalogTest(unittest.TestCase):
    def test_unique_coverage_dedups_overlap(self):
        lo = DATA_BEGIN
        covered = unique_covered_bytes(
            [(lo, 32), (lo + 16, 32)],
            lo,
            lo + DATA_SIZE,
        )
        self.assertEqual(covered, 48)

    def test_first_overlap_names(self):
        self.assertEqual(
            first_overlap([(0, 16, "a"), (8, 16, "b")]),
            ("a", "b"),
        )
        self.assertIsNone(first_overlap([(0, 16, "a"), (16, 16, "b")]))

    def test_code_overlap_is_rejected(self):
        functions = [
            {"name": "a", "address": 0x00100000, "size": 16},
            {"name": "b", "address": 0x00100008, "size": 16},
        ]
        matches = {
            "a": {"address": 0x00100000, "size": 16, "complete": True},
            "b": {"address": 0x00100008, "size": 16, "complete": True},
        }
        with self.assertRaises(SystemExit):
            validate_code_catalog(functions, matches)

    def test_data_overlap_is_rejected(self):
        units = {"a": (DATA_BEGIN, 32), "b": (DATA_BEGIN + 16, 32)}
        matches = {
            "a": {"address": DATA_BEGIN, "size": 32, "complete": True},
            "b": {"address": DATA_BEGIN + 16, "size": 32, "complete": True},
        }
        with self.assertRaises(SystemExit):
            validate_data_catalog(units, matches)

    def test_complete_cannot_exceed_matched(self):
        matches = {
            "a": {"address": DATA_BEGIN, "size": 16, "complete": True},
        }
        matched, complete = data_progress(matches)
        self.assertEqual(matched, complete)
        with self.assertRaises(SystemExit):
            data_progress(
                {"a": {"address": DATA_BEGIN, "size": DATA_SIZE + 4, "complete": True}}
            )

    def test_linked_code_is_at_most_text_span(self):
        matches = {
            "a": {"address": 0x00100000, "size": 8, "complete": True},
        }
        matched, complete = code_progress(matches)
        self.assertEqual(matched, 8)
        self.assertEqual(complete, 8)
        self.assertLessEqual(complete, TEXT_SIZE)


if __name__ == "__main__":
    unittest.main()
