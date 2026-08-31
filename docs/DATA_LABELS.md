# Interior code-label provenance

`config/data_labels.csv` is a source-only allowlist for code addresses used as
data-table targets but not function entries. It provides the address, owning
function interval, in-function offset, consumer, and observed occurrence
count. It must not be used to bless arbitrary labels.

The first record is `lbl_00163F90`: it is `0x50` bytes inside
`func_00163F40` and is used by `gMvc2Dispatch_00445A20` 27 times. The owning
range is taken from the public function inventory. The executable control-flow
target was checked privately; no instruction or table bytes are in this export.

Run after copying the registry, verifier, test, and symbolic table source into
the repository:

```sh
python -m unittest tests/test_data_labels.py
python tools/verify_data_labels.py \
  --functions config/functions.csv \
  --labels config/data_labels.csv \
  --table src/mvc2_dispatch_00445A20.c
```

The verifier rejects:

* interior labels missing from the registry;
* `func_` names that do not name a function start; and
* all data and unrecognized identifiers in the table initializer.
