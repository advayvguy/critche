	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 26, 0
	.globl	_getint                         ; -- Begin function getint
	.p2align	2
_getint:                                ; @getint
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	ldrsb	w8, [x8]
	cbnz	w8, LBB0_2
	b	LBB0_1
LBB0_1:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB0_10
LBB0_2:
	ldr	x0, [sp, #16]
	bl	_strlen
	mov	x8, x0
	str	w8, [sp, #12]
	str	wzr, [sp, #8]
	str	wzr, [sp, #4]
	b	LBB0_3
LBB0_3:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	ldr	w9, [sp, #12]
	subs	w8, w8, w9
	b.ge	LBB0_9
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_3 Depth=1
	ldr	x8, [sp, #16]
	ldrsw	x9, [sp, #4]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #48
	b.lt	LBB0_6
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_3 Depth=1
	ldr	x8, [sp, #16]
	ldrsw	x9, [sp, #4]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #57
	b.le	LBB0_7
	b	LBB0_6
LBB0_6:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB0_10
LBB0_7:                                 ;   in Loop: Header=BB0_3 Depth=1
	ldr	w9, [sp, #8]
	mov	w8, #10                         ; =0xa
	mul	w8, w8, w9
	ldr	x9, [sp, #16]
	ldrsw	x10, [sp, #4]
	ldrsb	w9, [x9, x10]
	subs	w9, w9, #48
	add	w8, w8, w9
	str	w8, [sp, #8]
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_3 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB0_3
LBB0_9:
	ldr	w8, [sp, #8]
	stur	w8, [x29, #-4]
	b	LBB0_10
LBB0_10:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_count_and_add                  ; -- Begin function count_and_add
	.p2align	2
_count_and_add:                         ; @count_and_add
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	str	x1, [sp, #8]
	str	wzr, [sp, #4]
	ldr	x8, [sp, #8]
	str	wzr, [x8]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getchar
	str	w0, [sp]
	adds	w8, w0, #1
	b.eq	LBB1_9
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #8]
	ldr	w8, [x8]
	mov	w9, #34464                      ; =0x86a0
	movk	w9, #1, lsl #16
	subs	w8, w8, w9
	b.ne	LBB1_4
	b	LBB1_3
LBB1_3:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB1_10
LBB1_4:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp]
	subs	w8, w8, #10
	b.ne	LBB1_6
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	ldrsw	x9, [x9]
	add	x9, x8, x9
	mov	w8, #10                         ; =0xa
	strb	w8, [x9]
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB1_7
LBB1_6:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp]
	ldr	x9, [sp, #16]
	ldr	x10, [sp, #8]
	ldrsw	x10, [x10]
	strb	w8, [x9, x10]
	b	LBB1_7
LBB1_7:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_8
LBB1_8:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x9, [sp, #8]
	ldr	w8, [x9]
	add	w8, w8, #1
	str	w8, [x9]
	b	LBB1_1
LBB1_9:
	ldr	w8, [sp, #4]
	stur	w8, [x29, #-4]
	b	LBB1_10
LBB1_10:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printlastn                     ; -- Begin function printlastn
	.p2align	2
_printlastn:                            ; @printlastn
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	stur	w1, [x29, #-8]
	stur	x2, [x29, #-16]
	stur	w3, [x29, #-20]
	ldur	w8, [x29, #-4]
	ldur	w9, [x29, #-8]
	subs	w8, w8, w9
	str	w8, [sp, #24]
	ldr	w8, [sp, #24]
	tbz	w8, #31, LBB2_2
	b	LBB2_1
LBB2_1:
	str	wzr, [sp, #24]
	b	LBB2_2
LBB2_2:
	str	wzr, [sp, #20]
	str	wzr, [sp, #16]
	b	LBB2_3
LBB2_3:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.ge	LBB2_11
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #24]
	subs	w8, w8, w9
	b.lt	LBB2_6
	b	LBB2_5
LBB2_5:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldur	x8, [x29, #-16]
	ldrsw	x9, [sp, #16]
	ldrsb	w10, [x8, x9]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB2_9
LBB2_6:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldur	x8, [x29, #-16]
	ldrsw	x9, [sp, #16]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #10
	b.ne	LBB2_8
	b	LBB2_7
LBB2_7:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB2_8
LBB2_8:                                 ;   in Loop: Header=BB2_3 Depth=1
	b	LBB2_9
LBB2_9:                                 ;   in Loop: Header=BB2_3 Depth=1
	b	LBB2_10
LBB2_10:                                ;   in Loop: Header=BB2_3 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB2_3
LBB2_11:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
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
	mov	w9, #34512                      ; =0x86d0
	movk	w9, #1, lsl #16
Lloh0:
	adrp	x16, ___chkstk_darwin@GOTPAGE
Lloh1:
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #24, lsl #12            ; =98304
	sub	sp, sp, #1744
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
	str	w0, [sp, #32]
	str	x1, [sp, #24]
	mov	w8, #10                         ; =0xa
	str	w8, [sp, #20]
	ldr	w8, [sp, #32]
	subs	w8, w8, #1
	b.le	LBB3_5
	b	LBB3_1
LBB3_1:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	ldrsb	w8, [x8]
	subs	w8, w8, #45
	b.ne	LBB3_5
	b	LBB3_2
LBB3_2:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	add	x0, x8, #1
	bl	_getint
	str	w0, [sp, #12]
	ldr	w8, [sp, #12]
	tbz	w8, #31, LBB3_4
	b	LBB3_3
LBB3_3:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	str	wzr, [sp, #36]
	b	LBB3_8
LBB3_4:
	ldr	w8, [sp, #12]
	str	w8, [sp, #20]
	b	LBB3_5
LBB3_5:
	add	x0, sp, #40
	add	x1, sp, #16
	bl	_count_and_add
	str	w0, [sp, #8]
	ldr	w8, [sp, #8]
	tbz	w8, #31, LBB3_7
	b	LBB3_6
LBB3_6:
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	str	wzr, [sp, #36]
	b	LBB3_8
LBB3_7:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldr	w0, [sp, #8]
	ldr	w1, [sp, #20]
	ldr	w3, [sp, #16]
	add	x2, sp, #40
	bl	_printlastn
	b	LBB3_8
LBB3_8:
	ldr	w8, [sp, #36]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB3_10
	b	LBB3_9
LBB3_9:
	bl	___stack_chk_fail
LBB3_10:
	ldr	w0, [sp, #4]                    ; 4-byte Folded Reload
	add	sp, sp, #24, lsl #12            ; =98304
	add	sp, sp, #1744
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.loh AdrpLdrGot	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%c"

l_.str.1:                               ; @.str.1
	.asciz	"error in line number, should be of format <tail -n> where n>0\n"

l_.str.2:                               ; @.str.2
	.asciz	"buffer size exceeded\n"

l_.str.3:                               ; @.str.3
	.asciz	"-----------------------------------\n"

.subsections_via_symbols
