section .text
	global _ft_strlen

; the function:
; size_t ft_strlen(char *str)

_ft_strlen:
	xor rax, rax ; sets rax to 0
	cmp rdi, 0 ; checks if content of rdi, where the 1st argument is stored is empty (0)
	je Finished ; if empty/equal to 0, jump to Finished

LoopHead:
	cmp byte [rdi + rax], 0 ; checks if the content of rdi a NULL byte
	je Finished ; done if true
	inc rax ; increment the counter
	jmp LoopHead ; loop back to the top of LoopHead

Finished:
	ret ; return rax

; the explanation
; set rax to 0 as increment counter
; compare if rdi exists, if not jump straight to finish and return 0
; otherwise iterate through the string,
; compare each time if rdi is equal to 0 to check if you've reached the end
; if so, return rax. otherwise increment rax and keep going.