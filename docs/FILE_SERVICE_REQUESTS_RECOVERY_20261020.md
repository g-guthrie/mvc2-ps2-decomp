# Exact file-service request recovery

Three new Sony 2.9 translation units reproduce twelve complete file-service
functions: six path/scalar requests (2,440 bytes), four metadata/payload
requests (2,144 bytes), and two descriptor/buffer requests (912 bytes).
Every function was independently preprocessed, compiled with literal
`-O2 -G0 -ffunction-sections -quiet`, assembled with SN AS G0, relocated,
and compared against the entire native symbol in the integration checkout.
All new bodies are native control/data-flow reconstructions, rather than
copies of an upstream implementation. No readonly or data credit is claimed.

The typed request views express actual wire fields and bounded 1,024-byte
paths/payloads. Completion storage is a plain int, naturally placed at the
native stack offset by the compiler. The source adds no assembly, padding,
forced alignment, volatile qualifiers, fake helper clobbers, or synthetic
self-copies. Explicit uncached reply-address aliases preserve the console
memory access used by retail. Existing untouched packet tails and unusual
error handling are retained, including the descriptor request's native
semaphore wait on send failure and the payload API's signed size comparison.

The actual lock operation argument is now declared in a shared header and
its existing implementation. Both existing scalar-wrapper functions remain
exact. Five already credited 28-byte path wrappers move from the Grok CU to
the Sony CU as truthful int-returning path forwarders: this moves 140 bytes
of ownership and adds no progress. The remaining ten credited Grok spans
all verify exactly; all fifteen remaining function bodies and their
relocation targets are identical to the previously compiled Grok object.

The wire metadata copy is the real 64-byte native copy. Buffer request
bounds, cache extents, transport sizes, semaphore ownership, return values,
and all input argument transfers are represented directly. The implementation
continues using the existing RPC provider; its separately held near match
receives no credit from these callers.
