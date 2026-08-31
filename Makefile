PYTHON ?= python3
BIN ?=
CUE ?=
CONFIG := config/SLUS_204.86.yaml

.PHONY: setup split report test clean

setup:
	@test -n "$(BIN)" || { echo "BIN is required" >&2; exit 2; }
	@test -n "$(CUE)" || { echo "CUE is required" >&2; exit 2; }
	@PYTHON="$(PYTHON)" tools/setup_disc.sh "$(BIN)" "$(CUE)"

split:
	$(PYTHON) -m splat split $(CONFIG)

report:
	$(PYTHON) tools/objdiff_report.py --report build-report/report.json --svg assets/progress.svg

test:
	$(PYTHON) -m unittest tools/test_*.py

clean:
	rm -rf asm build build-report
