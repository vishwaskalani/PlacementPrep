	.file	"prepCpp5.cpp"
	.text
	.section	.rodata
	.type	_ZN6__pstl9execution2v1L3seqE, @object
	.size	_ZN6__pstl9execution2v1L3seqE, 1
_ZN6__pstl9execution2v1L3seqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L3parE, @object
	.size	_ZN6__pstl9execution2v1L3parE, 1
_ZN6__pstl9execution2v1L3parE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L9par_unseqE, @object
	.size	_ZN6__pstl9execution2v1L9par_unseqE, 1
_ZN6__pstl9execution2v1L9par_unseqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L5unseqE, @object
	.size	_ZN6__pstl9execution2v1L5unseqE, 1
_ZN6__pstl9execution2v1L5unseqE:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13error_collateE, @object
	.size	_ZNSt15regex_constantsL13error_collateE, 4
_ZNSt15regex_constantsL13error_collateE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_ctypeE, @object
	.size	_ZNSt15regex_constantsL11error_ctypeE, 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL12error_escapeE, @object
	.size	_ZNSt15regex_constantsL12error_escapeE, 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13error_backrefE, @object
	.size	_ZNSt15regex_constantsL13error_backrefE, 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
	.type	_ZNSt15regex_constantsL11error_brackE, @object
	.size	_ZNSt15regex_constantsL11error_brackE, 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_parenE, @object
	.size	_ZNSt15regex_constantsL11error_parenE, 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
	.type	_ZNSt15regex_constantsL11error_braceE, @object
	.size	_ZNSt15regex_constantsL11error_braceE, 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
	.type	_ZNSt15regex_constantsL14error_badbraceE, @object
	.size	_ZNSt15regex_constantsL14error_badbraceE, 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
	.type	_ZNSt15regex_constantsL11error_rangeE, @object
	.size	_ZNSt15regex_constantsL11error_rangeE, 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL11error_spaceE, @object
	.size	_ZNSt15regex_constantsL11error_spaceE, 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
	.type	_ZNSt15regex_constantsL15error_badrepeatE, @object
	.size	_ZNSt15regex_constantsL15error_badrepeatE, 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
	.type	_ZNSt15regex_constantsL16error_complexityE, @object
	.size	_ZNSt15regex_constantsL16error_complexityE, 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
	.type	_ZNSt15regex_constantsL11error_stackE, @object
	.size	_ZNSt15regex_constantsL11error_stackE, 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 8
	.type	_ZNSt8__detailL19_S_invalid_state_idE, @object
	.size	_ZNSt8__detailL19_S_invalid_state_idE, 8
_ZNSt8__detailL19_S_invalid_state_idE:
	.quad	-1
.LC0:
	.string	" "
	.text
	.globl	main
	.type	main, @function
main:
.LFB9720:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9720
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EEC1Ev
	movl	$1, -96(%rbp)
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZN11ArrayStaticIiLm5EE9push_backERKi
	movl	$2, -96(%rbp)
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EE9push_backERKi
	movl	$3, -96(%rbp)
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EE9push_backERKi
	movq	$0, -128(%rbp)
	jmp	.L2
.L3:
	movq	-128(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EEixEm
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addq	$1, -128(%rbp)
.L2:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK11ArrayStaticIiLm5EE4sizeEv
	cmpq	%rax, -128(%rbp)
	setb	%al
	testb	%al, %al
	jne	.L3
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EE8pop_backEv
	movl	$4, -96(%rbp)
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EE9push_backERKi
	movq	$0, -120(%rbp)
	jmp	.L4
.L5:
	movq	-120(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN11ArrayStaticIiLm5EEixEm
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addq	$1, -120(%rbp)
.L4:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK11ArrayStaticIiLm5EE4sizeEv
	cmpq	%rax, -120(%rbp)
	setb	%al
	testb	%al, %al
	jne	.L5
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE0:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiEC1Ev
	movl	$10, -132(%rbp)
	leaq	-132(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB1:
	call	_ZN12ArrayDynamicIiE9push_backERKi
	movl	$20, -132(%rbp)
	leaq	-132(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiE9push_backERKi
	movl	$30, -132(%rbp)
	leaq	-132(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiE9push_backERKi
	movq	$0, -112(%rbp)
	jmp	.L6
.L7:
	movq	-112(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiEixEm
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addq	$1, -112(%rbp)
.L6:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK12ArrayDynamicIiE4sizeEv
	cmpq	%rax, -112(%rbp)
	setb	%al
	testb	%al, %al
	jne	.L7
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiE8pop_backEv
	movl	$40, -132(%rbp)
	leaq	-132(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiE9push_backERKi
	movq	$0, -104(%rbp)
	jmp	.L8
.L9:
	movq	-104(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiEixEm
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addq	$1, -104(%rbp)
.L8:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK12ArrayDynamicIiE4sizeEv
	cmpq	%rax, -104(%rbp)
	setb	%al
	testb	%al, %al
	jne	.L9
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE1:
	movl	$0, %ebx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiED1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L12
	jmp	.L14
.L13:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L14:
	call	__stack_chk_fail@PLT
.L12:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9720:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA9720:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE9720-.LLSDACSB9720
.LLSDACSB9720:
	.uleb128 .LEHB0-.LFB9720
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB9720
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L13-.LFB9720
	.uleb128 0
	.uleb128 .LEHB2-.LFB9720
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE9720:
	.text
	.size	main, .-main
	.section	.text._ZN11ArrayStaticIiLm5EEC2Ev,"axG",@progbits,_ZN11ArrayStaticIiLm5EEC5Ev,comdat
	.align 2
	.weak	_ZN11ArrayStaticIiLm5EEC2Ev
	.type	_ZN11ArrayStaticIiLm5EEC2Ev, @function
_ZN11ArrayStaticIiLm5EEC2Ev:
.LFB10409:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10409:
	.size	_ZN11ArrayStaticIiLm5EEC2Ev, .-_ZN11ArrayStaticIiLm5EEC2Ev
	.weak	_ZN11ArrayStaticIiLm5EEC1Ev
	.set	_ZN11ArrayStaticIiLm5EEC1Ev,_ZN11ArrayStaticIiLm5EEC2Ev
	.section	.rodata
.LC1:
	.string	"ArrayStatic is full"
	.section	.text._ZN11ArrayStaticIiLm5EE9push_backERKi,"axG",@progbits,_ZN11ArrayStaticIiLm5EE9push_backERKi,comdat
	.align 2
	.weak	_ZN11ArrayStaticIiLm5EE9push_backERKi
	.type	_ZN11ArrayStaticIiLm5EE9push_backERKi, @function
_ZN11ArrayStaticIiLm5EE9push_backERKi:
.LFB10411:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10411
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	cmpq	$4, %rax
	ja	.L17
	movq	-32(%rbp), %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	leaq	1(%rax), %rsi
	movq	-24(%rbp), %rdx
	movq	%rsi, 24(%rdx)
	movq	-24(%rbp), %rdx
	movl	%ecx, (%rdx,%rax,4)
	jmp	.L21
.L17:
	movl	$16, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB3:
	call	_ZNSt12out_of_rangeC1EPKc@PLT
.LEHE3:
	movq	_ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZTISt12out_of_range(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB4:
	call	__cxa_throw@PLT
.L20:
	endbr64
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE4:
.L21:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10411:
	.section	.gcc_except_table
.LLSDA10411:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10411-.LLSDACSB10411
.LLSDACSB10411:
	.uleb128 .LEHB3-.LFB10411
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L20-.LFB10411
	.uleb128 0
	.uleb128 .LEHB4-.LFB10411
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE10411:
	.section	.text._ZN11ArrayStaticIiLm5EE9push_backERKi,"axG",@progbits,_ZN11ArrayStaticIiLm5EE9push_backERKi,comdat
	.size	_ZN11ArrayStaticIiLm5EE9push_backERKi, .-_ZN11ArrayStaticIiLm5EE9push_backERKi
	.section	.text._ZNK11ArrayStaticIiLm5EE4sizeEv,"axG",@progbits,_ZNK11ArrayStaticIiLm5EE4sizeEv,comdat
	.align 2
	.weak	_ZNK11ArrayStaticIiLm5EE4sizeEv
	.type	_ZNK11ArrayStaticIiLm5EE4sizeEv, @function
_ZNK11ArrayStaticIiLm5EE4sizeEv:
.LFB10412:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10412:
	.size	_ZNK11ArrayStaticIiLm5EE4sizeEv, .-_ZNK11ArrayStaticIiLm5EE4sizeEv
	.section	.rodata
.LC2:
	.string	"Index out of range"
	.section	.text._ZN11ArrayStaticIiLm5EEixEm,"axG",@progbits,_ZN11ArrayStaticIiLm5EEixEm,comdat
	.align 2
	.weak	_ZN11ArrayStaticIiLm5EEixEm
	.type	_ZN11ArrayStaticIiLm5EEixEm, @function
_ZN11ArrayStaticIiLm5EEixEm:
.LFB10413:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10413
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	cmpq	%rax, -32(%rbp)
	jb	.L25
	movl	$16, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB5:
	call	_ZNSt12out_of_rangeC1EPKc@PLT
.LEHE5:
	movq	_ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZTISt12out_of_range(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB6:
	call	__cxa_throw@PLT
.L25:
	movq	-32(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	jmp	.L29
.L28:
	endbr64
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE6:
.L29:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10413:
	.section	.gcc_except_table
.LLSDA10413:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10413-.LLSDACSB10413
.LLSDACSB10413:
	.uleb128 .LEHB5-.LFB10413
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L28-.LFB10413
	.uleb128 0
	.uleb128 .LEHB6-.LFB10413
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE10413:
	.section	.text._ZN11ArrayStaticIiLm5EEixEm,"axG",@progbits,_ZN11ArrayStaticIiLm5EEixEm,comdat
	.size	_ZN11ArrayStaticIiLm5EEixEm, .-_ZN11ArrayStaticIiLm5EEixEm
	.section	.rodata
.LC3:
	.string	"ArrayStatic is empty"
	.section	.text._ZN11ArrayStaticIiLm5EE8pop_backEv,"axG",@progbits,_ZN11ArrayStaticIiLm5EE8pop_backEv,comdat
	.align 2
	.weak	_ZN11ArrayStaticIiLm5EE8pop_backEv
	.type	_ZN11ArrayStaticIiLm5EE8pop_backEv, @function
_ZN11ArrayStaticIiLm5EE8pop_backEv:
.LFB10417:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10417
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	je	.L31
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 24(%rax)
	jmp	.L35
.L31:
	movl	$16, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB7:
	call	_ZNSt12out_of_rangeC1EPKc@PLT
.LEHE7:
	movq	_ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZTISt12out_of_range(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB8:
	call	__cxa_throw@PLT
.L34:
	endbr64
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE8:
.L35:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10417:
	.section	.gcc_except_table
.LLSDA10417:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10417-.LLSDACSB10417
.LLSDACSB10417:
	.uleb128 .LEHB7-.LFB10417
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L34-.LFB10417
	.uleb128 0
	.uleb128 .LEHB8-.LFB10417
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE10417:
	.section	.text._ZN11ArrayStaticIiLm5EE8pop_backEv,"axG",@progbits,_ZN11ArrayStaticIiLm5EE8pop_backEv,comdat
	.size	_ZN11ArrayStaticIiLm5EE8pop_backEv, .-_ZN11ArrayStaticIiLm5EE8pop_backEv
	.section	.text._ZN12ArrayDynamicIiEC2Ev,"axG",@progbits,_ZN12ArrayDynamicIiEC5Ev,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiEC2Ev
	.type	_ZN12ArrayDynamicIiEC2Ev, @function
_ZN12ArrayDynamicIiEC2Ev:
.LFB10419:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10419:
	.size	_ZN12ArrayDynamicIiEC2Ev, .-_ZN12ArrayDynamicIiEC2Ev
	.weak	_ZN12ArrayDynamicIiEC1Ev
	.set	_ZN12ArrayDynamicIiEC1Ev,_ZN12ArrayDynamicIiEC2Ev
	.section	.text._ZN12ArrayDynamicIiED2Ev,"axG",@progbits,_ZN12ArrayDynamicIiED5Ev,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiED2Ev
	.type	_ZN12ArrayDynamicIiED2Ev, @function
_ZN12ArrayDynamicIiED2Ev:
.LFB10422:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L39
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv@PLT
.L39:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10422:
	.size	_ZN12ArrayDynamicIiED2Ev, .-_ZN12ArrayDynamicIiED2Ev
	.weak	_ZN12ArrayDynamicIiED1Ev
	.set	_ZN12ArrayDynamicIiED1Ev,_ZN12ArrayDynamicIiED2Ev
	.section	.text._ZN12ArrayDynamicIiE9push_backERKi,"axG",@progbits,_ZN12ArrayDynamicIiE9push_backERKi,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiE9push_backERKi
	.type	_ZN12ArrayDynamicIiE9push_backERKi, @function
_ZN12ArrayDynamicIiE9push_backERKi:
.LFB10424:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, %rdx
	jne	.L41
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN12ArrayDynamicIiE6resizeEv
.L41:
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movq	(%rax), %rdi
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	leaq	1(%rax), %rsi
	movq	-8(%rbp), %rcx
	movq	%rsi, 8(%rcx)
	salq	$2, %rax
	addq	%rdi, %rax
	movl	%edx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10424:
	.size	_ZN12ArrayDynamicIiE9push_backERKi, .-_ZN12ArrayDynamicIiE9push_backERKi
	.section	.text._ZNK12ArrayDynamicIiE4sizeEv,"axG",@progbits,_ZNK12ArrayDynamicIiE4sizeEv,comdat
	.align 2
	.weak	_ZNK12ArrayDynamicIiE4sizeEv
	.type	_ZNK12ArrayDynamicIiE4sizeEv, @function
_ZNK12ArrayDynamicIiE4sizeEv:
.LFB10425:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10425:
	.size	_ZNK12ArrayDynamicIiE4sizeEv, .-_ZNK12ArrayDynamicIiE4sizeEv
	.section	.text._ZN12ArrayDynamicIiEixEm,"axG",@progbits,_ZN12ArrayDynamicIiEixEm,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiEixEm
	.type	_ZN12ArrayDynamicIiEixEm, @function
_ZN12ArrayDynamicIiEixEm:
.LFB10426:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10426
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -32(%rbp)
	jb	.L45
	movl	$16, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB9:
	call	_ZNSt12out_of_rangeC1EPKc@PLT
.LEHE9:
	movq	_ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZTISt12out_of_range(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB10:
	call	__cxa_throw@PLT
.L45:
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	salq	$2, %rax
	addq	%rdx, %rax
	jmp	.L49
.L48:
	endbr64
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE10:
.L49:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10426:
	.section	.gcc_except_table
.LLSDA10426:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10426-.LLSDACSB10426
.LLSDACSB10426:
	.uleb128 .LEHB9-.LFB10426
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L48-.LFB10426
	.uleb128 0
	.uleb128 .LEHB10-.LFB10426
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
.LLSDACSE10426:
	.section	.text._ZN12ArrayDynamicIiEixEm,"axG",@progbits,_ZN12ArrayDynamicIiEixEm,comdat
	.size	_ZN12ArrayDynamicIiEixEm, .-_ZN12ArrayDynamicIiEixEm
	.section	.rodata
.LC4:
	.string	"ArrayDynamic is empty"
	.section	.text._ZN12ArrayDynamicIiE8pop_backEv,"axG",@progbits,_ZN12ArrayDynamicIiE8pop_backEv,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiE8pop_backEv
	.type	_ZN12ArrayDynamicIiE8pop_backEv, @function
_ZN12ArrayDynamicIiE8pop_backEv:
.LFB10427:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10427
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L51
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L55
.L51:
	movl	$16, %edi
	call	__cxa_allocate_exception@PLT
	movq	%rax, %rbx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB11:
	call	_ZNSt12out_of_rangeC1EPKc@PLT
.LEHE11:
	movq	_ZNSt12out_of_rangeD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZTISt12out_of_range(%rip), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB12:
	call	__cxa_throw@PLT
.L54:
	endbr64
	movq	%rax, %r12
	movq	%rbx, %rdi
	call	__cxa_free_exception@PLT
	movq	%r12, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE12:
.L55:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10427:
	.section	.gcc_except_table
.LLSDA10427:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10427-.LLSDACSB10427
.LLSDACSB10427:
	.uleb128 .LEHB11-.LFB10427
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L54-.LFB10427
	.uleb128 0
	.uleb128 .LEHB12-.LFB10427
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE10427:
	.section	.text._ZN12ArrayDynamicIiE8pop_backEv,"axG",@progbits,_ZN12ArrayDynamicIiE8pop_backEv,comdat
	.size	_ZN12ArrayDynamicIiE8pop_backEv, .-_ZN12ArrayDynamicIiE8pop_backEv
	.section	.text._ZN12ArrayDynamicIiE6resizeEv,"axG",@progbits,_ZN12ArrayDynamicIiE6resizeEv,comdat
	.align 2
	.weak	_ZN12ArrayDynamicIiE6resizeEv
	.type	_ZN12ArrayDynamicIiE6resizeEv, @function
_ZN12ArrayDynamicIiE6resizeEv:
.LFB10822:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L57
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	leaq	(%rax,%rax), %rdx
	jmp	.L58
.L57:
	movl	$1, %edx
.L58:
	movq	-24(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movabsq	$2305843009213693950, %rdx
	cmpq	%rdx, %rax
	ja	.L59
	salq	$2, %rax
	movq	%rax, %rdi
	call	_Znam@PLT
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L61
.L59:
	call	__cxa_throw_bad_array_new_length@PLT
.L62:
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	salq	$2, %rax
	addq	%rdx, %rax
	movq	-16(%rbp), %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addq	$1, -16(%rbp)
.L61:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L62
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L63
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv@PLT
.L63:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10822:
	.size	_ZN12ArrayDynamicIiE6resizeEv, .-_ZN12ArrayDynamicIiE6resizeEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB11494:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L66
	cmpl	$65535, -8(%rbp)
	jne	.L66
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L66:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11494:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB11517:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11517:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
