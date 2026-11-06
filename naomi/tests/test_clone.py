"""Clone drafts must retain declarations after compact object layouts."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from clone import function_spans, header_blocks


class CloneHeaderTests(unittest.TestCase):
    def test_compact_definition_skips_prototype_and_keeps_nested_body(self):
        body = 'void func_0c123456(int x) { if (x) { int a[] = {1,2}; } }'
        text = 'extern void func_0c123456(int);\n' + body + '\nvoid func_0c123460(void) { }\n'
        spans = function_spans(text)
        self.assertEqual([name for name, _, _ in spans], ['func_0c123456', 'func_0c123460'])
        self.assertEqual(text[spans[0][1]:spans[0][2]], body)

    def test_braces_in_comments_and_literals_do_not_truncate_definition(self):
        body = '''void func_0c123456(void)
{
    /* } */ const char *s = "}"; char c = '{'; // }
    if (func_0c123460()) { c = '}'; }
}'''
        spans = function_spans(body)
        self.assertEqual(spans, [('func_0c123456', 0, len(body))])

    def test_one_line_struct_does_not_swallow_following_extern(self):
        head = ('struct Global { unsigned char flag; };\n'
                'typedef void (*Handler)(struct Global *);\n'
                'extern Handler table_0c242524[];\n')
        self.assertEqual(header_blocks(head), [
            'struct Global { unsigned char flag; };',
            'typedef void (*Handler)(struct Global *);',
            'extern Handler table_0c242524[];',
        ])

    def test_nested_declaration_stays_whole(self):
        head = ('struct Actor {\n'
                '    union { int count; char bytes[4]; } value;\n'
                '};\n'
                'extern void callback(struct Actor *);\n')
        self.assertEqual(header_blocks(head), [
            'struct Actor {\n    union { int count; char bytes[4]; } value;\n};',
            'extern void callback(struct Actor *);',
        ])


if __name__ == '__main__':
    unittest.main()
