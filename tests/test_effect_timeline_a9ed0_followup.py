import unittest

from tools.effect_timeline import parse_program, partition_program


class FinalEffectStreamBoundaryTests(unittest.TestCase):
    def test_zero_opcode_terminates_before_next_root_and_tail_stays_raw(self):
        # One record: count, base, preamble opcode 1 + five payload bytes,
        # active-body opcode 0, then 15 bytes before the next independent root.
        program_bytes = bytes([1, 0, 1, 0, 0, 0, 0, 0, 0])
        padding = bytes(15)
        next_root_offset = len(program_bytes) + len(padding)
        image = program_bytes + padding
        parsed = parse_program(image, 0, next_root_offset)
        runs = partition_program(image, parsed)
        self.assertEqual(parsed.count, 1)
        self.assertEqual(parsed.end, len(program_bytes))
        self.assertEqual(runs[-1].fields[-1].name, "body_008_terminator_opcode")
        self.assertEqual(next_root_offset - parsed.end, 15)
        self.assertEqual(sum(run.end - run.start for run in runs), len(program_bytes))


if __name__ == "__main__":
    unittest.main()
