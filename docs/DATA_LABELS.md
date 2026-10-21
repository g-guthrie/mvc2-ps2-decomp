# Interior code-label provenance

`config/data_labels.csv` records addresses that are inside native functions,
with each exact owning interval, offset, consumer, and occurrence count.
Function entries belong in `config/functions.csv` and use `func_` names;
they must not remain on the interior-label allowlist.

For example, `00163F90` was originally recorded inside an oversized range.
Native boundaries and its existing complete 32-byte C implementation establish
an independent callback, now named `func_00163F90`. Its 27 references in
`gMvc2Dispatch_00445A20` are function references, not interior-label exceptions.
No additional code or data credit follows from that correction.

Run the public regression checks with:

```sh
PYTHONPATH=. python -m unittest discover -s tests -p test_data_labels.py
```

These checks validate the entire current registry against the function inventory
and validate every registered consumer's source occurrence counts. They also
check the callback table above after its obsolete allowlist entry was removed.
Both `make test` and report CI run this suite.

The standalone verifier accepts a registry scoped to one consumer:

```sh
python tools/verify_data_labels.py --functions config/functions.csv \
  --labels consumer_labels.csv --table src/data/consumer.c
```

Initializers may contain function-start or registered interior-label names,
optionally cast to the declared table element type. Unknown/data pointers,
raw addresses, unsupported expressions, stale owning ranges, and mismatched
occurrence counts are rejected. This source-only check does not replace the
private compiled-object and full-image checks.
