section .text
	global _ft_strdup ; strdup(string/rdi)
	extern _malloc ; malloc(size/rdi)
	extern _ft_strlen ; strlen(str/rdi)
	extern _ft_strcpy ; strcpy(dst/rdi, src/rsi)

_ft_strdup:
	push rdi ; push original rdi (string) to the stack
	call _ft_strlen ; determine the length to malloc, store in rax
	inc rax ; increment rax so it will hold the null byte
	mov rdi, rax ; move length value rdi for malloc
	call _malloc ; rax changes to hold the pointer for the new string
	mov rdi, rax ; move rax, which holds the pointer to the new string into rdi in preparation for strcpy
	pop rsi ; pop the original string into rsi
	call _ft_strcpy ; call string copy to copy the source into the destination, which will then be put in rax.
	ret ; return the destination string.