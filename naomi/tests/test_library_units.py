"""A library unit links a prebuilt SDK module; it compiles nothing and claims nothing extra."""
import sys
import unittest
import struct
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT, load, number, validate_units
from libunit import infer_internal_sections, defer_bss


class InternalPlacementTests(unittest.TestCase):
    def test_unresolved_bss_stops_retrying_until_evidence_changes(self):
        state = {}
        parts = [{'symbols': {'_buffer': 0}}]
        self.assertTrue(defer_bss('module', parts, {}, state))
        self.assertFalse(defer_bss('module', parts, {}, state))
        self.assertTrue(defer_bss('module', parts, {'_buffer': 0x3000}, state))
        self.assertFalse(defer_bss('module', parts, {'_buffer': 0x3000}, state))
        self.assertTrue(defer_bss('empty', [{'symbols': {}}], {}, state))
        self.assertFalse(defer_bss('empty', [{'symbols': {}}], {}, state))
    def place(self, pointers, payload=b'\x01\x02\x03\x04', observed=None):
        origin, second = 0x1000, 0x2000
        source = b''.join(struct.pack('<I', origin + 0x100) for _ in pointers)
        moved = b''.join(struct.pack('<I', second + 0x100) for _ in pointers)
        def segment(address, data):
            return {'address': address, 'size': len(data), 'data': data}
        rows = [('P', 'module', origin, len(source), 'CODE'), ('D', 'module', origin+0x100, 4, 'DATA')]
        images = {
            'a': ([segment(origin, source), segment(origin+0x100, payload)], (rows, {}), {'P': origin, 'D': origin+0x100}),
            'b': ([segment(second, moved), segment(second+0x100, payload)], (rows, {}), {'P': second, 'D': second+0x100}),
        }
        rom = bytearray(0x200)
        rom[:len(source)] = b''.join(struct.pack('<I', x) for x in pointers)
        rom[0x100:0x104] = payload if observed is None else observed
        parts = [{'section': 'P', 'kind': 'code', 'address': 0x3000, 'size': len(source),
                  'link_start': origin, 'exports': {}, 'relocated': list(range(0, len(source), 4))}]
        return infer_internal_sections(parts, [('D', 4, 'too little fixed content')], 'module', images, rom, 0x3000)

    def test_agreeing_internal_relocations_place_small_section(self):
        parts, remaining = self.place([0x3100, 0x3100])
        self.assertEqual(remaining, [])
        self.assertEqual(parts[-1]['address'], 0x3100)
        self.assertEqual(len(parts[-1]['placement_evidence']), 2)

    def test_conflicting_relocations_do_not_place_section(self):
        parts, remaining = self.place([0x3100, 0x3110])
        self.assertEqual(len(parts), 1)
        self.assertTrue(remaining)

    def test_fixed_byte_mismatch_is_not_overridden_by_pointer(self):
        parts, remaining = self.place([0x3100], observed=b'bad!')
        self.assertEqual(len(parts), 1)
        self.assertTrue(remaining)


def library_unit(**changes):
    unit = dict(id='lib_x_m', library='toolchain/naomi-sdk/lib/libkamui2.lib', module='km2ver_kamui2_lib_',
                mode='verified', sections=[dict(section='PSG', kind='code', address='0x0c200000', size=64)],
                exports={'_kmGetVersionInfo': '0x0c200000'})
    unit.update(changes)
    return [unit]


class LibraryUnitTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.target = load(ROOT / 'config/target.json')

    def test_a_library_unit_validates(self):
        validate_units(library_unit(), self.target)

    def test_a_library_unit_compiles_nothing(self):
        for extra in ({'source': 'src/verified/x.c'}, {'options': 'game'}):
            with self.assertRaises(ValueError):
                validate_units(library_unit(**extra), self.target)

    def test_a_library_unit_names_a_module_and_its_exports(self):
        for missing in ('module', 'exports'):
            with self.assertRaises(ValueError):
                validate_units(library_unit(**{missing: None}), self.target)

    def test_the_library_comes_from_the_checked_in_sdk(self):
        for path in ('/etc/passwd.lib', '../evil.lib', 'toolchain/naomi-sdk/../x.lib', 'src/libkamui2.lib',
                     'toolchain/naomi-sdk/lib/libkamui2.c'):
            with self.assertRaises(ValueError):
                validate_units(library_unit(library=path), self.target)

    def test_registered_library_units_name_a_checked_in_library_and_module(self):
        seen = 0
        for unit in load(ROOT / 'config/units.json'):
            if 'library' not in unit:
                continue
            seen += 1
            self.assertTrue((ROOT / unit['library']).is_file(), unit['id'])
            self.assertNotIn('source', unit)
            self.assertTrue(unit['exports'], unit['id'])
            for part in unit['sections']:
                self.assertGreater(number(part['size']), 0)
        self.assertGreater(seen, 100)

    def test_library_units_do_not_overlap_each_other(self):
        spans = []
        for unit in load(ROOT / 'config/units.json'):
            for part in unit['sections']:
                if part['kind'] != 'bss':
                    start = number(part['address'])
                    spans.append((start, start + number(part['size']), unit['id']))
        spans.sort()
        for left, right in zip(spans, spans[1:]):
            self.assertLessEqual(left[1], right[0], f'{left[2]} overlaps {right[2]}')


if __name__ == '__main__':
    unittest.main()
