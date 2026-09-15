import unittest

from tools.objdiff_report import DATA_SIZE, TEXT_SIZE, build_report


class ProjectTest(unittest.TestCase):
    def test_source_tiles_preserve_totals_across_chunk_boundary(self):
        result = build_report(
            [{"name": "crossing", "address": 0x10FFFC, "size": 8}],
            {"crossing": {"address": 0x10FFFC, "size": 8,
                          "source": "src/crossing.c", "complete": True}},
        )
        units = result["units"]
        self.assertEqual(sum(int(u["measures"].get("total_code", 0)) for u in units), TEXT_SIZE)
        self.assertEqual(sum(u["measures"].get("total_functions", 0) for u in units), 1)
        tile = next(u for u in units if u["name"] == "src/crossing.c")
        self.assertEqual(tile["measures"]["fuzzy_match_percent"], 100)
        self.assertTrue(tile["metadata"]["complete"])
        self.assertNotIn("data_matches", units[-1]["metadata"])

    def test_report_is_objdiff_v2_and_conservative(self):
        result = build_report(
            [{"name": "func_00100008", "address": 0x00100008, "size": 8}],
            {"func_00100008": {
                "address": 0x00100008,
                "size": 8,
                "source": "src/main.c",
                "complete": True,
            }},
        )
        self.assertEqual(result["version"], 2)
        self.assertEqual(result["measures"]["total_code"], str(TEXT_SIZE))
        self.assertEqual(result["measures"]["total_data"], str(DATA_SIZE))
        self.assertEqual(result["measures"]["matched_code"], "8")
        self.assertEqual(result["measures"]["matched_functions"], 1)
        self.assertEqual(result["measures"]["complete_code"], "8")
        self.assertEqual(result["units"][0]["metadata"]["progress_categories"], ["main"])

    def test_overlapping_data_units_are_rejected(self):
        from pathlib import Path
        import tempfile
        from tools.objdiff_report import load_data_matches

        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "units.csv").write_text(
                "name,address,size\n"
                "a,0x00424200,0x20\n"
                "b,0x00424210,0x20\n",
                encoding="utf-8",
            )
            (root / "matches.csv").write_text(
                "name,address,size,source,status\n"
                "a,0x00424200,0x20,src/a.c,complete\n"
                "b,0x00424210,0x20,src/b.c,complete\n",
                encoding="utf-8",
            )
            with self.assertRaises(SystemExit):
                load_data_matches(root / "units.csv", root / "matches.csv")

    def test_linked_data_percent_never_exceeds_span(self):
        from tools.objdiff_report import unique_covered_bytes, DATA_SIZE, BASE_ADDRESS, TEXT_SIZE

        data_lo = BASE_ADDRESS + TEXT_SIZE
        covered = unique_covered_bytes(
            [(data_lo, DATA_SIZE), (data_lo + 16, 32)],
            data_lo,
            data_lo + DATA_SIZE,
        )
        self.assertEqual(covered, DATA_SIZE)
        result = build_report([], {}, {
            "a": {"address": data_lo, "size": DATA_SIZE, "source": "src/a.c", "complete": True},
        })
        self.assertLessEqual(float(result["measures"]["complete_data_percent"]), 100.0)
        self.assertEqual(result["measures"]["complete_data"], str(DATA_SIZE))


if __name__ == "__main__":
    unittest.main()
