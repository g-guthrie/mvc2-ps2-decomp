# Owner start callbacks and active priority queue

Five whole functions add 1,228 code bytes: four inherited owner-start
callbacks and the active object priority-queue insertion routine. The actor
callbacks preserve the actual owner argument, copied state, motion setup,
record fields and animation calls. Their native entries are independently
rooted by the existing callback tables. Four leading 12-byte gaps remain
uncredited alignment; native zero words and a scan of all cataloged direct
branches/jumps and initialized data pointers confirm no entry into those gaps.

The queue inserts an active object into its palette row, up to 96 pointers,
and moves it toward the front while earlier objects have greater signed
priority. The record declaration describes only its accessed shared prefix.
The actual caller also processes 0x5B8-byte objects, so this routine does not
establish one complete fixed 0x1E4-byte allocation type. An unused tail and
an incorrect allocation/free-list comment were removed during integration.
The routine neither allocates nor unlinks free objects.

The caller uses the matching struct Object pointer contract. Two other
units lose unused incompatible declarations for the queue banks. The root
also preserves the previously verified func_00267D70 two-argument caller
prototype, which was absent from the CODE worker's older baseline. No
existing caller behavior or instruction bytes change.

Root independently rebuilt five production units and verified all 40 whole
registered functions. The source/object cache audit pins 15,165 other pairs
and all 47 unchanged headers. The queue's narrower record prefix still
reproduces the exact complete native function. All source, configuration,
test and tool inputs are frozen during the combined linkage gate.

After a successful complete gate, code reaches 2,072,956 / 3,293,696 bytes.
Data remains 255,591 / 648,064 bytes. No queue bank or other BSS data gains
initialized-data credit. The next fixed code publication threshold remains
2,080,510 bytes, leaving 7,554 bytes.

The final combined checkpoint also includes twelve bounded bobbing amplitude
data bytes and the vector-row baseline repair. Six code units reproduce
41 whole functions; three data units verify in full. All 111 tests, catalog
and coverage gates, fresh split, full retail ROM and packed ELF identity
checks pass. A second cache audit verifies 15,163 unaffected pairs and all
47 headers against main46; five existing pairs were rebuilt and four new
source units added. Final reconstructed data is 255,603 bytes (39.4410%).
