import tempfile
import unittest
from pathlib import Path

from tools.objdiff_report import TOTAL_CODE, report


class ProjectTest(unittest.TestCase):
    def test_report_is_objdiff_v2_and_conservative(self):
        result = report()
        self.assertEqual(result["version"], 2)
        self.assertEqual(result["measures"]["total_code"], str(TOTAL_CODE))
        self.assertEqual(result["measures"]["matched_code"], "0")
        self.assertEqual(result["units"][0]["metadata"]["progress_categories"], ["main"])


if __name__ == "__main__":
    unittest.main()

