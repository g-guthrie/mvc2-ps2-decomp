import struct
import unittest

from tools.pack_retail_elf import (
    COMMENT,
    COMMENT_OFFSET,
    ELF_IDENT,
    IMAGE_OFFSET,
    IMAGE_SIZE,
    LOAD_ADDRESS,
    MEMORY_END,
    OUTPUT_SIZE,
    SECTION_HEADERS_OFFSET,
    SHSTRTAB,
    SHSTRTAB_OFFSET,
    build_elf,
)


class RetailElfPackerTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image = bytes((index * 17 + 3) & 0xFF for index in range(IMAGE_SIZE))
        cls.elf = build_elf(cls.image)

    def test_layout_and_payload_are_deterministic(self):
        self.assertEqual(len(self.elf), OUTPUT_SIZE)
        self.assertEqual(self.elf[IMAGE_OFFSET:SHSTRTAB_OFFSET], self.image)
        self.assertEqual(self.elf[SHSTRTAB_OFFSET:COMMENT_OFFSET], SHSTRTAB)
        self.assertEqual(self.elf[COMMENT_OFFSET:COMMENT_OFFSET + len(COMMENT)], COMMENT)
        self.assertEqual(self.elf, build_elf(self.image))

    def test_elf_header_matches_declared_layout(self):
        values = struct.unpack_from("<16sHHIIIIIHHHHHH", self.elf, 0)
        self.assertEqual(values[0], ELF_IDENT)
        self.assertEqual(values[1:4], (2, 8, 1))
        self.assertEqual(values[4], 0x00100008)
        self.assertEqual(values[5], 52)
        self.assertEqual(values[6], SECTION_HEADERS_OFFSET)
        self.assertEqual(values[7], 0x20924000)
        self.assertEqual(values[8:], (52, 32, 2, 40, 8, 1))

    def test_program_headers_cover_image_and_bss(self):
        first = struct.unpack_from("<8I", self.elf, 52)
        second = struct.unpack_from("<8I", self.elf, 84)
        self.assertEqual(
            first,
            (1, IMAGE_OFFSET, LOAD_ADDRESS, LOAD_ADDRESS, IMAGE_SIZE,
             MEMORY_END - LOAD_ADDRESS, 7, 0x80),
        )
        self.assertEqual(second, (1, SHSTRTAB_OFFSET, MEMORY_END, MEMORY_END, 0, 0, 6, 0x10))

    def test_loaded_section_header_matches_image(self):
        loaded = struct.unpack_from("<10I", self.elf, SECTION_HEADERS_OFFSET + 4 * 40)
        self.assertEqual(
            loaded,
            (0, 1, 7, LOAD_ADDRESS, IMAGE_OFFSET, IMAGE_SIZE, 0, 0, 0x80, 1),
        )

    def test_rejects_wrong_image_size(self):
        with self.assertRaisesRegex(ValueError, "loaded image"):
            build_elf(b"short")


if __name__ == "__main__":
    unittest.main()
