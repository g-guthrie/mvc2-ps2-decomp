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
  R11 alias     the TU that owns a credited data unit also defines every
                catalog name (symbol_addrs) that falls inside the unit, as a
                weak `unit + offset` alias (file-scope `.set`; wasm32 has no
                cross-object symbol+offset, so the alias must live in the
                unit's own object).  The TU that owns a credited function
                defines the function's other catalog names as weak
                `__attribute__((alias))`es.  Host runtime names (memcpy,
                __udivdi3, ...) and names the TU itself mentions are skipped.
  R15 varargs   the EE varargs walkers rebuild a pointer into the EE register
                save area by hand: `[(T *)]__builtin_next_arg(last) - K`.
                That whole expression becomes PS2_VA_START_HERE(last), a host
                va_start whose va_list (a plain pointer on i386 and wasm32)
                the game's own vfprintf reads with __builtin_va_arg.
  R12 sigs      (needs host_sigs.json, see configure()) one canonical
                prototype per function whose callers disagree with its
                definition: declarations replaced, calls given the callee's
                arity and argument classes (EE EABI: floats and ints are
                assigned to registers independently), void calls used as
                values become (f(), 0).
  R13 codeaddr  code addresses declared as data become ps2_code_F, an
                asm-label alias of the function.
  R14 return    `return 0;` where a non-void function falls off the end or
                says `return;` (sites from the raw build's diagnostics).
  R17 replaced  a credited function listed in port/host/host_impl.csv (the
                port implements it on the host): `#pragma weak name` at the
                top of its TU, so the port's strong definition wins at link
                time, and a `name__game` alias of the original body.
  R16 null      a symbol whose catalog address is 0 (func_00000000 in a
                callback table) is declared weak, so it stays undefined and
                its address is NULL on the host, as on the PS2.
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


def rewrite_block_externs(toks, statics=()):
    """R7.  Names with a file-scope static definition are skipped: a
    block-scope extern after it refers to the static (internal linkage)."""
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
    conflicted = {n for n, s in sigs.items() if n in blocks and n not in macros and conflict(s)
                  and n not in statics}
    # implicit declaration (use before any declaration) + later block extern
    for k, t in enumerate(toks):
        if t[0] == "ident" and t[1] in blocks and t[1] not in file_level \
                and t[1] not in macros and t[1] not in statics and k < first_decl[t[1]]:
            conflicted.add(t[1])
    if not conflicted:
        return toks, set()
    out = list(toks)
    aliases = set()
    for (a, b, dep, _, ret, name, args, _) in sorted(decls, key=lambda d: -d[0]):
        if dep > 0 and name in conflicted:
            r = join(ret)
            ar = join(args)
            lead = 0
            while toks[a + lead][0] in ("ws", "comment"):
                lead += 1
            nl = text_of(toks[a + lead:b + 1]).count("\n")   # keep line numbers
            rep = (f"{r} (*const {name})({ar}) = ({r} (*)({ar}))ps2_alias_{name};"
                   f" /* host R7 */" + "\n" * nl)
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


def defined_names(toks):
    """Names a TU defines at file scope (variables without `extern`, and
    function definitions).  Struct members and initializers are skipped."""
    out = set()
    br = Braces()
    stmt = []
    infunc = False

    def declarators(stmt):
        words = [x[1] for x in stmt if x[0] == "ident"]
        if not words or "typedef" in words or "extern" in words:
            return ()
        chunk, depth = [], 0
        for x in stmt:
            if x[1] in "([":
                depth += 1
            elif x[1] in ")]":
                depth -= 1
            if x[1] == "=" and depth == 0:
                break
            chunk.append(x)
        # a name directly followed by '(' is a function declarator (a
        # prototype, not a definition)
        return [x[1] for k, x in enumerate(chunk) if x[0] == "ident"
                and not (k + 1 < len(chunk) and chunk[k + 1][1] == "(")]

    for t in toks:
        if t[0] == "pp":
            br.pp(t[1])
            continue
        if t[0] in ("ws", "comment"):
            continue
        if t[0] == "punct" and t[1] in "{}":
            if t[1] == "{" and br.depth == 0:
                sig = [x for x in stmt]
                top_eq = any(x[1] == "=" for x in sig)
                if not top_eq and sig and (sig[-1][1] == ")" or sig[-1][1] == ";"):
                    for k in range(len(sig) - 1):   # function definition
                        if sig[k][0] == "ident" and sig[k + 1][1] == "(":
                            out.add(sig[k][1])
                            break
                    infunc = True
            br.punct(t[1])
            if br.depth == 0 and t[1] == "}" and infunc:
                infunc = False
                stmt = []
            continue
        if br.depth != 0:
            continue
        if t[1] == ";":
            out.update(declarators(stmt))
            stmt = []
            continue
        stmt.append(t)
    return out


def alias_tail(toks, path, statics):
    """R11: weak aliases for catalog names inside this TU's data units and
    for other names of the functions this TU is credited for."""
    import link_catalog as L
    ids = {t[1] for t in toks if t[0] == "ident"}
    defs = defined_names(toks)
    host = L.host_runtime_names()
    unit_names = {u[2] for u in L.data_units()}
    lines = []
    for u in L.units_by_source().get(path, ()):
        base = u[2] + "__hs" if u[2] in statics else u[2]
        if base not in defs:
            continue
        for name, off, size in L.unit_aliases().get(u[2], ()):
            if name in defs or name in host or name in unit_names:
                continue
            lines.append(f"PS2_DATA_ALIAS({name}, {base}, {off:#x}, {size:#x})")
    for f in owned_functions(path):
        if f not in ids:
            continue
        for alt in L.text_alt_names().get(f, ()):
            if alt in ids or alt in host:
                continue
            lines.append(f"PS2_TEXT_ALIAS({alt}, {f})")
    if not lines:
        return ""
    return "\n/* host R11: catalog aliases (port/tools/link_catalog.py) */\n" + "\n".join(lines) + "\n"


_OWNED = None


def owned_functions(path):
    """credited (`complete`, C) functions whose source is `path`."""
    global _OWNED
    if _OWNED is None:
        _OWNED = {}
        for n, r in owners_rows().items():
            if r["status"] == "complete" and r["source"].endswith(".c"):
                _OWNED.setdefault(r["source"], []).append(n)
    return _OWNED.get(path, ())


def _arg_regs(params):
    """EE EABI argument registers: ints in $a0-$a3,$t0-$t3, floats in $f12-$f19."""
    out, ni, nf = [], 0, 0
    for t in params:
        if t in ("float", "double"):
            out.append("f%d" % (12 + nf))
            nf += 1
        else:
            out.append("a%d" % ni)
            ni += 1
    return out


def _load_regpass():
    import csv
    from pathlib import Path
    f = Path(__file__).resolve().parent / "r12_regpass.csv"
    out = {}
    if f.exists():
        for r in csv.DictReader(open(f, newline="")):
            out[(r["source"], r["caller"], r["callee"], int(r["arg"]))] = int(r["caller_param"])
    return out


REGPASS = _load_regpass()


def _load_regexpr():
    """port/tools/r12_regexpr.csv: hand-checked R12 sites where the register
    held a caller local, not a parameter (the asm says which C variable)."""
    import csv
    from pathlib import Path
    f = Path(__file__).resolve().parent / "r12_regexpr.csv"
    out = {}
    if f.exists():
        for r in csv.DictReader(l for l in open(f, newline="") if not l.startswith("#")):
            out[(r["source"], r["caller"], r["callee"], int(r["arg"]))] = r["expr"]
    return out


REGEXPR = _load_regexpr()


def _pad_log(path, name, have, want, ks=None):
    """HOSTIFY_PAD_LOG=file: record R12 calls that get missing arguments as 0
    (the EE passed whatever the argument registers held); ks = the canonical
    indices padded (default have..want-1)."""
    import os
    f = os.environ.get("HOSTIFY_PAD_LOG")
    if f:
        ks = list(range(have, want)) if ks is None else ks
        with open(f, "a") as o:
            o.write(f"{path},{name},{have},{want},{';'.join(map(str, ks))}\n")


def hole_text(key):
    """The zero hole after layout unit `key` (link_catalog.data_holes) with
    aliases for the catalog names inside it."""
    import link_catalog as L
    lo, size, names = L.data_holes()[key]
    if size <= 0:
        return ""
    h = f"mvc2_hole_{lo:08X}"
    al = 512 if key is None else 1  # the image start: EE 0x00424200 is 512-aligned
    lines = [f'__attribute__((section(".data.ee_{lo:08X}.1"), aligned({al}))) unsigned char {h}[{size:#x}] = {{0}};']
    lines += [f"PS2_DATA_ALIAS({n}, {h}, {off:#x}, {sz:#x})" for n, off, sz in names]
    return "\n".join(lines) + "\n"


def section_units(toks, path):
    """R18: `__attribute__((section(".data.ee_<addr>.0")))` on the definition
    of each layout unit of this TU (before its `=` or `;`).  One section name
    for const and writable units alike: a named section is data on ELF and on
    wasm, so zero-initialised units do not drift into .bss."""
    import link_catalog as L
    units = {u[2]: u[0] for u in L.layout_units() if u[3] == path}
    out = list(toks)
    br = Braces()
    i = 0
    stmt_start = 0
    while i < len(out):
        t = out[i]
        if t[0] == "pp":
            br.pp(t[1])
        elif t[0] == "punct":
            if t[1] in "{}":
                br.punct(t[1])
            if t[1] in ";{}" and br.depth == 0:
                stmt_start = i + 1
        if t[0] == "ident" and t[1] in units and br.depth == 0:
            words = [x[1] for x in out[stmt_start:i] if x[0] == "ident"]
            if "extern" not in words and "typedef" not in words:
                # nesting of the declarator around the name: `void (*name)(...)`
                base = sum(1 if x[1] == "(" else -1 if x[1] == ")" else 0 for x in out[stmt_start:i])
                j, pd = i + 1, base
                while j < len(out):
                    x = out[j]
                    if x[1] in "([":
                        pd += 1
                    elif x[1] in ")]":
                        pd -= 1
                    elif pd == 0 and x[1] in ("=", ";", ","):
                        break
                    j += 1
                seg = text_of(out[i + 1:j])
                if "section(" not in seg:
                    # explicit alignment = the EE address's: wasm clang over-aligns
                    # arrays >= 16 bytes to 16 (preferred alignment) otherwise
                    a = units[t[1]]
                    al = min(a & -a, 16) if a else 16
                    out.insert(j, ("punct", f' __attribute__((section(".data.ee_{a:08X}.0"), aligned({al}))) '))
                del units[t[1]]
        i += 1
    return out


def data_layout(toks, path):
    """R18 layout: a data TU's unit goes to section .data.ee_<addr>.0x and the
    hole after it to .data.ee_<addr+size>.1, so the host link (sections
    sorted by name on ELF, objects in address order on wasm) lays the EE data
    image out contiguously (link_catalog.data_holes)."""
    import link_catalog as L
    lu = [u for u in L.layout_units() if u[3] == path]
    if not lu:
        return "", ""
    a = lu[0][0]
    pre = f"/* host R18: EE data layout, section .data.ee_{a:08X}.0 */\n"
    tail = '\n/* host R18: EE data layout */\n'
    defined = defined_names(toks)
    for u in lu:
        tail += f"_Static_assert(sizeof({u[2]}) == {u[1]:#x}, \"{u[2]}: host size differs from the EE\");\n" \
            if u[2] in defined else ""
    tail += hole_text(lu[-1][2])
    return pre, tail


FNDROP = re.compile(r"#[ \t]*define[ \t]+(\w+)[ \t]*\([^)]*\)[ \t]*PS2_TOPLEVEL_ASM_DROPPED")


def host_replaced(toks, path):
    """R17: credited functions of this TU that port/host/host_impl.csv replaces."""
    import link_catalog as L
    hi = L.host_impl()
    if not hi:
        return []
    ids = {t[1] for t in toks if t[0] == "ident"}
    pp = " ".join(t[1] for t in toks if t[0] == "pp")  # `#define name func_X` definitions
    # FN(name, body) assembly placeholders are dropped on the host (R6): no body to weaken
    fnm = {m.group(1) for t in toks if t[0] == "pp"
           for m in [FNDEF.search(t[1]) or FNDROP.search(t[1])] if m}
    sig = [t for t in toks if t[0] not in ("ws", "comment", "nl")]
    dropped = {sig[i + 2][1] for i in range(len(sig) - 2)
               if sig[i][1] in fnm and sig[i + 1][1] == "("}
    return sorted(n for n in hi if owners().get(n) == path and n not in dropped
                  and (n in ids or n in pp))


def owners_rows():
    import link_catalog as L
    return L.matches()


def _sig_list(toks):
    return [(n, x) for n, x in enumerate(toks) if x[0] not in ("ws", "comment")]


def _param_written(sig, i):
    """sig[i] is an identifier: is it written here (=, op=, ++/--, unary &)?"""
    nx = [sig[k][1][1] for k in range(i + 1, min(i + 4, len(sig)))]
    pv = [sig[k][1][1] for k in range(max(0, i - 2), i)]
    if i + 1 < len(sig) and sig[i + 1][1][0] == "punct":
        if nx[:1] == ["="] and nx[1:2] != ["="]:
            return True
        if len(nx) >= 2 and nx[0] in "+-*/%&|^" and nx[1] == "=":
            return True
        if len(nx) >= 3 and nx[0] == nx[1] and nx[0] in "<>" and nx[2] == "=":
            return True
        if len(nx) >= 2 and nx[0] == nx[1] and nx[0] in "+-":
            return True
    if len(pv) == 2 and pv[0] == pv[1] and pv[0] in ("+", "-"):
        return True
    if pv[-1:] == ["&"]:
        b = sig[i - 2][1] if i >= 2 else ("punct", "(")
        if b[0] == "punct" and b[1] not in (")", "]"):
            return True
    return False


UNCACHED = {"0x20000000", "0x30000000"}


def rewrite_uncached(toks):
    """R21: `(T *)(addr | 0x20000000)` (the EE's uncached / uncached-
    accelerated mirror of main RAM) is the same memory: on the host the OR
    makes a different (wasm: out of range) address, so it is dropped where
    the result is cast to a pointer."""
    sig = _sig_list(toks)
    drop = set()
    for s in range(1, len(sig) - 1):
        n, x = sig[s]
        if x[0] != "number" or x[1].lower() not in UNCACHED or sig[s - 1][1][1] != "|":
            continue
        if sig[s + 1][1][1] != ")":
            continue
        # the "(" that this ")" closes
        d, k = 0, s + 1
        while k >= 0:
            v = sig[k][1][1]
            if v == ")":
                d += 1
            elif v == "(":
                d -= 1
                if d == 0:
                    break
            k -= 1
        # preceded by a pointer cast `( ... * )`
        if k >= 2 and sig[k - 1][1][1] == ")" and sig[k - 2][1][1] == "*":
            drop.add(sig[s - 1][0])
            drop.add(n)
    if not drop:
        return toks
    return [x for i, x in enumerate(toks) if i not in drop]


def widen_definitions(toks, path):
    """R20: the definition of a function r12_widen.csv widens gets the extra
    parameters (`__rpN`) its canonical prototype now has, so R12 can pass
    them on where the body's calls miss them."""
    if SIGS is None:
        return toks
    canon = SIGS["canon"]
    sig = _sig_list(toks)
    depth = 0
    ins = {}
    for s in range(len(sig)):
        n, x = sig[s]
        if x[0] == "pp":
            continue
        if x[1] == "{":
            if depth == 0 and s >= 1 and sig[s - 1][1][1] == ")":
                d, k = 0, s - 1
                while k >= 0:
                    v = sig[k][1][1]
                    if v == ")":
                        d += 1
                    elif v == "(":
                        d -= 1
                        if d == 0:
                            break
                    k -= 1
                name = sig[k - 1][1][1] if k >= 1 and sig[k - 1][1][0] == "ident" else None
                c = canon.get(name or "")
                if c and "widened" in c and owners().get(name) == path:
                    inner = [sig[q][1][1] for q in range(k + 1, s - 1)]
                    have, dd = 0 if not inner or inner == ["void"] else 1, 0
                    for v in inner:
                        dd += v in "([" and 1 or v in ")]" and -1 or 0
                        have += 1 if (v == "," and dd == 0) else 0
                    extra = c["params"][have:]
                    txt = ", ".join(f"{ty} __rp{have + i}" for i, ty in enumerate(extra))
                    if have == 0:
                        ins[sig[k][0]] = ("open", txt, sig[s - 1][0])
                    else:
                        ins[sig[s - 1][0]] = ("close", ", " + txt, None)
            depth += 1
        elif x[1] == "}":
            depth -= 1
    if not ins:
        return toks
    out, skip_to = [], -1
    for i, x in enumerate(toks):
        if i <= skip_to:
            continue
        e = ins.get(i)
        if e and e[0] == "open":
            out.append(x)
            out += lex(e[1], pp=False)
            out.append(toks[e[2]])
            skip_to = e[2]
            continue
        if e and e[0] == "close":
            out += lex(e[1], pp=False)
        out.append(x)
    return out


def copy_written_params(toks):
    """R19 (i386 cdecl): a function that writes one of its parameters (the
    decomp idiom of parameters used as locals) writes into the caller's
    argument area; when the EE called it through a pointer with fewer
    arguments (dispatch tables) that area is the caller's own frame.  The
    written parameters become locals initialised from a renamed parameter."""
    sig = _sig_list(toks)
    depth = 0
    edits = []  # (token index, new text) replacements, (index, insert text after)
    s = 0
    while s < len(sig):
        n, x = sig[s]
        if x[0] == "pp":
            s += 1
            continue
        if x[1] == "{":
            if depth == 0 and s >= 1 and sig[s - 1][1][1] == ")":
                # find the matching "(" of the head
                d, k = 0, s - 1
                while k >= 0:
                    v = sig[k][1][1]
                    if v == ")":
                        d += 1
                    elif v == "(":
                        d -= 1
                        if d == 0:
                            break
                    k -= 1
                if k >= 1 and sig[k - 1][1][0] == "ident":
                    # body extent
                    d2, e = 0, s
                    while e < len(sig):
                        v = sig[e][1][1]
                        if v == "{":
                            d2 += 1
                        elif v == "}":
                            d2 -= 1
                            if d2 == 0:
                                break
                        e += 1
                    # parameters: split the head at top-level commas
                    params, cur, dd = [], [], 0
                    for q in range(k + 1, s - 1):
                        v = sig[q][1][1]
                        if v in "([":
                            dd += 1
                        elif v in ")]":
                            dd -= 1
                        if v == "," and dd == 0:
                            params.append(cur)
                            cur = []
                        else:
                            cur.append(q)
                    if cur:
                        params.append(cur)
                    decls = []
                    for pq in params:
                        ids = [q for q in pq if sig[q][1][0] == "ident"]
                        if not ids or any(sig[q][1][1] in ("[", "(", "...") for q in pq):
                            continue
                        nm = sig[ids[-1]][1][1]
                        if nm in ("void", "int", "char", "short", "long", "float", "double", "unsigned",
                                  "signed", "u8", "s8", "u16", "s16", "u32", "s32", "f32", "u64", "s64"):
                            continue
                        hit = any(sig[q][1][0] == "ident" and sig[q][1][1] == nm and _param_written(sig, q)
                                  and not (q + 1 < len(sig) and sig[q + 1][1][1] == "(")
                                  and not (q >= 1 and sig[q - 1][1][1] in (".", ">"))
                                  for q in range(s + 1, e))
                        if hit:
                            typ = "".join(sig[q][1][1] + " " for q in pq if q != ids[-1])
                            edits.append((sig[ids[-1]][0], nm + "__arg", None))
                            decls.append(f"{typ}{nm} = {nm}__arg; ")
                    if decls:
                        edits.append((n, None, " " + "".join(decls)))
            depth += 1
        elif x[1] == "}":
            depth -= 1
        s += 1
    if not edits:
        return toks
    rep = {i: r for i, r, a in edits if r is not None}
    ins = {i: a for i, r, a in edits if a is not None}
    out = []
    for i, x in enumerate(toks):
        out.append(("ident", rep[i]) if i in rep else x)
        if i in ins:
            out.append(("punct", ins[i]))
    return out


def rewrite_next_arg(toks):
    """R15."""
    out = []
    i = 0
    while i < len(toks):
        t = toks[i]
        if t[0] == "ident" and t[1] == "__builtin_next_arg":
            j = sig_next(toks, i)
            if j < len(toks) and toks[j][1] == "(":
                e = match_close(toks, j, "(", ")")
                arg = text_of(toks[j + 1:e]).strip()
                k = sig_next(toks, e)
                if k < len(toks) and toks[k][1] == "-":
                    m = sig_next(toks, k)
                    if m < len(toks) and toks[m][0] == "number":
                        e = m
                    elif m < len(toks) and toks[m][1] == "(":
                        e = match_close(toks, m, "(", ")")
                nl = text_of(toks[i:e + 1]).count("\n")
                out.append(("punct", f"PS2_VA_START_HERE({arg}) /* host R15 */" + "\n" * nl))
                i = e + 1
                continue
        out.append(t)
        i += 1
    return out


def null_tail(toks):
    """R16."""
    import link_catalog as L
    names = sorted({t[1] for t in toks if t[0] == "ident" and t[1].startswith(("func_", "D_"))
                    and L.ADDR_SUFFIX.search(t[1]) and L.address_of(t[1]) == 0})
    if not names:
        return ""
    return "/* host R16: address 0 on the PS2 -> weak, NULL on the host */\n" + \
        "".join(f"#pragma weak {n}\n" for n in names)


# ---------------------------------------------------------------- R12-R14
SPEC_WORDS = {"extern", "static", "inline", "__inline", "__inline__", "const", "volatile",
              "register", "unsigned", "signed", "struct", "union", "enum", "void", "char",
              "short", "int", "long", "float", "double", "_Bool", "long long"}
NOT_SPEC = {"return", "goto", "case", "else", "do", "if", "while", "for", "switch", "sizeof",
            "typedef", "default", "break", "continue"}


def proto_text(name, c, label=None):
    ps = list(c["params"])
    if c.get("variadic"):
        ptxt = ", ".join(ps + ["..."]) if ps else "..."
    else:
        ptxt = ", ".join(ps) or "void"
    asm = f' __asm__("{label}")' if label else ""
    return f"extern {c['ret']} {name}({ptxt}){asm};"


def decl_parts(seg):
    """Split a declaration statement (tokens before ';') into
    (spec_tokens, [declarator token lists]) or None if it is not a plain
    declaration.  Declarators keep their own leading '*'s."""
    sig = [t for t in seg if t[0] not in ("ws", "comment")]
    if not sig or sig[0][0] != "ident" or sig[0][1] in NOT_SPEC:
        return None
    depth = 0
    for t in sig:
        if t[1] in "([{":
            depth += 1
        elif t[1] in ")]}":
            depth -= 1
        elif depth == 0 and t[1] == "=":
            return None
        if t[1] in ("__attribute__", "__asm__", "asm", "typedef"):
            return None
    parts = split_top(sig, ",")
    first = parts[0]
    # specifiers: leading idents (keywords, typedef names, tags), then the
    # first declarator starts at the last ident before '(' / '[' / end,
    # including the '*'s before it.
    k = 0
    while k < len(first) and first[k][0] == "ident":
        k += 1
    # first[:k] are idents; the declarator name is the last of them unless
    # '*' or '(' follows
    if k < len(first) and first[k][1] == "*":
        spec = first[:k]
        decl0 = first[k:]
    else:
        if k == 0:
            return None
        spec = first[:k - 1]
        decl0 = first[k - 1:]
    if not spec:
        return None
    return spec, [decl0] + parts[1:]


def declarator_name(d):
    """(name, kind) of a simple declarator: kind 'func' for `*NAME(...)`,
    'array' for `*NAME[...]`, 'object' for `*NAME`; None otherwise."""
    j = 0
    while j < len(d) and d[j][1] == "*":
        j += 1
    if j >= len(d) or d[j][0] != "ident":
        return None
    name = d[j][1]
    rest = d[j + 1:]
    if not rest:
        return name, "object", d[:j]
    if rest[0][1] == "(" and match_close(rest, 0, "(", ")") == len(rest) - 1:
        return name, "func", d[:j]
    if rest[0][1] == "[" and all(t[1] != "(" for t in rest):
        return name, "array", d[:j]
    return None


def wclass(w):
    """MIPS EE EABI argument class: f32 travels in $f12-$f19, everything else
    (ints, pointers, 64-bit ints, soft-float doubles) in $a0-$a7/$t0-$t3."""
    return "f" if w == "f32" else "i"


def pp_head_split(text):
    """('#define NAME(params)', params, body) of a #define line."""
    m = re.match(r"(#\s*define\s+\w+)(\(([^)]*)\))?", text)
    if not m:
        return text, None, ""
    params = [x.strip() for x in m.group(3).split(",")] if m.group(2) else None
    return text[:m.end()], params, text[m.end():]


class SigRewriter:
    """R12 (canonical prototypes, call arguments, void-call values) and R13
    (code addresses declared as data) for one TU or header."""

    def __init__(self, path, skip, macros, toks):
        self.path = path
        self.is_header = path.endswith(".h")
        self.canon = SIGS["canon"]
        self.skip = set(skip) | set(SIGS.get("defines", {}).get(path, ())) | macros
        self.wrap = set(SIGS["wrap"].get(path, ()))
        self.imports = SIGS.get("imports", {}).get(path, {})
        self.dcode = {n: f for n, f in SIGS["data_code"].get(path, {}).items() if n not in self.skip}
        self.code_repl = {}     # data name -> (elem type text, kind, function)
        self.used_code = set()
        self.removed = set()
        self.mentioned = set()
        self.R = _rewrite_set()
        self.alias = {a: n for a, n in alias_macros(toks).items()
                      if n in self.canon and n not in self.skip}
        r7 = rewrite_block_externs(toks, skip)[1]
        self.R = self.R | {n for n in r7 if n in self.canon}
        self.callee_macros = {}   # macro -> (params, {called param index})
        self.macro_callees = set()
        self.callee_args = set()
        self.find_callee_macros(toks)
        self.R = self.R | self.macro_callees

    def target(self, n):
        n = self.alias.get(n, n)
        return n in self.R and n in self.canon and n not in self.skip

    # -- function-like macros that call one of their parameters
    def find_callee_macros(self, toks):
        cand = {}
        for t in toks:
            if t[0] != "pp":
                continue
            head, params, body = pp_head_split(t[1])
            if not params:
                continue
            b = [x for x in lex(body, pp=False) if x[0] not in ("ws", "comment")]
            inside, outside = set(), set()
            depth = 0
            for k, x in enumerate(b):
                if x[1] == "{":
                    depth += 1
                elif x[1] == "}":
                    depth -= 1
                if x[0] == "ident" and x[1] in params and k + 1 < len(b) and b[k + 1][1] == "(":
                    e = match_close(b, k + 1, "(", ")")
                    if e + 1 < len(b) and b[e + 1][1] == "{":
                        continue                     # defines the function
                    (inside if depth > 0 else outside).add(params.index(x[1]))
            if inside or outside:
                m = re.match(r"#\s*define\s+(\w+)", t[1])
                cand[m.group(1)] = (params, inside, outside)
        if not cand:
            return
        # a call at the macro body's top level is a call only where the
        # macro is used inside a function (`_DEFUN(name, ...)` at file scope
        # is a definition head)
        br = Braces()
        sig = []
        for x in toks:
            if x[0] == "pp":
                br.pp(x[1])
                continue
            if x[0] == "punct":
                br.punct(x[1])
            if x[0] not in ("ws", "comment"):
                sig.append((x, br.depth))
        uses = []
        for k, (x, d) in enumerate(sig):
            if x[0] == "ident" and x[1] in cand and k + 1 < len(sig) and sig[k + 1][0][1] == "(":
                uses.append((k, x[1], d))
        for k, m, d in uses:
            params, inside, outside = cand[m]
            if d == 0 and not inside:
                continue
            called = inside | (outside if d > 0 else set())
            self.callee_macros.setdefault(m, (params, set()))[1].update(called)
            toks_only = [y for y, _ in sig]
            e = match_close(toks_only, k + 1, "(", ")")
            args = split_top(toks_only[k + 2:e], ",")
            for q in called:
                if q < len(args) and len(args[q]) == 1 and args[q][0][0] == "ident":
                    n = args[q][0][1]
                    self.callee_args.add(n)
                    if n in self.canon and n not in self.skip:
                        self.macro_callees.add(n)
        # a macro whose top-level parameter call is only ever a definition
        # head keeps its body unchanged
        for m in list(self.callee_macros):
            if not self.callee_macros[m][1]:
                del self.callee_macros[m]

    # -- declarations
    def rewrite_decls(self, toks, in_pp=False, params=()):
        out = list(toks)
        br = Braces()
        stmt_start = 0
        edits = []
        for k, t in enumerate(toks):
            if t[0] == "pp":
                br.pp(t[1])
                stmt_start = k + 1
                continue
            if t[0] != "punct" or t[1] not in "{};":
                continue
            if t[1] == ";":
                seg = toks[stmt_start:k]
                e = self.decl_edit(seg, params)
                if e is not None:
                    edits.append((stmt_start, k, e))
            br.punct(t[1])
            stmt_start = k + 1
        for a, b, rep in reversed(edits):
            lead = 0
            while toks[a + lead][0] in ("ws", "comment"):
                lead += 1
            nl = text_of(toks[a + lead:b + 1]).count("\n")
            if in_pp:
                rep = rep.replace("\n", " ")
            # keep a real ';' token so later passes (R7) still see the
            # statement boundary
            body = rep.rstrip()
            nlt = ("ws", ("\\\n" if in_pp else "\n") * nl)
            if body.endswith("#endif"):
                out[a + lead:b + 1] = [("punct", body + "\n"), nlt]
                continue
            if body.endswith(";"):
                body = body[:-1]
            out[a + lead:b + 1] = [("punct", body), ("punct", ";"), nlt]
        return out

    def decl_edit(self, seg, params=()):
        dp = decl_parts(seg)
        if not dp:
            return None
        spec, decls = dp
        keep, changed, header_canon = [], False, []
        for d in decls:
            dn = declarator_name([t for t in d if t[0] not in ("ws", "comment")])
            if dn is None:
                keep.append(d)
                continue
            name, kind, stars = dn
            if kind == "func" and name in params:
                changed = True       # a called macro parameter: the caller's prototype goes
                continue
            if kind == "func" and self.target(name):
                changed = True
                name = self.alias.get(name, name)
                self.removed.add(name)
                header_canon.append(name)
                sw = [t[1] for t in spec if t[1] not in ("extern", "static", "inline", "const")]
                if (sw != ["void"] or stars) and self.canon[name]["ret"] == "void":
                    self.wrap.add(name)
                continue
            if kind in ("array", "object") and name in self.dcode and not self.is_header:
                f = self.dcode[name]
                elem = " ".join(t[1] for t in spec if t[1] not in ("extern", "static")) + \
                    " " + "".join("*" for _ in stars)
                self.code_repl[name] = (elem.strip(), kind, f)
                changed = True
                continue
            keep.append(d)
        if not changed:
            return None
        rep = ""
        if keep:
            rep = " ".join(t[1] for t in spec) + " " + ", ".join(text_of(d).strip() for d in keep) + ";"
        if self.is_header and header_canon:
            orig = text_of(seg).strip() + ";"
            for n in header_canon:
                rep += (f"\n#ifndef PS2_DEF_{n}\n{proto_text(n, self.canon[n])}"
                        f" /* host R12 */\n#else\n{orig}\n#endif\n")
            return rep
        return (rep + " /* host R12/R13 */") if rep else "/* host R12/R13: declaration replaced */"

    # -- arguments of one call
    def call_args(self, name, a_txt):
        c = self.canon[name]
        cw, _ = _parse_wsig(c["wasm"])
        m = len(c["params"])
        cw = cw[:m]
        pre = []
        imp = self.imports.get(name)
        iw = _parse_wsig(imp)[0] if imp else None
        if iw is not None and len(iw) == len(a_txt) and \
                [wclass(x) for x in iw[:m]] != [wclass(x) for x in cw]:
            # caller and callee disagree on which arguments are floats: pass
            # them as the EE did, ints in order to int parameters, floats in
            # order to float parameters
            pools = {"i": [], "f": []}
            for w, x in zip(iw, a_txt):
                pools[wclass(w)].append(x)
            new = []
            for k, w in enumerate(cw):
                pool = pools[wclass(w)]
                if not pool:
                    _pad_log(self.path, name, len(a_txt), m, [k])
                new.append(pool.pop(0) if pool else self.regpass(name, k))
            rest = pools["i"] + pools["f"]
            if c.get("variadic"):
                new += rest
            else:
                pre = rest
            a_txt = new
        else:
            if name in self.imports:
                for q, ct in enumerate(c["params"][:len(a_txt)]):
                    conv = ("PS2_TO_PTR" if ct.endswith("*") else "PS2_TO_F32" if ct == "float"
                            else "PS2_TO_F64" if ct == "double" else None)
                    if conv and a_txt[q].strip():
                        a_txt[q] = f"{conv}({a_txt[q]})"
            if len(a_txt) < m:
                _pad_log(self.path, name, len(a_txt), m)
                a_txt = a_txt + [self.regpass(name, k) for k in range(len(a_txt), m)]
            elif len(a_txt) > m and not c.get("variadic"):
                pre = a_txt[m:]
                a_txt = a_txt[:m]
        return a_txt, pre

    def regpass(self, name, k):
        """R12 missing argument k of a call to `name`: the EE passed what the
        argument register held.  When that is the caller's own parameter
        (dataflow over the asm, port/tools/r12_regpass.csv) pass it; else 0."""
        cp = REGPASS.get((self.path, getattr(self, "cur_fn", None), name, k))
        params = getattr(self, "cur_params", [])
        ex = REGEXPR.get((self.path, getattr(self, "cur_fn", None), name, k))
        if ex is not None:
            ct = self.canon[name]["params"][k]
            return f"PS2_TO_PTR({ex})" if ct.endswith("*") else f"(({ct})({ex}))"
        if cp is None:
            # the decomp idiom `f(a0, a1, a2) { ... a2 = buf; ... g(x, y); }`: the C
            # assigns the caller's parameter that lives in the register the callee
            # reads, so the EE passed that variable
            fc = self.canon.get(getattr(self, "cur_fn", None) or "")
            if fc:
                r = _arg_regs(self.canon[name]["params"])[k]
                fr = _arg_regs(fc["params"])
                if r in fr:
                    q = fr.index(r)
                    if q < len(params) and params[q] in getattr(self, "cur_assigned", ()):
                        cp = q
        if cp is None or cp >= len(params) or not params[cp]:
            return "0"
        ct = self.canon[name]["params"][k]
        if ct.endswith("*"):
            return f"PS2_TO_PTR({params[cp]})"
        return f"(({ct})({params[cp]}))"

    # -- calls and data-declared code addresses
    def rewrite_uses(self, toks, in_pp=False):
        self._nest = getattr(self, "_nest", 0) + 1
        try:
            return self._rewrite_uses(toks, in_pp)
        finally:
            self._nest -= 1

    def _head_params(self, stmt):
        """(function name, parameter names) of a definition head at depth 0."""
        k = next((n for n, x in enumerate(stmt) if x[1] == "("), None)
        if k is None or k == 0 or stmt[k - 1][0] != "ident":
            return None, []
        e = match_close(stmt, k, "(", ")")
        names = []
        for a in split_top(stmt[k + 1:e], ","):
            ids = [x[1] for x in a if x[0] == "ident"]
            if ids and ids[-1] not in ("void", "int", "char", "short", "long", "float", "double",
                                       "unsigned", "signed", "u8", "s8", "u16", "s16", "u32", "s32", "f32"):
                names.append(ids[-1])
            elif ids:
                names.append(None)
        return stmt[k - 1][1], names

    def _rewrite_uses(self, toks, in_pp=False):
        out = []
        i = 0
        func_void = False
        br = Braces()
        stmt = []
        while i < len(toks):
            t = toks[i]
            if t[0] == "pp":
                br.pp(t[1])
            elif t[0] == "punct":
                if t[1] == "{" and br.depth == 0:
                    words = [x[1] for x in stmt if x[0] == "ident"]
                    w = [x for x in words if x not in ("static", "extern", "inline", "__inline", "__inline__")]
                    func_void = bool(w) and w[0] == "void" and not any(x[1] == "*" for x in stmt[:3])
                    if self._nest == 1:
                        self.cur_fn, self.cur_params = self._head_params(stmt)
                        e = match_close(toks, i, "{", "}")
                        body = [x for x in toks[i:e] if x[0] not in ("ws", "comment")]
                        self.cur_assigned = {body[q][1] for q in range(len(body) - 1)
                                             if body[q][0] == "ident" and body[q + 1][1] == "="}
                if t[1] in "{};":
                    stmt = []
                br.punct(t[1])
            if t[0] not in ("ws", "comment", "pp") and br.depth == 0:
                stmt.append(t)
            if t[0] == "ident" and t[1] in self.code_repl:
                p = sig_prev(out, len(out))
                elem, kind, f = self.code_repl[t[1]]
                self.used_code.add(f)
                fp = f"ps2_code_{f}"
                if p >= 0 and out[p][1] == "&":
                    out[p] = ("punct", f"((void *){fp})")
                    i += 1
                    continue
                if kind == "array":
                    out.append(("punct", f"(({elem} *)(void *){fp})"))
                else:
                    out.append(("punct", f"(*({elem} *)(void *){fp})"))
                i += 1
                continue
            if t[0] == "ident" and self.target(t[1]):
                if t[1] in self.alias:
                    t = ("ident", self.alias[t[1]])
                self.mentioned.add(t[1])
                j = sig_next(toks, i)
                p = sig_prev(toks, i)
                if j < len(toks) and toks[j][1] == "(" and not (p >= 0 and toks[p][1] in (".", "->")):
                    e = match_close(toks, j, "(", ")")
                    inner = toks[j + 1:e]
                    args = split_top(inner, ",")
                    if len(args) == 1 and not text_of(args[0]).strip():
                        args = []
                    inner_new = self.rewrite_uses(inner, in_pp)
                    args_new = split_top(inner_new, ",") if args else []
                    c = self.canon[t[1]]
                    a_txt, pre = self.call_args(t[1], [text_of(a) for a in args_new])
                    pre_txt = "".join(f"(void)({x}), " for x in pre)
                    call = f"{t[1]}({','.join(a_txt)})"
                    nl = text_of(toks[i:e + 1]).count("\n")
                    prev_ret = p >= 0 and toks[p][1] == "return"
                    need_val = t[1] in self.wrap and c["ret"] == "void" and not (prev_ret and func_void)
                    if need_val:
                        call = f"({pre_txt}{call}, 0)"
                    elif pre_txt:
                        call = f"({pre_txt}{call})"
                    out.append(("punct", call + ("\\\n" if in_pp else "\n") * nl))
                    i = e + 1
                    continue
            out.append(t)
            i += 1
        return out

    def rewrite_pp(self, text):
        if not re.match(r"#\s*define\b", text):
            return text
        head, params, body = pp_head_split(text)
        t = lex(body, pp=False)
        name = re.match(r"#\s*define\s+(\w+)", text).group(1)
        called = ()
        if name in self.callee_macros:
            ps, idx = self.callee_macros[name]
            called = [ps[q] for q in idx]
        if not self.is_header:
            t = self.rewrite_decls(t, in_pp=True, params=called)
        t = self.rewrite_uses(t, in_pp=True)
        if called:   # route calls of a callee parameter through PS2_CALL_<name>
            sig = [k for k, x in enumerate(t) if x[0] not in ("ws", "comment")]
            for a, b in zip(sig, sig[1:]):
                if t[a][0] == "ident" and t[a][1] in called and t[b][1] == "(":
                    t[a] = ("ident", f"PS2_CALL_##{t[a][1]}")
        return head + text_of(t)

    def callee_defines(self):
        """`#define PS2_CALL_<f>(...)` for every function passed to a macro
        parameter the macro calls: the call with this TU's argument
        convention mapped onto the canonical prototype."""
        lines = [f"#define PS2_CALL_{n} {n}" for n in sorted(self.callee_args - self.macro_callees)]
        for n in sorted(self.macro_callees):
            imp = self.imports.get(n)
            c = self.canon.get(n, {})
            if imp is None and "widened" in c:  # R20: the TU passes the old count
                pad = ", ".join("0" for _ in c["params"][c["widened"]:])
                lines.append(f"#define PS2_CALL_{n}(...) {n}(__VA_ARGS__, {pad})")
                continue
            if imp is None:
                lines.append(f"#define PS2_CALL_{n} {n}")
                continue
            iw = _parse_wsig(imp)[0]
            names = [f"ps2_a{k}" for k in range(len(iw))]
            a_txt, pre = self.call_args(n, list(names))
            pre_txt = "".join(f"(void)({x}), " for x in pre)
            body = f"{n}({', '.join(a_txt)})"
            if n in self.wrap or (self.canon[n]["ret"] == "void" and _parse_wsig(imp)[1] != "void"):
                body = f"({pre_txt}{body}, 0)"
            elif pre_txt:
                body = f"({pre_txt}{body})"
            lines.append(f"#define PS2_CALL_{n}({', '.join(names)}) {body}")
        return lines

    def prelude(self, toks):
        ids = {t[1] for t in toks if t[0] == "ident"} | self.mentioned | self.removed | self.macro_callees
        for t in toks:
            if t[0] == "pp" and re.match(r"#\s*define\b", t[1]):
                ids.update(IDENT.findall(t[1]))
        lines = []
        if not self.is_header:
            for n in sorted({self.alias.get(x, x) for x in ids}):
                if self.target(n):
                    lines.append(proto_text(n, self.canon[n]))
            lines += self.callee_defines()
        for f in sorted(self.used_code):
            lines.append(proto_text(f"ps2_code_{f}", self.canon[f], label=f))
        if not self.is_header:
            for n in SIGS.get("implicit", {}).get(self.path, ()):
                c = self.canon.get(n)
                if c and n in self.skip and not c["ret"].endswith("*"):
                    # used before its own definition in this TU: the implicit
                    # `int n()` made explicit, with the definition's return type
                    lines.append(f"extern {c['ret']} {n}();")
        if lines:
            lines.insert(0, "/* host R12/R13: canonical prototypes (host_sigs.json) */")
        return lines


def _parse_wsig(s):
    p, r = s[1:].split(")->")
    return [x for x in p.split(",") if x], r


_RSET = None


def _rewrite_set():
    global _RSET
    if _RSET is None or _RSET[0] is not SIGS:
        _RSET = (SIGS, set(SIGS["rewrite"]))
    return _RSET[1]


_HDR_DECL = None


def header_declared():
    """function names some project header declares (for PS2_DEF_ guards)."""
    global _HDR_DECL
    if _HDR_DECL is None:
        from pathlib import Path
        root = Path(__file__).resolve().parents[2]
        s = set()
        for d in ("src", "src/data"):
            for h in (root / d).glob("*.h"):
                s.update(re.findall(r"\b(\w+_[0-9A-Fa-f]{8})\s*\(", h.read_text(encoding="latin-1")))
        _HDR_DECL = s
    return _HDR_DECL


def alias_macros(toks):
    """`#define A B` object-like aliases: {A: B}."""
    out = {}
    for t in toks:
        if t[0] == "pp":
            m = re.match(r"#\s*define\s+(\w+)\s+(\w+)\s*$", t[1])
            if m:
                out[m.group(1)] = m.group(2)
    return out


def macro_skips(toks):
    """Names a TU defines through a function-generating macro
    (`#define STEP(name, ...) void name(u8 *p) { ... }` + `STEP(func_X, ...)`)
    and names reached through an alias macro (`#define memset func_0011D8F8`):
    R12 leaves those to the TU's own declarations."""
    fmacros = {}
    skip = set()
    for t in toks:
        if t[0] != "pp":
            continue
        m = re.match(r"#\s*define\s+(\w+)\(([^)]*)\)(.*)$", t[1], re.S)
        if not m:
            continue
        params = [x.strip() for x in m.group(2).split(",")]
        body = [x for x in lex(m.group(3), pp=False) if x[0] not in ("ws", "comment")]
        pos = set()
        for k, x in enumerate(body):
            if x[0] == "ident" and k + 1 < len(body) and body[k + 1][1] == "(":
                e = match_close(body, k + 1, "(", ")")
                if e + 1 < len(body) and body[e + 1][1] == "{":
                    if x[1] in params:
                        pos.add(params.index(x[1]))
                    else:
                        skip.add(x[1])
        if pos:
            fmacros[m.group(1)] = pos
    if fmacros:
        sig = [x for x in toks if x[0] not in ("ws", "comment")]
        for k, x in enumerate(sig):
            if x[0] == "ident" and x[1] in fmacros and k + 1 < len(sig) and sig[k + 1][1] == "(":
                e = match_close(sig, k + 1, "(", ")")
                args = split_top(sig[k + 2:e], ",")
                for q in fmacros[x[1]]:
                    if q < len(args):
                        skip.update(a[1] for a in args[q] if a[0] == "ident")
    return skip


def add_returns(toks, path):
    """R14: `return 0;` before the closing brace of each non-void function
    that the raw build reported as falling off the end, and `return;` in a
    non-void function becomes `return 0;`."""
    lines = set(SIGS["noreturn"].get(path, ())) if SIGS else set()
    bare = set(SIGS.get("bare_return", {}).get(path, ())) if SIGS else set()
    if not lines and not bare:
        return toks
    out = []
    line = 1
    br = Braces()
    for k, t in enumerate(toks):
        if t[0] == "pp":
            br.pp(t[1])
        if t[0] == "punct" and t[1] == "}" and br.depth == 1 and line in lines:
            out.append(("punct", " return 0; /* host R14 */ "))
        if t[0] == "ident" and t[1] == "return" and line in bare:
            j = sig_next(toks, k)
            if j < len(toks) and toks[j][1] == ";":
                out.append(("punct", "return 0 /* host R14 */"))
                line += t[1].count("\n")
                continue
        if t[0] == "punct":
            br.punct(t[1])
        out.append(t)
        line += t[1].count("\n")
    return out


SIGS = None   # host_sigs.json contents (R12-R14); None = rules off


def configure(sigs_path=None):
    """Load host_sigs.json (gen_link_glue.py sigs) for R12-R14."""
    global SIGS
    import json
    import os
    sigs_path = sigs_path or os.environ.get("MVC2_HOST_SIGS")
    SIGS = json.load(open(sigs_path)) if sigs_path else None
    if SIGS is not None:
        import link_catalog as L
        L.apply_host_sig_overrides(SIGS["canon"])
        # every declaration of an overridden function must take the new type
        over = [n for n, r in L.host_impl().items() if (r.get("ret") or "").strip()]
        wid = [n for n, c in SIGS["canon"].items() if "widened" in c]
        SIGS["rewrite"] = sorted(set(SIGS["rewrite"]) | set(over) | set(wid))
        for n in over:  # callers that use the value now get it (no (f(), 0) wrap)
            for v in SIGS["wrap"].values():
                if n in v:
                    v.remove(n)


def transform(text, path="?"):
    text = apply_overrides(text, path)
    text = drop_fn_macros(text)
    toks = lex(text)
    toks = add_returns(toks, path)
    toks = rewrite_asm(toks)
    toks = rewrite_long(toks)
    toks = rewrite_next_arg(toks)
    toks = rewrite_uncached(toks)  # R21
    if path.endswith(".c"):
        toks = widen_definitions(toks, path)  # R20
    statics = set(static_defs(toks)) if path.endswith(".c") else set()
    sr = None
    if SIGS is not None:
        macros = set(re.findall(r"^[ \t]*#[ \t]*define[ \t]+(\w+)", text, re.M))
        sr = SigRewriter(path, statics | defined_names(toks) | macro_skips(toks), macros, toks)
        toks = sr.rewrite_decls(toks)
        toks = sr.rewrite_uses(toks)
        toks = [("pp", sr.rewrite_pp(t[1])) if t[0] == "pp" else t for t in toks]
    toks, aliases = rewrite_block_externs(toks, statics)
    alias = dict(re.findall(r"^[ \t]*#[ \t]*define[ \t]+(\w+)[ \t]+(\w+)[ \t]*$", text, re.M))
    owned = {n for n in statics if owners().get(alias.get(n, n)) == path}
    if owned:  # R9: the credited copy is the program-wide definition
        toks = export_owned(toks, owned)
        statics -= owned
    if statics:  # R8: token-level rename inside this file only
        toks = [("ident", t[1] + "__hs") if t[0] == "ident" and t[1] in statics else t
                for t in toks]
    toks = [("pp", rewrite_pp(t[1], statics)) if t[0] == "pp" else t for t in toks]
    toks = copy_written_params(toks)  # R19
    head = [f'extern void ps2_alias_{n}(void) __asm__("{n}");' for n in sorted(aliases)]
    if sr is not None:
        head = sr.prelude(toks) + head
        if not sr.is_header:
            hd = header_declared()
            head = [f"#define PS2_DEF_{n} 1" for n in sorted(defined_names(toks))
                    if n in hd and n in sr.R] + head
    lay_pre, lay_tail = data_layout(toks, path) if path.endswith(".c") else ("", "")
    # R17 only in the real build: the raw build (no SIGS) must see the original
    # definitions, it is where host_sigs.json learns the canonical prototypes
    weak = host_replaced(toks, path) if path.endswith(".c") and SIGS is not None else []
    # a replacement whose return type differs (host_impl.csv `ret`) cannot be
    # a weak twin on wasm (signature mismatch): the original is renamed
    import link_catalog as L
    renamed = [n for n in weak if (L.host_impl()[n].get("ret") or "").strip()]
    weak = [n for n in weak if n not in renamed]
    head = [f"#pragma weak {n}" for n in weak] + head
    pre_ren = "".join(f"#define {n} {n}__game\n" for n in renamed)
    pre = "\n".join(head) + "\n" if head else ""
    tail = alias_tail(toks, path, statics) if path.endswith(".c") else ""
    if weak:  # R17: the original stays callable as name__game
        tail += "\n/* host R17: replaced by port/host (port/host/host_impl.csv) */\n" + "".join(
            f'extern __typeof__({n}) {n}__game __attribute__((alias("{n}")));\n' for n in weak)
    pre += null_tail(toks) if path.endswith(".c") else ""
    if lay_pre:
        toks = section_units(toks, path)
    body = text_of(toks)
    if lay_pre:  # R18: an explicit data section in a layout TU would escape the layout
        sec = lay_pre.split()[-2]
        a = int(sec.split("_")[1].split(".")[0], 16)
        al = min(a & -a, 16) if a else 16
        body = re.sub(r'section\(\s*"\.s?(?:data|bss|rodata)[^"]*"\s*\)', f'section("{sec}"), aligned({al})', body)
    return lay_pre + pre + pre_ren + f'#line 1 "{path}"\n' + body + tail + lay_tail


if __name__ == "__main__":
    src = sys.argv[1]
    data = open(src, encoding="latin-1").read()
    res = transform(data, src)
    if len(sys.argv) > 2:
        open(sys.argv[2], "w", encoding="latin-1").write(res)
    else:
        sys.stdout.write(res)
