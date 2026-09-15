PYTHON ?= python3
BIN ?=
CUE ?=
CONFIG := config/SLUS_204.86.yaml

.PHONY: setup split relink match hybrid pack-elf progress-check report test clean

setup:
	@test -n "$(BIN)" || { echo "BIN is required" >&2; exit 2; }
	@test -n "$(CUE)" || { echo "CUE is required" >&2; exit 2; }
	@PYTHON="$(PYTHON)" tools/setup_disc.sh "$(BIN)" "$(CUE)"

split:
	$(PYTHON) -m splat split $(CONFIG)

relink:
	PYTHON="$(PYTHON)" tools/relink_baseline.sh

match:
	PYTHON="$(PYTHON)" tools/compile_matching.sh

hybrid: match
	PYTHON="$(PYTHON)" tools/relink_hybrid.sh
	PYTHON="$(PYTHON)" tools/pack_hybrid_elf.sh

pack-elf:
	PYTHON="$(PYTHON)" tools/pack_hybrid_elf.sh

progress-check:
	PYTHONPATH=. $(PYTHON) -m tools.validate_progress_catalog

report: progress-check
	PYTHONPATH=. $(PYTHON) -m tools.objdiff_report --report build-report/report.json --svg assets/progress.svg

test:
	PYTHONPATH=. $(PYTHON) -m unittest tools.test_project tools.test_progress_catalog tools.test_hybrid_relink tools.test_pack_retail_elf

clean:
	rm -rf asm build build-report
