section .text
	global _ft_write
	extern ___error

; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ sys call codes

; ssize_t		ft_write(int fd/rdi, const void *buf/rsi, size_t count/rdx);
; ___error: 
_ft_write:
	push rdx ; push count onto stack
	mov rax, 1 ; move 1 into rax to call sys_write
	syscall ; perform the system call
	jc check_error;check for error
	pop rdx
	ret

check_error:
	push rax
	call ___error
	mov rdi, rax
	pop rax
	mov [rdi], rax
	mov rax, -1
	ret