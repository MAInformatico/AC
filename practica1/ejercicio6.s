
	call	clock_gettime
	leaq	0(,%rbp,8), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movsd	v1(%rax), %xmm0
	addsd	v2(%rax), %xmm0
	movsd	%xmm0, v3(%rax)
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L7
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime

	
	call	clock_gettime
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	