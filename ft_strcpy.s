section .text
	global _ft_strcpy

_ft_strcpy:
	xor rax ; set rax to 0 for incrementing

loophead:
	mov byte dl, [rsi + rax] ; move value of rsi (source) into dl, least relevant bits of stack
	mov byte [rdi + rax], dl ; move dl into rdi (destination)
	inc rax
	cmp byte [rsi + rax], 0 ; compare if the next value in source is the null byte
	je end
	jne loophead

end:
	mov byte dl, [rsi + rax] ; move NULL byte
	mov byte [rdi + rax], dl 
	ret