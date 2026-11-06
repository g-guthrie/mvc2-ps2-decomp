Vendored sh4dis from https://github.com/lwerdna/sh4dis at 04aa2dafceb201ca58dba770545a8bd05d8938c6.
Public-domain license in LICENSE. Bundled to allow offline original-byte inspection.
Disassembly is an inspection aid, not proof that a range is executable code.

Local compatibility fix: REG.NONE is integer 0, not tuple (0,), so Enum.auto works on Python 3.13+.
