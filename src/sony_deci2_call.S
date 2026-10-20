/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# (C)2001, Gustavo Scotti (gustavo@scotti.com)
# (c) 2003 Marcus R. Brown (mrbrown@0xd6.org)
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

/* Original PS2SDK normal-mode syscall macro, retained verbatim below.
 * Source: ps2dev/ps2sdk 329e2bb43287e16af16c4dde1c614e2662c24468,
 * ee/kernel/src/kernel.S and ee/kernel/include/syscallnr.h.
 * Only the exported name is adapted by the original macro's symbol argument.
 * This is an SDK architecture primitive, not reconstructed portable C.
 */
#define __NR_Deci2Call 0x7c

#define SYSCALL_SPECIAL(symbol, name) 		\
	.set	push;		\
	.set	noreorder;	\
	.text;			\
	.align 4;		\
	.globl	symbol;		\
	.type	symbol,@function;	\
	.ent	symbol,0;		\
symbol:	li	$3, __NR_##name;\
	syscall;		\
	jr	$31;		\
	nop;			\
	.end	symbol;		\
	.size	symbol,.-symbol;	\
	.set	pop;

SYSCALL_SPECIAL(func_00104210, Deci2Call)
