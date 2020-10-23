section .text
	global _ft_strcmp
; int strcmp(const char *s1/rdi, const char *s2/rsi)
_ft_strcmp:
	xor rax, rax ; set counter to 0

loophead:
	mov byte dl, [rdi + rax] 	; move what's in rdi[rax] into dl
	mov byte dh, [rsi + rax] 	; move what's in rsi[rax] into dh
	cmp dl, dh					; compare dl and dh
	je checkend
	jl lesser
	jg greater

checkend:
	cmp dl, 0	; check if the end of the string has been reached
	je end 		; if equal, skip to the end
	inc rax 	; else increment rax and go back into the loop
	jmp loophead

lesser:
	mov rax, -1 ;move -1 into rax for return
	ret

greater:
	mov rax, 1 	;move 1 into rax for return
	ret

end:
	mov rax, 0 	; move said value into rax to return it
	ret
; note, strcmp does different things depending on if a string is malloc'd or not.
; if the string is just strcmp("s1", "s2"); it will return -1, 0 or 1
; after optimising.
; however, if a string is malloc'd,
; ie. str1 = strdup("s1"); str2 = stdrup("s2");
; then it will subtract the two values from each other and return something other than 0, -1 or 1. However, both methods are valid.

; the explanation
; set rax to 0, for incrementing
; move rdi (s1) into a register (dl), do the same for rsi (s2) -> dh
; compare the two (cmp dl, dh) -> cmp s1, s2, compares s1 with s2
; if equal (je) go to check end and check if you've reached the end of the string, if yes, skip to the end
; if not equal go back into the loop after incrementing rax
; if it's dl and dh are not equal to each other, skip to end
; subtract dl from dh and store that in dh,
; move dh into rax for the return value and return it