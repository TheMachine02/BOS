
include 'include/ez80.inc'
include 'include/ti84pceg.inc'
include 'include/bos.inc'

org ti.userMem
	jr explorer_main
	db "REX",0
explorer_main:
	call load_libload
	jr z,.main
	ld hl,str_FailedToLoadLibload
	scf
	sbc hl,hl
	ret
.main:
	;call gfx_Begin ;no need for this lol, already in 8bpp
	ld c,1
	push bc
	call gfx_SetDraw
	call gfx_ZeroScreen
	pop bc
	ld c,0
	push bc
	call gfx_SetTextTransparentColor
	call gfx_SetTextBGColor
	pop bc
	ld c,$A0
	push bc
	call gfx_SetTextFGColor
	pop bc
	ld bc,10
	push bc,bc
	ld bc,str_HelloWorld
	push bc
	call gfx_PrintStringXY
	pop bc,bc,bc
	call gfx_SwapDraw
.key_loop:
	call bos.sys_WaitKeyCycle
	cp a,9
	jr z,.exit
	cp a,15
	jr nz,.key_loop
.exit:
	xor a,a
	sbc hl,hl
	ret

load_libload:
	ld hl,libload_name
	push hl
	call bos.fs_OpenFile
	pop bc
	jr c,.notfound
	ld bc,0
	push bc,hl
	call bos.fs_GetClusterPtr
	pop bc,bc
	ld   de,.relocations
	ld   bc,.notfound
	push   bc
	ld   bc,$aa55aa
	jp   (hl)

.notfound:
	xor   a,a
	inc   a
	ret

.relocations:
	db	$C0, "GRAPHX", $00, 11
gfx_Begin:
	jp 0
gfx_End:
	jp 3
gfx_SetColor:
	jp 6
gfx_FillScreen:
	jp 15
gfx_SetDraw:
	jp 27
gfx_SwapDraw:
	jp 30
gfx_PrintInt:
	jp 45
gfx_PrintString:
	jp 51
gfx_PrintStringXY:
	jp 54
gfx_SetTextXY:
	jp 57
gfx_SetTextBGColor:
	jp 60
gfx_SetTextFGColor:
	jp 63
gfx_SetTextTransparentColor:
	jp 66
gfx_ZeroScreen:
	jp 228

	xor   a,a      ; return z (loaded)
	pop   hl      ; pop error return
	ret

libload_name:
	db   "A:/LibLoad.v21", 0
.len := $ - .

str_HelloWorld:
	db "Hello World!",0
str_FailedToLoadLibload:
	db "Failed to load libload.",0
