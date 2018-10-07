	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg.): %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movl	$10, %edx
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol
	movl	%eax, %ebx
	movq	%rax, %r12
	salq	$3, %rbx
	movq	%rbx, %rdi
	call	malloc
	movq	%rbx, %rdi
	movq	%rax, %rbp
	call	malloc
	movq	%rsp, %rsi
	xorl	%edi, %edi
	movq	%rax, %rbx
	call	clock_gettime
	movl	%r12d, %esi
	shrl	$2, %esi
	testl	%esi, %esi
	je	.L3
	xorl	%eax, %eax
	xorl	%edx, %edx
	cvtsi2sd	%eax, %xmm1
	.p2align 4,,10
	.p2align 3
.L4:
	movsd	8(%rbp,%rdx,8), %xmm0
	mulsd	%xmm1, %xmm0
	addsd	8(%rbx,%rdx,8), %xmm0
	movsd	%xmm0, 8(%rbx,%rdx,8)
	addq	$1, %rdx
	leal	1(%rdx), %ecx
	cmpl	%ecx, %esi
	jae	.L4
.L3:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movl	$.LC1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	printf
	addq	$32, %rsp
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE21:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (GNU) 4.8.2 20131212 (Red Hat 4.8.2-7)"
	.section	.note.GNU-stack,"",@progbits
