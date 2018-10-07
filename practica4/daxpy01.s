	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg.): %11.9f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %r12
	movl	%eax, %ebp
	salq	$3, %rbp
	movq	%rbp, %rdi
	call	malloc
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	malloc
	movq	%rax, %rbp
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	%r12d, %edi
	shrl	$2, %edi
	testl	%edi, %edi
	je	.L2
	movl	$1, %edx
	movl	$0, %eax
	cvtsi2sd	%eax, %xmm1
.L3:
	movslq	%edx, %rsi
	leaq	0(%rbp,%rsi,8), %rcx
	movapd	%xmm1, %xmm0
	mulsd	(%rbx,%rsi,8), %xmm0
	addsd	(%rcx), %xmm0
	movsd	%xmm0, (%rcx)
	addl	$1, %edx
	cmpl	%edi, %edx
	jbe	.L3
.L2:
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	(%rsp), %rax
	subq	16(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	8(%rsp), %rax
	subq	24(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	addq	$32, %rsp
	.cfi_def_cfa_offset 32
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
