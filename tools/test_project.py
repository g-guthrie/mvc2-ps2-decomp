import unittest

from tools.objdiff_report import DATA_SIZE, TEXT_SIZE, build_report


class ProjectTest(unittest.TestCase):
    def test_report_is_objdiff_v2_and_conservative(self):
        result = build_report([
            {"name": "func_00100008", "address": 0x00100008, "size": 8},
        ])
        self.assertEqual(result["version"], 2)
        self.assertEqual(result["measures"]["total_code"], str(TEXT_SIZE))
        self.assertEqual(result["measures"]["total_data"], str(DATA_SIZE))
        self.assertEqual(result["measures"]["matched_code"], "0")
        self.assertEqual(result["units"][0]["metadata"]["progress_categories"], ["main"])


if __name__ == "__main__":
    unittest.main()
