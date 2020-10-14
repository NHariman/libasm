section .text
	global _ft_read
	extern ___error

; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ sys call codes
; ssize_t		ft_read(int fd/rdi, const void *buf/rsi, size_t count/rdx);
_ft_read:
	push rbx ; push the count number onto the stack
	mov rax, 0 ; move 0 into rax to call sys_read
	syscall ; perform the system call
	jc check_error;check for error
	pop rbx ; pop the original count number back in
	ret

check_error:
	push rax ; push the value stored in rax
	call ___error
	mov rdi, rax
	pop rax
	mov [rdi], rax
	mov rax, -1
	ret