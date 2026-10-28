#!/usr/bin/env python3
"""Source filter for the HOST port build.

Rewrites one decomp translation unit into host-compilable C without touching
src/ (the output goes to the build tree; `#line` keeps diagnostics pointing at
the original file).  Every rewrite is mechanical.  Where the PS2 semantics can
be expressed in C they are; anything only the PS2 can do becomes an explicit
call into the platform layer (ps2_asm_stmt) so it shows up at link/run time
instead of being silently lost.

Rewrites (evidence in port/docs/HOST_BUILD_ISSUES.md):

  R1 long64     `long` is 64-bit under MWCC PS2 and EE GCC (measured with
                MWCC 2.4.1: sizeof(long)==8, sizeof(long double)==8).
                `long` -> `long long` unless already part of `long long`;
                `long double` -> `double`.
  R2 hexexp     MW reads `0x1E7-0x1E0` as three tokens; ISO C reads
                `0x1E-0x...` as one pp-number.  A space is inserted before the
                sign that follows a hex digit e/E.
  R3 reglabel   `register T x __asm__("$17")` -> `register T x` (drops EE
                register pins).  Symbol asm labels are kept.
  R4 gnuasm     GNU statement asm -> `do { <outputs zeroed>;
                ps2_asm_stmt(file, line, "template"); } while (0)`.
                Pure-nop templates become `((void)0)`.
  R5 mwasm      Metrowerks `asm { ... }` blocks: nop-only -> no-op; blocks of
                only `add.s/sub.s/mul.s/div.s d, a, b` on C operands -> the
                equivalent C; anything else -> ps2_asm_stmt(...).
  R6 toplevel   file-scope `__asm__("...")` and the FN(name, body) placeholder
                macro (whole-function assembly, uncredited) are dropped; FN
                expands to PS2_TOPLEVEL_ASM_DROPPED(name).
  R7 blockext   MW scopes block-level `extern` function declarations to the
                block, so one TU may give a function different prototypes in
                different functions; C merges them and rejects the conflict.
                When a name has more than one distinct prototype in the TU,
                each block-scope declaration becomes a block-local const
                function pointer to the same symbol (through an asm-label
                alias declared at file scope).
  R8 staticdef  every file-scope `static` function definition is renamed
                (token rename `name` -> `name__hs` inside the .c only), so a
                shared header that declares the retail function extern does
                not collide with the TU's verified static copy.
  R9 export     ...except in the TU that config/matches.csv credits for that
                function: there `static` is dropped and the name kept, so the
                one credited copy is the global definition other TUs link to
                (static copies elsewhere stay private as name__hs).
  R10 override  per-file exact replacements in host_overrides.py for the few
                constructs no rule can carry (each one documented there).
"""
import re
import sys

IDENT = re.compile(r"[A-Za-z_]\w*")
REGNAME = re.compile(
    r"^(\$\w+|[vatskf]\d+|zero|r0|at|sp|ra|gp|fp|vf\d+[xyzw]?|vi\d+|ACC|Q|I|R|f\d+|hi|lo)$")


# --------------------------------------------------------------------------
# lexer: list of (kind, text); kind in ws, comment, string, char, pp, ident,
# number, punct.  `pp` is a whole preprocessor line including continuations.
# --------------------------------------------------------------------------
def lex(text, pp=True):
    i, n = 0, len(text)
    out = []
    bol = True
    while i < n:
        c = text[i]
        if c in " \t\r\f\v":
            j = i
            while j < n and text[j] in " \t\r\f\v":
                j += 1
            out.append(("ws", text[i:j])); i = j; continue
        if c == "\n":
            out.append(("ws", c)); i += 1; bol = True; continue
        if c == "\\" and i + 1 < n and text[i + 1] == "\n":
            out.append(("ws", "\\\n")); i += 2; continue
        if c == "#" and bol and pp:
            j = i
            while j < n:
                if text[j] == "\\" and j + 1 < n and text[j + 1] == "\n":
                    j += 2; continue
                if text.startswith("/*", j):
                    k = text.find("*/", j + 2)
                    j = n if k < 0 else k + 2; continue
                if text[j] == "\n":
                    break
                j += 1
            out.append(("pp", text[i:j])); i = j; continue
        bol = False
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(("comment", text[i:j])); i = j; continue
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(("comment", text[i:j])); i = j; continue
        if c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                if text[j] == "\\":
                    j += 1
                j += 1
            j = min(j + 1, n)
            out.append(("string" if c == '"' else "char", text[i:j])); i = j; continue
        if c.isdigit() or (c == "." and i + 1 < n and text[i + 1].isdigit()):
            j = i + 1
            while j < n:
                if text[j] in "eEpP" and j + 1 < n and text[j + 1] in "+-":
                    j += 2; continue
                if text[j].isalnum() or text[j] in "._":
                    j += 1; continue
                break
            out.append(("number", text[i:j])); i = j; continue
        if c.isalpha() or c == "_":
            m = IDENT.match(text, i)
            out.append(("ident", m.group())); i = m.end(); continue
        out.append(("punct", c)); i += 1
    return out


class Braces:
    """Brace depth that survives `#if A { #else { #endif` (each conditional
    branch restarts from the depth at its #if; the first branch's final depth
    wins at #endif) plus the conditional branch path of the current token, so
    declarations in mutually exclusive branches are never compared."""
    PPDIR = re.compile(r"#\s*(if|ifdef|ifndef|elif|else|endif)\b")

    def __init__(self, depth=0):
        self.depth = depth
        self.stack = []   # [gid, branch, depth_at_if, depth_after_first]
        self.gid = 0

    def pp(self, text):
        m = self.PPDIR.match(text)
        if not m:
            return
        d = m.group(1)
        if d.startswith("if"):
            self.gid += 1
            self.stack.append([self.gid, 0, self.depth, None])
        elif self.stack and d in ("elif", "else"):
            fr = self.stack[-1]
            if fr[3] is None:
                fr[3] = self.depth
            fr[1] += 1
            self.depth = fr[2]
        elif self.stack and d == "endif":
            fr = self.stack.pop()
            if fr[3] is not None:
                self.depth = fr[3]

    def punct(self, c):
        if c == "{":
            self.depth += 1
        elif c == "}":
            self.depth -= 1

    def path(self):
        return tuple((g, b) for g, b, _, _ in self.stack)


def paths_compatible(p, q):
    a = dict(p)
    return all(a.get(g, b) == b for g, b in q)


def sig_next(toks, k):
    k += 1
    while k < len(toks) and toks[k][0] in ("ws", "comment"):
        k += 1
    return k


def sig_prev(toks, k):
    k -= 1
    while k >= 0 and toks[k][0] in ("ws", "comment"):
        k -= 1
    return k


def match_close(toks, k, open_, close):
    depth = 0
    while k < len(toks):
        t = toks[k]
        if t[0] == "punct":
            if t[1] == open_:
                depth += 1
            elif t[1] == close:
                depth -= 1
                if depth == 0:
                    return k
        k += 1
    return len(toks) - 1


def text_of(toks):
    return "".join(t[1] for t in toks)


def cstr(s):
    s = s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\t", " ")
    return '"' + s + '"'


def unstring(lit):
    body = lit[1:-1]
    try:
        return bytes(body, "latin-1").decode("unicode_escape")
    except Exception:
        return body


ASM_KW = {"asm", "__asm__", "__asm"}
ASM_QUAL = {"volatile", "__volatile__", "__volatile", "goto", "inline"}


def split_top(toks, sep):
    parts, cur, depth = [], [], 0
    for t in toks:
        if t[0] == "punct" and t[1] in "([{":
            depth += 1
        elif t[0] == "punct" and t[1] in ")]}":
            depth -= 1
        if depth == 0 and t[0] == "punct" and t[1] == sep:
            parts.append(cur); cur = []
        else:
            cur.append(t)
    parts.append(cur)
    return parts


def operands(op_toks):
    """[(constraint, lvalue_expr)] of a GNU asm operand list."""
    res = []
    for op in split_top(op_toks, ","):
        op = [t for t in op if t[0] not in ("ws", "comment")]
        if not op:
            continue
        k = 0
        if op[k][1] == "[":  # [name] "=r" (expr)
            while k < len(op) and op[k][1] != "]":
                k += 1
            k += 1
        con = unstring(op[k][1]) if op[k][0] == "string" else ""
        expr = text_of(op[k + 1:]).strip()
        if expr.startswith("(") and expr.endswith(")"):
            expr = expr[1:-1].strip()
        while True:  # strip C casts (longlong.h `(USItype)(w1)`)
            m = re.match(r"^\(\s*[A-Za-z_]\w*(\s+[A-Za-z_]\w*)*\s*\**\s*\)\s*(?=\()", expr)
            if not m:
                break
            expr = expr[m.end():]
        res.append((con, expr))
    return res


def zero_outputs(outs):
    return " ".join(f"__builtin_memset(&({e}), 0, sizeof({e}));" for _, e in outs if e)


def known_template(tmpl, outs, ins):
    """GNU asm templates with an exact C equivalent."""
    t = re.sub(r"\s+", " ", tmpl.strip())
    m = re.match(r"^mult(u?) %(\d),%(\d)$", t)
    if m and len(outs) == 2 and {c for c, _ in outs} == {"=l", "=h"} and len(ins) == 2:
        ty = "unsigned" if m.group(1) else "int"
        lo = next(e for c, e in outs if c == "=l")
        hi = next(e for c, e in outs if c == "=h")
        return (f"do {{ {'unsigned ' if m.group(1) else ''}long long __p = "
                f"({'unsigned ' if m.group(1) else ''}long long)({ty})({ins[0][1]}) * ({ty})({ins[1][1]}); "
                f"({lo}) = (unsigned)__p; ({hi}) = (unsigned)(__p >> 32); }} while (0)")
    return None


FPU3 = re.compile(r"^(add|sub|mul|div)\.s\s+(\w+)\s*,\s*(\w+)\s*,\s*(\w+)$")
OPS = {"add": "+", "sub": "-", "mul": "*", "div": "/"}


def mw_block(body):
    insns = [s.strip() for s in re.split(r"[;\n]", body) if s.strip()]
    if all(s == "nop" for s in insns):
        return "do { } while (0); /* host R5: MW asm nop padding */"
    c = []
    for s in insns:
        if s == "nop":
            continue
        m = FPU3.match(s)
        if m and not any(REGNAME.match(x) for x in m.group(2, 3, 4)):
            op, d, a, b = m.groups()
            c.append(f"{d} = {a} {OPS[op]} {b};")
            continue
        c = None
        break
    if c is not None:
        return "do { " + " ".join(c) + " } while (0); /* host R5: MW FPU asm as C */"
    return (f"do {{ ps2_asm_stmt(__FILE__, __LINE__, {cstr(body.strip())}); }} while (0);"
            " /* host R5: MW asm block */")


def rewrite_asm(toks, depth=0, eol="\n"):
    """R3-R6.  `depth`/`eol` let #define bodies be rewritten as statements
    with line continuations."""
    out = []
    i = 0
    br = Braces(depth)
    while i < len(toks):
        t = toks[i]
        if t[0] == "punct":
            br.punct(t[1])
        elif t[0] == "pp":
            br.pp(t[1])
        depth = br.depth
        if t[0] == "ident" and t[1] in ASM_KW:
            j = sig_next(toks, i)
            if j < len(toks) and toks[j][1] == "{":  # MW block (R5)
                e = match_close(toks, j, "{", "}")
                nl = text_of(toks[i:e + 1]).count("\n")
                out.append(("punct", mw_block(text_of(toks[j + 1:e])) + eol * nl))
                i = e + 1
                continue
            quals = []
            while j < len(toks) and toks[j][0] == "ident" and toks[j][1] in ASM_QUAL:
                quals.append(toks[j][1]); j = sig_next(toks, j)
            if j < len(toks) and toks[j][1] == "(":
                e = match_close(toks, j, "(", ")")
                inner = toks[j + 1:e]
                nl = text_of(toks[i:e + 1]).count("\n")
                p = sig_prev(toks, i)
                prevt = toks[p] if p >= 0 else ("punct", ";")
                parts = split_top(inner, ":")
                tmpl = "".join(unstring(s[1]) for s in parts[0] if s[0] == "string")
                is_label = not quals and len(parts) == 1 and (
                    prevt[0] == "ident" or (prevt[1] in (")", "]") and tmpl.startswith("$")))
                if is_label:  # R3
                    if tmpl.startswith("$") or REGNAME.match(tmpl):
                        out.append(("punct", "/* host R3: register pin dropped */" + eol * nl))
                    else:
                        out.extend(toks[i:e + 1])
                    i = e + 1
                    continue
                if depth == 0:  # R6
                    out.append(("punct", "/* host R6: file-scope asm dropped */" + eol * nl))
                    i = e + 1
                    continue
                insns = [s.strip() for s in re.split(r"[;\n]", tmpl) if s.strip()]
                if insns and all(s == "nop" for s in insns) and len(parts) <= 1:
                    rep = "((void)0)"
                else:  # R4
                    outs = operands(parts[1]) if len(parts) > 1 else []
                    ins = operands(parts[2]) if len(parts) > 2 else []
                    rep = known_template(tmpl, outs, ins) or (
                        f"do {{ {zero_outputs(outs)} ps2_asm_stmt(__FILE__, __LINE__, "
                        f"{cstr(tmpl)}); }} while (0)")
                out.append(("punct", rep + eol * nl))
                i = e + 1
                continue
        out.append(t)
        i += 1
    return out


def rewrite_long(toks):
    """R1, R2."""
    out = []
    for k, t in enumerate(toks):
        if t[0] == "ident" and t[1] == "long":
            p = sig_prev(toks, k)
            nx = sig_next(toks, k)
            pv = toks[p][1] if p >= 0 else ""
            nv = toks[nx][1] if nx < len(toks) else ""
            if pv == "long" or nv == "long":
                out.append(t)
            elif nv == "double":
                out.append(("ws", "/*long*/"))
            else:
                out.append(("ident", "long long"))
            continue
        if t[0] == "number" and t[1][:2].lower() == "0x":
            out.append(("number", re.sub(r"([eE])([+-])", r"\1 \2", t[1])))
            continue
        out.append(t)
    return out


def rewrite_pp(text, statics=()):
    """R1/R2/R4 (and R8 renames) inside #define bodies."""
    if not re.match(r"#\s*define\b", text):
        return text
    toks = rewrite_long(rewrite_asm(lex(text, pp=False), depth=1, eol="\\\n"))
    if statics:
        toks = [("ident", t[1] + "__hs") if t[0] == "ident" and t[1] in statics else t
                for t in toks]
    return text_of(toks)


FNDEF = re.compile(r"#[ \t]*define[ \t]+(\w+)[ \t]*\([ \t]*(\w+)[ \t]*,[ \t]*(\w+)[ \t]*\)[ \t]*(__asm__|asm)[ \t]*\(")


def drop_fn_macros(text):
    """R6 for `#define FN(name, body) __asm__(...)`; MW accepts raw newlines
    inside that string literal."""
    pos = 0
    while True:
        m = FNDEF.search(text, pos)
        if not m:
            return text
        j = m.end()
        depth = 1
        while j < len(text) and depth:
            c = text[j]
            if c == '"':
                j += 1
                while j < len(text) and text[j] != '"':
                    j += 2 if text[j] == "\\" else 1
            elif c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            j += 1
        if j < len(text) and text[j] == ";":
            j += 1
        nl = text[m.start():j].count("\n")
        rep = (f"#define {m.group(1)}({m.group(2)}, {m.group(3)}) "
               f"PS2_TOPLEVEL_ASM_DROPPED({m.group(2)})")
        text = text[:m.start()] + rep + "\n" * nl + text[j:]
        pos = m.start() + len(rep)


def norm(toks):
    return re.sub(r"\s+", " ", text_of([t for t in toks if t[0] not in ("comment", "ws")
                                         or t[0] == "ws"])).strip()


def canon_args(toks):
    """Parameter list without parameter names, for prototype comparison."""
    parts = []
    for p in split_top([t for t in toks if t[0] not in ("ws", "comment")], ","):
        if len(p) >= 2 and p[-1][0] == "ident" and p[-2][0] in ("ident", "punct") \
                and p[-2][1] not in ("(", ","):
            if not (len(p) == 2 and p[0][1] in ("unsigned", "signed")):
                p = p[:-1]
        parts.append(" ".join(t[1] for t in p))
    s = ",".join(parts)
    return "void" if s == "" else s


STORAGE = {"extern", "static", "inline", "__inline", "__inline__"}


def parse_decl(seg):
    """Simple function declarator `[storage] RET NAME(ARGS)`; returns
    (ret_tokens, name, arg_tokens, storage_set) or None."""
    s = [t for t in seg if t[0] not in ("ws", "comment")]
    if len(s) < 4 or s[-1][1] != ")" or s[0][0] != "ident":
        return None
    if any(t[1] in ("__attribute__", "__asm__", "asm", "=") for t in s):
        return None
    storage = set()
    while s and s[0][1] in STORAGE:
        storage.add(s[0][1]); s = s[1:]
    if not s or s[0][1] in ("typedef", "return", "goto", "case", "else", "do"):
        return None
    depth = 0
    k = len(s) - 1
    while k >= 0:
        if s[k][1] == ")":
            depth += 1
        elif s[k][1] == "(":
            depth -= 1
            if depth == 0:
                break
        k -= 1
    if k < 1 or s[k - 1][0] != "ident":
        return None
    ret = s[:k - 1]
    if not ret or any(t[0] == "punct" and t[1] != "*" for t in ret) \
            or any(t[0] not in ("ident", "punct") for t in ret):
        return None
    if ret[0][1] in ("if", "while", "for", "switch", "return", "sizeof"):
        return None
    return (ret, s[k - 1][1], s[k + 1:-1], storage)


def join(toks):
    return " ".join(t[1] for t in toks)


CTYPES = {"void", "char", "short", "int", "long", "float", "double", "unsigned",
          "signed", "struct", "union", "enum", "const", "volatile", "long long"}


def looks_like_type(ret, typenames):
    """Block-level `T f(...);` without extern: accept only when T is a type,
    so a macro invocation followed by a call is not taken for a declaration."""
    return all(t[1] == "*" or t[1] in CTYPES or t[1] in typenames for t in ret) and \
        any(t[1] in CTYPES or t[1] in typenames for t in ret)


def rewrite_block_externs(toks):
    """R7."""
    typenames = set(re.findall(r"\b([us](?:8|16|32|64|128)|f32|f64)\b", text_of(toks)))
    typenames |= set(re.findall(r"typedef[^;]*?\b(\w+)\s*(?:\[[^;]*\])?;", text_of(toks)))
    decls = []   # (start, end, depth, path, ret, name, args, storage)
    defs = []
    br = Braces()
    stmt_start = 0
    for k, t in enumerate(toks):
        if t[0] == "pp":
            br.pp(t[1])
            stmt_start = k + 1
            continue
        if t[0] != "punct" or t[1] not in "{};":
            continue
        depth = br.depth
        seg = toks[stmt_start:k]
        if t[1] == ";":
            d = parse_decl(seg)
            if d and (depth == 0 or "extern" in d[3] or looks_like_type(d[0], typenames)):
                decls.append((stmt_start, k, depth, br.path()) + d)
        elif t[1] == "{" and depth == 0:
            d = parse_decl(seg)
            if d:
                defs.append((br.path(),) + d)
        br.punct(t[1])
        stmt_start = k + 1
    macros = set(re.findall(r"^[ \t]*#[ \t]*define[ \t]+(\w+)", text_of(toks), re.M))
    sigs, blocks, file_level, first_decl = {}, {}, set(), {}
    for (a, _, dep, path, ret, name, args, _) in decls:
        sigs.setdefault(name, []).append(((join(ret), canon_args(args)), path))
        first_decl[name] = min(first_decl.get(name, a), a)
        if dep > 0:
            blocks[name] = blocks.get(name, 0) + 1
            if re.search(r"\b(struct|union|enum)\b", join(args) + join(ret)):
                sigs[name].append((("tagged", str(a)), path))  # block-local tag types differ
        else:
            file_level.add(name)
    for (path, ret, name, args, _) in defs:
        sigs.setdefault(name, []).append(((join(ret), canon_args(args)), path))
        file_level.add(name)

    def conflict(lst):
        return any(x[0] != y[0] and paths_compatible(x[1], y[1])
                   for i, x in enumerate(lst) for y in lst[i + 1:])
    # a #define'd name is not a symbol: an asm-label alias to it would be wrong
    conflicted = {n for n, s in sigs.items() if n in blocks and n not in macros and conflict(s)}
    # implicit declaration (use before any declaration) + later block extern
    for k, t in enumerate(toks):
        if t[0] == "ident" and t[1] in blocks and t[1] not in file_level \
                and t[1] not in macros and k < first_decl[t[1]]:
            conflicted.add(t[1])
    if not conflicted:
        return toks, set()
    out = list(toks)
    aliases = set()
    for (a, b, dep, _, ret, name, args, _) in sorted(decls, key=lambda d: -d[0]):
        if dep > 0 and name in conflicted:
            r = join(ret)
            ar = join(args)
            nl = text_of(toks[a:b + 1]).count("\n")
            rep = (f"{r} (*const {name})({ar}) = ({r} (*)({ar}))ps2_alias_{name};"
                   f" /* host R7 */" + "\n" * nl)
            lead = 0
            while toks[a + lead][0] in ("ws", "comment"):
                lead += 1
            out[a + lead:b + 1] = [("punct", rep)]
            aliases.add(name)
    return out, aliases


def kr_head(seg):
    """`[storage] T f(a, b) <param decl>` -> parse_decl of the head part."""
    sig = [t for t in seg if t[0] not in ("ws", "comment")]
    for k, t in enumerate(sig):
        if t[1] == "(" and k > 0 and sig[k - 1][0] == "ident":
            e = match_close(sig, k, "(", ")")
            d = parse_decl(sig[:e + 1])
            if not d:
                return None
            args = [x for x in d[2]]
            if args and all(x[0] == "ident" or x[1] == "," for x in args):
                return d
            return None
        if t[1] in ("=", "{", ";"):
            return None
    return None


def file_scope_heads(toks):
    """File-scope declarations and function heads as (term, idx, decl):
    term is ';' or '{', idx the token indexes of the declaration and decl
    parse_decl()'s result.  Conditional branches restart from the statement
    text at their #if, and K&R heads `f(a, b) T a; T b; {` are recognised."""
    br = Braces()
    stmt, run = [], []        # current statement / ';'-ended segments before it
    saved = []                # per #if: [stmt, run, first-branch stmt/run]
    PPD = Braces.PPDIR
    for k, t in enumerate(toks):
        if t[0] == "pp":
            m = PPD.match(t[1])
            if m and br.depth == 0:
                d = m.group(1)
                if d.startswith("if"):
                    saved.append([list(stmt), list(run), None])
                elif saved and d in ("elif", "else"):
                    fr = saved[-1]
                    if fr[2] is None:
                        fr[2] = (list(stmt), list(run))
                    stmt, run = list(fr[0]), list(fr[1])
                elif saved and d == "endif":
                    fr = saved.pop()
                    if fr[2] is not None:
                        stmt, run = fr[2]
            elif m:
                pass
            br.pp(t[1])
            continue
        if t[0] == "punct" and t[1] in "{};":
            if br.depth == 0 and t[1] in "{;":
                seg = [toks[j] for j in stmt]
                d = parse_decl(seg)
                if d:
                    yield t[1], stmt, d
                elif t[1] == ";":
                    yield ";", stmt, None   # unparsed (e.g. `static T f _PARAMS((..));`)
                if not d and t[1] == "{" and run:
                    for seg_idx in reversed(run + [stmt]):  # K&R head
                        d = kr_head([toks[j] for j in seg_idx])
                        if d:
                            yield "{", seg_idx, d
                            break
                if t[1] == ";":
                    run.append(stmt)
                else:
                    run = []
            elif br.depth == 0:
                run = []
            br.punct(t[1])
            stmt = []
            if br.depth != 0:
                run = []
            continue
        if t[0] in ("ws", "comment") and not stmt:
            continue
        stmt.append(k)


def static_defs(toks):
    """R8: names of file-scope static function definitions."""
    return [d[1] for term, _, d in file_scope_heads(toks)
            if d and term == "{" and "static" in d[3]]


def export_owned(toks, names):
    """R9: drop `static` from file-scope declarations/definitions of `names`."""
    out = list(toks)
    for _, idx, d in file_scope_heads(toks):
        if d is not None and d[1] in names:
            hit = "static" in d[3]
        else:  # e.g. `static T name _PARAMS((...));` (parsed as a call of _PARAMS)
            sig = [toks[j][1] for j in idx if toks[j][0] == "ident"]
            hit = "static" in sig and "typedef" not in sig and any(n in names for n in sig) \
                and "=" not in [toks[j][1] for j in idx]
        if hit:
            for j in idx:
                if toks[j][0] == "ident" and toks[j][1] == "static":
                    out[j] = ("ws", "/*static*/")
    return out


_OWNERS = None


def owners():
    """function name -> credited source (config/matches.csv)."""
    global _OWNERS
    if _OWNERS is None:
        import csv
        from pathlib import Path
        root = Path(__file__).resolve().parents[2]
        with open(root / "config/matches.csv", newline="") as f:
            _OWNERS = {r["name"]: r["source"] for r in csv.DictReader(f)}
    return _OWNERS


def apply_overrides(text, path):
    from host_overrides import OVERRIDES
    for old, new in OVERRIDES.get(path, ()):
        if text.count(old) != 1:
            raise ValueError(f"host override for {path} no longer applies: {old!r}")
        text = text.replace(old, new)
    return text


def transform(text, path="?"):
    text = apply_overrides(text, path)
    text = drop_fn_macros(text)
    toks = lex(text)
    toks = rewrite_asm(toks)
    toks = rewrite_long(toks)
    toks, aliases = rewrite_block_externs(toks)
    statics = set(static_defs(toks)) if path.endswith(".c") else set()
    alias = dict(re.findall(r"^[ \t]*#[ \t]*define[ \t]+(\w+)[ \t]+(\w+)[ \t]*$", text, re.M))
    owned = {n for n in statics if owners().get(alias.get(n, n)) == path}
    if owned:  # R9: the credited copy is the program-wide definition
        toks = export_owned(toks, owned)
        statics -= owned
    if statics:  # R8: token-level rename inside this file only
        toks = [("ident", t[1] + "__hs") if t[0] == "ident" and t[1] in statics else t
                for t in toks]
    toks = [("pp", rewrite_pp(t[1], statics)) if t[0] == "pp" else t for t in toks]
    head = [f'extern void ps2_alias_{n}(void) __asm__("{n}");' for n in sorted(aliases)]
    pre = "\n".join(head) + "\n" if head else ""
    return pre + f'#line 1 "{path}"\n' + text_of(toks)


if __name__ == "__main__":
    src = sys.argv[1]
    data = open(src, encoding="latin-1").read()
    res = transform(data, src)
    if len(sys.argv) > 2:
        open(sys.argv[2], "w", encoding="latin-1").write(res)
    else:
        sys.stdout.write(res)
