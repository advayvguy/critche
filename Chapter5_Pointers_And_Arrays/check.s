	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	add	x8, sp, #12
	mov	w9, #30                         ; =0x1e
	str	w9, [sp, #12]
	str	x8, [sp]
	ldr	x9, [sp]
	mov	w8, #40                         ; =0x28
	str	w8, [x9]
	mov	w0, #0                          ; =0x0
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
