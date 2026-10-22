# Working on this repository

Rules for any agent (or person) adding matches. CI cannot compile, so the
checks here are what keep `main` building.

## Before starting

- `git pull origin main`, then `make hybrid PYTHON="$PYTHON"`. Work from a
  tree that reproduces the retail ELF, not from a stale checkout or branch.
- Use the names in `config/symbol_addrs.txt` as they are on `main`. Names
  get corrected over time (for example `0x119BC0` is `dptoli`, not
  `dptoul`), and a source that only matches under an old name is wrong.

## Adding a function

1. Put the C in `src/`, add its row to `config/matches.csv`, and add its
   compile + verify stanza to `tools/compile_matching.sh` **before** the
   final `tools/compile_matching_data.sh` line.
2. MWCC does not search the including file's directory. A stanza whose
   source includes a project header needs `-i src`.
3. Every compiled object must be verified (`tools/verify_object.py`) and
   written by exactly one stanza.
4. Run `make progress-check PYTHON="$PYTHON"`. It runs
   `tools/check_build_script.py` (stanza structure, includes, duplicates,
   unverified objects, data labels), build coverage, and the source-credit
   audit.
5. Run `make hybrid PYTHON="$PYTHON"`. Push only if it ends with
   `exact retail ELF` and sha256 `48ebf907…6f13d7`.

`make match` runs the stanzas in parallel and caches compiles under
`build/cache/`, so a rebuild after a small change takes about a minute.
Every failure is listed at the end. `make match-serial` runs the script with
`sh` if you need to rule out the runner.

## Never

- Credit assembly as C: no `FN(...)` macro bodies, `.word` streams, empty
  asm barriers, or unused register-pinned locals. The audit rejects them.
- Commit the retail image, compilers (Metrowerks, SN, EE GCC, Sony), or SDK
  files. They stay in `private/`.
- Leave work only on a local branch for long. Rebase it onto `main`, run the
  steps above, and push to `main`.
