# Sony pad port close

The complete 184-byte close routine at `0010D7A8` matches with Sony EE GCC 2.9 O2/G0 and SNAS G0. It returns zero for an unopened port/slot, sends command 14 through the existing 128-byte pad RPC buffer with flags one at offset 16, returns zero on transport failure, and clears the slot's enabled field only after successful transport. Its return value is the reply word at offset 12.

The source reuses the established 28-byte slot layout and a typed five-word close-packet view over the existing raw RPC buffer. It allocates or credits no new packet/storage object. The final object contains precisely one complete 184-byte function and no allocated readonly, data or BSS payload; the standard verifier passes the entire span. The nonmatching open-port candidate remains private and is excluded.
