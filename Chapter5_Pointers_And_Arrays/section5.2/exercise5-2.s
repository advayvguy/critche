	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_getch                          ; -- Begin function getch
	.p2align	2
_getch:                                 ; @getch
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _bufp@PAGE
	ldr	w8, [x8, _bufp@PAGEOFF]
	cbnz	w8, LBB0_2
	b	LBB0_1
LBB0_1:
	bl	_getchar
	stur	w0, [x29, #-4]                  ; 4-byte Folded Spill
	b	LBB0_3
LBB0_2:
	adrp	x8, _bufp@PAGE
	ldr	w9, [x8, _bufp@PAGEOFF]
	subs	w9, w9, #1
	str	w9, [x8, _bufp@PAGEOFF]
	adrp	x8, _buf@GOTPAGE
	ldr	x8, [x8, _buf@GOTPAGEOFF]
	ldrsb	w8, [x8, w9, sxtw]
	stur	w8, [x29, #-4]                  ; 4-byte Folded Spill
	b	LBB0_3
LBB0_3:
	ldur	w0, [x29, #-4]                  ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_ungetch                        ; -- Begin function ungetch
	.p2align	2
_ungetch:                               ; @ungetch
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	ldr	w8, [sp, #12]
	adrp	x11, _bufp@PAGE
	ldrsw	x10, [x11, _bufp@PAGEOFF]
	mov	x9, x10
	add	w9, w9, #1
	str	w9, [x11, _bufp@PAGEOFF]
	adrp	x9, _buf@GOTPAGE
	ldr	x9, [x9, _buf@GOTPAGEOFF]
	strb	w8, [x9, x10]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_getfloat                       ; -- Begin function getfloat
	.p2align	2
_getfloat:                              ; @getfloat
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getch
	str	w0, [sp, #12]
	bl	_isspace
	mov	w8, #1                          ; =0x1
	str	w8, [sp]                        ; 4-byte Folded Spill
	cbnz	w0, LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w9, [sp, #12]
	mov	w8, #1                          ; =0x1
	subs	w9, w9, #45
	str	w8, [sp]                        ; 4-byte Folded Spill
	b.eq	LBB2_4
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]
	subs	w8, w8, #43
	cset	w8, eq
	str	w8, [sp]                        ; 4-byte Folded Spill
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp]                        ; 4-byte Folded Reload
	tbz	w8, #0, LBB2_8
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]
	subs	w8, w8, #45
	b.ne	LBB2_7
	b	LBB2_6
LBB2_6:                                 ;   in Loop: Header=BB2_1 Depth=1
	adrp	x9, _getfloat.sign@PAGE
	mov	w8, #-1                         ; =0xffffffff
	str	w8, [x9, _getfloat.sign@PAGEOFF]
	b	LBB2_7
LBB2_7:                                 ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_1
LBB2_8:
	ldr	w0, [sp, #12]
	bl	_isdigit
	cbnz	w0, LBB2_14
	b	LBB2_9
LBB2_9:
	ldr	w8, [sp, #12]
	subs	w8, w8, #45
	b.eq	LBB2_14
	b	LBB2_10
LBB2_10:
	ldr	w8, [sp, #12]
	adds	w8, w8, #1
	b.eq	LBB2_14
	b	LBB2_11
LBB2_11:
	ldr	w8, [sp, #12]
	subs	w8, w8, #43
	b.eq	LBB2_14
	b	LBB2_12
LBB2_12:
	ldr	w8, [sp, #12]
	subs	w8, w8, #46
	b.eq	LBB2_14
	b	LBB2_13
LBB2_13:
	ldr	w0, [sp, #12]
	bl	_ungetch
	stur	wzr, [x29, #-4]
	b	LBB2_30
LBB2_14:
	ldr	x8, [sp, #16]
	movi	d0, #0000000000000000
	str	d0, [x8]
	b	LBB2_15
LBB2_15:                                ; =>This Inner Loop Header: Depth=1
	ldr	w0, [sp, #12]
	bl	_isdigit
	cbz	w0, LBB2_18
	b	LBB2_16
LBB2_16:                                ;   in Loop: Header=BB2_15 Depth=1
	ldr	x8, [sp, #16]
	ldr	d0, [x8]
	ldr	w8, [sp, #12]
	subs	w8, w8, #48
	scvtf	d2, w8
	fmov	d1, #10.00000000
	fmadd	d0, d0, d1, d2
	ldr	x8, [sp, #16]
	str	d0, [x8]
	b	LBB2_17
LBB2_17:                                ;   in Loop: Header=BB2_15 Depth=1
	bl	_getch
	str	w0, [sp, #12]
	b	LBB2_15
LBB2_18:
	ldr	w8, [sp, #12]
	subs	w8, w8, #46
	b.ne	LBB2_27
	b	LBB2_19
LBB2_19:
	str	wzr, [sp, #8]
	b	LBB2_20
LBB2_20:                                ; =>This Inner Loop Header: Depth=1
	bl	_getch
	str	w0, [sp, #12]
	bl	_isdigit
	cbz	w0, LBB2_22
	b	LBB2_21
LBB2_21:                                ;   in Loop: Header=BB2_20 Depth=1
	ldr	x8, [sp, #16]
	ldr	d0, [x8]
	ldr	w8, [sp, #12]
	subs	w8, w8, #48
	scvtf	d2, w8
	fmov	d1, #10.00000000
	fmadd	d0, d0, d1, d2
	ldr	x8, [sp, #16]
	str	d0, [x8]
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB2_20
LBB2_22:
	str	wzr, [sp, #4]
	b	LBB2_23
LBB2_23:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	b.ge	LBB2_26
	b	LBB2_24
LBB2_24:                                ;   in Loop: Header=BB2_23 Depth=1
	ldr	x8, [sp, #16]
	ldr	d0, [x8]
	fmov	d1, #10.00000000
	fdiv	d0, d0, d1
	ldr	x8, [sp, #16]
	str	d0, [x8]
	b	LBB2_25
LBB2_25:                                ;   in Loop: Header=BB2_23 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB2_23
LBB2_26:
	b	LBB2_27
LBB2_27:
	adrp	x9, _getfloat.sign@PAGE
	ldr	s1, [x9, _getfloat.sign@PAGEOFF]
                                        ; implicit-def: $d0
	fmov	s0, s1
	sshll.2d	v0, v0, #0
                                        ; kill: def $d0 killed $d0 killed $q0
	scvtf	d1, d0
	ldr	x8, [sp, #16]
	ldr	d0, [x8]
	fmul	d0, d0, d1
	str	d0, [x8]
	mov	w8, #1                          ; =0x1
	str	w8, [x9, _getfloat.sign@PAGEOFF]
	ldr	w8, [sp, #12]
	adds	w8, w8, #1
	b.eq	LBB2_29
	b	LBB2_28
LBB2_28:
	ldr	w0, [sp, #12]
	bl	_ungetch
	b	LBB2_29
LBB2_29:
	ldr	w8, [sp, #12]
	stur	w8, [x29, #-4]
	b	LBB2_30
LBB2_30:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	mov	w9, #8048                       ; =0x1f70
Lloh0:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh1:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #1, lsl #12             ; =4096
	sub	sp, sp, #3952
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #36]
	str	wzr, [sp, #32]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w9, [sp, #32]
	mov	w8, #0                          ; =0x0
	subs	w9, w9, #1000
	str	w8, [sp, #24]                   ; 4-byte Folded Spill
	b.ge	LBB3_3
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldrsw	x9, [sp, #32]
	add	x8, sp, #40
	add	x0, x8, x9, lsl #3
	bl	_getfloat
	adds	w8, w0, #1
	cset	w8, ne
	str	w8, [sp, #24]                   ; 4-byte Folded Spill
	b	LBB3_3
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #24]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB3_5
	b	LBB3_4
LBB3_4:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #32]
	add	w8, w8, #1
	str	w8, [sp, #32]
	b	LBB3_1
LBB3_5:
	str	wzr, [sp, #28]
	b	LBB3_6
LBB3_6:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #28]
	ldr	w9, [sp, #32]
	subs	w8, w8, w9
	b.ge	LBB3_9
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_6 Depth=1
	ldrsw	x9, [sp, #28]
	add	x8, sp, #40
	ldr	d0, [x8, x9, lsl #3]
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB3_8
LBB3_8:                                 ;   in Loop: Header=BB3_6 Depth=1
	ldr	w8, [sp, #28]
	add	w8, w8, #1
	str	w8, [sp, #28]
	b	LBB3_6
LBB3_9:
	ldr	w8, [sp, #36]
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB3_11
	b	LBB3_10
LBB3_10:
	bl	___stack_chk_fail
LBB3_11:
	ldr	w0, [sp, #20]                   ; 4-byte Folded Reload
	add	sp, sp, #1, lsl #12             ; =4096
	add	sp, sp, #3952
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.loh AdrpLdrGot	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.globl	_bufp                           ; @bufp
.zerofill __DATA,__common,_bufp,4,2
	.comm	_buf,1000,0                     ; @buf
	.section	__DATA,__data
	.p2align	2, 0x0                          ; @getfloat.sign
_getfloat.sign:
	.long	1                               ; 0x1

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%f\n"

.subsections_via_symbols
