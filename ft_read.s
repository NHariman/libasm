section .text
	global _ft_read
	extern ___error

; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ sys call codes
; ssize_t		ft_read(int fd/rdi, const void *buf/rsi, size_t count/rdx);
_ft_read:
	mov rax, 0x2000003 	; move sys_read into rax to call it
	syscall 			; perform the system call
	jc check_error 		;check for error
	ret

check_error:
	push rax 			; push the value stored in rax
	push rbp
	mov rbp, rsp
	and rsp, - 16 		; force align stack
	call ___error 		; set errno, moves this value into rax
	mov rsp, rbp
	pop rbp
	mov rdi, rax 		; move this value into rdi
	pop rax 			; pop original value, the error number from the syscall into rax
	mov [rdi], rax 		; move this value into the address or rdi
	mov rax, -1 		; move -1 into rax for error.
	ret 				; return rax