section .text
	global _ft_strcmp
; int strcmp(const char *s1, const char *s2)
_ft_strcmp:
	xor rax, rax ; set counter to 0

loophead:
	mov byte dl, [rdi + rax]
	mov byte dh, [rsi + rax]
	cmp dl, dh
	je checkend
	jl lesser
	jg greater

checkend:
	cmp dl, 0 ; check if the end of the string has been reached
	je end ; if equal, skip to the end
	inc rax ; else increment rax and go back into the loop
	jmp loophead

lesser:
	mov rax, -1 ;move -1 into rax for return
	ret

greater:
	mov rax, 1 ;move 1 into rax for return
	ret

end:
	mov rax, 0 ; move said value into rax to return it
	ret

; the explanation
; set rax to 0, for incrementing
; move rdi (s1) into a register (dl), do the same for rsi (s2) -> dh
; compare the two (cmp dl, dh) -> cmp s1, s2, compares s1 with s2
; if equal (je) go to check end and check if you've reached the end of the string, if yes, skip to the end
; if not equal go back into the loop after incrementing rax
; if it's dl and dh are not equal to each other, skip to end
; subtract dl from dh and store that in dh,
; move dh into rax for the return value and return it