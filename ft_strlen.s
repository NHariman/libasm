section .text
	global _ft_strlen

; the function:
; size_t ft_strlen(char *str)

_ft_strlen:
	xor rax, rax 			; sets rax to 0

loophead:
	cmp byte [rdi + rax], 0 ; checks if the content of rdi a NULL byte
	je _end 				; done if true
	inc rax 				; increment the counter
	jmp loophead 			; loop back to the top of LoopHead

_end:
	ret 					; return rax

; the explanation
; set rax to 0 as increment counter
; compare each time if rdi is equal to 0 to check if you've reached the end
; if so, return rax. otherwise increment rax and keep going.