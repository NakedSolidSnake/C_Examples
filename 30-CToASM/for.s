	.file	"for.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 112
	mov	DWORD PTR -100[rbp], edi
	mov	QWORD PTR -112[rbp], rsi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	DWORD PTR -80[rbp], 0
	lea	rax, func1[rip]
	mov	QWORD PTR -72[rbp], rax
	mov	DWORD PTR -64[rbp], 1
	lea	rax, func2[rip]
	mov	QWORD PTR -56[rbp], rax
	mov	DWORD PTR -48[rbp], 2
	lea	rax, func3[rip]
	mov	QWORD PTR -40[rbp], rax
	mov	DWORD PTR -32[rbp], 3
	lea	rax, func4[rip]
	mov	QWORD PTR -24[rbp], rax
	mov	DWORD PTR -88[rbp], 4
	mov	DWORD PTR -84[rbp], 0
	mov	eax, DWORD PTR -84[rbp]
	cmp	eax, DWORD PTR -88[rbp]
	jge	.L2
	mov	eax, DWORD PTR -84[rbp]
	cdqe
	sal	rax, 4
	add	rax, rbp
	sub	rax, 72
	mov	rax, QWORD PTR [rax]
	call	rax
	nop
.L2:
	mov	eax, 0
	mov	rdx, QWORD PTR -8[rbp]
	xor	rdx, QWORD PTR fs:40
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"func1."
	.text
	.globl	func1
	.type	func1, @function
func1:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	rdi, .LC0[rip]
	call	puts@PLT
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func1, .-func1
	.section	.rodata
.LC1:
	.string	"func2."
	.text
	.globl	func2
	.type	func2, @function
func2:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	rdi, .LC1[rip]
	call	puts@PLT
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func2, .-func2
	.section	.rodata
.LC2:
	.string	"func3."
	.text
	.globl	func3
	.type	func3, @function
func3:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	rdi, .LC2[rip]
	call	puts@PLT
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	func3, .-func3
	.section	.rodata
.LC3:
	.string	"func4."
	.text
	.globl	func4
	.type	func4, @function
func4:
.LFB4:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	rdi, .LC3[rip]
	call	puts@PLT
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	func4, .-func4
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
