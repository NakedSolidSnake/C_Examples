	.file	"switch.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"func1."
.LC1:
	.string	"func2."
.LC2:
	.string	"func3."
.LC3:
	.string	"func4."
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
	sub	rsp, 32
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi
	mov	DWORD PTR -4[rbp], 0
	jmp	.L2
.L10:
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, 1
	je	.L4
	cmp	eax, 1
	jg	.L5
	test	eax, eax
	je	.L6
	jmp	.L9
.L5:
	cmp	eax, 2
	je	.L7
	cmp	eax, 3
	je	.L8
	jmp	.L9
.L6:
	lea	rdi, .LC0[rip]
	call	puts@PLT
	jmp	.L9
.L4:
	lea	rdi, .LC1[rip]
	call	puts@PLT
	jmp	.L9
.L7:
	lea	rdi, .LC2[rip]
	call	puts@PLT
	jmp	.L9
.L8:
	lea	rdi, .LC3[rip]
	call	puts@PLT
	nop
.L9:
	add	DWORD PTR -4[rbp], 1
.L2:
	cmp	DWORD PTR -4[rbp], 3
	jle	.L10
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
