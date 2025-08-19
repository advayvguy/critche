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
	adrp	x8, _ungetvar@PAGE
	ldr	w8, [x8, _ungetvar@PAGEOFF]
	cbnz	w8, LBB0_2
	b	LBB0_1
LBB0_1:
	bl	_getchar
	stur	w0, [x29, #-4]
	b	LBB0_3
LBB0_2:
	adrp	x8, _ungetvar@PAGE
	ldr	w9, [x8, _ungetvar@PAGEOFF]
	str	w9, [sp, #8]
	str	wzr, [x8, _ungetvar@PAGEOFF]
	ldr	w8, [sp, #8]
	stur	w8, [x29, #-4]
	b	LBB0_3
LBB0_3:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_getop                          ; -- Begin function getop
	.p2align	2
_getop:                                 ; @getop
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	str	wzr, [sp, #12]
	adrp	x8, _pushedEOF@PAGE
	ldr	w8, [x8, _pushedEOF@PAGEOFF]
	subs	w8, w8, #1
	b.ne	LBB1_2
	b	LBB1_1
LBB1_1:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB1_33
LBB1_2:
	b	LBB1_3
LBB1_3:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getch
	str	w0, [sp, #8]
	ldr	x8, [sp, #16]
	strb	w0, [x8]
	sxtb	w9, w0
	mov	w8, #1                          ; =0x1
	subs	w9, w9, #32
	str	w8, [sp]                        ; 4-byte Folded Spill
	b.eq	LBB1_5
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [sp, #8]
	subs	w8, w8, #9
	cset	w8, eq
	str	w8, [sp]                        ; 4-byte Folded Spill
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [sp]                        ; 4-byte Folded Reload
	tbz	w8, #0, LBB1_7
	b	LBB1_6
LBB1_6:                                 ;   in Loop: Header=BB1_3 Depth=1
	b	LBB1_3
LBB1_7:
	ldr	x8, [sp, #16]
	strb	wzr, [x8, #1]
	ldr	w8, [sp, #8]
	subs	w8, w8, #97
	b.lt	LBB1_10
	b	LBB1_8
LBB1_8:
	ldr	w8, [sp, #8]
	subs	w8, w8, #122
	b.gt	LBB1_10
	b	LBB1_9
LBB1_9:
	mov	w8, #49                         ; =0x31
	stur	w8, [x29, #-4]
	b	LBB1_33
LBB1_10:
	ldr	w0, [sp, #8]
	bl	_isdigit
	cbnz	w0, LBB1_14
	b	LBB1_11
LBB1_11:
	ldr	w8, [sp, #8]
	subs	w8, w8, #46
	b.eq	LBB1_14
	b	LBB1_12
LBB1_12:
	ldr	w8, [sp, #8]
	subs	w8, w8, #45
	b.eq	LBB1_14
	b	LBB1_13
LBB1_13:
	ldr	w8, [sp, #8]
	stur	w8, [x29, #-4]
	b	LBB1_33
LBB1_14:
	ldr	w8, [sp, #8]
	subs	w8, w8, #45
	b.ne	LBB1_19
	b	LBB1_15
LBB1_15:
	bl	_getch
	str	w0, [sp, #4]
	ldr	w0, [sp, #4]
	bl	_isdigit
	cbz	w0, LBB1_17
	b	LBB1_16
LBB1_16:
	ldr	w8, [sp, #4]
	str	w8, [sp, #8]
	ldr	x9, [sp, #16]
	ldr	w10, [sp, #12]
	add	w10, w10, #1
	str	w10, [sp, #12]
	strb	w8, [x9, w10, sxtw]
	b	LBB1_18
LBB1_17:
	ldr	w8, [sp, #4]
	adrp	x9, _ungetvar@PAGE
	str	w8, [x9, _ungetvar@PAGEOFF]
	ldr	w8, [sp, #8]
	stur	w8, [x29, #-4]
	b	LBB1_33
LBB1_18:
	b	LBB1_19
LBB1_19:
	ldr	w0, [sp, #8]
	bl	_isdigit
	cbz	w0, LBB1_24
	b	LBB1_20
LBB1_20:
	b	LBB1_21
LBB1_21:                                ; =>This Inner Loop Header: Depth=1
	bl	_getch
	ldr	x8, [sp, #16]
	ldr	w9, [sp, #12]
	add	w9, w9, #1
	str	w9, [sp, #12]
	strb	w0, [x8, w9, sxtw]
	sxtb	w0, w0
	str	w0, [sp, #8]
	bl	_isdigit
	cbz	w0, LBB1_23
	b	LBB1_22
LBB1_22:                                ;   in Loop: Header=BB1_21 Depth=1
	b	LBB1_21
LBB1_23:
	b	LBB1_24
LBB1_24:
	ldr	w8, [sp, #8]
	subs	w8, w8, #46
	b.ne	LBB1_29
	b	LBB1_25
LBB1_25:
	b	LBB1_26
LBB1_26:                                ; =>This Inner Loop Header: Depth=1
	bl	_getch
	ldr	x8, [sp, #16]
	ldr	w9, [sp, #12]
	add	w9, w9, #1
	str	w9, [sp, #12]
	strb	w0, [x8, w9, sxtw]
	sxtb	w0, w0
	str	w0, [sp, #8]
	bl	_isdigit
	cbz	w0, LBB1_28
	b	LBB1_27
LBB1_27:                                ;   in Loop: Header=BB1_26 Depth=1
	b	LBB1_26
LBB1_28:
	b	LBB1_29
LBB1_29:
	ldr	x8, [sp, #16]
	ldrsw	x9, [sp, #12]
	add	x8, x8, x9
	strb	wzr, [x8]
	ldr	w8, [sp, #8]
	adds	w8, w8, #1
	b.eq	LBB1_31
	b	LBB1_30
LBB1_30:
	ldr	w8, [sp, #8]
	adrp	x9, _ungetvar@PAGE
	str	w8, [x9, _ungetvar@PAGEOFF]
	b	LBB1_32
LBB1_31:
	mov	w8, #1                          ; =0x1
	adrp	x9, _pushedEOF@PAGE
	str	w8, [x9, _pushedEOF@PAGEOFF]
	b	LBB1_32
LBB1_32:
	mov	w8, #48                         ; =0x30
	stur	w8, [x29, #-4]
	b	LBB1_33
LBB1_33:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_push                           ; -- Begin function push
	.p2align	2
_push:                                  ; @push
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	d0, [sp, #8]
	adrp	x8, _sp@PAGE
	ldr	w8, [x8, _sp@PAGEOFF]
	subs	w8, w8, #100
	b.ge	LBB2_2
	b	LBB2_1
LBB2_1:
	ldr	d0, [sp, #8]
	adrp	x10, _sp@PAGE
	ldrsw	x9, [x10, _sp@PAGEOFF]
	mov	x8, x9
	add	w8, w8, #1
	str	w8, [x10, _sp@PAGEOFF]
	adrp	x8, _val@GOTPAGE
	ldr	x8, [x8, _val@GOTPAGEOFF]
	str	d0, [x8, x9, lsl #3]
	b	LBB2_3
LBB2_2:
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB2_3
LBB2_3:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_pop                            ; -- Begin function pop
	.p2align	2
_pop:                                   ; @pop
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _sp@PAGE
	ldr	w8, [x8, _sp@PAGEOFF]
	subs	w8, w8, #0
	b.le	LBB3_2
	b	LBB3_1
LBB3_1:
	adrp	x8, _sp@PAGE
	ldr	w9, [x8, _sp@PAGEOFF]
	subs	w9, w9, #1
	str	w9, [x8, _sp@PAGEOFF]
	adrp	x8, _val@GOTPAGE
	ldr	x8, [x8, _val@GOTPAGEOFF]
	ldr	d0, [x8, w9, sxtw #3]
	str	d0, [sp, #8]
	b	LBB3_3
LBB3_2:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	movi	d0, #0000000000000000
	str	d0, [sp, #8]
	b	LBB3_3
LBB3_3:
	ldr	d0, [sp, #8]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #208
	stp	x29, x30, [sp, #192]            ; 16-byte Folded Spill
	add	x29, sp, #192
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	str	wzr, [sp, #80]
	b	LBB4_1
LBB4_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB4_35 Depth 2
                                        ;     Child Loop BB4_24 Depth 2
	add	x0, sp, #84
	bl	_getop
	str	w0, [sp, #76]
	adds	w8, w0, #1
	b.eq	LBB4_45
	b	LBB4_2
LBB4_2:                                 ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _check@PAGE
	ldr	w8, [x8, _check@PAGEOFF]
	subs	w8, w8, #1
	b.ne	LBB4_5
	b	LBB4_3
LBB4_3:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldrsb	w8, [sp, #84]
	subs	w8, w8, #61
	b.eq	LBB4_5
	b	LBB4_4
LBB4_4:                                 ;   in Loop: Header=BB4_1 Depth=1
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	w8, [sp, #76]
	subs	w8, w8, #10
	mov	w8, w8
                                        ; kill: def $x8 killed $w8
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	subs	x8, x8, #73
	b.hi	LBB4_43
; %bb.6:                                ;   in Loop: Header=BB4_1 Depth=1
	ldr	x11, [sp, #40]                  ; 8-byte Folded Reload
	adrp	x10, lJTI4_0@PAGE
	add	x10, x10, lJTI4_0@PAGEOFF
Ltmp0:
	adr	x8, Ltmp0
	ldrsw	x9, [x10, x11, lsl #2]
	add	x8, x8, x9
	br	x8
LBB4_7:                                 ;   in Loop: Header=BB4_1 Depth=1
	add	x0, sp, #84
	bl	_atof
	bl	_push
	b	LBB4_44
LBB4_8:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldrsb	w8, [sp, #84]
	subs	w9, w8, #97
	adrp	x8, _init@PAGE
	add	x8, x8, _init@PAGEOFF
	ldr	w8, [x8, w9, sxtw #2]
	subs	w8, w8, #1
	b.ne	LBB4_10
	b	LBB4_9
LBB4_9:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldrsb	w8, [sp, #84]
	subs	w9, w8, #97
	adrp	x8, _vararray@GOTPAGE
	ldr	x8, [x8, _vararray@GOTPAGEOFF]
	ldr	d0, [x8, w9, sxtw #3]
	bl	_push
	b	LBB4_11
LBB4_10:                                ;   in Loop: Header=BB4_1 Depth=1
	ldrsb	w8, [sp, #84]
	subs	w8, w8, #97
	scvtf	d0, w8
	fmov	d1, #1.00000000
	fmul	d0, d0, d1
	str	d0, [sp, #64]
	bl	_push
	mov	w8, #1                          ; =0x1
	adrp	x9, _check@PAGE
	str	w8, [x9, _check@PAGEOFF]
	b	LBB4_11
LBB4_11:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_44
LBB4_12:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _check@PAGE
	ldr	w8, [x8, _check@PAGEOFF]
	subs	w8, w8, #1
	b.ne	LBB4_14
	b	LBB4_13
LBB4_13:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #64]
	bl	_pop
	ldr	d1, [sp, #64]
	fcvtzs	w9, d1
	adrp	x8, _vararray@GOTPAGE
	ldr	x8, [x8, _vararray@GOTPAGEOFF]
	str	d0, [x8, w9, sxtw #3]
	ldr	d0, [sp, #64]
	fcvtzs	w10, d0
	adrp	x9, _init@PAGE
	add	x9, x9, _init@PAGEOFF
	mov	w8, #1                          ; =0x1
	str	w8, [x9, w10, sxtw #2]
	adrp	x8, _check@PAGE
	str	wzr, [x8, _check@PAGEOFF]
	b	LBB4_15
LBB4_14:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	b	LBB4_15
LBB4_15:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_44
LBB4_16:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #32]                   ; 8-byte Folded Spill
	bl	_pop
	fmov	d1, d0
	ldr	d0, [sp, #32]                   ; 8-byte Folded Reload
	fadd	d0, d0, d1
	bl	_push
	b	LBB4_44
LBB4_17:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #64]
	bl	_pop
	ldr	d1, [sp, #64]
	fsub	d0, d0, d1
	bl	_push
	b	LBB4_44
LBB4_18:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_pop
	fmov	d1, d0
	ldr	d0, [sp, #24]                   ; 8-byte Folded Reload
	fmul	d0, d0, d1
	bl	_push
	b	LBB4_44
LBB4_19:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #64]
	ldr	d0, [sp, #64]
	fcmp	d0, #0.0
	b.eq	LBB4_21
	b	LBB4_20
LBB4_20:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	ldr	d1, [sp, #64]
	fdiv	d0, d0, d1
	bl	_push
	b	LBB4_22
LBB4_21:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB4_22
LBB4_22:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_44
LBB4_23:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	fcvtzs	w8, d0
	str	w8, [sp, #60]
	bl	_pop
	fcvtzs	w8, d0
	str	w8, [sp, #56]
	str	wzr, [sp, #52]
	b	LBB4_24
LBB4_24:                                ;   Parent Loop BB4_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #60]
	ldr	w9, [sp, #52]
	mul	w8, w8, w9
	ldr	w9, [sp, #56]
	subs	w8, w8, w9
	b.gt	LBB4_27
	b	LBB4_25
LBB4_25:                                ;   in Loop: Header=BB4_24 Depth=2
	b	LBB4_26
LBB4_26:                                ;   in Loop: Header=BB4_24 Depth=2
	ldr	w8, [sp, #52]
	add	w8, w8, #1
	str	w8, [sp, #52]
	b	LBB4_24
LBB4_27:                                ;   in Loop: Header=BB4_1 Depth=1
	ldr	w8, [sp, #56]
	ldr	w9, [sp, #60]
	ldr	w10, [sp, #52]
	subs	w10, w10, #1
	mul	w9, w9, w10
	subs	w8, w8, w9
	scvtf	d0, w8
	bl	_push
	b	LBB4_44
LBB4_28:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	bl	_sin
	bl	_push
	b	LBB4_44
LBB4_29:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	bl	_exp
	bl	_push
	b	LBB4_44
LBB4_30:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	str	d0, [sp, #64]
	bl	_pop
	ldr	d1, [sp, #64]
	bl	_pow
	bl	_push
	b	LBB4_44
LBB4_31:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _sp@PAGE
	ldr	w8, [x8, _sp@PAGEOFF]
	subs	w9, w8, #1
	adrp	x8, _val@GOTPAGE
	ldr	x8, [x8, _val@GOTPAGEOFF]
	ldr	d0, [x8, w9, sxtw #3]
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB4_44
LBB4_32:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x11, _sp@PAGE
	ldr	w8, [x11, _sp@PAGEOFF]
	subs	w9, w8, #1
	adrp	x8, _val@GOTPAGE
	ldr	x8, [x8, _val@GOTPAGEOFF]
	ldr	d0, [x8, w9, sxtw #3]
	ldrsw	x9, [x11, _sp@PAGEOFF]
	mov	x10, x9
	add	w10, w10, #1
	str	w10, [x11, _sp@PAGEOFF]
	str	d0, [x8, x9, lsl #3]
	b	LBB4_44
LBB4_33:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x9, _sp@PAGE
	ldr	w8, [x9, _sp@PAGEOFF]
	subs	w10, w8, #1
	adrp	x8, _val@GOTPAGE
	ldr	x8, [x8, _val@GOTPAGEOFF]
	ldr	d0, [x8, w10, sxtw #3]
	str	d0, [sp, #64]
	ldr	w10, [x9, _sp@PAGEOFF]
	subs	w10, w10, #2
	ldr	d0, [x8, w10, sxtw #3]
	ldr	w10, [x9, _sp@PAGEOFF]
	subs	w10, w10, #1
	str	d0, [x8, w10, sxtw #3]
	ldr	d0, [sp, #64]
	ldr	w9, [x9, _sp@PAGEOFF]
	subs	w9, w9, #2
	str	d0, [x8, w9, sxtw #3]
	b	LBB4_44
LBB4_34:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _sp@PAGE
	str	wzr, [x8, _sp@PAGEOFF]
	str	wzr, [sp, #48]
	b	LBB4_35
LBB4_35:                                ;   Parent Loop BB4_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	w8, [sp, #48]
	subs	w8, w8, #26
	b.ge	LBB4_38
	b	LBB4_36
LBB4_36:                                ;   in Loop: Header=BB4_35 Depth=2
	ldrsw	x10, [sp, #48]
	adrp	x9, _init@PAGE
	add	x9, x9, _init@PAGEOFF
	mov	w8, #0                          ; =0x0
	str	w8, [x9, x10, lsl #2]
	b	LBB4_37
LBB4_37:                                ;   in Loop: Header=BB4_35 Depth=2
	ldr	w8, [sp, #48]
	add	w8, w8, #1
	str	w8, [sp, #48]
	b	LBB4_35
LBB4_38:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_44
LBB4_39:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _sp@PAGE
	ldr	w8, [x8, _sp@PAGEOFF]
	subs	w8, w8, #1
	b.le	LBB4_41
	b	LBB4_40
LBB4_40:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	b	LBB4_42
LBB4_41:                                ;   in Loop: Header=BB4_1 Depth=1
	bl	_pop
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB4_42
LBB4_42:                                ;   in Loop: Header=BB4_1 Depth=1
	adrp	x8, _sp@PAGE
	str	wzr, [x8, _sp@PAGEOFF]
	b	LBB4_44
LBB4_43:                                ;   in Loop: Header=BB4_1 Depth=1
	mov	x9, sp
	add	x8, sp, #84
	str	x8, [x9]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	b	LBB4_44
LBB4_44:                                ;   in Loop: Header=BB4_1 Depth=1
	b	LBB4_1
LBB4_45:
	ldr	w8, [sp, #80]
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB4_47
	b	LBB4_46
LBB4_46:
	bl	___stack_chk_fail
LBB4_47:
	ldr	w0, [sp, #20]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #192]            ; 16-byte Folded Reload
	add	sp, sp, #208
	ret
	.cfi_endproc
	.p2align	2
lJTI4_0:
	.long	LBB4_39-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_23-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_18-Ltmp0
	.long	LBB4_16-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_17-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_19-Ltmp0
	.long	LBB4_7-Ltmp0
	.long	LBB4_8-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_12-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_34-Ltmp0
	.long	LBB4_32-Ltmp0
	.long	LBB4_29-Ltmp0
	.long	LBB4_33-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_30-Ltmp0
	.long	LBB4_43-Ltmp0
	.long	LBB4_31-Ltmp0
	.long	LBB4_28-Ltmp0
                                        ; -- End function
	.globl	_pushedEOF                      ; @pushedEOF
.zerofill __DATA,__common,_pushedEOF,4,2
	.globl	_ungetvar                       ; @ungetvar
.zerofill __DATA,__common,_ungetvar,4,2
	.globl	_sp                             ; @sp
.zerofill __DATA,__common,_sp,4,2
	.comm	_val,800,3                      ; @val
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"error: stack full, cant push\n"

l_.str.1:                               ; @.str.1
	.asciz	"stack empty\n"

	.globl	_init                           ; @init
.zerofill __DATA,__common,_init,104,2
	.globl	_check                          ; @check
.zerofill __DATA,__common,_check,4,2
l_.str.2:                               ; @.str.2
	.asciz	"variable is uninitialized\n"

	.comm	_vararray,208,3                 ; @vararray
l_.str.3:                               ; @.str.3
	.asciz	"error: you cant initialize a number to a number or existing variable\n"

l_.str.4:                               ; @.str.4
	.asciz	"cant divide by 0\n"

l_.str.5:                               ; @.str.5
	.asciz	"\t %.8lf \n"

l_.str.6:                               ; @.str.6
	.asciz	"error: operator/s missing\n"

l_.str.7:                               ; @.str.7
	.asciz	"unknown command %s\n"

.subsections_via_symbols
