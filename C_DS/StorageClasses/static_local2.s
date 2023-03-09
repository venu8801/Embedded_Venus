	.file	"static_local2.c"
	.text
	.local	x
	.comm	x,4,4
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	jmp	.L2
.L3:
	movl	x.2317(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	x.2317(%rip), %eax
	addl	$1, %eax
	movl	%eax, x.2317(%rip)
	movl	x.2316(%rip), %eax
	addl	$1, %eax
	movl	%eax, x.2316(%rip)
.L2:
	movl	x.2316(%rip), %eax
	cmpl	$10, %eax
	jle	.L3
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 4
	.type	x.2317, @object
	.size	x.2317, 4
x.2317:
	.long	10
	.align 4
	.type	x.2316, @object
	.size	x.2316, 4
x.2316:
	.long	1
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
