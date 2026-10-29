"""Minimal reader for wasm32 relocatable objects (clang/Emscripten .o).

Only what the host link needs: the function symbols of an object with their
wasm signatures, so call-site/definition mismatches (which wasm-ld turns into
trapping stubs, or errors under --fatal-warnings) can be found before linking.

    syms = function_symbols(path)
    # -> [(name, defined, binding, sig)] ; sig = "(i32,f32)->i32"
"""
import struct

VALTYPES = {0x7F: "i32", 0x7E: "i64", 0x7D: "f32", 0x7C: "f64", 0x7B: "v128",
            0x70: "funcref", 0x6F: "externref"}
SYM_UNDEFINED, SYM_EXPLICIT_NAME = 0x10, 0x40
SYM_WEAK, SYM_LOCAL = 0x1, 0x2


class R:
    def __init__(self, b, p=0):
        self.b, self.p = b, p

    def u8(self):
        v = self.b[self.p]
        self.p += 1
        return v

    def leb(self):
        r = s = 0
        while True:
            c = self.b[self.p]
            self.p += 1
            r |= (c & 0x7F) << s
            s += 7
            if not c & 0x80:
                return r

    def name(self):
        n = self.leb()
        v = self.b[self.p:self.p + n].decode("utf-8", "replace")
        self.p += n
        return v


def sig_str(params, results):
    return "(" + ",".join(params) + ")->" + (",".join(results) or "void")


def function_symbols(path):
    return symbols(path)[0]


def symbols(path, data_bytes=None):
    """(function symbols as function_symbols(), [(data name, defined)])."""
    b = data_bytes if data_bytes is not None else open(path, "rb").read()
    if b[:4] != b"\0asm":
        raise ValueError(f"{path}: not a wasm object")
    r = R(b, 8)
    types, imports, funcs = [], [], []
    linking = None
    while r.p < len(b):
        sid = r.u8()
        size = r.leb()
        end = r.p + size
        if sid == 1:
            for _ in range(r.leb()):
                r.u8()  # 0x60
                ps = [VALTYPES.get(r.u8(), "?") for _ in range(r.leb())]
                rs = [VALTYPES.get(r.u8(), "?") for _ in range(r.leb())]
                types.append(sig_str(ps, rs))
        elif sid == 2:
            for _ in range(r.leb()):
                mod, field, kind = r.name(), r.name(), r.u8()
                if kind == 0:
                    imports.append((field, r.leb()))
                elif kind == 1:
                    r.u8()
                    fl = r.leb(); r.leb()
                    if fl & 1:
                        r.leb()
                elif kind == 2:
                    fl = r.leb(); r.leb()
                    if fl & 1:
                        r.leb()
                elif kind == 3:
                    r.u8(); r.u8()
                elif kind == 4:
                    r.u8(); r.leb()
        elif sid == 3:
            funcs = [r.leb() for _ in range(r.leb())]
        elif sid == 0:
            nm = r.name()
            if nm == "linking":
                linking = (r.p, end)
        r.p = end
    out = []
    data = []
    if linking is None:
        return out, data
    r.p, end = linking
    r.leb()  # version
    while r.p < end:
        st = r.u8()
        ssz = r.leb()
        send = r.p + ssz
        if st == 8:  # WASM_SYMBOL_TABLE
            for _ in range(r.leb()):
                kind = r.u8()
                flags = r.leb()
                undef = bool(flags & SYM_UNDEFINED)
                if kind in (0, 2, 4, 5):  # function, global, tag, table
                    idx = r.leb()
                    name = None
                    if not undef or flags & SYM_EXPLICIT_NAME:
                        name = r.name()
                    if kind != 0:
                        continue
                    if idx < len(imports):
                        tidx = imports[idx][1]
                        if name is None:
                            name = imports[idx][0]
                    else:
                        tidx = funcs[idx - len(imports)]
                    binding = "local" if flags & SYM_LOCAL else ("weak" if flags & SYM_WEAK else "global")
                    out.append((name, not undef, binding, types[tidx]))
                elif kind == 1:  # data
                    dn = r.name()
                    if not undef:
                        r.leb(); r.leb(); r.leb()
                    if not flags & SYM_LOCAL:
                        data.append((dn, not undef))
                elif kind == 3:  # section
                    r.leb()
        r.p = send
    return out, data


def archive_members(path):
    """[(member name, bytes)] of a System V / GNU ar archive."""
    b = open(path, "rb").read()
    if b[:8] != b"!<arch>\n":
        return []
    out, p, names = [], 8, b""
    while p + 60 <= len(b):
        h = b[p:p + 60]
        name = h[:16].decode("latin-1").strip()
        size = int(h[48:58].decode().strip())
        data = b[p + 60:p + 60 + size]
        if name == "//":
            names = data
        elif name.startswith("/") and name[1:].isdigit() and names:
            off = int(name[1:])
            name = names[off:names.index(b"/\n", off)].decode("latin-1")
            out.append((name, data))
        elif name not in ("/", "/SYM64/"):
            out.append((name.rstrip("/"), data))
        p += 60 + size + (size & 1)
    return out


if __name__ == "__main__":
    import sys
    for p in sys.argv[1:]:
        for s in function_symbols(p):
            print(p, *s)
