# Recovery workflow

The objective remains every main-image byte reproduced from C. These tools
choose and bound work; they do not establish matching or change ROM acceptance.

## Start with a fresh plan

After a successful current-input check:

```sh
python3 tools/recovery.py plan --owners worker-1,worker-2,worker-3
python3 tools/recovery.py snapshot build/recovery-baseline.json
```

`build/recovery_plan.json` includes existing candidates and complete, unowned
reviewed spans from the existing native boundary tool. Spans outside the default
64–4096-byte window are counted explicitly; increase `--max-span` when needed.
Unknown/unreviewed bytes are never silently converted into tasks with proven
boundaries. SDK spans are routed to SDK placement/feasibility review first.

Ranking favors potential new executable bytes per estimated hour, rather than
fewest unequal bytes. The estimate is a disclosed heuristic, not a measured
speedup. Whole-unit C completion value is separately recorded and breaks ties;
promoting previously matching fragments and finding new matching bytes are not
the same metric. Supply a grounded effort estimate with `record` as work teaches
us more. Source-pattern family hits, current behavioral results, and callback
entry witnesses are attached as evidence or review leads, not acceptance facts.

The proposed batch selects disjoint whole spans with a shared source-pattern
family or native address region. Region proximity does not prove related
semantics. One integrator owns registry changes, shared headers, and the full
build; workers receive explicit file/span ownership and return native proof.
If no coherent disjoint companions exist, work the single unit rather than
padding the batch. Do not let workers independently rewrite shared declarations.

## Record a hypothesis and stop repeating it

```sh
python3 tools/permute.py src/candidates/UNIT.c \
  --hypothesis 'Describe the specific native discrepancy and proposed source shape'
```

The default limit is ten compiled variants and twenty minutes. Structural
mismatches retain the existing stricter admission checks. Trials use private C
copies; interruption leaves the source intact. Publication rejects changed
source/compiler/fact inputs. Only an actually compiled improvement is written
back, and exact results still require normal registration and full comparison.

Failed, non-improving trials are remembered in `build/recovery/`, bound to their
starting source, compiler, headers, native facts, unit descriptor, and host.
They are optimization hints only, never cached acceptance. Improving variants
and transient compiler failures are not negative-cached.

Experiment summaries append to `config/recovery.jsonl`. Native investigation
can record a concrete result without running permutations:

```sh
python3 tools/recovery.py record UNIT --hypothesis 'Question investigated' \
  --outcome evidence --minutes 8 --attempts 1 \
  --evidence 'Native address, pointer-table cell, or checked type contract' \
  --next-action 'Specific next experiment' --effort-minutes 30
```

A stalled unchanged input is parked. A changed source/compiler/fact context or
an explicit `--new-evidence` statement permits reconsideration. That statement
must identify an actual new observation, not merely a wish to keep trying.
Inconclusive tool failures remain retryable. Keep committed journal summaries
small and useful; generated variant cache files stay outside Git.

## Reuse facts, patterns, and selective tests

- `python3 tools/shared_facts.py --callbacks` shows established layout/prototype
  claims and their textual consumers, plus native callback-table leads. Review
  each lead before changing a boundary. Width and record-size contracts use SHC,
  alongside existing offsets and declarations.
- `python3 tools/compiler_patterns.py --verified-sources` recompiles positive compiler examples
  and negative controls. The source catalog points to other candidate families.
- `python3 tools/twins.py START SIZE --register-renaming` expands discovery with
  consistent register substitutions. Fixed ABI roles and supported instruction
  dependencies are preserved. Constants can differ; no normalized match earns
  byte-match credit or changes the existing cloning/admission path.
- `python3 tools/diagnose.py SOURCE` attaches behavioral evidence only while its
  source, compiler, headers, descriptor, native image and selected cases remain
  current. A pass covers only those tested paths. Known boundary repairs take
  precedence; failed expectations direct semantic work; stale or unsupported
  evidence is unknown. Use the pilot's `--unit`/`--case` for a concrete ambiguity.
  A surviving mutation cannot support a positive behavioral classification.

## Integrate a coherent batch and measure the result

During recovery, run isolated comparisons and relevant checks. At the stable
integration checkpoint, run the complete build, commit the coherent source,
facts and registry changes, and push. Clean CI remains the independent byte
check. Do not repeat unchanged full suites between spelling attempts.

```sh
python3 tools/build.py check
python3 tools/recovery.py measure build/recovery-baseline.json
```

The result separates verified-C code/data, SDK objects and candidate fragments,
and reports net newly matched executable bytes alongside verified-C bytes per
wall-clock hour. Zero C gain is reported as zero. Use that result to change work
selection; a larger tool/test inventory is not decompilation completion.
