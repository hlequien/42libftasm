	;; int ft_puts(char *s)
	;; print s to stdin
	;; returns
	;; NB : on MacOS, write is index 4,
	;; 		Have to define this macro :
	;; 		%define MACH_SYSCALL(nb)	0x2000000 | nb
	;; 	on Linux, write is index 1
	%define WRITE	1
	extern ft_strlen
	global ft_puts

ft_puts:
	push rdi
	call ft_strlen
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	mov rax, 1
	syscall
	pop rdi
	ret
