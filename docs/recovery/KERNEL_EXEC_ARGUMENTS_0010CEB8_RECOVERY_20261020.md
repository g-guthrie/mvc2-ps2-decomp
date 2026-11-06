# Exact kernel argument-vector staging

`func_0010CEB8` matches its complete 280-byte body with Sony EE GCC 2.9
O2/G0 and SN assembler G0. It stages the filename, then up to fifteen argv
pointers and strings through the native kernel Copy boundary. The pointer
table occupies the actual 64-byte prefix. Each string uses its native
strlen-plus-terminator length; no new validation or buffer policy is added.

The existing LoadExecPS2 and ExecOSD wrappers now express filename/argc/argv
contracts instead of the former message-format interpretation. Their third
parameters are actual argv pointers, and the wrapper code stays exact at
72 and 76 bytes. Unused conflicting helper/global declarations are removed
from three other CUs. Root independently replayed all fourteen complete
functions / 1,148 bytes across the five affected CUs under their literal
Sony 2.9 or EE96 O2/G0 profiles. New credit is only the 280-byte helper.

Existing Copy/SetSyscall/execution architecture stubs remain untouched and
are not presented as repaired portable C. No assembly, padding, or fake
helper clobber is added to the new C recovery.
