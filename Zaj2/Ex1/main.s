	.file	"main.c"
	.text
	.globl	lineFromFile
	.bss
	.align 32
	.type	lineFromFile, @object
	.size	lineFromFile, 1024
lineFromFile:
	.zero	1024
	.globl	lineNumber
	.align 4
	.type	lineNumber, @object
	.size	lineNumber, 4
lineNumber:
	.zero	4
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"\n"
.LC2:
	.string	"Wyraz znaleziono na lini:"
.LC3:
	.string	"%s %d %s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -8(%rbp)
.L6:
	cmpq	$0, -8(%rbp)
	je	.L2
	movq	-8(%rbp), %rax
	movq	%rax, %rdx
	movl	$1024, %esi
	leaq	lineFromFile(%rip), %rdi
	call	fgets@PLT
	testq	%rax, %rax
	je	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$0, %eax
.L3:
	testb	%al, %al
	je	.L4
	movl	lineNumber(%rip), %eax
	addl	$1, %eax
	movl	%eax, lineNumber(%rip)
	movq	-32(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	lineFromFile(%rip), %rdi
	call	strstr@PLT
	testq	%rax, %rax
	je	.L6
	movl	lineNumber(%rip), %eax
	leaq	.LC1(%rip), %rcx
	movl	%eax, %edx
	leaq	.LC2(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
