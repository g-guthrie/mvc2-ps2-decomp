import unittest

from tools.effect_timeline import TimelineParseError, parse_program, partition_program


def sample_program():
    # count=1, base=0x22; preamble metadata; begin opcode 1 with five
    # byte fields; then a five-byte payload, byte operand, lookup, cursor adjustments,
    # an ordinary opcode, and a terminator.
    return bytes(
        [
            1, 0x22,
            11, 0xA1, 12, 0xB2, 0xC3, 0,
            5, 8, 6, 1, 7, 2, 8, 3, 9, 4,
            1, 0x12, 0x34, 0x56, 0x78, 0x9A,
            1, 0x01, 0x02, 0x03, 0x04, 0x05,
            4, 0x44,
            10, 0x0C,
            5, 13, 0xFF,
            0,
        ]
    )


class EffectTimelineParserTests(unittest.TestCase):
    def test_native_cursor_grammar_and_pointer_adjustments(self):
        data = sample_program()
        program = parse_program(data, 0, len(data))
        self.assertEqual(program.count, 1)
        self.assertEqual(program.end, len(data))
        record = program.records[0]
        self.assertEqual(record.base, 0x22)
        self.assertEqual(record.preamble[-1].operand, bytes([0x12, 0x34, 0x56, 0x78, 0x9A]))
        self.assertEqual([command.opcode for command in record.commands], [1, 4, 10, 5, 13, 0xFF, 0])
        self.assertEqual(record.commands[0].operand, bytes([1, 2, 3, 4, 5]))
        self.assertEqual(record.commands[1].operand, b"\x44")
        self.assertEqual(record.commands[2].operand, b"\x0c")
        # 5 and 13 have no cursor operands; the terminator remains in range.
        self.assertEqual(record.commands[3].operand, b"")
        self.assertEqual(record.commands[4].operand, b"")

    def test_partition_excludes_unread_payload_bytes_from_credit(self):
        data = sample_program()
        program = parse_program(data, 0, len(data))
        runs = partition_program(data, program)
        typed = [run for run in runs if run.kind == "native_read"]
        opaque = [run for run in runs if run.kind == "opaque"]
        self.assertEqual(sum(run.end - run.start for run in typed), len(data) - 5)
        self.assertEqual(sum(run.end - run.start for run in opaque), 5)
        self.assertEqual(opaque[0].start, 5)  # opcode 12 has two unread bytes
        body_opcode1 = next(command for command in program.records[0].commands if command.opcode == 1)
        self.assertEqual(opaque[1].start, body_opcode1.offset + 3)
        self.assertEqual(opaque[1].end, body_opcode1.offset + 6)
        self.assertFalse(any("signed" in field.name or "keyframe" in field.name for run in typed for field in run.fields))

    def test_rejects_truncated_preamble_payload(self):
        data = bytes([1, 0, 1, 1, 2, 3])
        with self.assertRaisesRegex(TimelineParseError, "preamble opcode 1 payload"):
            parse_program(data, 0, len(data))

    def test_rejects_truncated_two_byte_opcode12_payload(self):
        data = bytes([1, 0, 12, 0xAA])
        with self.assertRaisesRegex(TimelineParseError, "preamble opcode 12 opaque payload"):
            parse_program(data, 0, len(data))

    def test_rejects_truncated_body_operand(self):
        data = bytes([1, 0, 1, 1, 2, 3, 4, 5, 6, 4])
        with self.assertRaisesRegex(TimelineParseError, "body opcode 4 payload"):
            parse_program(data, 0, len(data))

    def test_rejects_truncated_body_opcode1_opaque_tail(self):
        data = bytes([1, 0, 1, 0, 0, 0, 0, 0, 1, 0x12, 0x34, 0x56, 0x78])
        with self.assertRaisesRegex(TimelineParseError, "body opcode 1 payload"):
            parse_program(data, 0, len(data))

    def test_rejects_missing_terminator_at_owner_boundary(self):
        data = bytes([1, 0, 1, 0, 0, 0, 0, 0, 0x44])
        with self.assertRaisesRegex(TimelineParseError, "body opcode/terminator"):
            parse_program(data, 0, len(data))

    def test_rejects_bad_bounds(self):
        with self.assertRaisesRegex(TimelineParseError, "invalid program bounds"):
            parse_program(sample_program(), 4, 2)

    def test_rejects_count_that_runs_past_owner(self):
        data = bytearray(sample_program())
        data[0] = 2
        with self.assertRaisesRegex(TimelineParseError, "record base"):
            parse_program(bytes(data), 0, len(data))


if __name__ == "__main__":
    unittest.main()
