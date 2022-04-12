	.file	"splint1_init.c"
	.text
	.section	.rodata
.LC0:
	.string	"one"
.LC1:
	.string	"two"
.LC2:
	.string	"three"
.LC3:
	.string	"less than 1 or more than 3"
	.text
	.globl	into_string
	.type	into_string, @function
into_string:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$3, %eax
	je	.L4
	cmpl	$1, %eax
	jne	.L8
	leaq	.LC0(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L6
.L3:
	leaq	.LC1(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L6
.L4:
	leaq	.LC2(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L6
.L8:
	leaq	.LC3(%rip), %rax
	movq	%rax, -8(%rbp)
	nop
.L6:
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	into_string, .-into_string
	.section	.rodata
.LC4:
	.string	"into_string(2) = %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$25, -4(%rbp)
	movl	$2, %edi
	call	into_string
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
