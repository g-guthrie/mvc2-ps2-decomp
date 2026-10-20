# Exact SIF RPC reply completion

`func_00106928` matches all 180 bytes with Sony EE GCC 2.9 O2/G0,
function sections, and SN EE assembler G0. Its two arguments match the actual
command-handler registration at `0x001066BC..0x001066CC`. The handler dispatches
reply command codes, runs an optional client callback or fills binding
results, signals the existing semaphore, clears packet state and releases
the client's packet pointer.

The C body is reconstructed from native control/data flow. Public PS2SDK
headers at revision `329e2bb43287e16af16c4dde1c614e2662c24468` corroborate
packet/client layout, command constants and the handler ABI; no SDK C
implementation was imported. `src/sony29_rpc_packet_header.h` also corrects
the existing clear helper to accept its actual 28-byte header layout. That
helper remains a complete 28-byte exact match and adds no new credit.
