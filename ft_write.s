section .text
	global _ft_write
	extern ___error

; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ sys call codes

; ssize_t		ft_write(int fd/rdi, const void *buf/rsi, size_t count/rdx);
; ___error: 
_ft_write:
	mov rax, 0x2000004 ; move number into rax to call sys_write
	syscall ; perform the system call, rax changes to the amount of bytes written
	jc check_error;check for error
	ret ; return amount written

check_error:
	push rax ; push original rax value for error
	and rsp, - 16 ; force align stack
	call ___error ; call errno, rax is set to errno address
	mov rdi, rax ; move errno address into rdi
	pop rax ; pop rax back to original error value
	mov [rdi], rax ; move said value into rdi
	mov rax, -1 ; change rax return to -1
	ret