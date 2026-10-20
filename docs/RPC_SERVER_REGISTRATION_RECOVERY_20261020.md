# Exact RPC server registration and callback ABI

`func_00107098` (148 bytes) registers a queue and `func_00107130` (208 bytes)
registers a server with its real seven-argument interface. Both complete C
functions independently match retail with Sony EE GCC 2.9 O2/G0 and SN AS G0.
The shared header consolidates the actual 68-byte server and 24-byte queue
views previously declared separately in the removal CU.

The only current registration caller formerly declared its callback as
`void(void)`, although the provider consumes command, buffer and length.
Both now use the actual `void *(int, void *, int)` RPC callback interface.
The provider keeps its native unsigned command/length interpretation through
local conversions. Native indirect dispatch at `0x001073A8..0x001073B4`
confirms all three inputs. The caller uses actual Queue24 objects and a
Server68 view, with no function-pointer cast or padding array.

Root independently replayed every affected CU: registration/removal with
Sony 2.9 O2/G0, callback provider with EE96 O2/G0, and its caller with EE96
O2/G8. All thirteen complete functions / 2,240 bytes remain exact. Only the
two new registration functions add credit (356 bytes); existing functions
and type repairs add none. No initialized data credit is inferred from
these views or object sizes.
