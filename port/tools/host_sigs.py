"""Canonical function signatures for the host link (`gen_link_glue.py sigs`).

wasm needs every call to use the callee's exact signature: wasm-ld turns a
mismatch into a trapping stub (an error under --fatal-warnings).  MIPS never
cared, so the decomp's K&R declarations (`void f();`), per-block prototypes
and table externs (`extern void f(void);`) disagree with the definitions in
thousands of places.

Input: wasm32 objects of a build with hostify R12/R13 OFF (the "raw" build,
`probe_host_build.py --target emscripten --diag --out build/port_probe/em-raw`)
plus its diag.csv, and the wasm objects of port/stubs.
Output (host_sigs.json, read by hostify R12-R14 and gen_link_glue.py glue):

  canon      name -> {ret, params[], variadic, wasm}: one C prototype per
             function, from its definition (C types reduced to basic types:
             pointers become `void *`, typedefs are resolved, signedness and
             width kept); for a function with no definition (a stub), from
             its callers (widest call, majority types)
  rewrite    names whose declarations hostify R12 replaces by the canonical
             prototype (any caller disagrees with the definition, or no
             definition exists, or some TU calls it undeclared)
  wrap       tu -> names whose calls must yield a value although the
             function is void (the TU believed it returned one)
  data_code  tu -> {name: function}: code addresses the TU declares as data
             (`extern u8 D_0013B010[];` = a callback); R13 makes them
             function designators
  noreturn   tu -> [line]: non-void functions that fall off the end (R14)
  bare_return tu -> [line]: `return;` in a non-void function (R14)
  skipped    name -> reason (no canonical prototype possible)
  func_names every name used as a function anywhere
"""
import collections
import csv
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import hostify as H  # noqa: E402
import link_catalog as L  # noqa: E402
import wasm_obj  # noqa: E402

ROOT = L.ROOT
CTYPE = {"i32": "int", "i64": "long long", "f32": "float", "f64": "double", "void": "void"}
QUALS = {"const", "volatile", "register", "static", "extern", "inline", "__inline",
         "__inline__", "auto", "restrict", "__restrict"}
BASE_TYPEDEFS = {
    "u8": "unsigned char", "s8": "signed char", "u16": "unsigned short", "s16": "short",
    "u32": "unsigned int", "s32": "int", "u64": "unsigned long long", "s64": "long long",
    "f32": "float", "f64": "double", "size_t": "unsigned int", "uint": "unsigned int",
    "BOOL": "int", "bool": "int", "_Bool": "_Bool",
}
BASIC_WORDS = {"void", "char", "short", "int", "long", "float", "double", "unsigned",
               "signed", "_Bool"}


def parse_sig(s):
    p, r = s[1:].split(")->")
    return [x for x in p.split(",") if x], r


def lower(ctext):
    if ctext.endswith("*"):
        return "i32"
    if ctext == "void":
        return "void"
    if "float" in ctext:
        return "f32"
    if "double" in ctext:
        return "f64"
    if "long long" in ctext:
        return "i64"
    return "i32"


def normalize_basic(words):
    w = [x for x in words if x not in QUALS]
    if not w or any(x not in BASIC_WORDS for x in w):
        return None
    uns = "unsigned" in w
    core = [x for x in w if x not in ("unsigned", "signed")]
    if core.count("long") >= 2:
        base = "long long"
    elif "char" in core:
        base = "char"
    elif "short" in core:
        base = "short"
    elif "float" in core:
        return "float"
    elif "double" in core:
        return "double"
    elif "void" in core:
        return "void"
    elif "_Bool" in core:
        return "_Bool"
    else:
        base = "int"
    if base == "char":
        return "unsigned char" if uns else ("signed char" if "signed" in w else "char")
    return ("unsigned " + base) if uns else base


class TypeEnv:
    """Typedefs visible in a TU (its text plus the project headers it includes)."""

    def __init__(self, text, incdirs):
        self.td = dict(BASE_TYPEDEFS)
        self.ptr = set()
        self.agg = set()
        self.enum = set()
        seen = set()
        self._scan(text, incdirs, seen)

    def _scan(self, text, incdirs, seen):
        for inc in re.findall(r'^\s*#\s*include\s+"([^"]+)"', text, re.M):
            for d in incdirs:
                p = (d / inc).resolve()
                if p.exists() and p not in seen:
                    seen.add(p)
                    self._scan(p.read_text(encoding="latin-1"), [p.parent] + incdirs, seen)
                    break
        flat = re.sub(r"/\*.*?\*/|//[^\n]*", " ", text, flags=re.S)
        for m in re.finditer(r"\btypedef\b([^;]*);", flat):
            body = m.group(1)
            fp = re.search(r"\(\s*\*\s*(\w+)\s*\)", body)
            if fp:
                self.ptr.add(fp.group(1))
                continue
            names = re.findall(r"(\**)\s*(\w+)\s*(?:\[[^\]]*\])?\s*(?:,|$)", body.strip())
            head = re.sub(r"\{.*\}", " {} ", body, flags=re.S)
            for stars, name in names:
                if stars or "[" in body.split(name)[-1][:2]:
                    self.ptr.add(name)
                elif re.search(r"\b(struct|union)\b", head):
                    self.agg.add(name)
                elif re.search(r"\benum\b", head):
                    self.enum.add(name)
                else:
                    words = re.findall(r"\w+", head)
                    words = [x for x in words if x != name and x not in QUALS]
                    self.td[name] = " ".join(words)

    def ctype(self, toks, depth=0):
        """C basic type text for a declaration specifier+declarator, or None
        for an aggregate passed by value."""
        words = [t for t in toks if t not in QUALS]
        if "*" in words or "[" in words or "(" in words:
            return "void *"
        if "..." in words:
            return "..."
        if any(x in ("struct", "union") for x in words):
            return None
        if "enum" in words:
            return "int"
        names = [x for x in words if re.match(r"[A-Za-z_]\w*$", x) and x not in BASIC_WORDS]
        if not names:
            return normalize_basic(words)
        n = names[0]
        if n in self.ptr:
            return "void *"
        if n in self.agg:
            return None
        if n in self.enum:
            return "int"
        if n in self.td and depth < 8:
            sub = self.td[n].split()
            return self.ctype(sub + [x for x in words if x != n], depth + 1)
        return "?"


def split_params(arg_toks):
    """[[tokens]] of a parameter list, names dropped."""
    toks = [t for t in arg_toks if t[0] not in ("ws", "comment")]
    parts = H.split_top(toks, ",")
    out = []
    for p in parts:
        ws = [t[1] for t in p]
        if not ws:
            continue
        if set(ws) == {"."}:
            out.append(["..."])
            continue
        if len(ws) >= 2 and re.match(r"[A-Za-z_]\w*$", ws[-1]) and ws[-1] not in BASIC_WORDS \
                and ws[-2] not in ("struct", "union", "enum"):
            if not (len(ws) == 2 and ws[0] in ("unsigned", "signed")):
                ws = ws[:-1]
        out.append(ws)
    if out == [["void"]]:
        return []
    return out


def def_heads(text):
    """name -> (ret words, [param words]) of the file-scope definitions."""
    toks = H.lex(text)
    out = {}
    for term, _idx, d in H.file_scope_heads(toks):
        if d and term == "{":
            ret, name, args, storage = d
            sa = [x for x in args if x[0] not in ("ws", "comment")]
            kr = bool(sa) and all(x[0] == "ident" or x[1] == "," for x in sa) and \
                [x[1] for x in sa] != ["void"] and not any(x[1] in BASIC_WORDS for x in sa)
            out[name] = ([t[1] for t in ret if t[0] != "ws"], split_params(args), kr)
    return out


def canonical_from_def(name, wsig, head, env):
    ps, r = parse_sig(wsig)
    if head is None:
        return {"ret": CTYPE[r], "params": [CTYPE[p] for p in ps], "variadic": False,
                "wasm": wsig, "from": "wasm"}, None
    ret_w, params, kr = head
    variadic = bool(params) and params[-1] == ["..."]
    if variadic:
        params = params[:-1]
    if kr:   # K&R definition: types come from the promoted wasm signature
        return {"ret": fix(env.ctype(ret_w), r), "params": [CTYPE[p] for p in ps],
                "variadic": False, "wasm": wsig, "from": "def(K&R)"}, None
    nfix = len(ps) - (1 if variadic else 0)
    rc = env.ctype(ret_w)
    if rc is None and r == "void" and len(ps) == len(params) + 1 + (1 if variadic else 0):
        return None, "returns an aggregate by value"
    if nfix != len(params):
        return {"ret": fix(rc, r), "params": [CTYPE[p] for p in ps[:nfix]], "variadic": variadic,
                "wasm": wsig, "from": "wasm(param count)"}, None
    cps = []
    for words, w in zip(params, ps):
        c = env.ctype(words)
        if c is None:
            return None, "aggregate parameter by value"
        cps.append(fix(c, w))
    return {"ret": fix(rc, r), "params": cps, "variadic": variadic, "wasm": wsig,
            "from": "def"}, None


def fix(c, w):
    """C text c if it lowers to wasm type w, else the plain type for w."""
    if c in (None, "?", "..."):
        return CTYPE[w]
    if lower(c) != w:
        return CTYPE[w]
    return c


def canonical_from_calls(sigs):
    """Stub with no definition: widest call, majority types per position."""
    parsed = [parse_sig(s) for s in sigs]
    n = max(len(p) for p, _ in parsed)
    params = []
    for i in range(n):
        c = collections.Counter(p[i] for p, _ in parsed if len(p) > i)
        params.append(c.most_common(1)[0][0])
    rets = collections.Counter(r for _, r in parsed if r != "void")
    ret = rets.most_common(1)[0][0] if rets else "void"
    wsig = wasm_obj.sig_str(params, [] if ret == "void" else [ret])
    return {"ret": CTYPE[ret], "params": [CTYPE[p] for p in params], "variadic": False,
            "wasm": wsig, "from": "callers"}


def host_lib_canon(names):
    """Canonical prototypes for host C library / compiler-rt functions the
    game calls by name: the wasm signature from the Emscripten archive member
    that defines it, the C types from the sysroot header when one declares it."""
    import os
    emsdk = os.environ.get("EMSDK", "/home/user/emsdk")
    sysroot = Path(emsdk) / "upstream/emscripten/cache/sysroot"
    libdir = sysroot / "lib/wasm32-emscripten"
    found = {}
    for lib in ("libc.a", "libclang_rt.builtins.a", "libdlmalloc.a"):
        if not (libdir / lib).exists() or len(found) == len(names):
            continue
        for mname, data in wasm_obj.archive_members(libdir / lib):
            if not mname.endswith(".o"):
                continue
            try:
                fs, _ = wasm_obj.symbols(mname, data)
            except Exception:
                continue
            for n, d, b, sg in fs:
                if d and n in names and n not in found and b != "local":
                    found[n] = sg
    heads = ""
    for h in ("string.h", "math.h", "stdlib.h", "stdio.h"):
        p = sysroot / "include" / h
        if p.exists():
            heads += p.read_text(errors="replace")
    heads = re.sub(r"/\*.*?\*/", " ", heads, flags=re.S)
    env = TypeEnv("", [])
    env.td.update({"size_t": "unsigned int", "ssize_t": "int", "FILE": "int"})
    out = {}
    for n, sg in found.items():
        ps, r = parse_sig(sg)
        c = {"ret": CTYPE[r], "params": [CTYPE[x] for x in ps], "variadic": False,
             "wasm": sg, "from": "host library"}
        m = re.search(r"([\w\s\*]+?)\b" + re.escape(n) + r"\s*\(([^;{}]*)\)\s*;", heads)
        if m:
            ret_w = m.group(1).split()
            params = [x.split() for x in m.group(2).split(",") if x.strip() and x.strip() != "void"]
            params = [re.findall(r"\w+|\*|\.\.\.", " ".join(x)) for x in params]
            pt = []
            for words, w in zip(params, ps):
                if len(words) > 1 and re.match(r"\w+$", words[-1]) and words[-1] not in BASIC_WORDS \
                        and words[-1] not in env.td:
                    words = words[:-1]
                pt.append(fix(env.ctype(words), w))
            if len(pt) == len(ps):
                rt = [x for x in ret_w if x not in ("extern", "static", "inline")]
                c = {"ret": fix(env.ctype(rt), r), "params": pt, "variadic": False, "wasm": sg,
                     "from": "host library + header"}
        out[n] = c
    return out


def obj_source(objpath):
    name = Path(objpath).name
    if name.endswith(".c.o"):
        return name[:-2].replace("__", "/")
    return None


def main_sigs(a):
    """`gen_link_glue.py sigs` entry point."""
    objdirs = [Path(p) for p in a.inputs]
    objs = []
    for d in objdirs:
        objs.extend(sorted(d.glob("*.o")) if d.is_dir() else [d])
    stub_objs = []
    for d in a.stub_objs:
        stub_objs.extend(sorted(Path(d).glob("*.o")))
    defs = {}          # name -> (sig, obj, binding)
    imps = collections.defaultdict(list)   # name -> [(obj, sig)]
    data_undef = collections.defaultdict(set)
    func_names = set()
    definers = collections.defaultdict(list)
    for o in objs + stub_objs:
        fs, ds = wasm_obj.symbols(str(o))
        for n, d, b, s in fs:
            if b == "local":
                continue
            func_names.add(n)
            if d:
                definers[n].append(o)
                if n not in defs or defs[n][2] == "weak":
                    defs[n] = (s, o, b)
            else:
                imps[n].append((o, s))
        for n, d in ds:
            if not d:
                data_undef[o].add(n)
    host = L.host_runtime_names()
    hsrc = Path(a.inputs[0]).parent / "hsrc"
    envs, heads = {}, {}

    def head_of(srcpath, text_path, name):
        if text_path not in heads:
            text = text_path.read_text(encoding="latin-1") if text_path.exists() else ""
            heads[text_path] = def_heads(text)
            envs[text_path] = TypeEnv(text, [text_path.parent, hsrc / "src", ROOT / "src"])
        return heads[text_path].get(name), envs[text_path]

    canon, skipped = {}, {}
    alt = L.alt_to_credited()
    for n, (s, o, b) in defs.items():
        if n in host:
            continue
        src = obj_source(o)
        if o in stub_objs:
            tp = ROOT / "port/stubs" / (Path(o).stem + ".c")
        elif src:
            tp = hsrc / src
        else:
            tp = None
        head, env = (None, None)
        if tp is not None:
            head, env = head_of(src, tp, n)
            if head is None and n in alt:
                head, env = head_of(src, tp, alt[n])
        if env is None:
            env = TypeEnv("", [])
        c, why = canonical_from_def(n, s, head, env)
        if c is None:
            skipped[n] = why
        else:
            canon[n] = c
    for n, lst in imps.items():
        if n in defs or n in host or n in canon:
            continue
        canon[n] = canonical_from_calls([s for _, s in lst])
    canon.update(host_lib_canon({n for n in imps if n in host and n not in defs}))

    # diag (implicit declarations, missing returns) from the raw build
    implicit = collections.defaultdict(set)
    noreturn = collections.defaultdict(list)
    bare_return = collections.defaultdict(list)
    diag = Path(a.inputs[0]).parent / "diag.csv"
    if diag.exists():
        for r in csv.DictReader(open(diag)):
            if r["kind"] == "implicit":
                implicit[r["source"]].add(r["name"])
            elif r["kind"] == "noreturn" and r["file"] == r["source"]:
                noreturn[r["source"]].append(int(r["line"]))
            elif r["kind"] == "bare-return" and r["file"] == r["source"]:
                bare_return[r["source"]].append(int(r["line"]))

    rewrite = set()
    wrap = collections.defaultdict(set)
    mism = collections.defaultdict(set)
    imports_tu = collections.defaultdict(dict)
    mismatches = 0
    for n, lst in imps.items():
        c = canon.get(n)
        if c is None:
            continue
        if n not in defs:
            rewrite.add(n)
        for o, s in lst:
            if s != c["wasm"]:
                mismatches += 1
                rewrite.add(n)
                src = obj_source(o)
                if src:
                    mism[src].add(n)
                    imports_tu[src][n] = s
                if src and c["ret"] == "void" and parse_sig(s)[1] != "void":
                    wrap[src].add(n)
    for src, names in implicit.items():
        for n in names:
            if n in canon:
                rewrite.add(n)
                if canon[n]["ret"] == "void":
                    wrap[src].add(n)

    defines_tu = collections.defaultdict(list)
    for n, olist in definers.items():
        if n in rewrite:
            for o in olist:
                src = obj_source(o)
                if src:
                    defines_tu[src].append(n)
    defines_tu = {k: sorted(v) for k, v in sorted(defines_tu.items())}

    cat = L.credited_at()
    data_code = collections.defaultdict(dict)
    for o, names in data_undef.items():
        src = obj_source(o)
        if not src:
            continue
        for n in names:
            ad = L.address_of(n)
            if ad is None or not (L.TEXT_START <= ad < L.TEXT_END):
                continue
            f = cat.get(ad)
            if f is None:
                fc = L.function_containing(ad)
                if fc and fc[0] == ad:
                    f = fc[2]
                    if f not in defs and f not in canon:
                        # code address of a function with no C and no caller
                        # by name: the glue generates a stub for it
                        canon[f] = {"ret": "void", "params": [], "variadic": False,
                                    "wasm": "()->void", "from": "code address"}
            if f and f in canon:
                data_code[src][n] = f

    out = {
        "canon": canon,
        "rewrite": sorted(rewrite),
        "wrap": {k: sorted(v) for k, v in sorted(wrap.items())},
        "mismatch": {k: sorted(v) for k, v in sorted(mism.items())},
        "imports": {k: dict(sorted(v.items())) for k, v in sorted(imports_tu.items())},
        "defines": defines_tu,
        "data_code": {k: dict(sorted(v.items())) for k, v in sorted(data_code.items())},
        "noreturn": {k: sorted(set(v)) for k, v in sorted(noreturn.items())},
        "bare_return": {k: sorted(set(v)) for k, v in sorted(bare_return.items())},
        "implicit": {k: sorted(v) for k, v in sorted(implicit.items())},
        "skipped": skipped,
        "func_names": sorted(func_names),
        "stats": {"objects": len(objs), "stub_objects": len(stub_objs), "definitions": len(defs),
                  "canonical": len(canon), "mismatching_imports": mismatches,
                  "rewrite": len(rewrite), "skipped": len(skipped),
                  "data_code_refs": sum(len(v) for v in data_code.values()),
                  "noreturn": sum(len(v) for v in noreturn.values()),
                  "bare_return": sum(len(v) for v in bare_return.values()),
                  "implicit": sum(len(v) for v in implicit.values())},
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(out, indent=0, sort_keys=True))
    print(json.dumps(out["stats"]))
    for n, why in sorted(skipped.items()):
        print(f"  skipped {n}: {why}")
    return 0
