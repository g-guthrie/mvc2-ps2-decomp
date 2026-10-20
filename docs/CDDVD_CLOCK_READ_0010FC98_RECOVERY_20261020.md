# Exact CD/DVD clock reply

`func_0010FC98` matches all 248 native bytes with Sony EE GCC 2.9 O2/G0 and
SN assembler G0. The eight-byte clock view follows the pinned public
libcdvd-common.h structure. A normal `memcpy(sizeof(*clock))` produces the
native unaligned copy from the uncached response, with no forced integer
width or alignment qualifier.

The source preserves acquisition, diagnostics, RPC receive size, uncached
status/result accesses, and semaphore release on each native path. Root
independently compiled and relocated the complete function. It adds code
only, without inferring initialized-data credit from the reply view.
