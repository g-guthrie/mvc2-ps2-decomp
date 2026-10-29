#!/usr/bin/env python3
"""Build a personal, single-file copy of the web port with the game data
from YOUR OWN disc image embedded. Contains no asset bytes itself; the output
does, so keep it private (never commit or publish it).

    pack_personal.py SINGLE_FILE_HTML ISO OUT.html

SINGLE_FILE_HTML is the web build linked with -DPORT_SINGLE_FILE=ON (wasm and
JS inlined). The ISO is embedded as gzip+base64 in <script id="embedded-disc">,
which port/web/shell.html unpacks with DecompressionStream at start-up. Files
the native port never reads (the IOP modules) are zeroed first
so they compress away; the ISO9660 directory stays intact.
"""
import base64, gzip, os, sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'convert'))
from iso import Iso  # noqa: E402

UNUSED_PREFIXES = ('/MODULES/',)  # SLUS_204.86 stays: tables are read from it


def strip_iso(path):
    iso = Iso(path)
    data = bytearray(open(path, 'rb').read())
    zeroed = 0
    for name, (lba, size) in iso.files().items():
        if name.startswith(UNUSED_PREFIXES):
            off = lba * 2048
            data[off:off + size] = bytes(size)
            zeroed += size
    return bytes(data), zeroed


def main():
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    html_in, iso_path, out = sys.argv[1:]
    page = open(html_in, encoding='utf-8').read()
    marker = '</body>'
    if page.count(marker) != 1:
        sys.exit('expected exactly one </body> in ' + html_in)
    data, zeroed = strip_iso(iso_path)
    gz = gzip.compress(data, compresslevel=9, mtime=0)
    blob = ('<script type="application/octet-stream" id="embedded-disc">\n'
            + base64.b64encode(gz).decode('ascii') + '\n</script>\n')
    # The embedded data must precede the page script that reads it.
    head, tail = page.split('<canvas', 1)
    page = head + blob + '<canvas' + tail
    with open(out, 'w', encoding='utf-8') as f:
        f.write(page)
    print(f'{out}: {os.path.getsize(out) / 1048576:.1f} MB '
          f'(image {len(data) / 1048576:.0f} MB, {zeroed / 1048576:.1f} MB unused zeroed, '
          f'gzip {len(gz) / 1048576:.0f} MB)')


if __name__ == '__main__':
    main()
