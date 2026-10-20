# Interaction sequence records

Eleven independently referenced records at 00452170/180/190/1A0/1C0/1D0/1E0 and 0045D990/9A0/9B0/9C0 now have source-owned fields. Together with the bounded byte maps at 0045DA30 and 0045DA40, they reconstruct 217 bytes.

The native dispatcher at 00189310 reads the owner key byte at +4 and dispatches through D_00448F10. The exact reader at 001893E0 reads a u16 count at +0 and u16 masks at +8 with stride two. After the final counted step it passes the unchanged completed index to 00189500; native load 00189544 reads that terminal mask. Each record therefore owns count+1 masks. The exact predicate consumer 0018A460 reads u16 flags at +2; the exact post-accept consumer 0018A990 reads u16 flags at +6. The unread byte at +5 stays in a separate raw unit. The five-step record ends at 004521B4; its twelve trailing zero bytes remain raw.

The exact function 0031E2C0 masks input with 0x3C00 and shifts by ten before indexing the 16-entry map at 0045DA30. The exact function 0031E3E0 uses that four-bit index plus an optional sixteen offset for the 32-entry map at 0045DA40. Both bounds follow from the complete indexed load expressions.

The previous placeholder spans 004520C0..004521F0 (304 bytes) and 0045D974..0045DA70 (252 bytes) retain contiguous coverage, including every raw gap. The unclassified prefixes, neighboring coordinate-like values, byte choices, and zero tails receive no new reconstruction credit. All forty replacement data objects pass the standard compiler/data verifier. Payload symbol names end in their actual addresses so automatic symbol generation preserves the six-byte header offset.
