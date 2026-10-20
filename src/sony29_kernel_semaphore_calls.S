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

/*
 * Normal-mode SYSCALL_SPECIAL provider from PS2SDK kernel.S at
 * 329e2bb43287e16af16c4dde1c614e2662c24468. The five selector constants
 * match the same revision's ee/kernel/include/syscallnr.h. Existing project
 * symbols are retained as the macro's symbol argument.
 */
#define __NR_CreateSema 0x40
#define __NR_DeleteSema 0x41
#define __NR_SignalSema 0x42
#define __NR_iSignalSema (-0x43)
#define __NR_WaitSema 0x44

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

SYSCALL_SPECIAL(func_00103DE0, CreateSema)
SYSCALL_SPECIAL(func_00103DF0, DeleteSema)
SYSCALL_SPECIAL(func_00103E00, SignalSema)
SYSCALL_SPECIAL(func_00103E10, iSignalSema)
SYSCALL_SPECIAL(func_00103E20, WaitSema)
