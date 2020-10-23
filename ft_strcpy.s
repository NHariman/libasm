section .text
	global _ft_strcpy

;char *strcpy(dst/rdi, src/rsi)
_ft_strcpy:
	xor rax, rax 				; set rax to 0 for incrementing

loophead:
	mov dl, byte [rsi + rax] 	; move value of rsi (source) into dl, least relevant bits of stack
	mov byte [rdi + rax], dl 	; move dl into rdi (destination)
	inc rax
	cmp byte [rsi + rax], 0 	; compare if the next value in source is the null byte
	je _end
	jne loophead

_end:
	mov dl, byte [rsi + rax] 	; move NULL byte
	mov byte [rdi + rax], dl
	mov rax, rdi
	ret