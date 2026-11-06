"""A candidate unit is credited per matching function, never for its pool or a misplaced section."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import compare
from report import credited_bytes, metrics


def executable(address, data):
    header = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01' + b'\0' * 9,
                         2, 42, 1, address, 52, 0, 0, 52, 32, 1, 0, 0, 0)
    return header + struct.pack('<8I', 1, 84, address, address, len(data), len(data), 5, 4) + data


def link(address, size, symbols):
    lines = [f"ATTRIBUTE : CODE", f"P H'{address:08X} - H'{address + size - 1:08X} H'{size:X}"]
    lines += [f"{name} H'{value:08X} ENT" for name, value in symbols.items()]
    return '\n'.join(lines) + '\n'


class FunctionCreditTests(unittest.TestCase):
    retail = bytes.fromhex('0b000900') + bytes.fromhex('0b000900') + bytes.fromhex('34120000')

    def setUp(self):
        self.unit = dict(id='tu', source='src/tu.c', mode='candidate',
                         exports={'_first': 0x1000, '_second': 0x1004},
                         sections=[dict(section='P', kind='code', address=0x1000, size=12,
                                        interior=[dict(address=0x1008, size=4, kind='data')])])

    def rows(self, data, address=0x1000):
        symbols = {'_first': address, '_second': address + 4}
        proof, _ = compare(self.unit, executable(address, data), link(address, 12, symbols), self.retail, 0x1000)
        return proof

    def test_each_function_is_judged_on_its_own_bytes(self):
        proof = self.rows(bytes.fromhex('0b000900') + bytes.fromhex('0b000800') + bytes.fromhex('34120000'))
        self.assertFalse(proof['exact'])
        self.assertEqual([(r['symbol'], r['size'], r['exact']) for r in proof['functions']],
                         [('_first', 4, True), ('_second', 4, False)])
        self.assertEqual(proof['function_bytes'], 4)

    def test_declared_interior_data_is_not_part_of_the_last_function(self):
        proof = self.rows(bytes.fromhex('0b000900') + bytes.fromhex('0b000900') + bytes.fromhex('00000000'))
        self.assertEqual(proof['functions'][1]['size'], 4)
        self.assertEqual(proof['function_bytes'], 8)

    def test_function_continues_after_an_interior_pool(self):
        retail = bytes.fromhex('04a0090000e00900') + bytes.fromhex('deadbeef') + bytes.fromhex('01e009000b000900') + bytes.fromhex('0b000900')
        unit = dict(id='split', mode='candidate', exports={'_first': 0x1000, '_second': 0x1014},
                    sections=[dict(section='P', kind='code', address=0x1000, size=24,
                                   interior=[dict(address=0x1008, size=4, kind='data')])])
        symbols = unit['exports']
        for changed, expected in ((True, 4), (False, 20)):
            with self.subTest(changed_continuation=changed):
                actual = bytearray(retail)
                if changed:
                    actual[12] ^= 1
                proof, _ = compare(unit, executable(0x1000, actual), link(0x1000, 24, symbols), retail, 0x1000)
                self.assertEqual(proof['functions'][0]['size'], 16)
                self.assertEqual(proof['functions'][0]['exact'], not changed)
                self.assertEqual(proof['function_bytes'], expected)

    def test_misplaced_section_credits_nothing(self):
        proof = self.rows(self.retail, address=0x2000)
        self.assertEqual(proof['function_bytes'], 0)

    def test_matching_instructions_with_wrong_literal_are_not_credited(self):
        for instruction, second_instruction in ((0x9004, 0x0009), (0xd002, 0x0009), (0xc702, 0xf008)):
            with self.subTest(instruction=instruction):
                retail = struct.pack('<6H', instruction, second_instruction, 0x000b, 0x0009,
                                     0x000b, 0x0009) + bytes.fromhex('0000803f')
                actual = retail[:12] + bytes.fromhex('0100803f')
                unit = dict(id='literal', mode='candidate', exports={'_first': 0x1000, '_second': 0x1008},
                            sections=[dict(section='P', kind='code', address=0x1000, size=16,
                                           interior=[dict(address=0x100c, size=4, kind='data')])])
                symbols = {'_first': 0x1000, '_second': 0x1008}
                proof, _ = compare(unit, executable(0x1000, actual), link(0x1000, 16, symbols), retail, 0x1000)
                self.assertEqual(proof['functions'][0]['equal_bytes'], 8)
                self.assertFalse(proof['functions'][0]['exact'])
                self.assertEqual(proof['function_bytes'], 4)

    def test_report_counts_candidate_functions_and_verified_units(self):
        candidate = dict(credited=False, function_bytes=8, sections=[dict(kind='code', size=12)])
        verified = dict(credited=True, sections=[dict(kind='code', size=4), dict(kind='data', size=2)])
        self.assertEqual(credited_bytes(candidate), dict(code=8, data=0))
        self.assertEqual(credited_bytes(verified), dict(code=4, data=2))
        proof = {'main_size': 100, 'units': [candidate, verified]}
        self.assertEqual(metrics(proof)['code']['matched_bytes'], 12)
        self.assertEqual(metrics(proof)['data']['matched_bytes'], 2)


if __name__ == '__main__':
    unittest.main()
