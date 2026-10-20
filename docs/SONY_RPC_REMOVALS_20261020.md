# Exact RPC server and queue removal

`func_00107200` (148 bytes) unlinks a server from its queue, and
`func_00107298` (144 bytes) unlinks a queue from the shared RPC pool. Both
native-first C functions match with Sony EE GCC 2.9 O2/G0, function sections,
and SN EE assembler G0. Their list traversal, interrupt exclusion, head
updates and return values follow the retail implementation.

The shared pool declaration now expresses its known prefix through the
queue-head field at +40. Intervening unknown storage stays explicitly
unknown; no complete-object size, allocation, or data credit is inferred.
All header consumers were independently recompiled under their existing
production profiles: the five Sony CUs plus both existing bind callers.
All nine functions (1,680 bytes) remain exact, including the 292 new bytes.
The earlier request-only seven-function closure totals 1,388 bytes; its
previous receipt text overstated that closure sum by 100 bytes. Catalog
progress is calculated from per-function sizes and was unaffected.
